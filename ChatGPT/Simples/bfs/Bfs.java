// Input: Using the previous graph, how to implement the Breadth-First Search algorithm?
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Bfs {
    private ArrayList<LinkedList<Integer>> adjList;
    private int numVertices;

    public Bfs(int numVertices) {
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
    public static void main(String[] args) {
        Bfs g = new Bfs(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.bfs(0);
    }
}
/*
Score: 1
*/