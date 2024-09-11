#include <stdio.h>
#include <string.h>

#define NUM_FRUITS 200

typedef struct {
    char name[20];
    float price;
} Fruit;

void swap(Fruit *a, Fruit *b) {
    Fruit temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Fruit arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j].price <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(Fruit arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void adjustPrices(Fruit arr[], int n, float bananaTax, float appleTax) {
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, "banana") == 0) {
            arr[i].price += bananaTax;
        } else if (strcmp(arr[i].name, "apple") == 0) {
            arr[i].price += appleTax;
        }
    }
}

int main() {
    Fruit fruits[NUM_FRUITS]; // Populate this array with the fruits' names and prices
    
    // Simulating the initial prices
    for (int i = 0; i < NUM_FRUITS; i++) {
        sprintf(fruits[i].name, "fruit%d", i); // Assign a generic name or banana, apple, etc.
        fruits[i].price = 10.0 + i; // Example price
    }

    printf("Sorting with old prices:\n");
    quicksort(fruits, 0, NUM_FRUITS - 1);
    for (int i = 0; i < NUM_FRUITS; i++) {
        printf("%s: %.2f\n", fruits[i].name, fruits[i].price);
    }

    // Adjust prices for bananas and apples
    adjustPrices(fruits, NUM_FRUITS, 2.0, 3.0); // Assume 2.0 tax for bananas and 3.0 for apples

    printf("\nSorting with new prices:\n");
    quicksort(fruits, 0, NUM_FRUITS - 1);
    for (int i = 0; i < NUM_FRUITS; i++) {
        printf("%s: %.2f\n", fruits[i].name, fruits[i].price);
    }

    return 0;
}
