#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 10
#define NUM_FRUITS 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    double price;
} Fruit;

double get_price_with_old_tax(const Fruit* fruit) {
    return fruit->price;
}

double get_price_with_new_tax(const Fruit* fruit) {
    if (strcmp(fruit->name, "banana") == 0 || strcmp(fruit->name, "apple") == 0) {
        return fruit->price * 1.1; // 10% tax increase
    }
    return fruit->price;
}

int partition(Fruit* arr, int low, int high, double (*price_func)(const Fruit*)) {
    double pivot = price_func(&arr[high]);
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (price_func(&arr[j]) <= pivot) {
            i++;
            Fruit temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    Fruit temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quicksort(Fruit* arr, int low, int high, double (*price_func)(const Fruit*)) {
    if (low < high) {
        int pi = partition(arr, low, high, price_func);
        quicksort(arr, low, pi - 1, price_func);
        quicksort(arr, pi + 1, high, price_func);
    }
}

int main() {
    srand(time(NULL));
    const char* fruit_names[] = {"apple", "banana", "orange", "grape", "pear"};
    int num_fruit_names = sizeof(fruit_names) / sizeof(fruit_names[0]);

    Fruit fruits[NUM_FRUITS];
    for (int i = 0; i < NUM_FRUITS; i++) {
        strcpy(fruits[i].name, fruit_names[rand() % num_fruit_names]);
        fruits[i].price = 0.5 + ((double)rand() / RAND_MAX) * 4.5; // Random price between 0.5 and 5.0
    }

    // Sort with old taxes
    Fruit old_tax_fruits[NUM_FRUITS];
    memcpy(old_tax_fruits, fruits, sizeof(fruits));
    quicksort(old_tax_fruits, 0, NUM_FRUITS - 1, get_price_with_old_tax);

    // Sort with new taxes
    Fruit new_tax_fruits[NUM_FRUITS];
    memcpy(new_tax_fruits, fruits, sizeof(fruits));
    quicksort(new_tax_fruits, 0, NUM_FRUITS - 1, get_price_with_new_tax);

    // Print results
    printf("Sorted fruits with old taxes:\n");
    for (int i = 0; i < 10 && i < NUM_FRUITS; i++) {
        printf("%s: $%.2f\n", old_tax_fruits[i].name, old_tax_fruits[i].price);
    }

    printf("\nSorted fruits with new taxes:\n");
    for (int i = 0; i < 10 && i < NUM_FRUITS; i++) {
        double price = get_price_with_new_tax(&new_tax_fruits[i]);
        printf("%s: $%.2f\n", new_tax_fruits[i].name, price);
    }

    return 0;
}
