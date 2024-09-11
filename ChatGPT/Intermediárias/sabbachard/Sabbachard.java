public class Sabacchard {
    public static int maxScore(int[] cards) {
        int n = cards.length;
        int[][] dp = new int[n][n];
        
        for (int i = 0; i < n; i++) {
            dp[i][i] = cards[i];
        }
        
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1;
                dp[i][j] = Math.max(cards[i] + Math.min((i + 2 <= j ? dp[i + 2][j] : 0),
                                                       (i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0)),
                                   cards[j] + Math.min((i + 1 <= j - 1 ? dp[i + 1][j - 1] : 0),
                                                       (i <= j - 2 ? dp[i][j - 2] : 0)));
            }
        }
        
        return dp[0][n - 1];
    }

    public static void main(String[] args) {
        int[] cards = {10, 19, 1, 2};
        System.out.println(maxScore(cards));  // Output: 21
    }
}
