def pluck_elements(matrix, elements_to_pluck):
    def is_valid(i, j):
        return 0 <= i < len(matrix) and 0 <= j < len(matrix[0])

    def pluck(i, j):
        if not is_valid(i, j) or matrix[i][j] == 0:
            return
        matrix[i][j] = 0
        for x, y in [(i-1, j), (i, j-1), (i, j), (i, j+1), (i+1, j)]:
            if is_valid(x, y):
                matrix[x][y] = 0

    plucks = 0
    for i, j in elements_to_pluck:
        if matrix[i][j] == 1:
            pluck(i, j)
            plucks += 1
    
    return plucks

# Example usage
matrix = [
    [1, 1, 0],
    [1, 1, 1],
    [0, 1, 0]
]

elements_to_pluck = [(0, 0), (1, 1), (2, 1)]
print("Total plucks:", pluck_elements(matrix, elements_to_pluck))
