// Input: How to implement the insertionsort sort algorithm? in Java

public class InsertionSort {

    // Function to perform insertion sort
    public static void insertionSort(int[] array) {
        // Traverse through 1 to array.length
        for (int i = 1; i < array.length; i++) {
            // The current element to be compared
            int key = array[i];
            // The position where the current element will be inserted
            int j = i - 1;
            
            // Move elements of array[0..i-1], that are greater than key,
            // to one position ahead of their current position
            while (j >= 0 && array[j] > key) {
                array[j + 1] = array[j];
                j = j - 1;
            }
            // Insert the key into its correct position
            array[j + 1] = key;
        }
    }

    // Helper function to print the array
    public static void printArray(int[] array) {
        for (int num : array) {
            System.out.print(num + " ");
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] array = {12, 11, 13, 5, 6, 0, -23, 5};
        System.out.println("Original array:");
        printArray(array);
        
        insertionSort(array);
        
        System.out.println("Sorted array:");
        printArray(array);
    }
}

/*
Output:
    Original array:
    12 11 13 5 6 0 -23 5 
    Sorted array:
    -23 0 5 5 6 11 12 13

Score: 1
*/