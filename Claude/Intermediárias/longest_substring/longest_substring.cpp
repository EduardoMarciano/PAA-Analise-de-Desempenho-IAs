#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_map<char, int> char_index;
        int max_length = 0;
        int start = 0;

        for (int end = 0; end < s.length(); end++) {
            if (char_index.find(s[end]) != char_index.end() && char_index[s[end]] >= start) {
                start = char_index[s[end]] + 1;
            } else {
                max_length = std::max(max_length, end - start + 1);
            }

            char_index[s[end]] = end;
        }

        return max_length;
    }
};

// Exemplo de uso
int main() {
    Solution solution;
    std::cout << solution.lengthOfLongestSubstring("abcabcbb") << std::endl;  // Saída: 3
    std::cout << solution.lengthOfLongestSubstring("bbbbb") << std::endl;     // Saída: 1
    std::cout << solution.lengthOfLongestSubstring("pwwkew") << std::endl;    // Saída: 3
    return 0;
}
