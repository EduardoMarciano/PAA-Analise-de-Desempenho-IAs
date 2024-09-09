// Input: Using the previous graph, how to implement the Breadth-First Search algorithm?

public void bfs(int startVertex) {
    boolean[] visited = new boolean[vertices.size()];
    Queue<Integer> queue = new LinkedList<>();

    visited[startVertex] = true;
    queue.offer(startVertex);

    while (!queue.isEmpty()) {
        int currentVertex = queue.poll();
        System.out.print(vertices.get(currentVertex).getLabel() + " "); // Process vertex

        for (Vertex neighbor : vertices.get(currentVertex).getAdjacentVertices()) {
            if (!visited[neighbor.getLabel()]) {
                visited[neighbor.getLabel()] = true;
                queue.offer(neighbor.getLabel());
            }
        }
    }
}

/*
Error in Compilation 
Score: 0
*/