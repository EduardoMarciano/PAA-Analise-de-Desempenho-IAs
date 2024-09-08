# Input: How to implement the radixsort sort algorithm? in python

def radix_sort(arr):
    """Sorts an array of integers using Radix Sort.

    Args:
        arr: The array of integers to be sorted.

    Returns:
        The sorted array.
    """

    max_element = max(arr)
    exp = 1

    while max_element // exp > 0:
        counting_sort(arr, exp)
        exp *= 10

    return arr

def counting_sort(arr, exp):
    """Performs counting sort on an array based on a specific digit.

    Args:
        arr: The array to be sorted.
        exp: The exponent determining the digit to be considered.
    """

    n = len(arr)
    count = [0] * 10
    output = [0] * n

    for i in range(n):
        count[(arr[i] // exp) % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    for i in range(n - 1, -1, -1):
        index = (arr[i] // exp) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1

    for i in range(n):
        arr[i] = output[i]
