#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LongestSubstringWithoutRepeating {
public:
    // =========================================================================
    // 1. Optimal Last-Seen Direct Jump Sliding Window
    // Time Complexity: O(N) - single pass, R advances linearly
    // Space Complexity: O(128) = O(1) auxiliary space
    // =========================================================================
    int lengthOfLongestSubstring(const string& s) {
        vector<int> lastSeen(128, -1);
        int maxLen = 0;
        int left = 0;

        for (int right = 0; right < (int)s.size(); right++) {
            char c = s[right];

            // If character seen inside current active window, leap left pointer
            if (lastSeen[(unsigned char)c] >= left) {
                left = lastSeen[(unsigned char)c] + 1;
            }

            lastSeen[(unsigned char)c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};

int main() {
    LongestSubstringWithoutRepeating solver;

    cout << "Test 1 (\"abcabcbb\"): " << solver.lengthOfLongestSubstring("abcabcbb") << " (Expected: 3)\n";
    cout << "Test 2 (\"bbbbb\"):    " << solver.lengthOfLongestSubstring("bbbbb") << " (Expected: 1)\n";
    cout << "Test 3 (\"pwwkew\"):   " << solver.lengthOfLongestSubstring("pwwkew") << " (Expected: 3)\n";

    return 0;
}
