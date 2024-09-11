public class LongestPalindrome {

    public static String longestPalindrome(String s) {
        String T = "^#" + String.join("#", s.split("")) + "#$";
        int n = T.length();
        int[] P = new int[n];
        int C = 0, R = 0;

        for (int i = 1; i < n - 1; i++) {
            P[i] = (R > i) ? Math.min(R - i, P[2 * C - i]) : 0;

            while (T.charAt(i + 1 + P[i]) == T.charAt(i - 1 - P[i])) P[i]++;

            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }

        int maxLen = 0, centerIndex = 0;
        for (int i = 1; i < n - 1; i++) {
            if (P[i] > maxLen) {
                maxLen = P[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2;
        return s.substring(start, start + maxLen);
    }

    public static void main(String[] args) {
        String s = "babad";
        System.out.println(longestPalindrome(s)); // Output: "bab" or "aba"
    }
}
