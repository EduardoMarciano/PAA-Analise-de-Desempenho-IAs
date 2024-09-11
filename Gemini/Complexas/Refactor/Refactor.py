def refactor_matrix(A0, P):
    M, N = len(A0), len(A0[0])
    A1 = [[0 for _ in range(N // P)] for _ in range(M // P)]
    for i in range(0, M, P):
        for j in range(0, N, P):
            max_val = max(A0[x][y] for x in range(i, i + P) for y in range(j, j + P))
            A1[i // P][j // P] = max_val
    return A1

# Example usage:
A0 = [[1, 2, 3, 4],
     [5, 6, 7, 8],
     [9, 10, 11, 12],
     [13, 14, 15, 16]]
P = 2
A1 = refactor_matrix(A0, P)
print(A1)