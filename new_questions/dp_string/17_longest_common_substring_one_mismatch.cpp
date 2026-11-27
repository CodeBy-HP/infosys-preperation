#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
public:
    // Optimal O(N * M) time, O(M) space DP for Longest Common Substring with <= 1 mismatch
    int longestCommonSubstringOneMismatch(const string& s1, const string& s2) {
        int n = s1.size(), m = s2.size();
        vector<int> exact(m + 1, 0), oneMis(m + 1, 0);
        int maxLen = 0;

        for (int i = 1; i <= n; i++) {
            // Iterate backwards in inner loop to reuse diagonal (i-1, j-1) in-place
            for (int j = m; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1]) {
                    exact[j] = exact[j - 1] + 1;
                    oneMis[j] = oneMis[j - 1] + 1;
                } else {
                    oneMis[j] = exact[j - 1] + 1;
                    exact[j] = 0;
                }
                maxLen = max(maxLen, oneMis[j]);
            }
        }
        return maxLen;
    }

    // Generalized Version for at most K mismatches in O(N * M * K) time
    int longestCommonSubstringKMismatches(const string& s1, const string& s2, int k) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(m + 1, vector<int>(k + 1, 0));
        int maxLen = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s1[i - 1] == s2[j - 1]) {
                    for (int c = 0; c <= k; c++) {
                        dp[j][c] = dp[j - 1][c] + 1;
                        maxLen = max(maxLen, dp[j][c]);
                    }
                } else {
                    for (int c = k; c >= 1; c--) {
                        dp[j][c] = dp[j - 1][c - 1] + 1;
                        maxLen = max(maxLen, dp[j][c]);
                    }
                    dp[j][0] = 0;
                }
            }
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    assert(sol.longestCommonSubstringOneMismatch("abcde", "abfde") == 5);
    assert(sol.longestCommonSubstringOneMismatch("abca", "rama") == 2);
    assert(sol.longestCommonSubstringOneMismatch("xyz", "abc") == 1);
    assert(sol.longestCommonSubstringKMismatches("abcde", "abfde", 1) == 5);
    cout << "17_longest_common_substring_one_mismatch passed all tests!\n";
    return 0;
}
