# Input: How to implement the countingsort sort algorithm? in python

def counting_sort(arr):
    """
    Performs counting sort on the given array.

    Args:
        arr: The input array to be sorted.

    Returns:
        The sorted array.
    """

    # Find the maximum element in the array
    max_element = max(arr)

    # Create a counting array to store counts of each element
    count = [0] * (max_element + 1)

    # Store the count of each element in the count array
    for num in arr:
        count[num] += 1

    # Modify the count array to store the cumulative sum
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Create an output array to store the sorted elements
    output = [0] * len(arr)

    # Place each element in its correct position in the output array
    for i in range(len(arr)):
        output[count[arr[i]] - 1] = arr[i]
        count[arr[i]] -= 1

    return output

# Example usage
arr = [4, 2, 10, 8, 3, 1, 7, 6, 5, 9]
sorted_arr = counting_sort(arr)
print(sorted_arr)

"""
Output:1 2 3 4 5 6 7 8 9 10
Wrong:  is not stable
Score: 0.75
"""