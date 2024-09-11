def longest_palindrome(s):
    """
    Encontra a substring palindroma mais longa em uma string.

    Args:
        s: A string de entrada.

    Returns:
        A substring palindroma mais longa.
    """

    n = len(s)
    dp = [[False] * n for _ in range(n)]

    # Palíndromos de tamanho 1
    for i in range(n):
        dp[i][i] = True

    # Palíndromos de tamanho 2
    for i in range(n - 1):
        dp[i][i + 1] = s[i] == s[i + 1]

    # Palíndromos de tamanho 3 ou mais
    for cl in range(2, n):
        for i in range(n - cl):
            j = i + cl
            dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]

    # Encontrar o palíndromo mais longo
    start = 0
    max_len = 1
    for cl in range(2, n + 1):
        for i in range(n - cl + 1):
            if dp[i][i + cl - 1] and cl > max_len:
                start = i
                max_len = cl

    return s[start:start + max_len]

# Exemplo de uso
s = "babad"
print(longest_palindrome(s))  # Saída: "bab"
