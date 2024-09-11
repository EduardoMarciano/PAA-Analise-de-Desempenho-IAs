#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    bool dp[n][n];

    // Palíndromos de tamanho 1
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
    }

    // Palíndromos de tamanho 2
    for (int i = 0; i < n - 1; ++i) {
        dp[i][i + 1] = (s[i] == s[i + 1]);
    }

    // Palíndromos de tamanho 3 ou mais
    for (int cl = 2; cl < n; ++cl) {
        for (int i = 0; i < n - cl; ++i) {
            int j = i + cl;
            dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
        }
    }

    // Encontrar o palíndromo mais longo
    int start = 0, end = 0;
    for (int cl = 0; cl < n; ++cl) {
        for (int i = 0; i < n - cl; ++i) {
            if (dp[i][i + cl] && cl > end - start) {
                start = i;
                end = i + cl;
            }
        }
    }

    return s.substr(start, end - start + 1);
}

int main() {
    string s = "babad";
    cout << longestPalindrome(s) << endl; // Saída: bab
    return 0;
}
