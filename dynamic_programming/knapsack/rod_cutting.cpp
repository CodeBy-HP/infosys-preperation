#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class RodCutting {
public:
    // Approach 1: 2D Unbounded Knapsack - O(N^2) Time, O(N^2) Space
    static int cutRod2D(const std::vector<int>& price, int n) {
        std::vector<std::vector<int>> dp(n, std::vector<int>(n + 1, 0));

        for (int len = 0; len <= n; ++len) {
            dp[0][len] = len * price[0];
        }

        for (int i = 1; i < n; ++i) {
            int rodLength = i + 1;
            for (int len = 0; len <= n; ++len) {
                int notTake = dp[i - 1][len];
                int take = (rodLength <= len) ? price[i] + dp[i][len - rodLength] : 0;
                dp[i][len] = std::max(notTake, take);
            }
        }
        return dp[n - 1][n];
    }

    // Approach 2: 1D Forward Array - O(N^2) Time, O(N) Space
    static int cutRodOptimized(const std::vector<int>& price, int n) {
        std::vector<int> dp(n + 1, 0);

        for (int len = 1; len <= n; ++len) {
            int maxVal = 0;
            for (int i = 1; i <= len; ++i) {
                maxVal = std::max(maxVal, price[i - 1] + dp[len - i]);
            }
            dp[len] = maxVal;
        }
        return dp[n];
    }
};

int main() {
    std::vector<int> p1 = {1, 5, 8, 9, 10, 17, 17, 20};
    assert(RodCutting::cutRod2D(p1, 8) == 22);
    assert(RodCutting::cutRodOptimized(p1, 8) == 22);

    std::vector<int> p2 = {3, 5, 8, 9, 10, 17, 17, 20};
    assert(RodCutting::cutRod2D(p2, 8) == 24);
    assert(RodCutting::cutRodOptimized(p2, 8) == 24);

    std::cout << "All Rod Cutting tests passed successfully!\n";
    return 0;
}

