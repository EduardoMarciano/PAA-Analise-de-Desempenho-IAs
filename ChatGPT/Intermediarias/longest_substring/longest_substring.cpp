#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLength = 0;
    int start = 0;  // Início da janela deslizante

    for (int end = 0; end < s.length(); end++) {
        char currentChar = s[end];

        // Se o caractere está no mapa e está dentro da janela atual
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= start) {
            start = charIndexMap[currentChar] + 1;  // Mova o início da janela para a direita do último índice deste caractere
        }

        charIndexMap[currentChar] = end;  // Atualize o último índice deste caractere
        maxLength = max(maxLength, end - start + 1);  // Atualize o comprimento máximo
    }

    return maxLength;
}

int main() {
    string input = "abcabcbb";
    cout << "Length of the longest substring without repeating characters: " << lengthOfLongestSubstring(input) << endl;
    return 0;
}
