#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class MinimumFallingPathSum {
public:
    // Approach 1: 2D DP Tabulation - O(N^2) Time, O(N^2) Space
    static int minFallingPathSum2D(const std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int j = 0; j < n; ++j) {
            dp[0][j] = matrix[0][j];
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                int up = dp[i - 1][j];
                int leftDiag = (j > 0) ? dp[i - 1][j - 1] : 1e9;
                int rightDiag = (j + 1 < n) ? dp[i - 1][j + 1] : 1e9;
                dp[i][j] = matrix[i][j] + std::min({up, leftDiag, rightDiag});
            }
        }

        int minSum = 1e9;
        for (int j = 0; j < n; ++j) {
            minSum = std::min(minSum, dp[n - 1][j]);
        }
        return minSum;
    }

    // Approach 2: Space-Optimized Rolling Rows - O(N^2) Time, O(N) Space
    static int minFallingPathSumOptimized(const std::vector<std::vector<int>>& matrix) {
        int n = matrix.size();
        std::vector<int> prev(matrix[0]);

        for (int i = 1; i < n; ++i) {
            std::vector<int> curr(n, 0);
            for (int j = 0; j < n; ++j) {
                int up = prev[j];
                int leftDiag = (j > 0) ? prev[j - 1] : 1e9;
                int rightDiag = (j + 1 < n) ? prev[j + 1] : 1e9;
                curr[j] = matrix[i][j] + std::min({up, leftDiag, rightDiag});
            }
            prev = curr;
        }

        int minSum = 1e9;
        for (int val : prev) {
            minSum = std::min(minSum, val);
        }
        return minSum;
    }
};

int main() {
    std::vector<std::vector<int>> m1 = {
        {2, 1, 3},
        {6, 5, 4},
        {7, 8, 9}
    };
    assert(MinimumFallingPathSum::minFallingPathSum2D(m1) == 13);
    assert(MinimumFallingPathSum::minFallingPathSumOptimized(m1) == 13);

    std::vector<std::vector<int>> m2 = {
        {-19, 57},
        {-40, -5}
    };
    assert(MinimumFallingPathSum::minFallingPathSum2D(m2) == -59);
    assert(MinimumFallingPathSum::minFallingPathSumOptimized(m2) == -59);

    std::cout << "All Minimum Falling Path Sum tests passed successfully!\n";
    return 0;
}

