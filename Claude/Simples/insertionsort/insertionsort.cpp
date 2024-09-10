// Input: How to implement the insertionsort sort algorithm? in c++

#include <cstdio>
#include <vector>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        // Move elements of arr[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90, -25, 0, 0 , 2 , 2};
    insertionSort(arr);
    for(int i : arr){
        printf("%i \n", i);
    }
    
    return 0;
}

/*
Output:
    -25 
    0 
    0 
    2 
    2 
    11 
    12 
    22 
    25 
    34 
    64 
    90

Score: 1
*/