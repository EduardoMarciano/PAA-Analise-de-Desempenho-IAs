import java.util.Arrays;

public class MatrixRefactor {
    public static int[][] refactorMatrix(int[][] A0, int P) {
        int M = A0.length;
        int N = A0[0].length;
        int newM = M / P;
        int newN = N / P;
        
        int[][] A1 = new int[newM][newN];
        
        for (int i = 0; i < newM; i++) {
            for (int j = 0; j < newN; j++) {
                int maxElement = A0[i*P][j*P];
                for (int x = 0; x < P; x++) {
                    for (int y = 0; y < P; y++) {
                        maxElement = Math.max(maxElement, A0[i*P + x][j*P + y]);
                    }
                }
                A1[i][j] = maxElement;
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