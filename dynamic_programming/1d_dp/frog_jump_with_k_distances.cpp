#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>

class FrogJumpK {
public:
    // Approach 1: Top-down Memoization - O(N * K) Time, O(N) Space
    static int solveMemo(int i, int k, const std::vector<int>& height, std::vector<int>& memo) {
        if (i == 0) return 0;
        if (memo[i] != -1) return memo[i];

        int minCost = 1e9;
        for (int j = 1; j <= k; ++j) {
            if (i - j >= 0) {
                int cost = solveMemo(i - j, k, height, memo) + std::abs(height[i] - height[i - j]);
                minCost = std::min(minCost, cost);
            }
        }
        return memo[i] = minCost;
    }

    static int minEnergyMemo(const std::vector<int>& height, int k) {
        int n = height.size();
        std::vector<int> memo(n, -1);
        return solveMemo(n - 1, k, height, memo);
    }

    // Approach 2: Bottom-up Tabulation - O(N * K) Time, O(N) Space
    static int minEnergyTabulation(const std::vector<int>& height, int k) {
        int n = height.size();
        if (n <= 1) return 0;

        std::vector<int> dp(n, 1e9);
        dp[0] = 0;

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                if (i - j >= 0) {
                    dp[i] = std::min(dp[i], dp[i - j] + std::abs(height[i] - height[i - j]));
                }
            }
        }
        return dp[n - 1];
    }
};

int main() {
    std::vector<int> h1 = {10, 30, 40, 50, 20};
    int k1 = 3;
    assert(FrogJumpK::minEnergyMemo(h1, k1) == 30);
    assert(FrogJumpK::minEnergyTabulation(h1, k1) == 30);

    std::vector<int> h2 = {10, 20, 10};
    int k2 = 1;
    assert(FrogJumpK::minEnergyMemo(h2, k2) == 20);
    assert(FrogJumpK::minEnergyTabulation(h2, k2) == 20);

    std::cout << "All Frog Jump with K Distances tests passed successfully!\n";
    return 0;
}

