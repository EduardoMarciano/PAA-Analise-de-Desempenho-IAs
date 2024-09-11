def max_score(cards):
    n = len(cards)
    dp = [[0] * n for _ in range(n)]
    
    for i in range(n):
        dp[i][i] = cards[i]
    
    for length in range(2, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1
            dp[i][j] = max(cards[i] + min(dp[i + 2][j] if i + 2 <= j else 0,
                                          dp[i + 1][j - 1] if i + 1 <= j - 1 else 0),
                           cards[j] + min(dp[i + 1][j - 1] if i + 1 <= j - 1 else 0,
                                          dp[i][j - 2] if i <= j - 2 else 0))
    
    return dp[0][n - 1]

# Example usage
cards = [10, 19, 1, 2]
print(max_score(cards))  # Output: 21
