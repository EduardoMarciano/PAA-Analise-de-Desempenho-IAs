# How to implement the countingsort sort algorithm? in python

def counting_sort(arr):
    if not arr:
        return arr
    
    # Step 1: Find the range of input values
    max_val = max(arr)
    min_val = min(arr)
    range_of_elements = max_val - min_val + 1

    # Step 2: Initialize count array and output array
    count = [0] * range_of_elements
    output = [0] * len(arr)
    
    # Step 3: Count occurrences of each value
    for num in arr:
        count[num - min_val] += 1
    
    # Step 4: Modify count array to store cumulative counts
    for i in range(1, len(count)):
        count[i] += count[i - 1]
    
    # Step 5: Place elements in the output array
    for num in reversed(arr):
        output[count[num - min_val] - 1] = num
        count[num - min_val] -= 1
    
    return output

# Example usage
arr = [4, 2, 2, 8, 3, 3, 1]
sorted_arr = counting_sort(arr)
print(sorted_arr)  # Output: [1, 2, 2, 3, 3, 4, 8]


"""
Output:
    [1, 2, 2, 3, 3, 4, 8]
"""