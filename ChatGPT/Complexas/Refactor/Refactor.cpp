#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> refactorMatrix(const vector<vector<int>>& A0, int P) {
    int M = A0.size();
    int N = A0[0].size();
    int M1 = M / P;
    int N1 = N / P;
    
    vector<vector<int>> A1(M1, vector<int>(N1, 0));
    
    for (int i = 0; i < M1; ++i) {
        for (int j = 0; j < N1; ++j) {
            int maxVal = A0[i*P][j*P];
            for (int x = 0; x < P; ++x) {
                for (int y = 0; y < P; ++y) {
                    maxVal = max(maxVal, A0[i*P + x][j*P + y]);
                }
            }
            A1[i][j] = maxVal;
        }
    }
    
    return A1;
}

int main() {
    vector<vector<int>> A0 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };
    int P = 2;
    vector<vector<int>> A1 = refactorMatrix(A0, P);
    
    for (const auto& row : A1) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
    
    return 0;
}