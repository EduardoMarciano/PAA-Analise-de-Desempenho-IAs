import java.util.HashSet;
import java.util.Set;

public class MatrixPlucker {
    private int[][] matrix;
    private Set<int[]> elementsToPluck;
    private int rows;
    private int cols;

    public MatrixPlucker(int[][] matrix, Set<int[]> elementsToPluck) {
        this.matrix = matrix;
        this.elementsToPluck = elementsToPluck;
        this.rows = matrix.length;
        this.cols = matrix[0].length;
    }

    public int pluckElements() {
        int plucks = 0;
        for (int[] elem : elementsToPluck) {
            int i = elem[0];
            int j = elem[1];
            if (matrix[i][j] == 1) {
                pluck(i, j);
                plucks++;
            }
        }
        return plucks;
    }

    private void pluck(int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] == 0) return;
        matrix[i][j] = 0;
        int[][] positions = {{i-1, j}, {i, j-1}, {i, j}, {i, j+1}, {i+1, j}};
        for (int[] pos : positions) {
            int x = pos[0], y = pos[1];
            if (x >= 0 && x < rows && y >= 0 && y < cols) {
                matrix[x][y] = 0;
            }
        }
    }

    // Example usage
    public static void main(String[] args) {
        int[][] matrix = {
            {1, 1, 0},
            {1, 1, 1},
            {0, 1, 0}
        };

        Set<int[]> elementsToPluck = new HashSet<>();
        elementsToPluck.add(new int[]{0, 0});
        elementsToPluck.add(new int[]{1, 1});
        elementsToPluck.add(new int[]{2, 1});

        MatrixPlucker plucker = new MatrixPlucker(matrix, elementsToPluck);
        System.out.println("Total plucks: " + plucker.pluckElements());
    }
}