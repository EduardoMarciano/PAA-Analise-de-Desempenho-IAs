import java.util.Arrays;

public class MatrixRefactor {
    
    public static int[][] refactorMatrix(int[][] A0, int P) {
        int M = A0.length;
        int N = A0[0].length;
        int M1 = M / P;
        int N1 = N / P;
        
        int[][] A1 = new int[M1][N1];
        
        for (int i = 0; i < M1; ++i) {
            for (int j = 0; j < N1; ++j) {
                int maxVal = A0[i*P][j*P];
                for (int x = 0; x < P; ++x) {
                    for (int y = 0; y < P; ++y) {
                        maxVal = Math.max(maxVal, A0[i*P + x][j*P + y]);
                    }
                }
                A1[i][j] = maxVal;
            }
        }
        
        return A1;
    }
    
    public static void main(String[] args) {
        int[][] A0 = {
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12},
            {13, 14, 15, 16}
        };
        int P = 2;
        int[][] A1 = refactorMatrix(A0, P);
        
        for (int[] row : A1) {
            System.out.println(Arrays.toString(row));
        }
    }
}