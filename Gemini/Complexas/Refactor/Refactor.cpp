#include <vector>
#include <algorithm>

std::vector<std::vector<int>> refactor_matrix(const std::vector<std::vector<int>>& A0, int P) {
    int M = A0.size(), N = A0[0].size();
    std::vector<std::vector<int>> A1(M / P, std::vector<int>(N / P));
    for (int i = 0; i < M; i += P) {
        for (int j = 0; j < N; j += P) {
            int max_val = *std::max_element(A0.begin() + i, A0.begin() + i + P,
                                           [&](const std::vector<int>& row1, const std::vector<int>& row2) {
                                               return *std::max_element(row1.begin() + j, row1.begin() + j + P) <
                                                      *std::max_element(row2.begin() + j, row2.begin() + j + P);
                                           });
            A1[i / P][j / P] = max_val;
        }
    }
    return A1;
}