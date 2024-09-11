import java.util.ArrayList;
import java.util.Collections;

public class MatrixRefactor {
    public static ArrayList<ArrayList<Integer>> refactorMatrix(ArrayList<ArrayList<Integer>> A0, int P) {
        int M = A0.size(), N = A0.get(0).size();
        ArrayList<ArrayList<Integer>> A1 = new ArrayList<>();
        for (int i = 0; i < M; i += P) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j = 0; j < N; j += P) {
                int max_val = Collections.max(A0.subList(i, i + P), (row1, row2) -> {
                    int maxRow1 = Collections.max(row1.subList(j, j + P));
                    int maxRow2 = Collections.max(row2.subList(j, j + P));
                    return maxRow1 - maxRow2;
                });
                row.add(max_val);
            }
            A1.add(row);
        }
        return A1;
    }
}