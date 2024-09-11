import numpy as np

def refactor_matrix(A0, P):
    M, N = A0.shape
    new_M, new_N = M // P, N // P
    A1 = np.zeros((new_M, new_N), dtype=int)
    
    for i in range(new_M):
        for j in range(new_N):
            submatrix = A0[i*P:(i+1)*P, j*P:(j+1)*P]
            A1[i, j] = np.max(submatrix)
    
    return A1

# Example usage
A0 = np.array([
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
    [13, 14, 15, 16]
])
P = 2

A1 = refactor_matrix(A0, P)
print(A1)