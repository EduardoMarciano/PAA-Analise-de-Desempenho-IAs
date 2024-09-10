# Input: How to implement the countingsort sort algorithm? in python

def counting_sort(arr):
    """
    Perform counting sort on the given array.
    
    Args:
        arr (list): The input array to be sorted.
        
    Returns:
        list: The sorted array.
    """
    # Find the maximum element in the array
    max_element = max(arr)
    
    # Create a count array to store the count of individual
    # elements in the input array
    count_arr = [0] * (max_element + 1)
    
    # Store count of each element
    for element in arr:
        count_arr[element] += 1
    
    # Modify the count_arr to get the actual
    # position of this element in the output array
    for i in range(1, len(count_arr)):
        count_arr[i] += count_arr[i - 1]
    
    # Build the output character array
    output_arr = [0] * len(arr)
    i = len(arr) - 1
    while i >= 0:
        output_arr[count_arr[arr[i]] - 1] = arr[i]
        count_arr[arr[i]] -= 1
        i -= 1
    
    return output_arr

lista = [1, 5, 2, 25, 40, 10, 0]

counting_sort(lista)
print(lista)

"""
Score: 1
"""