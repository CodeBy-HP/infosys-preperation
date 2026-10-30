#include <iostream>
#include <string>

using namespace std;

class LongestPalindromicSubstring {
private:
    pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < (int)s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Valid palindrome segment was (left + 1) to (right - 1)
        return {left + 1, right - left - 1};
    }

public:
    // =========================================================================
    // 1. Expand Around Center
    // Time Complexity: O(N^2)
    // Space Complexity: O(1) auxiliary space
    // =========================================================================
    string longestPalindrome(const string& s) {
        if (s.size() <= 1) return s;

        int bestStart = 0;
        int bestLen = 1;

        for (int i = 0; i < (int)s.size(); i++) {
            // Odd length center (centered at i)
            auto [start1, len1] = expandAroundCenter(s, i, i);
            if (len1 > bestLen) {
                bestStart = start1;
                bestLen = len1;
            }

            // Even length center (centered between i and i+1)
            auto [start2, len2] = expandAroundCenter(s, i, i + 1);
            if (len2 > bestLen) {
                bestStart = start2;
                bestLen = len2;
            }
        }

        return s.substr(bestStart, bestLen);
    }
};

int main() {
    LongestPalindromicSubstring solver;

    cout << "Test 1 (\"babad\"): " << solver.longestPalindrome("babad") << " (Expected: \"bab\" or \"aba\")\n";
    cout << "Test 2 (\"cbbd\"):  " << solver.longestPalindrome("cbbd") << " (Expected: \"bb\")\n";

    return 0;
}
