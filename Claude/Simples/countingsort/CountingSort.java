// Input: How to implement the countingsort sort algorithm? in Java

import java.util.Arrays;

public class CountingSort {
    public static void countingSort(int[] arr) {
        int n = arr.length;
        int max = Arrays.stream(arr).max().orElse(0);
        
        // Create a count array to store the count of individual elements
        int[] count = new int[max + 1];
        
        // Store the count of each element
        for (int i = 0; i < n; ++i) {
            count[arr[i]]++;
        }
        
        // Store the cumulative count
        for (int i = 1; i <= max; ++i) {
            count[i] += count[i - 1];
        }
        
        // Find the index of each element of the original array in count array
        // and place the elements in output array
        int[] output = new int[n];
        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }
        
        // Copying the output array to the original array
        for (int i = 0; i < n; i++) {
            arr[i] = output[i];
        }
    }

    public static void main(String[] args) {
        int[] arr = {5, 2, 4, 6, 1, 3, 2, 6};
        countingSort(arr);
        System.out.println(Arrays.toString(arr)); // Output: [1, 2, 2, 3, 4, 5, 6, 6]
    }
}