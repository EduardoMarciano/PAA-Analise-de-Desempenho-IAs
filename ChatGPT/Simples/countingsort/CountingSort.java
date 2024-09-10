// Input: How to implement the countingsort sort algorithm? in Java

import java.util.Arrays;

public class CountingSort {

    // Function to perform counting sort
    public static void countingSort(int[] array) {
        if (array == null || array.length == 0) {
            return;
        }

        // Step 1: Find the maximum value
        int max = Arrays.stream(array).max().getAsInt();

        // Step 2: Create the count array
        int[] count = new int[max + 1];

        // Step 3: Store the count of each number
        for (int num : array) {
            count[num]++;
        }

        // Step 4: Build the sorted output array
        int index = 0;
        for (int i = 0; i < count.length; i++) {
            while (count[i] > 0) {
                array[index++] = i;
                count[i]--;
            }
        }
    }

    // Main method to test the counting sort
    public static void main(String[] args) {
        int[] array = {4, 2, 2, 8, 3, 3, 1};
        System.out.println("Original array: " + Arrays.toString(array));
        countingSort(array);
        System.out.println("Sorted array: " + Arrays.toString(array));
    }
}

/*
Output:
    Original array: [4, 2, 2, 8, 3, 3, 1]
    Sorted array: [1, 2, 2, 3, 3, 4, 8]

Wrong:  is not stable
Score: 0.75
*/