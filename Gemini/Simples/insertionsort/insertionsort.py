# Input: How to implement the insertionsort sort algorithm? in python

def insertion_sort(arr):
  """Sorts an array of elements using the insertion sort algorithm.

  Args:
    arr: The array to be sorted.

  Returns:
    The sorted array.
  """

  n = len(arr)

  # Iterate through the array, starting from the second element
  for i in range(1, n):
    key = arr[i]  # Key is the element to be inserted

    # Find the correct position for the key in the sorted subarray
    j = i - 1
    while j >= 0 and arr[j] > key:
      arr[j + 1] = arr[j]
      j -= 1

    # Insert the key at its correct position
    arr[j + 1] = key

  return arr

lista = [-2, 0, 1, 38, 2, 8, 4, 5, 3, 25, 2]
lista = insertion_sort(lista)

print(lista)

"""
Output:
  [-2, 0, 1, 2, 2, 3, 4, 5, 8, 25, 38]

Score: 1
"""