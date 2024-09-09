// Input: Using the previous graph, how to implement the Depth-First Search algorith?

#include <iostream>
#include <vector>
#include <list>

class Graph {
private:
    std::vector<std::list<int>> adjList;
    int numVertices;

    void DFSUtil(int v, std::vector<bool>& visited) {
        // Mark the current node as visited
        visited[v] = true;
        std::cout << v << " ";

        // Recur for all adjacent vertices
        for (const int& vertex : adjList[v]) {
            if (!visited[vertex]) {
                DFSUtil(vertex, visited);
            }
        }
    }

public:
    Graph(int vertices) : numVertices(vertices) {
        adjList.resize(vertices);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void DFS(int start) {
        std::vector<bool> visited(numVertices, false);
        DFSUtil(start, visited);
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);

    std::cout << "DFS starting from vertex 0:" << std::endl;
    g.DFS(0);

    return 0;
}

/*
Score: 1
*/