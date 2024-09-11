public class LongestPalindromicSubstring {

    public String longestPalindrome(String s) {
        if (s == null || s.length() < 1) return "";
        int start = 0, end = 0;
        String t = preProcess(s);
        int len = t.length();
        int[] p = new int[len];

        for (int i = 1; i < len - 1; i++) {
            int mirror = 2 * center - i;
            p[i] = (i < end) ? Math.min(end - i, p[mirror]) : 0;

            while (t.charAt(i + 1 + p[i]) == t.charAt(i - 1 - p[i])) p[i]++;

            if (i + p[i] > end) {
                center = i;
                end = i + p[i];
            }
        }

        int maxLen = 0;
        for (int i = 1; i < len - 1; i++) {
            if (p[i] > maxLen) {
                start = (i - 1 - p[i]) / 2;
                maxLen = p[i];
            }
        }
        return s.substring(start, start + maxLen);
    }

    private String preProcess(String s) {
        int n = s.length();
        if (n == 0) return "^$";
        String ret = "^";
        for (int i = 0; i < n; i++) ret += "#" + s.charAt(i);
        ret += "#$";
        return ret;
    }
}
