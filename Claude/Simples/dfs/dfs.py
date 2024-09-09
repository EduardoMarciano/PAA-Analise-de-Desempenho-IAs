#Input: Using the previous graph, how to implement the Depth-First Search algorith?

from collections import deque

class Graph:
    def __init__(self):
        self.adjacency_list = {}

    def add_vertex(self, vertex):
        if vertex not in self.adjacency_list:
            self.adjacency_list[vertex] = []

    def add_edge(self, vertex1, vertex2):
        if vertex1 in self.adjacency_list and vertex2 in self.adjacency_list:
            self.adjacency_list[vertex1].append(vertex2)
            self.adjacency_list[vertex2].append(vertex1)

    def print_graph(self):
        for vertex in self.adjacency_list:
            print(vertex, ":", self.adjacency_list[vertex])

    def dfs(self, start_vertex):
        visited = set()
        stack = deque([start_vertex])

        while stack:
            vertex = stack.pop()
            if vertex not in visited:
                visited.add(vertex)
                print(vertex)
                for neighbor in self.adjacency_list[vertex]:
                    stack.append(neighbor)

# Example usage
graph = Graph()
graph.add_vertex('A')
graph.add_vertex('B')
graph.add_vertex('C')
graph.add_vertex('D')
graph.add_vertex('E')

graph.add_edge('A', 'B')
graph.add_edge('A', 'C')
graph.add_edge('B', 'D')
graph.add_edge('B', 'E')

print("Depth-First Search (DFS) traversal:")
graph.dfs('A')

"""
Output: Depth-First Search (DFS) traversal:
        A
        C
        B
        E
        D
Wrong:
Should be: Depth-First Search (DFS) traversal:
        A
        B
        D
        E
        C
Score: 0.5
"""