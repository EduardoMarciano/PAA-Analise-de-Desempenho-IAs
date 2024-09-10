# Input: How to implement the radixsort sort algorithm? in python

def radix_sort(arr):
    """
    Performs radix sort on the given array.
    
    Args:
        arr (list): The input array to be sorted.
    
    Returns:
        list: The sorted array.
    """
    # Get the maximum element to know the number of digits
    max_element = max(arr)

    # Do counting sort for every digit. Note that instead of passing
    # digit number, exp is passed. exp is 10^i where i is current
    # digit number
    exp = 1
    while max_element / exp > 0:
        counting_sort(arr, len(arr), exp)
        exp *= 10

    return arr

def counting_sort(arr, n, exp):
    """
    Performs counting sort on the given array based on the current digit.
    
    Args:
        arr (list): The input array to be sorted.
        n (int): The length of the input array.
        exp (int): The current digit to sort on (10^i).
    
    Returns:
        None (the input array is modified in-place)
    """
    output = [0] * n  # output array
    count = [0] * 10  # count array as 0-9

    # Store count of occurrences in count[]
    for i in range(n):
        index = arr[i] // exp
        count[index % 10] += 1

    # Change count[i] so that count[i] now contains actual
    # position of this digit in output array
    for i in range(1, 10):
        count[i] += count[i - 1]

    i = n - 1
    while i >= 0:
        index = arr[i] // exp
        output[count[index % 10] - 1] = arr[i]
        count[index % 10] -= 1
        i -= 1

    for i in range(n):
        arr[i] = output[i]

example_array = [170, 45, 75, 90, 802, 24, 2, 66]
sorted_array = radix_sort(example_array)
print(sorted_array)  # Output: [2, 24, 45, 66, 75, 90, 170, 802]

"""
Score: 1
"""