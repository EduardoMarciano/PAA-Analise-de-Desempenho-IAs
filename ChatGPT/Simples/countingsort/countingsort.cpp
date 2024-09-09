// Input: How to implement the countingsort sort algorithm? in c++

#include <iostream>
#include <vector>
#include <algorithm> // For std::max

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) return; // Handle empty input

    // Find the maximum and minimum values in the array
    int maxVal = *std::max_element(arr.begin(), arr.end());
    int minVal = *std::min_element(arr.begin(), arr.end());

    // Create a count array and initialize it with zeroes
    int range = maxVal - minVal + 1;
    std::vector<int> count(range, 0);

    // Fill the count array
    for (int num : arr) {
        count[num - minVal]++;
    }

    // Reconstruct the sorted array
    int index = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[index++] = i + minVal;
            count[i]--;
        }
    }
}

int main() {
    std::vector<int> arr = {4, 2, 2, 8, 3, 3, 1};

    countingSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
Output:
    Sorted array: 1 2 2 3 3 4 8 
*/
