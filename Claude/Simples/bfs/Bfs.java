// Input: Using the previous graph, how to implement the Breadth-First Search algorithm?

import java.util.*;

public class Bfs<T> {
    private Map<T, List<T>> adjacencyList;

    public Bfs() {
        adjacencyList = new HashMap<>();
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

    public void addVertex(T vertex) {
        adjacencyList.putIfAbsent(vertex, new ArrayList<>());
    }
    
    public List<T> getNeighbors(T vertex) {
        return adjacencyList.get(vertex);
    }

    public List<T> breadthFirstSearch(T startVertex) {
        Set<T> visited = new HashSet<>();
        List<T> result = new ArrayList<>();
        Queue<T> queue = new LinkedList<>();

        visited.add(startVertex);
        queue.offer(startVertex);
        result.add(startVertex);

        while (!queue.isEmpty()) {
            T currentVertex = queue.poll();
            for (T neighbor : getNeighbors(currentVertex)) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    queue.offer(neighbor);
                    result.add(neighbor);
                }
            }
        }

        return result;
    }
        public static void main(String[] args) {
        Bfs<String> g = new Bfs<>();

        g.addEdge("A", "B"); 
        g.addEdge("A", "C"); 
        g.addEdge("C", "D");

        List<String> bfs = g.breadthFirstSearch("A");

        System.out.println("" + bfs);
    }
}

/*
Score: 1
*/
