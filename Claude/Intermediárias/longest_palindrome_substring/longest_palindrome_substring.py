def longest_palindrome(s):
    # Preprocess the string
    T = '#'.join('^{}$'.format(s))
    n = len(T)
    P = [0] * n
    C = R = 0

    for i in range(1, n-1):
        P[i] = (R > i) and min(R - i, P[2*C - i])
        # Attempt to expand palindrome centered at i
        while T[i + 1 + P[i]] == T[i - 1 - P[i]]:
            P[i] += 1

        # If palindrome centered at i expands past R,
        # adjust center based on expanded palindrome.
        if i + P[i] > R:
            C, R = i, i + P[i]

    # Find the maximum element in P
    maxLen, centerIndex = max((n, i) for i, n in enumerate(P))
    return s[(centerIndex  - maxLen)//2: (centerIndex  + maxLen)//2]

# Test the function
s = "babad"
print(longest_palindrome(s))  # Output: "bab" or "aba"
