#include <iostream>
#include <vector>
#include <set>

using namespace std;

class MatrixPlucker {
public:
    MatrixPlucker(vector<vector<int>>& mat, const set<pair<int, int>>& elemsToPluck)
        : matrix(mat), elementsToPluck(elemsToPluck), rows(mat.size()), cols(mat[0].size()) {}

    int pluckElements() {
        int plucks = 0;
        for (const auto& elem : elementsToPluck) {
            int i = elem.first;
            int j = elem.second;
            if (matrix[i][j] == 1) {
                pluck(i, j);
                ++plucks;
            }
        }
        return plucks;
    }

private:
    vector<vector<int>>& matrix;
    const set<pair<int, int>>& elementsToPluck;
    int rows, cols;

    void pluck(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] == 0) return;
        matrix[i][j] = 0;
        vector<pair<int, int>> positions = {{i-1, j}, {i, j-1}, {i, j}, {i, j+1}, {i+1, j}};
        for (const auto& pos : positions) {
            int x = pos.first, y = pos.second;
            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                matrix[x][y] = 0;
            }
        }
    }
};

// Example usage
int main() {
    vector<vector<int>> matrix = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 0}
    };

    set<pair<int, int>> elementsToPluck = {{0, 0}, {1, 1}, {2, 1}};
    MatrixPlucker plucker(matrix, elementsToPluck);
    cout << "Total plucks: " << plucker.pluckElements() << endl;

    return 0;
}