#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

class Solution {
    int m, n;
    int dp[205][205][2];
    const int dr[4] = {-1, 1, 0, 0};
    const int dc[4] = {0, 0, -1, 1};

    int dfs(const vector<vector<int>>& grid, int r, int c, int usedDash) {
        if (dp[r][c][usedDash] != -1) return dp[r][c][usedDash];

        int best = 1;
        // 1. Normal 1-step moves
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > grid[r][c]) {
                best = max(best, 1 + dfs(grid, nr, nc, usedDash));
            }
        }

        // 2. Optional 2-step Dash move (if not yet used)
        if (usedDash == 0) {
            for (int d = 0; d < 4; d++) {
                int nr = r + 2 * dr[d], nc = c + 2 * dc[d];
                if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] > grid[r][c]) {
                    best = max(best, 1 + dfs(grid, nr, nc, 1));
                }
            }
        }

        return dp[r][c][usedDash] = best;
    }

public:
    int longestIncreasingPathWithDash(const vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for (int r = 0; r < m; r++)
            for (int c = 0; c < n; c++)
                dp[r][c][0] = dp[r][c][1] = -1;

        int ans = 1;
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                ans = max(ans, dfs(grid, r, c, 0));
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> g1 = {
        {1, 9, 2},
        {8, 5, 7},
        {3, 6, 4}
    };
    // Trace: (0,0)[1] -> Dash(0,2)[2] -> (1,2)[7] -> (1,1) no, wait: (0,0)[1] -> (0,2)[2] -> (2,2)[4] -> (2,1)[6] -> (1,1)[5] no, wait 3->6->5 no, 2->5->8 (from 2 to 5 via dash? no, 7 is between 5 and 2? No: (0,2)[2] -> (1,2)[7] (step), (2,2)[4] -> (2,1)[6] -> (1,1)5 no, (2,0)[3] -> (1,0)[8] -> (0,0)1 no)
    // Wait: (0,0)[1] -> Dash(0,2)[2] -> (1,2)[7] (3), or (1,1)[5] -> (2,1)[6] -> ... Wait: (0,2)[2] -> (2,2)[4]? needs dash! Then (2,1)[6] (len 3). So g1 has max length 3!
    // Let's test a grid where Dash clearly creates length 5:
    vector<vector<int>> g2 = {
        {1, 100, 2, 3},
        {10, 20, 30, 4}
    };
    // Path: (0,0)[1] -> Dash(0,2)[2] -> (0,3)[3] -> (1,3)[4] -> (1,2)[30] (len = 5!)
    assert(sol.longestIncreasingPathWithDash(g2) == 5);
    assert(sol.longestIncreasingPathWithDash({{1, 2}, {3, 4}}) == 3);
    cout << "28_longest_increasing_path_one_dash passed all tests!\n";
    return 0;
}
