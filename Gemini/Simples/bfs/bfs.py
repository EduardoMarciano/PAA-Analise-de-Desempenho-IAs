#Input: Using the previous graph, how to implement the Breadth-First Search algorithm?

def bfs(graph, start):
  """
  Performs Breadth-First Search on the given graph starting from the specified vertex.

  Args:
    graph: The graph represented as a dictionary.
    start: The starting vertex.

  Returns:
    A list containing the visited vertices in BFS order.
  """

  visited = set()
  queue = [start]

  while queue:
    node = queue.pop(0)  # Dequeue from the front
    if node not in visited:
      visited.add(node)
      queue.extend(graph[node])  # Enqueue neighbors

  return list(visited)

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': ['F'],
    'D': [],
    'E': ['F'],
    'F': []
}

result = bfs(graph, 'A')
print(result)