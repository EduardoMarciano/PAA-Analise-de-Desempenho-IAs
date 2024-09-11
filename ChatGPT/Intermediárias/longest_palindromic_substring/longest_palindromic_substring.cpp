#include <iostream>
#include <string>

using namespace std;

// Função para expandir ao redor do centro e encontrar o palíndromo
string expandAroundCenter(const string& s, int left, int right) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }
    return s.substr(left + 1, right - left - 1);
}

// Função para encontrar a maior substring palindrômica
string longestPalindromicSubstring(const string& s) {
    if (s.length() < 2) {
        return s;
    }

    string longest;
    for (int i = 0; i < s.length(); i++) {
        // Encontrar o maior palíndromo com um centro único
        string oddPalindrome = expandAroundCenter(s, i, i);
        if (oddPalindrome.length() > longest.length()) {
            longest = oddPalindrome;
        }

        // Encontrar o maior palíndromo com um centro duplo
        string evenPalindrome = expandAroundCenter(s, i, i + 1);
        if (evenPalindrome.length() > longest.length()) {
            longest = evenPalindrome;
        }
    }

    return longest;
}

// Função principal para testar o algoritmo de substring palindrômica
int main() {
    string input = "babad";
    cout << "A maior substring palindrômica é: " << longestPalindromicSubstring(input) << endl;
    return 0;
}
