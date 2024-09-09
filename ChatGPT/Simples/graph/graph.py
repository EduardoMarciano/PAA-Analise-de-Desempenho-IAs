# Input: How to implement a graph? in python

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

    def __str__(self):
        return str(self.graph)

# Example usage
g = Graph()
g.add_vertex('A')
g.add_vertex('B')
g.add_vertex('D')
g.add_vertex('F')

g.add_edge('A', 'B')
g.add_edge('A', 'A')
g.add_edge('B', 'D')
g.add_edge('D', 'B')

print(g)
"""
Output:
    {'A': ['B', 'A', 'A'], 'B': ['A', 'D', 'D'], 'D': ['B', 'B'], 'F': []}
    Wrong: 'A': ['B', 'A', 'A']
    Should be: 'A': ['B', 'A']...
    Score: 0.75
"""