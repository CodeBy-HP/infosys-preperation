#include <iostream>
#include <vector>
#include <cassert>

class UniquePathsII {
public:
    // Approach 1: 2D Tabulation - O(M * N) Time, O(M * N) Space
    static int uniquePathsWithObstacles2D(const std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        std::vector<std::vector<long long>> dp(m, std::vector<long long>(n, 0));
        dp[0][0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[i][j] = 0;
                    continue;
                }
                if (i > 0) dp[i][j] += dp[i - 1][j];
                if (j > 0) dp[i][j] += dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }

    // Approach 2: Space-Optimized 1D Row - O(M * N) Time, O(N) Space
    static int uniquePathsWithObstaclesOptimized(const std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;

        std::vector<long long> dp(n, 0);
        dp[0] = 1;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {
    std::vector<std::vector<int>> g1 = {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    assert(UniquePathsII::uniquePathsWithObstacles2D(g1) == 2);
    assert(UniquePathsII::uniquePathsWithObstaclesOptimized(g1) == 2);

    std::vector<std::vector<int>> g2 = {
        {0, 1},
        {0, 0}
    };
    assert(UniquePathsII::uniquePathsWithObstacles2D(g2) == 1);
    assert(UniquePathsII::uniquePathsWithObstaclesOptimized(g2) == 1);

    std::cout << "All Unique Paths II tests passed successfully!\n";
    return 0;
}

