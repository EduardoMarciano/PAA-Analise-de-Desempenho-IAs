# Input: How to implement the insertionsort sort algorithm? in python

def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

# Example usage
arr = [64, 34, 25, 12, 22, 11, 90, -23, 0, 0]
sorted_arr = insertion_sort(arr)
print(sorted_arr)

"""
Output:
    [-23, 0, 0, 11, 12, 22, 25, 34, 64, 90]

Score: 1
"""