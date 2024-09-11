#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int max_score(const vector<int>& deck) {
    int n = deck.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int length = 1; length <= n; ++length) {
        for (int start = 0; start <= n - length; ++start) {
            int end = start + length - 1;
            if (length == 1) {
                dp[start][end] = deck[start];
            } else {
                dp[start][end] = max(deck[start] + dp[start+1][end], 
                                     deck[end] + dp[start][end-1]);
            }
        }
    }
    
    return dp[0][n-1];
}

int main() {
    vector<int> deck = {10, 19, 1, 2};
    cout << "Maximum score: " << max_score(deck) << endl;
    return 0;
}