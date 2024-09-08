// Input: How to implement the countingsort sort algorithm? in c++

#include <iostream>
#include <vector>

void countingSort(std::vector<int>& arr) {
    int n = arr.size();

    // Find the maximum element in the array
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Create a counting array to store the frequency of each element
    std::vector<int> count(max + 1, 0);
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Modify the counting array to store the cumulative sum
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted elements
    std::vector<int> output(n);

    // Place elements in the output array based on their frequency
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy the sorted elements back to the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() {
    std::vector<int> arr = {4, 2, 10, 8, 3, 9, 7, 5, 6, 1};

    countingSort(arr);

    // Print the sorted array
    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }

    return 0;
}
