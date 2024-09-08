// How to implement a graph? in Java


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

    public void addEdge(int src, int dest) {
        adjList.get(src).add(dest);
        adjList.get(dest).add(src); // If the graph is undirected
    }

    public void removeEdge(int src, int dest) {
        adjList.get(src).remove((Integer) dest);
        adjList.get(dest).remove((Integer) src); // If the graph is undirected
    }

    public boolean hasEdge(int src, int dest) {
        return adjList.get(src).contains(dest);
    }

    public LinkedList<Integer> getAdjVertices(int vertex) {
        return adjList.get(vertex);
    }
}
