#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Knapsack01 {
public:
    // Approach 1: 2D Tabulation - O(N * W) Time, O(N * W) Space
    static int knapSack2D(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
        std::vector<std::vector<int>> dp(n, std::vector<int>(W + 1, 0));

        for (int w = wt[0]; w <= W; ++w) {
            dp[0][w] = val[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int w = 0; w <= W; ++w) {
                int notTake = dp[i - 1][w];
                int take = (wt[i] <= w) ? val[i] + dp[i - 1][w - wt[i]] : 0;
                dp[i][w] = std::max(notTake, take);
            }
        }
        return dp[n - 1][W];
    }

    // Approach 2: Single 1D Array Backwards Traversal - O(N * W) Time, O(W) Space
    static int knapSackOptimized(int W, const std::vector<int>& wt, const std::vector<int>& val, int n) {
        std::vector<int> dp(W + 1, 0);

        for (int w = wt[0]; w <= W; ++w) {
            dp[w] = val[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int w = W; w >= wt[i]; --w) {
                dp[w] = std::max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
        return dp[W];
    }
};

int main() {
    std::vector<int> val1 = {60, 100, 120};
    std::vector<int> wt1 = {10, 20, 30};
    int W1 = 50;
    assert(Knapsack01::knapSack2D(W1, wt1, val1, 3) == 220);
    assert(Knapsack01::knapSackOptimized(W1, wt1, val1, 3) == 220);

    std::vector<int> val2 = {10, 40, 30, 50};
    std::vector<int> wt2 = {5, 4, 6, 3};
    int W2 = 5;
    assert(Knapsack01::knapSack2D(W2, wt2, val2, 4) == 50);
    assert(Knapsack01::knapSackOptimized(W2, wt2, val2, 4) == 50);

    std::cout << "All 0/1 Knapsack tests passed successfully!\n";
    return 0;
}

