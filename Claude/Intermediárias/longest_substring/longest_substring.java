import java.util.HashMap;

class Solution {

    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> charIndex = new HashMap<>();
        int maxLength = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++) {
            char c = s.charAt(end);
            if (charIndex.containsKey(c) && charIndex.get(c) >= start) {
                start = charIndex.get(c) + 1;
            } else {
                maxLength = Math.max(maxLength, end - start + 1);
            }

            charIndex.put(c, end);
        }

        return maxLength;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        System.out.println(solution.lengthOfLongestSubstring("abcabcbb")); // Saída: 3
        System.out.println(solution.lengthOfLongestSubstring("bbbbb")); // Saída: 1
        System.out.println(solution.lengthOfLongestSubstring("pwwkew")); // Saída: 3
    }
}
