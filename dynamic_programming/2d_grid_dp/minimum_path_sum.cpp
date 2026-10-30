#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MinimumPathSum {
private:
    static const int INF = 1e9;

public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int minPathSumMemo(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solveMemo(0, 0, m, n, grid, memo);
    }

private:
    int solveMemo(int r, int c, int m, int n, const vector<vector<int>>& grid, vector<vector<int>>& memo) {
        if (r >= m || c >= n) return INF;
        if (r == m - 1 && c == n - 1) return grid[r][c];

        if (memo[r][c] != -1) return memo[r][c];

        int down = solveMemo(r + 1, c, m, n, grid, memo);
        int right = solveMemo(r, c + 1, m, n, grid, memo);

        return memo[r][c] = grid[r][c] + min(down, right);
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (2D Tabulation)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int minPathSumTabulation(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];

        for (int r = 1; r < m; r++) {
            dp[r][0] = dp[r - 1][0] + grid[r][0];
        }

        for (int c = 1; c < n; c++) {
            dp[0][c] = dp[0][c - 1] + grid[0][c];
        }

        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                dp[r][c] = grid[r][c] + min(dp[r - 1][c], dp[r][c - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }

    // =========================================================================
    // 3. Space-Optimized Approach (1D Array)
    // Time Complexity: O(M * N)
    // Space Complexity: O(N)
    // =========================================================================
    int minPathSumSpaceOptimized(const vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n, 0);

        dp[0] = grid[0][0];
        for (int c = 1; c < n; c++) {
            dp[c] = dp[c - 1] + grid[0][c];
        }

        for (int r = 1; r < m; r++) {
            dp[0] += grid[r][0];
            for (int c = 1; c < n; c++) {
                dp[c] = grid[r][c] + min(dp[c], dp[c - 1]);
            }
        }

        return dp[n - 1];
    }
};

int main() {
    MinimumPathSum solver;

    vector<vector<int>> grid = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };

    cout << "Test Grid:\n";
    cout << "  Memoization:     " << solver.minPathSumMemo(grid) << "\n";
    cout << "  Tabulation:      " << solver.minPathSumTabulation(grid) << "\n";
    cout << "  Space-Optimized: " << solver.minPathSumSpaceOptimized(grid) << " (Expected: 7)\n";

    return 0;
}

