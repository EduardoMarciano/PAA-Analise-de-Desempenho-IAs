#include <iostream>
#include <vector>

class Fruit {
public:
    std::string name;
    double price;
    bool isTaxed;

    Fruit(const std::string& name, double price, bool isTaxed)
        : name(name), price(price), isTaxed(isTaxed) {}
};

void quicksort(std::vector<Fruit>& fruits, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(fruits, low, high);
        quicksort(fruits, low, pivotIndex - 1);
        quicksort(fruits, pivotIndex + 1, high);
    }
}


int partition(std::vector<Fruit>& fruits, int low, int high) {
    double pivotPrice = fruits[high].price;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (fruits[j].price <= pivotPrice) {
            i++;
            std::swap(fruits[i], fruits[j]);
        }
    }

    std::swap(fruits[i + 1], fruits[high]);
    return i + 1;
}


int main() {
    // Create a vector of fruits
    std::vector<Fruit> fruits = {
        {"apple", 1.5, true},
        {"banana", 1.2, true},
        {"orange", 1.0, false},
        // ... add more fruits
    };

    // Sort with original taxes
    std::vector<Fruit> fruitsWithOriginalTaxes = fruits;
    quicksort(fruitsWithOriginalTaxes, 0, fruitsWithOriginalTaxes.size() - 1);

    // Sort with increased taxes
    for (Fruit& fruit : fruits) {
        if (fruit.isTaxed) {
            fruit.price *= 1.1; // Increase price by 10% for taxed fruits
        }
    }
    std::vector<Fruit> fruitsWithIncreasedTaxes = fruits;
    quicksort(fruitsWithIncreasedTaxes, 0, fruitsWithIncreasedTaxes.size() - 1);

    // Print results
    // ...
    for (Fruit& fruit : fruits) {
        if (fruit.isTaxed) {
            std::cout << fruit.name << "\n";
            std::cout << fruit.price;
        }
    }
}