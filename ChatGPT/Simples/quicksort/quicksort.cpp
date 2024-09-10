// Input:How to implement the quicksort sort algorithm? in c++

#include <iostream>
using namespace std;

// Function to swap elements at index i and j in an array
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Partition function to place pivot element at its correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choose the rightmost element as the pivot
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j < high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++;  // Increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return the partitioning index
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the pivot element such that
        // elements smaller than pivot are on the left of pivot
        // elements greater than pivot are on the right of pivot
        int pi = partition(arr, low, high);

        // Recursively sort elements before and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: ";
    printArray(arr, n);
    return 0;
}

/*
Output:
    Sorted array: 1 5 7 8 9 10

Score: 1
*/
