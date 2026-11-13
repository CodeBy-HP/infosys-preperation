#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

class LongestCommonSubstring {
public:
    // Approach 1: 2D Tabulation - O(N * M) Time, O(N * M) Space
    static int longestCommonSubstr2D(const std::string& s1, const std::string& s2) {
        int n = s1.length();
        int m = s2.length();
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1, 0));
        int maxLen = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    maxLen = std::max(maxLen, dp[i][j]);
                } else {
                    dp[i][j] = 0; // Contiguity broken!
                }
            }
        }
        return maxLen;
    }

    // Approach 2: Space-Optimized Rolling Rows - O(N * M) Time, O(M) Space
    static int longestCommonSubstrOptimized(const std::string& s1, const std::string& s2) {
        int n = s1.length();
        int m = s2.length();
        std::vector<int> prev(m + 1, 0);
        int maxLen = 0;

        for (int i = 1; i <= n; ++i) {
            std::vector<int> curr(m + 1, 0);
            for (int j = 1; j <= m; ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                    maxLen = std::max(maxLen, curr[j]);
                } else {
                    curr[j] = 0;
                }
            }
            prev = curr;
        }
        return maxLen;
    }
};

int main() {
    std::string s1 = "ABCDGH", s2 = "ACDGHR";
    assert(LongestCommonSubstring::longestCommonSubstr2D(s1, s2) == 4); // "CDGH"
    assert(LongestCommonSubstring::longestCommonSubstrOptimized(s1, s2) == 4);

    std::string s3 = "ABC", s4 = "ACB";
    assert(LongestCommonSubstring::longestCommonSubstr2D(s3, s4) == 1);
    assert(LongestCommonSubstring::longestCommonSubstrOptimized(s3, s4) == 1);

    std::cout << "All Longest Common Substring tests passed successfully!\n";
    return 0;
}

