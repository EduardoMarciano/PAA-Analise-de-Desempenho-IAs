public class Main {
    // Método para expandir ao redor do centro e encontrar o palíndromo
    private static String expandAroundCenter(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return s.substring(left + 1, right);
    }

    // Método para encontrar a maior substring palindrômica
    public static String longestPalindromicSubstring(String s) {
        if (s == null || s.length() < 1) {
            return "";
        }

        String longest = "";
        for (int i = 0; i < s.length(); i++) {
            // Palíndromo de comprimento ímpar
            String oddPalindrome = expandAroundCenter(s, i, i);
            if (oddPalindrome.length() > longest.length()) {
                longest = oddPalindrome;
            }
            // Palíndromo de comprimento par
            String evenPalindrome = expandAroundCenter(s, i, i + 1);
            if (evenPalindrome.length() > longest.length()) {
                longest = evenPalindrome;
            }
        }

        return longest;
    }

    public static void main(String[] args) {
        String input = "babad";
        System.out.println("A maior substring palindrômica é: " + longestPalindromicSubstring(input));
    }
}
