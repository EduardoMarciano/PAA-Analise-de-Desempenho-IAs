// Input  Using the previous graph, how to implement the Depth-First Search algorith?

public void dfs(int startVertex) {
    boolean[] visited = new boolean[vertices.size()];
    dfsHelper(startVertex, visited);
}

private void dfsHelper(int vertex, boolean[] visited) {
    visited[vertex] = true;
    System.out.print(vertices.get(vertex).getLabel() + " "); // Process vertex

    for (Vertex neighbor : vertices.get(vertex).getAdjacentVertices()) {
        if (!visited[neighbor.getLabel()]) {
            dfsHelper(neighbor.getLabel(), visited);
        }
    }
}

/*

Error in Compilation 
Score: 0

*/