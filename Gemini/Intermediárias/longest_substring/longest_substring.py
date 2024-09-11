def length_of_longest_substring(s: str) -> int:
    """
    Finds the length of the longest substring without repeating characters.

    Args:
        s: The input string.

    Returns:
        The length of the longest substring.
    """

    char_index_map = {}
    max_len = start = 0
    for end in range(len(s)):
        if s[end] in char_index_map and start <= char_index_map[s[end]]:
            start = char_index_map[s[end]] + 1
        char_index_map[s[end]] = end
        max_len = max(max_len, end - start + 1)
    return max_len

# Test cases
assert length_of_longest_substring("abcabcbb") == 3
assert length_of_longest_substring("bbbbb") == 1
assert length_of_longest_substring("pwwkew") == 3
