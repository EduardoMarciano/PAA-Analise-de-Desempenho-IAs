class Fruit:
    def __init__(self, name, price):
        self.name = name
        self.price = price

    def __repr__(self):
        return f"{self.name}: {self.price:.2f}"

def swap(arr, i, j):
    arr[i], arr[j] = arr[j], arr[i]

def partition(arr, low, high):
    pivot = arr[high].price
    i = low - 1
    for j in range(low, high):
        if arr[j].price <= pivot:
            i += 1
            swap(arr, i, j)
    swap(arr, i + 1, high)
    return i + 1

def quicksort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quicksort(arr, low, pi - 1)
        quicksort(arr, pi + 1, high)

def adjust_prices(fruits, banana_tax, apple_tax):
    for fruit in fruits:
        if fruit.name == "banana":
            fruit.price += banana_tax
        elif fruit.name == "apple":
            fruit.price += apple_tax

# Initialize fruits
fruits = [Fruit(f"fruit{i}", 10.0 + i) for i in range(200)]

print("Sorting with old prices:")
quicksort(fruits, 0, len(fruits) - 1)
for fruit in fruits:
    print(fruit.name)
    print(fruit.price)

# Adjust prices for banana and apple
adjust_prices(fruits, 2.0, 3.0)  # Example taxes

print("\nSorting with new prices:")
quicksort(fruits, 0, len(fruits) - 1)
for fruit in fruits:
    print(fruit.name)
    print(fruit.price)
