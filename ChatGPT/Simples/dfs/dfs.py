#Input: Using the previous graph, how to implement the Depth-First Search algorith?

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

    def dfs(self, start_vertex, visited=None):
        if visited is None:
            visited = set()
        visited.add(start_vertex)
        print(start_vertex, end=' ')
        for neighbor in self.graph[start_vertex]:
            if neighbor not in visited:
                self.dfs(neighbor, visited)

    def __str__(self):
        return str(self.graph)

# Example usage
g = Graph()
g.add_vertex('A')
g.add_vertex('B')
g.add_vertex('C')
g.add_vertex('D')
g.add_edge('A', 'B')
g.add_edge('A', 'D')
g.add_edge('B', 'C')

print("DFS traversal starting from vertex 'A':")
g.dfs('A')

"""
Output:
    A B C D

Score: 1
"""