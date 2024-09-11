#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> refactor_matrix(const std::vector<std::vector<int>>& A0, int P) {
    int M = A0.size();
    int N = A0[0].size();
    int new_M = M / P;
    int new_N = N / P;
    
    std::vector<std::vector<int>> A1(new_M, std::vector<int>(new_N, 0));
    
    for (int i = 0; i < new_M; ++i) {
        for (int j = 0; j < new_N; ++j) {
            int max_element = A0[i*P][j*P];
            for (int x = 0; x < P; ++x) {
                for (int y = 0; y < P; ++y) {
                    max_element = std::max(max_element, A0[i*P + x][j*P + y]);
                }
            }
            A1[i][j] = max_element;
        }
    }
    
    return A1;
}

int main() {
    std::vector<std::vector<int>> A0 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int P = 2;
    
    std::vector<std::vector<int>> A1 = refactor_matrix(A0, P);
    
    for (const auto& row : A1) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}