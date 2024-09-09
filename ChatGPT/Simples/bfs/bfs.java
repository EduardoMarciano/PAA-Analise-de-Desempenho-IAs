// Input: Using the previous graph, how to implement the Breadth-First Search algorithm?
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

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

    public void bfs(int startVertex) {
        boolean[] visited = new boolean[numVertices];
        Queue<Integer> queue = new LinkedList<>();

        visited[startVertex] = true;
        queue.add(startVertex);

        while (!queue.isEmpty()) {
            int vertex = queue.poll();
            System.out.print(vertex + " "); // Process the vertex

            for (int neighbor : adjList.get(vertex)) {
                if (!visited[neighbor]) { // Check if not visited
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
    }
}
