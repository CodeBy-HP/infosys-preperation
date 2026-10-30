#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TravelingSalesperson {
private:
    static const int INF = 1e9;

public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Bitmask Memoization)
    // Time Complexity: O(N^2 * 2^N)
    // Space Complexity: O(N * 2^N)
    // =========================================================================
    int tspMemo(int n, const vector<vector<int>>& dist) {
        int maxMask = 1 << n;
        vector<vector<int>> memo(maxMask, vector<int>(n, -1));
        // Start at city 0, mask = 1 (city 0 marked visited)
        return solveMemo(1, 0, n, dist, memo);
    }

private:
    int solveMemo(int mask, int pos, int n, const vector<vector<int>>& dist, vector<vector<int>>& memo) {
        // Base case: All cities visited
        if (mask == (1 << n) - 1) {
            return dist[pos][0]; // Return home to city 0
        }

        if (memo[mask][pos] != -1) return memo[mask][pos];

        int minCost = INF;

        for (int nextCity = 0; nextCity < n; nextCity++) {
            if ((mask & (1 << nextCity)) == 0) {
                int newMask = mask | (1 << nextCity);
                int cost = dist[pos][nextCity] + solveMemo(newMask, nextCity, n, dist, memo);
                minCost = min(minCost, cost);
            }
        }

        return memo[mask][pos] = minCost;
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (Iterative Mask Tabulation)
    // Time Complexity: O(N^2 * 2^N)
    // Space Complexity: O(N * 2^N)
    // =========================================================================
    int tspTabulation(int n, const vector<vector<int>>& dist) {
        int maxMask = 1 << n;
        // dp[mask][u] = min cost to reach subset 'mask' ending at city 'u'
        vector<vector<int>> dp(maxMask, vector<int>(n, INF));

        // Base case: Starting at city 0
        dp[1][0] = 0;

        for (int mask = 1; mask < maxMask; mask++) {
            for (int u = 0; u < n; u++) {
                if ((mask & (1 << u)) == 0) continue;
                if (dp[mask][u] == INF) continue;

                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) != 0) continue;

                    int nextMask = mask | (1 << v);
                    dp[nextMask][v] = min(dp[nextMask][v], dp[mask][u] + dist[u][v]);
                }
            }
        }

        // Return from final full mask back to city 0
        int fullMask = maxMask - 1;
        int minCost = INF;

        for (int u = 1; u < n; u++) {
            if (dp[fullMask][u] != INF) {
                minCost = min(minCost, dp[fullMask][u] + dist[u][0]);
            }
        }

        return minCost;
    }
};

int main() {
    TravelingSalesperson solver;

    vector<vector<int>> dist = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };

    cout << "Test 4 Cities TSP:\n";
    cout << "  Memoization: " << solver.tspMemo(4, dist) << "\n";
    cout << "  Tabulation:  " << solver.tspTabulation(4, dist) << " (Expected: 80)\n";

    return 0;
}

