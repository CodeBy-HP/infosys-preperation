#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class StockWithCooldown {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int maxProfitMemo(const vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<vector<int>> memo(n, vector<int>(2, -1));
        return solveMemo(0, 0, prices, memo);
    }

private:
    int solveMemo(int i, int holding, const vector<int>& prices, vector<vector<int>>& memo) {
        if (i >= (int)prices.size()) return 0;
        if (memo[i][holding] != -1) return memo[i][holding];

        if (holding == 1) {
            // Can SELL today (mandatory 1 day cooldown -> jump to i + 2) OR REST
            int sell = prices[i] + solveMemo(i + 2, 0, prices, memo);
            int rest = solveMemo(i + 1, 1, prices, memo);
            return memo[i][holding] = max(sell, rest);
        } else {
            // Can BUY today OR REST
            int buy = -prices[i] + solveMemo(i + 1, 1, prices, memo);
            int rest = solveMemo(i + 1, 0, prices, memo);
            return memo[i][holding] = max(buy, rest);
        }
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (Iterative Tabulation)
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int maxProfitTabulation(const vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        // Padded to n + 2 to safely absorb the i + 2 cooldown jump
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));

        for (int i = n - 1; i >= 0; i--) {
            // Holding state
            dp[i][1] = max(prices[i] + dp[i + 2][0], dp[i + 1][1]);

            // Not holding state
            dp[i][0] = max(-prices[i] + dp[i + 1][1], dp[i + 1][0]);
        }

        return dp[0][0];
    }

    // =========================================================================
    // 3. Space-Optimized Approach (O(1) Space)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int maxProfitSpaceOptimized(const vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;

        int held = -prices[0];
        int sold = 0;
        int rest = 0;

        for (int i = 1; i < n; i++) {
            int prevHeld = held;
            int prevSold = sold;
            int prevRest = rest;

            held = max(prevHeld, prevRest - prices[i]);
            sold = prevHeld + prices[i];
            rest = max(prevRest, prevSold);
        }

        return max(sold, rest);
    }
};

int main() {
    StockWithCooldown solver;

    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Test [1, 2, 3, 0, 2]:\n";
    cout << "  Memoization:     " << solver.maxProfitMemo(prices) << "\n";
    cout << "  Tabulation:      " << solver.maxProfitTabulation(prices) << "\n";
    cout << "  Space-Optimized: " << solver.maxProfitSpaceOptimized(prices) << " (Expected: 3)\n";

    return 0;
}

