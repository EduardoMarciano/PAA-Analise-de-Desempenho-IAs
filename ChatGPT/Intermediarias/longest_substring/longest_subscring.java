import java.util.HashMap;

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        int maxLength = 0;
        int start = 0; // Início da janela deslizante

        for (int end = 0; end < s.length(); end++) {
            char currentChar = s.charAt(end);

            if (map.containsKey(currentChar)) {
                // Se o caractere já está no mapa e está dentro da janela atual
                // Mova o início da janela para a direita do último índice desse caractere
                start = Math.max(start, map.get(currentChar) + 1);
            }

            // Atualiza o último índice deste caractere
            map.put(currentChar, end);
            // Calcula o tamanho da janela atual e atualiza o maxLength se necessário
            maxLength = Math.max(maxLength, end - start + 1);
        }

        return maxLength;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        String input = "abcabcbb";
        System.out.println("Length of the longest substring without repeating characters: " + solution.lengthOfLongestSubstring(input));
    }
}
