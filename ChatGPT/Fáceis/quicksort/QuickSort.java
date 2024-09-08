// Input: How to implement the quicksort sort algorithm? in Java

public class QuickSort {

    // Main method to perform quicksort
    public static void quickSort(int[] array, int low, int high) {
        if (low < high) {
            // Find pivot element such that
            // elements smaller than pivot are on the left
            // elements greater than pivot are on the right
            int pivotIndex = partition(array, low, high);
            
            // Recursively sort elements before
            // partition and after partition
            quickSort(array, low, pivotIndex - 1);
            quickSort(array, pivotIndex + 1, high);
        }
    }

    // Method to partition the array on the basis of pivot
    private static int partition(int[] array, int low, int high) {
        // Choose the rightmost element as the pivot
        int pivot = array[high];
        int i = (low - 1); // Index of smaller element

        for (int j = low; j < high; j++) {
            // If the current element is smaller than the pivot
            if (array[j] <= pivot) {
                i++;
                // Swap array[i] and array[j]
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
        // Swap the pivot element with the element at index i + 1
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        return i + 1;
    }

    // Helper method to print the array
    public static void printArray(int[] array) {
        for (int i : array) {
            System.out.print(i + " ");
        }
        System.out.println();
    }

    // Main method to test quicksort
    public static void main(String[] args) {
        int[] array = {10, 7, 8, 9, 1, 5};
        System.out.println("Unsorted array:");
        printArray(array);

        quickSort(array, 0, array.length - 1);

        System.out.println("Sorted array:");
        printArray(array);
    }
}

/*
Output:
    Unsorted array:
    10 7 8 9 1 5 
    Sorted array:
    1 5 7 8 9 10 
*/