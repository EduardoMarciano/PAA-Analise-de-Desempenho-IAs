// Input: How to implement the countingsort sort algorithm? in c++

#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // Find the range of the array
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    // Create a count array to store count of individual numbers
    std::vector<int> count(range);

    // Create an output array
    std::vector<int> output(arr.size());

    // Store count of each number
    for (int i = 0; i < arr.size(); i++) {
        count[arr[i] - min]++;
    }

    // Change count[i] so that count[i] now contains actual
    // position of this number in output array
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // Copy the output array to arr, so that arr now
    // contains sorted numbers
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

// Driver program to test above function
int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    countingSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
Score: 1
*/