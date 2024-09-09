// Input  Using the previous graph, how to implement the Depth-First Search algorith?

import java.util.*;

public class Dfs<T> {
    private Map<T, List<T>> adjacencyList;

    public Dfs() {
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
    public static void main(String[] args) {
        Dfs<String> g = new Dfs<>();

        g.addEdge("A", "B"); 
        g.addEdge("A", "C"); 
        g.addEdge("B", "D");

        List<String> dfs = g.depthFirstSearch("A");

        System.out.println("" + dfs);
    }
}

/*
Output:
    [A, B, C, D]

Wrong:
Should be:[A, B, D, C]
Score: 0.5
*/