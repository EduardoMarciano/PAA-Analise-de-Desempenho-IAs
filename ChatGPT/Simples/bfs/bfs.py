#Input: Using the previous graph, how to implement the Breadth-First Search algorithm?

from collections import deque

class Graph:
    def __init__(self):
        self.graph = {}

    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []

    def add_edge(self, u, v):
        if u not in self.graph:
            self.add_vertex(u)
        if v not in self.graph:
            self.add_vertex(v)
        self.graph[u].append(v)
        self.graph[v].append(u)  # For undirected graph

    def bfs(self, start_vertex):
        visited = set()
        queue = deque([start_vertex])
        visited.add(start_vertex)
        while queue:
            vertex = queue.popleft()
            print(vertex, end=' ')
            for neighbor in self.graph[vertex]:
                if neighbor not in visited:
                    visited.add(neighbor)
                    queue.append(neighbor)

    def __str__(self):
        return str(self.graph)

# Example usage
g = Graph()
g.add_vertex('A')
g.add_vertex('B')
g.add_vertex('C')
g.add_vertex('D')
g.add_edge('A', 'B')
g.add_edge('A', 'C')
g.add_edge('B', 'D')

print("BFS traversal starting from vertex 'A':")
g.bfs('A')

"""
Score: 1
"""