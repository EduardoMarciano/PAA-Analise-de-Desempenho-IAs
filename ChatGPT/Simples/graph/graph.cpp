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
    g.addEdge(1, 2);
    g.addEdge(2, 2);
    g.printGraph();

    return 0;
}
/*
Output:
    Vertex 0: -> 1
    Vertex 1: -> 0 -> 2
    Vertex 2: -> 1 -> 2 -> 2
    Vertex 3:
    Wrong: Vertex 2: -> 1 -> 2 -> 2
    Should be: 'Vertex 2: -> 1 -> 2
    Score: 0.75
*/