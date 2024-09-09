// Input  Using the previous graph, how to implement the Depth-First Search algorith?
import java.util.ArrayList;
import java.util.LinkedList;

public class Graph {
    private ArrayList<LinkedList<Integer>> adjList;
    private int numVertices;

    public Graph(int numVertices) {
        this.numVertices = numVertices;
        adjList = new ArrayList<>(numVertices);
        for (int i = 0; i < numVertices; i++) {
            adjList.add(new LinkedList<>());
        }
    }

    // Other methods (addEdge, removeEdge, etc.)

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
}
