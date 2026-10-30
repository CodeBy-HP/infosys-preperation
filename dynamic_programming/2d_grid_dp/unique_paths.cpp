#include <iostream>
#include <vector>

using namespace std;

class UniquePaths {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int uniquePathsMemo(int m, int n) {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solveMemo(0, 0, m, n, memo);
    }

private:
    int solveMemo(int r, int c, int m, int n, vector<vector<int>>& memo) {
        // Out of bounds
        if (r >= m || c >= n) return 0;

        // Reached destination
        if (r == m - 1 && c == n - 1) return 1;

        if (memo[r][c] != -1) return memo[r][c];

        int down = solveMemo(r + 1, c, m, n, memo);
        int right = solveMemo(r, c + 1, m, n, memo);

        return memo[r][c] = down + right;
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (2D Tabulation)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int uniquePathsTabulation(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Base cases: First row and first column
        for (int r = 0; r < m; r++) dp[r][0] = 1;
        for (int c = 0; c < n; c++) dp[0][c] = 1;

        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[r][c] = dp[r - 1][c] + dp[r][c - 1];
            }
        }

        return dp[m - 1][n - 1];
    }

    // =========================================================================
    // 3. Space-Optimized Approach (1D Rolling Row)
    // Time Complexity: O(M * N)
    // Space Complexity: O(N)
    // =========================================================================
    int uniquePathsSpaceOptimized(int m, int n) {
        vector<int> dp(n, 1);

        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[c] = dp[c] + dp[c - 1];
            }
        }

        return dp[n - 1];
    }

    // =========================================================================
    // 4. Mathematical Combinatorics Approach
    // Total steps = (m - 1) Down + (n - 1) Right = m + n - 2
    // Choose (m - 1) Down steps: C(m + n - 2, m - 1)
    // Time Complexity: O(min(M, N))
    // Space Complexity: O(1)
    // =========================================================================
    long long uniquePathsCombinatorics(int m, int n) {
        int totalSteps = m + n - 2;
        int k = min(m - 1, n - 1);
        long long res = 1;

        for (int i = 1; i <= k; i++) {
            res = res * (totalSteps - k + i) / i;
        }

        return res;
    }
};

int main() {
    UniquePaths solver;

    cout << "Test m = 3, n = 7:\n";
    cout << "  Memoization:     " << solver.uniquePathsMemo(3, 7) << "\n";
    cout << "  Tabulation:      " << solver.uniquePathsTabulation(3, 7) << "\n";
    cout << "  Space-Optimized: " << solver.uniquePathsSpaceOptimized(3, 7) << "\n";
    cout << "  Combinatorics:   " << solver.uniquePathsCombinatorics(3, 7) << " (Expected: 28)\n";

    return 0;
}

