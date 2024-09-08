// Input: Using the previous graph, how to implement the Depth-First Search algorith?

#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

class Graph {
public:
    Graph(int V) {
        this->V = V;
        adj = new list<int>[V];
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); // For undirected graphs
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        stack<int> stack;

        stack.push(start);
        visited[start] = true;

        while (!stack.empty()) {
            int current = stack.top();
            stack.pop();

            cout << current << " ";

            for (auto neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    stack.push(neighbor);
                    visited[neighbor] = true;
                }
            }
        }
    }

private:
    int V;
    list<int>* adj;
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    cout << "DFS traversal starting from vertex 0:\n";
    g.DFS(0);

    return 0;
}