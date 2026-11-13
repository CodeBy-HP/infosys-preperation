#include <iostream>
#include <vector>
#include <cassert>

class SubsetSum {
public:
    // Approach 1: 2D Tabulation - O(N * K) Time, O(N * K) Space
    static bool subsetSumToK2D(int n, int k, const std::vector<int>& arr) {
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(k + 1, false));

        for (int i = 0; i < n; ++i) dp[i][0] = true;
        if (arr[0] <= k) dp[0][arr[0]] = true;

        for (int i = 1; i < n; ++i) {
            for (int target = 1; target <= k; ++target) {
                bool notTake = dp[i - 1][target];
                bool take = (arr[i] <= target) ? dp[i - 1][target - arr[i]] : false;
                dp[i][target] = notTake || take;
            }
        }
        return dp[n - 1][k];
    }

    // Approach 2: Space-Optimized 1D Vector - O(N * K) Time, O(K) Space
    static bool subsetSumToKOptimized(int n, int k, const std::vector<int>& arr) {
        std::vector<bool> dp(k + 1, false);
        dp[0] = true;
        if (arr[0] <= k) dp[arr[0]] = true;

        for (int i = 1; i < n; ++i) {
            std::vector<bool> curr(k + 1, false);
            curr[0] = true;
            for (int target = 1; target <= k; ++target) {
                bool notTake = dp[target];
                bool take = (arr[i] <= target) ? dp[target - arr[i]] : false;
                curr[target] = notTake || take;
            }
            dp = curr;
        }
        return dp[k];
    }
};

int main() {
    std::vector<int> a1 = {1, 2, 3, 4};
    int k1 = 4;
    assert(SubsetSum::subsetSumToK2D(4, k1, a1) == true);
    assert(SubsetSum::subsetSumToKOptimized(4, k1, a1) == true);

    std::vector<int> a2 = {4, 3, 2, 1};
    int k2 = 5;
    assert(SubsetSum::subsetSumToK2D(4, k2, a2) == true);
    assert(SubsetSum::subsetSumToKOptimized(4, k2, a2) == true);

    std::vector<int> a3 = {2, 5, 1, 6, 7};
    int k3 = 4;
    assert(SubsetSum::subsetSumToK2D(5, k3, a3) == false);
    assert(SubsetSum::subsetSumToKOptimized(5, k3, a3) == false);

    std::cout << "All Subset Sum Equals Target tests passed successfully!\n";
    return 0;
}

