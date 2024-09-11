#include <vector>
#include <queue>

using namespace std;

struct Coordinate {
    int row;
    int col;
};

int pluckElements(vector<vector<int>>& matrix, vector<Coordinate>& elements) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<bool>> visited(rows, vector<bool>(cols, false));

    queue<Coordinate> q;

    for (const Coordinate& element : elements) {
        int row = element.row;
        int col = element.col;

        if (!visited[row][col]) {
            q.push(element);

            while (!q.empty()) {
                Coordinate current = q.front();
                q.pop();

                if (!visited[current.row][col]) {
                    visited[current.row][col] = true;

                    if (current.row > 0 && !visited[current.row - 1][col]) {
                        q.push({current.row - 1, col});
                    }
                    if (current.col > 0 && !visited[current.row][col - 1]) {
                        q.push({current.row, col - 1});
                    }
                    if (current.row < rows - 1 && !visited[current.row + 1][col]) {
                        q.push({current.row + 1, col});
                    }
                    if (current.col < cols - 1 && !visited[current.row][col + 1]) {
                        q.push({current.row, col + 1});
                    }
                }
            }
        }
    }

    return count(visited.begin(), visited.end(), true);
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<Coordinate> elements = {{0, 0}, {1, 2}, {2, 1}};

    int numPlucks = pluckElements(matrix, elements);
    cout << "Number of plucks: " << numPlucks << endl;

    return 0;
}