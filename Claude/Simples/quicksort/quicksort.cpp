// How to implement the quicksort sort algorithm? in c++

#include <iostream>
#include <vector>

// Function to swap two elements
void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function
int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose the last element as pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Quicksort function
void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print the array
void printArray(const std::vector<int>& arr) {
    for (int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}

// Main function to test the quicksort implementation
int main() {
    std::vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    
    std::cout << "Unsorted array: ";
    printArray(arr);
    
    quickSort(arr, 0, n - 1);
    
    std::cout << "Sorted array: ";
    printArray(arr);
    
    return 0;
}

/*
Score: 1
*/