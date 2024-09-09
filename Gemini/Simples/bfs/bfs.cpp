// Input Using the previous graph, how to implement the Breadth-First Search algorithm?

#include <iostream>
#include <vector>
#include <list>
#include <queue>

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

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            cout << current << " ";

            for (auto neighbor : adj[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }

private:
    int V;
    list<int>* adj;
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 3);
    g.addEdge(1, 2);
    g.addEdge(4, 5);

    cout << "BFS traversal starting from vertex 0:\n";
    g.BFS(0);

    return 0;
}

/*
Score: 1
*/