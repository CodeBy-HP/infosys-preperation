#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class DungeonGame {
private:
    static const int INF = 1e9;

public:
    // =========================================================================
    // 1. Backwards Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int calculateMinimumHPMemo(const vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return solveMemo(0, 0, m, n, dungeon, memo);
    }

private:
    int solveMemo(int r, int c, int m, int n, const vector<vector<int>>& dungeon, vector<vector<int>>& memo) {
        if (r >= m || c >= n) return INF;
        if (r == m - 1 && c == n - 1) {
            return max(1, 1 - dungeon[r][c]);
        }

        if (memo[r][c] != -1) return memo[r][c];

        int down = solveMemo(r + 1, c, m, n, dungeon, memo);
        int right = solveMemo(r, c + 1, m, n, dungeon, memo);

        int minExitHealth = min(down, right);
        int healthNeeded = minExitHealth - dungeon[r][c];

        return memo[r][c] = max(1, healthNeeded);
    }

public:
    // =========================================================================
    // 2. Backwards Bottom-Up Approach (2D Tabulation)
    // Time Complexity: O(M * N)
    // Space Complexity: O(M * N)
    // =========================================================================
    int calculateMinimumHPTabulation(const vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        // Padded table of size (m + 1) x (n + 1) initialized to INF
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));

        // Setting boundary cells directly exiting the princess room to 1
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                int minExitHealth = min(dp[r + 1][c], dp[r][c + 1]);
                int healthNeeded = minExitHealth - dungeon[r][c];
                dp[r][c] = max(1, healthNeeded);
            }
        }

        return dp[0][0];
    }

    // =========================================================================
    // 3. Space-Optimized Approach (1D Rolling Row)
    // Time Complexity: O(M * N)
    // Space Complexity: O(N)
    // =========================================================================
    int calculateMinimumHPSpaceOptimized(const vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<int> dp(n + 1, INF);
        dp[n - 1] = 1; // Base case for last column

        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                int minExitHealth = min(dp[c], dp[c + 1]);
                if (r == m - 1 && c == n - 1) minExitHealth = 1;
                int healthNeeded = minExitHealth - dungeon[r][c];
                dp[c] = max(1, healthNeeded);
            }
        }

        return dp[0];
    }
};

int main() {
    DungeonGame solver;

    vector<vector<int>> dungeon = {
        {-2, -3,  3},
        {-5, -10, 1},
        {10,  30, -5}
    };

    cout << "Test Dungeon:\n";
    cout << "  Memoization:     " << solver.calculateMinimumHPMemo(dungeon) << "\n";
    cout << "  Tabulation:      " << solver.calculateMinimumHPTabulation(dungeon) << "\n";
    cout << "  Space-Optimized: " << solver.calculateMinimumHPSpaceOptimized(dungeon) << " (Expected: 7)\n";

    return 0;
}

