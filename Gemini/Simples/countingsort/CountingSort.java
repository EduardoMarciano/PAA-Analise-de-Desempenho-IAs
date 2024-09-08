// Input: How to implement the countingsort sort algorithm? in Java

public class CountingSort {
    public static void countSort(int[] arr) {
        int n = arr.length;

        // Find the maximum element in the array
        int max = arr[0];
        for (int i = 1; i < n; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }

        // Create an auxiliary array to store counts
        int[] count = new int[max + 1];

        // Store counts of elements in the auxiliary array
        for (int i = 0; i < n; i++) {
            count[arr[i]]++;
        }

        // Modify the auxiliary array to store cumulative counts
        for (int i = 1; i <= max; i++) {
            count[i] += count[i - 1];
        }

        // Create an output array of the same size as the input
        int[] output = new int[n];

        // Place elements in the output array using cumulative counts
        for (int i = n - 1; i >= 0; i--) {
            output[count[arr[i]] - 1] = arr[i];
            count[arr[i]]--;
        }

        // Copy the output array to the input array
        System.arraycopy(output, 0, arr, 0, n);
    }

    public static void main(String[] args) {
        int[] arr = {4, 2, 10, 8, 3, 1};
        countSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}
