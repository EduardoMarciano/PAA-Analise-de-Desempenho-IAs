// How to implement a graph? in c++

#include <iostream>
#include <vector>
#include <list>

// Graph class
class Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjacencyList;

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    // Add an edge
    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src); // Undirected graph
    }

    // Print the graph
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << "Vertex " << i << ":";
            for (int neighbor : adjacencyList[i]) {
                std::cout << " -> " << neighbor;
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph g(3);

    g.addEdge(0, 1);
    g.addEdge(1, 0);
    g.addEdge(2, 2);

    g.printGraph();

    return 0;
}

/*
Output:
    Vertex 0: -> 1 -> 1
    Vertex 1: -> 0 -> 0
    Vertex 2: -> 2 -> 2
    Wrong:  Vertex 2: -> 2 -> 2
    Should be:  Vertex 2: -> 2
    Score: 0.75
*/
