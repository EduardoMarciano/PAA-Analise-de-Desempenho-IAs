// Input: How to implement the radixsort sort algorithm? in Java

import java.util.Arrays;

public class RadixSort {

    public static void radixSort(int[] arr) {
        int n = arr.length;
        int max = getMax(arr, n);

        // Do counting sort for every digit. Note that instead of passing
        // digit number, exp is passed. exp is 10^i where i is current
        // digit number
        for (int exp = 1; max / exp > 0; exp *= 10)
            countingSort(arr, n, exp);
    }

    // A utility function to get maximum value in arr[]
    static int getMax(int arr[], int n) {
        int mx = arr[0];
        for (int i = 1; i < n; i++)
            if (arr[i] > mx)
                mx = arr[i];
        return mx;
    }

    // A function to do counting sort of arr[] according to the digit represented by exp.
    static void countingSort(int arr[], int n, int exp) {
        int output[] = new int[n]; // output array
        int i;
        int count[] = new int[10];
        Arrays.fill(count, 0);

        // Store count of occurrences in count[]
        for (i = 0; i < n; i++)
            count[(arr[i] / exp) % 10]++;

        // Change count[i] so that count[i] now contains actual
        // position of this digit in output array
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        i = n - 1;
        while (i >= 0) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
            i--;
        }

        // Populate the original array with sorted elements
        for (i = 0; i < n; i++)
            arr[i] = output[i];
    }

    // Driver method to test above
    public static void main(String[] args) {
        int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
        radixSort(arr);
        System.out.println(Arrays.toString(arr));
    }
}