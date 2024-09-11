import random

class Fruit:
    def __init__(self, name, price):
        self.name = name
        self.price = price

def quicksort(arr, low, high, price_func):
    if low < high:
        pi = partition(arr, low, high, price_func)
        quicksort(arr, low, pi - 1, price_func)
        quicksort(arr, pi + 1, high, price_func)

def partition(arr, low, high, price_func):
    pivot = price_func(arr[high])
    i = low - 1
    for j in range(low, high):
        if price_func(arr[j]) <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def get_price_with_old_tax(fruit):
    return fruit.price

def get_price_with_new_tax(fruit):
    if fruit.name in ["banana", "apple"]:
        return fruit.price * 1.1  # 10% tax increase
    return fruit.price

# Generate 200 random fruits
fruits = []
fruit_names = ["apple", "banana", "orange", "grape", "pear"]
for _ in range(200):
    name = random.choice(fruit_names)
    price = random.uniform(0.5, 5.0)
    fruits.append(Fruit(name, price))

# Sort with old taxes
old_tax_fruits = fruits.copy()
quicksort(old_tax_fruits, 0, len(old_tax_fruits) - 1, get_price_with_old_tax)

# Sort with new taxes
new_tax_fruits = fruits.copy()
quicksort(new_tax_fruits, 0, len(new_tax_fruits) - 1, get_price_with_new_tax)

# Print results
print("Sorted fruits with old taxes:")
for fruit in old_tax_fruits[:10]:  # Print first 10 for brevity
    print(f"{fruit.name}: ${fruit.price:.2f}")

print("\nSorted fruits with new taxes:")
for fruit in new_tax_fruits[:10]:  # Print first 10 for brevity
    price = get_price_with_new_tax(fruit)
    print(f"{fruit.name}: ${price:.2f}")