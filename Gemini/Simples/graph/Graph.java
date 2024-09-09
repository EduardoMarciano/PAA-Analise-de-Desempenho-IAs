// How to implement a graph? in Java

import java.util.*;

class Vertex {
    private int label;
    private List<Vertex> adjacentVertices;

    public Vertex(int label) {
        this.label = label;
        this.adjacentVertices = new ArrayList<>();
    }

    // Getters and setters for label and adjacentVertices
}

class Graph {
    private List<Vertex> vertices;

    public Graph() {
        this.vertices = new ArrayList<>();
    }

    public void addVertex(int label) {
        vertices.add(new Vertex(label));
    }

    public void addEdge(int from, int to) {
        vertices.get(from).getAdjacentVertices().add(vertices.get(to));
    }

    // Implement DFS, BFS, Dijkstra's, Bellman-Ford, etc.
}

/*
Error in Compilation 
Score: 0
*/
