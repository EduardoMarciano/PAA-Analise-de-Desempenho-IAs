// Input: Using the previous graph, how to implement the Breadth-First Search algorithm?

import java.util.*;

public class Graph<T> {
    private Map<T, List<T>> adjacencyList;

    public Graph() {
        adjacencyList = new HashMap<>();
    }

    // Previous graph implementation methods (addVertex, addEdge, removeEdge, getNeighbors, getVertices) remain the same

    public List<T> depthFirstSearch(T startVertex) {
        // Existing DFS implementation
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
}

