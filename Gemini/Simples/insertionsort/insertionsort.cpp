// Input: How to implement the insertionsort sort algorithm? in c++

#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>& arr) {
int n = arr.size();

for (int i = 1; i < n; i++) {
    int key = arr[i];  

 // Element to be inserted
    int j = i - 1;

    // Find the correct position of key
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
    }

    arr[j + 1] = key;
}

}

int main() {
vector<int> arr = {12, 11, 13, 5, 6, -23, 0, 20, 20, 21};
int n = arr.size();

cout << "Unsorted array: \n";
for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

insertionSort(arr);

cout << "\nSorted array: \n";
for (int i = 0; i < n; i++)
    cout << arr[i] << " ";

return 0;

}
/*
Output:
    Unsorted array: 
    12 11 13 5 6 -23 0 20 20 21 
    Sorted array: 
    -23 0 5 6 11 12 13 20 20 21

Score: 1
*/