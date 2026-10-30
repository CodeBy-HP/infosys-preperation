#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class CoinChange {
private:
    static const int INF = 1e9;

public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(N * Amount)
    // Space Complexity: O(N * Amount)
    // =========================================================================
    int coinChangeMemo(const vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> memo(n, vector<int>(amount + 1, -1));
        int ans = solveMemo(n - 1, amount, coins, memo);
        return ans >= INF ? -1 : ans;
    }

private:
    int solveMemo(int i, int amount, const vector<int>& coins, vector<vector<int>>& memo) {
        if (amount == 0) return 0;
        if (i < 0 || amount < 0) return INF;

        if (memo[i][amount] != -1) return memo[i][amount];

        // Choice A: Do not pick this coin, move to i - 1
        int notPick = solveMemo(i - 1, amount, coins, memo);

        // Choice B: Pick this coin, STAY on coin i (unbounded reuse)
        int pick = INF;
        if (coins[i] <= amount) {
            pick = 1 + solveMemo(i, amount - coins[i], coins, memo);
        }

        return memo[i][amount] = min(pick, notPick);
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (2D Tabulation)
    // Time Complexity: O(N * Amount)
    // Space Complexity: O(N * Amount)
    // =========================================================================
    int coinChangeTabulation(const vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, INF));

        for (int i = 0; i < n; i++) dp[i][0] = 0;

        for (int a = 1; a <= amount; a++) {
            if (a % coins[0] == 0) dp[0][a] = a / coins[0];
        }

        for (int i = 1; i < n; i++) {
            for (int a = 1; a <= amount; a++) {
                int notPick = dp[i - 1][a];
                int pick = (coins[i] <= a) ? 1 + dp[i][a - coins[i]] : INF;
                dp[i][a] = min(notPick, pick);
            }
        }

        return dp[n - 1][amount] >= INF ? -1 : dp[n - 1][amount];
    }

    // =========================================================================
    // 3. Space-Optimized Approach (1D Array with Forward Loop)
    // Time Complexity: O(N * Amount)
    // Space Complexity: O(Amount)
    // =========================================================================
    int coinChangeSpaceOptimized(const vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int coin : coins) {
            // Forward loop allows infinite coin reuse
            for (int j = coin; j <= amount; j++) {
                dp[j] = min(dp[j], 1 + dp[j - coin]);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};

int main() {
    CoinChange solver;

    vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    cout << "Test 1 [1, 2, 5], amount = 11:\n";
    cout << "  Memoization:     " << solver.coinChangeMemo(coins1, amount1) << "\n";
    cout << "  Tabulation:      " << solver.coinChangeTabulation(coins1, amount1) << "\n";
    cout << "  Space-Optimized: " << solver.coinChangeSpaceOptimized(coins1, amount1) << " (Expected: 3)\n";

    vector<int> coins2 = {2};
    int amount2 = 3;
    cout << "Test 2 [2], amount = 3:\n";
    cout << "  Space-Optimized: " << solver.coinChangeSpaceOptimized(coins2, amount2) << " (Expected: -1)\n";

    return 0;
}

