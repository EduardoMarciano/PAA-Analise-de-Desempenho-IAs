// Input Using the previous graph, how to implement the Breadth-First Search algorithm?

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

// Graph class
class Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjacencyList;
    std::vector<bool> visited;

public:
    // Constructor
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
        visited.resize(vertices, false);
    }

    // Add an edge
    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
        adjacencyList[dest].push_back(src); // Undirected graph
    }

    // Depth-First Search
    void dfs(int startVertex) {
        std::stack<int> stack;
        visited[startVertex] = true;
        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            std::cout << currentVertex << " ";
            stack.pop();

            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    stack.push(neighbor);
                }
            }
        }
    }

    // Breadth-First Search
    void bfs(int startVertex) {
        std::queue<int> queue;
        visited[startVertex] = true;
        queue.push(startVertex);

        while (!queue.empty()) {
            int currentVertex = queue.front();
            std::cout << currentVertex << " ";
            queue.pop();

            for (int neighbor : adjacencyList[currentVertex]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    queue.push(neighbor);
                }
            }
        }
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
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.printGraph();

    std::cout << "\nDepth-First Search (starting from vertex 0):" << std::endl;
    g.dfs(0);

    std::cout << "\n\nBreadth-First Search (starting from vertex 0):" << std::endl;
    g.bfs(0);

    return 0;
}