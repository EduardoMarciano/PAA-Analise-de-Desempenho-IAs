import java.util.HashSet;
import java.util.Set;

public class MatrixPlucker {

    public static int pluckAll(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        Set<Integer> pluckedElements = new HashSet<>();
        int pluckedCount = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!pluckedElements.contains(i * cols + j)) {
                    pluckCross(matrix, i, j, pluckedElements);
                    pluckedCount++;
                }
            }
        }

        return pluckedCount;
    }

    private static void pluckCross(int[][] matrix, int i, int j, Set<Integer> pluckedElements) {
        int rows = matrix.length;
        int cols = matrix[0].length;

        // Pluck the center element
        pluckedElements.add(i * cols + j);

        // Pluck adjacent elements if they exist and haven't been plucked
        if (i > 0 && !pluckedElements.contains((i - 1) * cols + j)) {
            pluckedElements.add((i - 1) * cols + j);
        }
        if (j > 0 && !pluckedElements.contains(i * cols + (j - 1))) {
            pluckedElements.add(i * cols + (j - 1));
        }
        if (i < rows - 1 && !pluckedElements.contains((i + 1) * cols + j)) {
            pluckedElements.add((i + 1) * cols + j);
        }
        if (j < cols - 1 && !pluckedElements.contains(i * cols + (j + 1))) {
            pluckedElements.add(i * cols + (j + 1));
        }
    }

    public static void main(String[] args) {
        int[][] matrix = {
                {1, 2, 3},
                {4, 5, 6},
                {7, 8, 9}
        };

        int pluckedCount = pluckAll(matrix);
        System.out.println("Number of elements plucked: " + pluckedCount);
    }
}