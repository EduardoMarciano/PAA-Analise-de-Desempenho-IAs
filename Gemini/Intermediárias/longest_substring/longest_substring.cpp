#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndexMap;
    int maxLen = 0, start = 0;
    for (int end = 0; end < s.length(); end++) {
        if (charIndexMap.count(s[end]) && start <= charIndexMap[s[end]]) {
            start = charIndexMap[s[end]] + 1;
        }
        charIndexMap[s[end]] = end;
        maxLen = max(maxLen, end - start + 1);
    }
    return maxLen;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // Output: 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;   // Output: 1
    cout << lengthOfLongestSubstring("pwwkew") << endl;  // Output: 3
    return 0;
}
