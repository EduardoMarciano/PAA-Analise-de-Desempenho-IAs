# Input: How to implement the insertionsort sort algorithm? in python

def insertion_sort(arr):
    # Iterate from the second element to the end of the array
    for i in range(1, len(arr)):
        key = arr[i]  # The element to be inserted into the sorted portion of the array
        j = i - 1  # The index of the last element in the sorted portion
        
        # Move elements of the sorted portion that are greater than the key to one position ahead
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        
        # Insert the key into its correct position
        arr[j + 1] = key

# Example usage
arr = [12, 11, 13, 5, 6, 5, -5, -24]
insertion_sort(arr)
print("Sorted array:", arr)


"""
Output:
    Sorted array: [-24, -5, 5, 5, 6, 11, 12, 13]
Score: 1
"""