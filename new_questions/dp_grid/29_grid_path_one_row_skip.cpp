#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long INF = 1e18;

public:
    // Minimum Cost Path from (0,0) to (m-1,n-1) with at most 1 vertical Row Skip (r -> r+2)
    long long minCostPathWithOneRowSkip(const vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // dp[r][c][usedSkip]
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, INF)));

        if (grid[0][0] != -1) {
            dp[0][0][0] = grid[0][0];
        }

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == -1) continue;
                for (int used = 0; used <= 1; used++) {
                    if (r == 0 && c == 0 && used == 0) continue;

                    long long bestPrev = INF;
                    if (r > 0) bestPrev = min(bestPrev, dp[r - 1][c][used]);
                    if (c > 0) bestPrev = min(bestPrev, dp[r][c - 1][used]);

                    // Row Skip arrival into used == 1 from (r - 2, c, 0)
                    if (used == 1 && r >= 2) {
                        bestPrev = min(bestPrev, dp[r - 2][c][0]);
                    }

                    if (bestPrev < INF) {
                        dp[r][c][used] = min(dp[r][c][used], bestPrev + grid[r][c]);
                    }
                }
            }
        }

        long long ans = min(dp[m - 1][n - 1][0], dp[m - 1][n - 1][1]);
        return ans >= INF ? -1 : ans;
    }

    // Counting Unique Paths Variant (with at most 1 Row Skip)
    long long uniquePathsWithOneRowSkip(int m, int n) {
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, 0)));
        dp[0][0][0] = 1;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) continue;
                for (int used = 0; used <= 1; used++) {
                    if (r > 0) dp[r][c][used] += dp[r - 1][c][used];
                    if (c > 0) dp[r][c][used] += dp[r][c - 1][used];
                    if (used == 1 && r >= 2) dp[r][c][1] += dp[r - 2][c][0];
                }
            }
        }
        return dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> g1 = {
        {1, 100, 1},
        {50, 50, 50},
        {1, 1, 1}
    };
    assert(sol.minCostPathWithOneRowSkip(g1) == 4);
    assert(sol.uniquePathsWithOneRowSkip(3, 2) == 5); // 3 normal paths + (0,0)->(2,0)->(2,1) + (0,0)->(0,1)->(2,1) = 5
    cout << "29_grid_path_one_row_skip passed all tests!\n";
    return 0;
}
