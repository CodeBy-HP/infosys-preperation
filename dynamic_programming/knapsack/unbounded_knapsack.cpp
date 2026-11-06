#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class UnboundedKnapsack {
public:
    // Approach 1: 2D Tabulation - O(N * W) Time, O(N * W) Space
    static int knapSack2D(int n, int W, const std::vector<int>& val, const std::vector<int>& wt) {
        std::vector<std::vector<int>> dp(n, std::vector<int>(W + 1, 0));

        for (int w = 0; w <= W; ++w) {
            dp[0][w] = (w / wt[0]) * val[0];
        }

        for (int i = 1; i < n; ++i) {
            for (int w = 0; w <= W; ++w) {
                int notTake = dp[i - 1][w];
                int take = (wt[i] <= w) ? val[i] + dp[i][w - wt[i]] : 0;
                dp[i][w] = std::max(notTake, take);
            }
        }
        return dp[n - 1][W];
    }

    // Approach 2: 1D Forward Array - O(N * W) Time, O(W) Space
    static int knapSackOptimized(int n, int W, const std::vector<int>& val, const std::vector<int>& wt) {
        std::vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; ++i) {
            for (int w = wt[i]; w <= W; ++w) {
                dp[w] = std::max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }
        return dp[W];
    }
};

int main() {
    std::vector<int> val1 = {1, 1};
    std::vector<int> wt1 = {2, 1};
    int W1 = 3;
    assert(UnboundedKnapsack::knapSack2D(2, W1, val1, wt1) == 3);
    assert(UnboundedKnapsack::knapSackOptimized(2, W1, val1, wt1) == 3);

    std::vector<int> val2 = {6, 1, 7, 7};
    std::vector<int> wt2 = {1, 3, 4, 5};
    int W2 = 8;
    // can take eight of item 0 (weight 1, value 6): 8 * 6 = 48
    assert(UnboundedKnapsack::knapSack2D(4, W2, val2, wt2) == 48);
    assert(UnboundedKnapsack::knapSackOptimized(4, W2, val2, wt2) == 48);

    std::cout << "All Unbounded Knapsack tests passed successfully!\n";
    return 0;
}

