# Input:How to implement the quicksort sort algorithm? in python

def quicksort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quicksort(left) + middle + quicksort(right)

# Helper function to partition the array
def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# The main quicksort function
def quicksort_inplace(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quicksort_inplace(arr, low, pi - 1)
        quicksort_inplace(arr, pi + 1, high)

# Wrapper function to call quicksort
def sort(arr):
    quicksort_inplace(arr, 0, len(arr) - 1)
    return arr

# Example usage
if __name__ == "__main__":
    test_array = [3, 6, 8, 10, 1, 2, 1]
    print("Unsorted array:", test_array)
    sorted_array = sort(test_array)
    print("Sorted array:", sorted_array)