#include <vector>
#include <algorithm>
#include <iostream>

int maxScore(const std::vector<int>& cards) {
    int n = cards.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));
    
    for (int i = 0; i < n; ++i) {
        dp[i][i] = cards[i];
    }
    
    for (int length = 2; length <= n; ++length) {
        for (int i = 0; i <= n - length; ++i) {
            int j = i + length - 1;
            dp[i][j] = std::max(cards[i] + std::min(dp[i + 2][j], dp[i + 1][j - 1]),
                               cards[j] + std::min(dp[i + 1][j - 1], dp[i][j - 2]));
        }
    }
    
    return dp[0][n - 1];
}

int main() {
    std::vector<int> cards = {10, 19, 1, 2};
    std::cout << maxScore(cards) << std::endl;  // Output: 21
    return 0;
}
