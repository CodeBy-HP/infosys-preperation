#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long minWeightCoinChange(const std::vector<int>& coins, 
                                 const std::vector<int>& weights, 
                                 int target) {
        if (target == 0) return 0;
        int n = coins.size();

        const long long INF = 1e18;
        // dp[v]: minimum weight to make change for amount v
        std::vector<long long> dp(target + 1, INF);
        dp[0] = 0;

        for (int v = 1; v <= target; ++v) {
            for (int i = 0; i < n; ++i) {
                if (v >= coins[i] && dp[v - coins[i]] != INF) {
                    dp[v] = std::min(dp[v], dp[v - coins[i]] + weights[i]);
                }
            }
        }

        return dp[target] == INF ? -1 : dp[target];
    }
};

int main() {
    Solution sol;

    // Test 1: coins = [1, 2, 5], weights = [3, 2, 8], target = 11
    // Option A: 5 * 2-cent (weight 5 * 2 = 10) + 1 * 1-cent (weight 3) = 13
    // Option B: 2 * 5-cent (weight 2 * 8 = 16) + 1 * 1-cent (weight 3) = 19
    // Min weight: 13
    std::vector<int> coins1 = {1, 2, 5};
    std::vector<int> weights1 = {3, 2, 8};
    int target1 = 11;
    std::cout << "Test 1 [target=11]: " 
              << sol.minWeightCoinChange(coins1, weights1, target1) << " (Expected: 13)\n";

    // Test 2: Impossible target
    std::vector<int> coins2 = {2, 4};
    std::vector<int> weights2 = {5, 10};
    int target2 = 7;
    std::cout << "Test 2 [target=7]:  " 
              << sol.minWeightCoinChange(coins2, weights2, target2) << " (Expected: -1)\n";

    // Test 3: Standard unweighted equivalence (all weights = 1)
    std::vector<int> coins3 = {1, 2, 5};
    std::vector<int> weights3 = {1, 1, 1};
    int target3 = 11;
    std::cout << "Test 3 [target=11, all weights=1]: " 
              << sol.minWeightCoinChange(coins3, weights3, target3) << " (Expected: 3)\n";

    return 0;
}

