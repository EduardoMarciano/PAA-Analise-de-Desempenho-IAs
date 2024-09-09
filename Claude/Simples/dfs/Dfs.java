// Input  Using the previous graph, how to implement the Depth-First Search algorith?

import java.util.*;

public class Graph<T> {
    private Map<T, List<T>> adjacencyList;

    public Graph() {
        adjacencyList = new HashMap<>();
    }

    // Previous graph implementation methods (addVertex, addEdge, removeEdge, getNeighbors, getVertices) remain the same

    public List<T> depthFirstSearch(T startVertex) {
        Set<T> visited = new HashSet<>();
        List<T> result = new ArrayList<>();
        Stack<T> stack = new Stack<>();

        visited.add(startVertex);
        stack.push(startVertex);
        result.add(startVertex);

        while (!stack.isEmpty()) {
            T currentVertex = stack.pop();
            for (T neighbor : getNeighbors(currentVertex)) {
                if (!visited.contains(neighbor)) {
                    visited.add(neighbor);
                    stack.push(neighbor);
                    result.add(neighbor);
                }
            }
        }

        return result;
    }
}
