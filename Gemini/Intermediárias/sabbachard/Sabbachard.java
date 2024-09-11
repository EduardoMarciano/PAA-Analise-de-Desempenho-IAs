import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Sabacchard {

    public static int highestScore(List<Integer> cards) {
        int n = cards.size();
        int[][] dp = new int[n][n];

        // Base case: single card
        for (int i = 0; i < n; i++) {
            dp[i][i] = cards.get(i);
        }

        // Fill the dp table
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1;
                dp[i][j] = Math.max(cards.get(i) + dp[i + 1][j], cards.get(j) + dp[i][j - 1]);
            }
        }

        return dp[0][n - 1];
    }

    public static void main(String[] args) {
        List<Integer> cards = new ArrayList<>();
        cards.add(10);
        cards.add(19);
        cards.add(1);
        cards.add(2);

        int highestScore = highestScore(cards);
        System.out.println("Highest possible score: " + highestScore);
    }
}