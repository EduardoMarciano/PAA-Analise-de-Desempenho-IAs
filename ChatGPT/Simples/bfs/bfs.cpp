// Input Using the previous graph, how to implement the Breadth-First Search algorithm?

#include <iostream>
#include <vector>
#include <list>
#include <queue>

class Graph {
private:
    std::vector<std::list<int>> adjList;
    int numVertices;

public:
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void BFS(int start) {
        std::vector<bool> visited(numVertices, false);
        std::queue<int> q;

        // Start with the initial node
        visited[start] = true;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            std::cout << v << " ";

            // Enqueue all adjacent vertices
            for (const int& vertex : adjList[v]) {
                if (!visited[vertex]) {
                    visited[vertex] = true;
                    q.push(vertex);
                }
            }
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    std::cout << "BFS starting from vertex 0:" << std::endl;
    g.BFS(0);

    return 0;
}

/*
Score: 1
*/