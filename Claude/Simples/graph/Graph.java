// How to implement a graph? in Java

import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.Set;


public class Graph<T> {
    private Map<T, List<T>> adjacencyList;

    public Graph() {
        adjacencyList = new HashMap<>();
    }

    public void addVertex(T vertex) {
        adjacencyList.putIfAbsent(vertex, new ArrayList<>());
    }

    public void addEdge(T source, T destination) {
        if (!adjacencyList.containsKey(source)) {
            addVertex(source);
        }
        if (!adjacencyList.containsKey(destination)) {
            addVertex(destination);
        }
        adjacencyList.get(source).add(destination);
    }

    public void removeEdge(T source, T destination) {
        if (adjacencyList.containsKey(source)) {
            adjacencyList.get(source).remove(destination);
        }
    }

    public List<T> getNeighbors(T vertex) {
        return adjacencyList.get(vertex);
    }

    public Set<T> getVertices() {
        return adjacencyList.keySet();
    }

    public static void main(String[] args) {

        Graph<String> g = new Graph<>();

        g.addEdge("a", "b");
        g.addEdge("b", "a");
        g.addEdge("a", "a");
        System.out.println("a: " + g.getNeighbors("a")); 
        System.out.println("b: " + g.getNeighbors("b"));  
    }
}

/*
Score: 1
*/