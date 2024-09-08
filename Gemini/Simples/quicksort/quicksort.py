# Input:How to implement the quicksort sort algorithm? in python

def quicksort(arr):
    """Sorts the given array using the quicksort algorithm.

    Args:
        arr: The array to be sorted.

    Returns:
        The sorted array.
    """

    if len(arr) <= 1:
        return arr

    # Choose a pivot element using the median-of-three method
    pivot_index = median_of_three(arr, 0, len(arr) - 1)
    pivot = arr[pivot_index]

    # Partition the array around the pivot
    left, right = 0, len(arr) - 1
    while left <= right:
        while arr[left] < pivot:
            left += 1
        while arr[right] > pivot:
            right -= 1
        if left <= right:
            arr[left], arr[right] = arr[right], arr[left]
            left += 1
            right -= 1

    # Recursively sort the left and right subarrays
    quicksort(arr[:left])
    quicksort(arr[right:])

    return arr

def median_of_three(arr, left, right):
    """Finds the median value of the three elements at the given indices.

    Args:
        arr: The array containing the elements.
        left: The index of the first element.
        right: The index of the last element.

    Returns:
        The index of the median element.
    """

    mid = (left + right) // 2
    if arr[left] > arr[mid]:
        arr[left], arr[mid] = arr[mid], arr[left]
    if arr[mid] > arr[right]:
        arr[mid], arr[right] = arr[right], arr[mid]
    if arr[left] > arr[mid]:
        arr[left], arr[mid] = arr[mid], arr[left]
    return mid

