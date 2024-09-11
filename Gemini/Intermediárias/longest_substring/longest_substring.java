import java.util.HashMap;

public class LongestSubstring {

    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> charIndexMap = new HashMap<>();
        int maxLen = 0, start = 0;
        for (int end = 0; end < s.length(); end++) {
            if (
                charIndexMap.containsKey(s.charAt(end)) &&
                start <= charIndexMap.get(s.charAt(end))
            ) {
                start = charIndexMap.get(s.charAt(end)) + 1;
            }
            charIndexMap.put(s.charAt(end), end);
            maxLen = Math.max(maxLen, end - start + 1);
        }
        return maxLen;
    }

    public static void main(String[] args) {
        LongestSubstring solution = new LongestSubstring();
        System.out.println(solution.lengthOfLongestSubstring("abcabcbb")); // Output: 3
        System.out.println(solution.lengthOfLongestSubstring("bbbbb")); // Output: 1
        System.out.println(solution.lengthOfLongestSubstring("pwwkew")); // Output: 3
    }
}
