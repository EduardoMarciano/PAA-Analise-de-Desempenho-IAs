#Input: Using the previous graph, how to implement the Depth-First Search algorith?

graph = {
    'A': ['B', 'C'],
    'B': ['D', 'E'],
    'C': [],
    'D': [],
    'E': []
}

def dfs(graph, start):
    """
    Performs Depth-First Search on the given graph starting from the specified vertex.

    Args:
        graph: The graph represented as a dictionary.
        start: The starting vertex.

    Returns:
        A list containing the visited vertices in DFS order.
    """

    visited = set()  # Set to keep track of visited vertices
    stack = [start]  # Stack to store vertices for exploration

    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            stack.extend(reversed(graph[node]))  # Add neighbors in reverse order for DFS

    return list(visited)


result = dfs(graph, 'A')
print(result)

"""
Output: ['A', 'D', 'C', 'E', 'B']
Wrong:
Should be: ['A', 'B', 'D', 'E', 'C']
Score: 0.5
"""