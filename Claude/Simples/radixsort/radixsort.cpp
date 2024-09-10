// Input: How to implement the radixsort sort algorithm? in c++

#include <iostream>
#include <vector>

// Function to get the maximum element from the array
int getMax(std::vector<int>& arr, int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Counting sort based on the digit. exp is 10^i where i is current digit level.
void countSort(std::vector<int>& arr, int n, int exp) {
    std::vector<int> output(n);
    int count[10] = { 0 };

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual
    // position of this digit in output array
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    int i = n - 1;
    while (i >= 0) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
        i--;
    }

    // Placing output array elements back to arr[]
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to implement radix sort
void radixSort(std::vector<int>& arr, int n) {
    // Find the maximum element to know the number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead of passing digit number,
    // exp is passed. exp is 10^i where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() {
    std::vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
    int n = arr.size();

    radixSort(arr, n);

    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}

/*
Score: 1
*/