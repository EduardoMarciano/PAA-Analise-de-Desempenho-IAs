# Input: How to implement a graph? in python

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

# Example usage
graph = Graph()
graph.add_vertex('A')
graph.add_vertex('B')
graph.add_vertex('C')
graph.add_edge('A', 'B')
graph.add_edge('B', 'A')
graph.add_edge('C', 'C')
graph.print_graph()

"""
Output:
    A : ['B', 'B']
    B : ['A', 'A']
    C : ['C', 'C']

Wrong: C : ['C', 'C']
Should be: C : ['C']
Score: 0.75
"""