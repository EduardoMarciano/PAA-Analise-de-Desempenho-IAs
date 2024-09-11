import java.util.Arrays;

public class Sabacchard {
    public static int maxScore(int[] deck) {
        int n = deck.length;
        int[][] dp = new int[n][n];
        
        for (int length = 1; length <= n; length++) {
            for (int start = 0; start <= n - length; start++) {
                int end = start + length - 1;
                if (length == 1) {
                    dp[start][end] = deck[start];
                } else {
                    dp[start][end] = Math.max(deck[start] + dp[start+1][end], 
                                              deck[end] + dp[start][end-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }

    public static void main(String[] args) {
        int[] deck = {10, 19, 1, 2};
        System.out.println("Maximum score: " + maxScore(deck));
    }
}