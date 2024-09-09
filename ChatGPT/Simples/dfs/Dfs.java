// Input  Using the previous graph, how to implement the Depth-First Search algorith?
import java.util.ArrayList;
import java.util.LinkedList;

public class Dfs {
    private ArrayList<LinkedList<Integer>> adjList;
    private int numVertices;

    public Dfs(int numVertices) {
        this.numVertices = numVertices;
        adjList = new ArrayList<>(numVertices);
        for (int i = 0; i < numVertices; i++) {
            adjList.add(new LinkedList<>());
        }
    }

    public void addEdge(int src, int dest) {
        adjList.get(src).add(dest);
        adjList.get(dest).add(src); // If the graph is undirected
    }

    public void dfs(int startVertex) {
        boolean[] visited = new boolean[numVertices];
        dfsRecursive(startVertex, visited);
    }

    private void dfsRecursive(int vertex, boolean[] visited) {
        visited[vertex] = true;
        System.out.print(vertex + " "); // Process the vertex

        for (int neighbor : adjList.get(vertex)) {
            if (!visited[neighbor]) { // Check if not visited
                dfsRecursive(neighbor, visited);
            }
        }
    }

    public static void main(String[] args) {
        Dfs g = new Dfs(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.dfs(0);
    }
}
/*
Score: 1
*/