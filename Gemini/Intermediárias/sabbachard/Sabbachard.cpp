#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sabacchard(vector<int>& cards) {
    int n = cards.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Base case: single card
    for (int i = 0; i < n; ++i) {
        dp[i][i] = cards[i];
    }

    // Fill the dp table
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = max(cards[i] + dp[i + 1][j], cards[j] + dp[i][j - 1]);
        }
    }

    return dp[0][n - 1];
}

int main() {
    vector<int> cards = {10, 19, 1, 2};
    int maxScore = sabacchard(cards);
    cout << "Maximum score: " << maxScore << endl;
    return 0;
}