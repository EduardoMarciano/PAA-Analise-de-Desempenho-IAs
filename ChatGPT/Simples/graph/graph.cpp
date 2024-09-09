// How to implement a graph? in c++

#include <iostream>
#include <vector>
#include <list>

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

    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ":";
            for (const int& vertex : adjList[i]) {
                std::cout << " -> " << vertex;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.printGraph();

    return 0;
}
