import numpy as np

def refactor_matrix(A0, P):
    M, N = len(A0), len(A0[0])
    M1, N1 = M // P, N // P
    
    # Initialize the new matrix A1
    A1 = np.zeros((M1, N1), dtype=int)
    
    for i in range(M1):
        for j in range(N1):
            # Extract the PxP submatrix
            submatrix = [A0[i*P + x][j*P:j*P + P] for x in range(P)]
            # Flatten and find the maximum value
            A1[i][j] = np.max(np.array(submatrix).flatten())
    
    return A1.tolist()
