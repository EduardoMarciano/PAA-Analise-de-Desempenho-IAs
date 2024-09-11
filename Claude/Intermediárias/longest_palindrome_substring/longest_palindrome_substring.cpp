#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longest_palindrome(string s) {
    string T = "^#" + string(s.begin(), s.end()) + "#$";
    int n = T.length();
    vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 1; i < n-1; i++) {
        P[i] = (R > i) ? min(R - i, P[2*C - i]) : 0;

        while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            P[i]++;

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int maxLen = 0, centerIndex = 0;
    for (int i = 1; i < n-1; i++) {
        if (P[i] > maxLen) {
            maxLen = P[i];
            centerIndex = i;
        }
    }

    return s.substr((centerIndex - maxLen)/2, maxLen);
}

int main() {
    string s = "babad";
    cout << longest_palindrome(s) << endl;  // Output: "bab" or "aba"
    return 0;
}
