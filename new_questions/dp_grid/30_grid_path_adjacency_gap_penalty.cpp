#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long INF = 1e18;

public:
    // Generalized Grid Path with Adjacency Gap Penalty:
    // includeCellCost=true adds grid[r][c] at every visited cell; gapWeight multiplies |grid[next]-grid[prev]|
    long long minCostAdjacencyGap(const vector<vector<int>>& grid, long long gapWeight = 1, bool includeCellCost = false) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> dp(n, INF);

        for (int r = 0; r < m; r++) {
            vector<long long> nextDp(n, INF);
            for (int c = 0; c < n; c++) {
                if (r == 0 && c == 0) {
                    nextDp[0] = includeCellCost ? grid[0][0] : 0;
                    continue;
                }
                long long cellCost = includeCellCost ? grid[r][c] : 0;
                if (r > 0) {
                    long long gap = abs(static_cast<long long>(grid[r][c]) - grid[r - 1][c]);
                    nextDp[c] = min(nextDp[c], dp[c] + cellCost + gapWeight * gap);
                }
                if (c > 0) {
                    long long gap = abs(static_cast<long long>(grid[r][c]) - grid[r][c - 1]);
                    nextDp[c] = min(nextDp[c], nextDp[c - 1] + cellCost + gapWeight * gap);
                }
            }
            dp.swap(nextDp);
        }
        return dp[n - 1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {1, 3, 5},
        {10, 2, 6},
        {4, 8, 7}
    };
    assert(sol.minCostAdjacencyGap(grid, 1, false) == 6); // 1 -> 3 -> 5 -> 6 -> 7 (gaps: 2+2+1+1 = 6)
    assert(sol.minCostAdjacencyGap(grid, 1, true) == 27); // 1 -> 3 -> 2 -> 6 -> 7: cells(19) + gaps(2+1+4+1=8) = 27
    cout << "30_grid_path_adjacency_gap_penalty passed all tests!\n";
    return 0;
}
