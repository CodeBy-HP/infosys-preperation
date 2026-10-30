#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class LongestCommonSubsequence {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int longestCommonSubsequenceMemo(const string& text1, const string& text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solveMemo(m - 1, n - 1, text1, text2, memo);
    }

private:
    int solveMemo(int i, int j, const string& s1, const string& s2, vector<vector<int>>& memo) {
        if (i < 0 || j < 0) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        if (s1[i] == s2[j]) {
            return memo[i][j] = 1 + solveMemo(i - 1, j - 1, s1, s2, memo);
        }

        return memo[i][j] = max(solveMemo(i - 1, j, s1, s2, memo),
                                solveMemo(i, j - 1, s1, s2, memo));
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (2D Tabulation, 1-indexed)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int longestCommonSubsequenceTabulation(const string& text1, const string& text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[m][n];
    }

    // =========================================================================
    // 3. Space-Optimized Approach (Two 1D Rows)
    // Time Complexity: O(M * N)
    // Space Complexity: O(N)
    // =========================================================================
    int longestCommonSubsequenceSpaceOptimized(const string& text1, const string& text2) {
        int m = text1.length();
        int n = text2.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};

int main() {
    LongestCommonSubsequence solver;

    string s1 = "abcde", s2 = "ace";
    cout << "Test 1 (\"abcde\", \"ace\"):\n";
    cout << "  Memoization:     " << solver.longestCommonSubsequenceMemo(s1, s2) << "\n";
    cout << "  Tabulation:      " << solver.longestCommonSubsequenceTabulation(s1, s2) << "\n";
    cout << "  Space-Optimized: " << solver.longestCommonSubsequenceSpaceOptimized(s1, s2) << " (Expected: 3)\n";

    return 0;
}

