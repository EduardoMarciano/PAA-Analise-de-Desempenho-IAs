class Fruit:
    def __init__(self, name, price, is_taxed):
        self.name = name
        self.price = price
        self.is_taxed = is_taxed

def quicksort(fruits, low, high):
    if low < high:
        pivot_index = partition(fruits, low, high)
        quicksort(fruits, low, pivot_index - 1)
        quicksort(fruits, pivot_index + 1, high)

def partition(fruits, low, high):
    pivot_price = fruits[high].price
    i = low - 1

    for j in range(low, high):
        if fruits[j].price <= pivot_price:
            i += 1
            fruits[i], fruits[j] = fruits[j], fruits[i]

    fruits[i + 1], fruits[high] = fruits[high], fruits[i + 1]
    return i + 1

if __name__ == "__main__":
    # Create a list of fruits
    fruits = [
        Fruit("apple", 1.5, True),
        Fruit("banana", 1.2, True),
        Fruit("orange", 1.0, False),
        # ... add more fruits
    ]

    # Sort with original taxes
    fruits_with_original_taxes = fruits.copy()
    quicksort(fruits_with_original_taxes, 0, len(fruits_with_original_taxes) - 1)

    # Sort with increased taxes
    for fruit in fruits:
        if fruit.is_taxed:
            fruit.price *= 1.1  # Increase price by 10% for taxed fruits
    fruits_with_increased_taxes = fruits.copy()
    quicksort(fruits_with_increased_taxes, 0, len(fruits_with_increased_taxes) - 1)

    # Print results
    # ...