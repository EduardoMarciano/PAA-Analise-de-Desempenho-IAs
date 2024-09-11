def max_score(deck):
    n = len(deck)
    dp = [[0] * n for _ in range(n)]
    
    for length in range(1, n + 1):
        for start in range(n - length + 1):
            end = start + length - 1
            if length == 1:
                dp[start][end] = deck[start]
            else:
                dp[start][end] = max(deck[start] + dp[start+1][end], 
                                     deck[end] + dp[start][end-1])
    
    return dp[0][n-1]

# Example usage
deck = [10, 19, 1, 2]
print(f"Maximum score: {max_score(deck)}")