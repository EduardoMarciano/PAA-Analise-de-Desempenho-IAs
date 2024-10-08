// How to implement a graph? in c++

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
public:
    Graph(int V) {
        this->V = V;
        adj = new list<pair<int, int>>[V];
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w)); // For undirected graphs
    }

    void printGraph() {
        for (int i = 0; i < V; ++i) {
            cout << i << " -> ";
            for (auto x : adj[i]) {
                cout << "(" << x.first << ", " << x.second << ") ";
            }
            cout << endl;
        }
    }

private:
    int V;
    list<pair<int, int>>* adj;
};

int main() {
    Graph g(3);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 0, 6);
    g.addEdge(1, 2, 3);

    g.printGraph();

    return 0;
}
/*
Output:
    0 -> (1, 2) (0, 6) (0, 6) 
    1 -> (0, 2) (2, 3) 
    2 -> (1, 3) 
    
Wrong: 0 -> (1, 2) (0, 6) (0, 6) 

Should be: (1, 2) (0, 6)

Score: 0.75
*/