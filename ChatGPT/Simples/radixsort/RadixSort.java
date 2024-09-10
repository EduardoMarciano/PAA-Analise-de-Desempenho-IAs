// Input: How to implement the radixsort sort algorithm? in Java

import java.util.Arrays;

public class RadixSort {

    // Main function to sort the array using Radix Sort
    public static void radixSort(int[] array) {
        // Find the maximum number to determine the number of digits
        int max = Arrays.stream(array).max().getAsInt();
        int exp = 1; // Initialize exponent (10^0)

        // Perform Counting Sort for every digit
        while (max / exp > 0) {
            countingSort(array, exp);
            exp *= 10; // Move to the next digit
        }
    }

    // Function to perform Counting Sort based on a particular digit
    private static void countingSort(int[] array, int exp) {
        int n = array.length;
        int[] output = new int[n];
        int[] count = new int[10];

        // Initialize count array
        Arrays.fill(count, 0);

        // Store count of occurrences of each digit
        for (int i = 0; i < n; i++) {
            int index = (array[i] / exp) % 10;
            count[index]++;
        }

        // Update count[i] so that count[i] contains the actual position of
        // this digit in the output array
        for (int i = 1; i < 10; i++) {
            count[i] += count[i - 1];
        }

        // Build the output array
        for (int i = n - 1; i >= 0; i--) {
            int index = (array[i] / exp) % 10;
            output[count[index] - 1] = array[i];
            count[index]--;
        }

        // Copy the output array to the original array
        System.arraycopy(output, 0, array, 0, n);
    }

    // Main method to test the radixSort function
    public static void main(String[] args) {
        int[] array = {170, 45, 75, 90, 802, 24, 2, 66};
        System.out.println("Original array: " + Arrays.toString(array));

        radixSort(array);

        System.out.println("Sorted array: " + Arrays.toString(array));
    }
}

/*
Output:
    Original array: [170, 45, 75, 90, 802, 24, 2, 66]
    Sorted array: [2, 24, 45, 66, 75, 90, 170, 802]

Score: 1
*/