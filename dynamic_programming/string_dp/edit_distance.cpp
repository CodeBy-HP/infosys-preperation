#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class EditDistance {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int minDistanceMemo(const string& word1, const string& word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solveMemo(m - 1, n - 1, word1, word2, memo);
    }

private:
    int solveMemo(int i, int j, const string& w1, const string& w2, vector<vector<int>>& memo) {
        if (i < 0) return j + 1; // Insert remaining characters of w2
        if (j < 0) return i + 1; // Delete remaining characters of w1

        if (memo[i][j] != -1) return memo[i][j];

        if (w1[i] == w2[j]) {
            return memo[i][j] = solveMemo(i - 1, j - 1, w1, w2, memo);
        }

        int insertOp = solveMemo(i, j - 1, w1, w2, memo);
        int deleteOp = solveMemo(i - 1, j, w1, w2, memo);
        int replaceOp = solveMemo(i - 1, j - 1, w1, w2, memo);

        return memo[i][j] = 1 + min({insertOp, deleteOp, replaceOp});
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (2D Tabulation, 1-indexed)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int minDistanceTabulation(const string& word1, const string& word2) {
        int m = word1.length();
        int n = word2.length();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i <= m; i++) dp[i][0] = i;
        for (int j = 0; j <= n; j++) dp[0][j] = j;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = 1 + min({
                        dp[i][j - 1],    // Insert
                        dp[i - 1][j],    // Delete
                        dp[i - 1][j - 1] // Replace
                    });
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
    int minDistanceSpaceOptimized(const string& word1, const string& word2) {
        int m = word1.length();
        int n = word2.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);

        for (int j = 0; j <= n; j++) prev[j] = j;

        for (int i = 1; i <= m; i++) {
            curr[0] = i;
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];
                } else {
                    curr[j] = 1 + min({curr[j - 1], prev[j], prev[j - 1]});
                }
            }
            prev = curr;
        }

        return prev[n];
    }
};

int main() {
    EditDistance solver;

    string w1 = "horse", w2 = "ros";
    cout << "Test 1 (\"horse\", \"ros\"):\n";
    cout << "  Memoization:     " << solver.minDistanceMemo(w1, w2) << "\n";
    cout << "  Tabulation:      " << solver.minDistanceTabulation(w1, w2) << "\n";
    cout << "  Space-Optimized: " << solver.minDistanceSpaceOptimized(w1, w2) << " (Expected: 3)\n";

    return 0;
}

