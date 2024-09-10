// Input: How to implement the radixsort sort algorithm? in c++

#include <iostream>
#include <vector>

void radixSort(std::vector<int>& arr) {
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exp = 1;
    while (max / exp > 0) {
        std::vector<int> bucket[10];

        for (int i = 0; i < arr.size(); i++) {
            bucket[(arr[i] / exp) % 10].push_back(arr[i]);
        }

        int index = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < bucket[i].size(); j++) {
                arr[index++] = bucket[i][j];
            }
        }

        exp *= 10;
    }
}

int main() {
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    radixSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
/*
Score: 1
*/
