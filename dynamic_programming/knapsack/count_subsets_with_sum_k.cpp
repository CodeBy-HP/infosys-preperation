#include <iostream>
#include <vector>
#include <cassert>

class CountSubsetsWithSumK {
public:
    static const int MOD = 1e9 + 7;

    // Space-Optimized 1D DP - O(N * K) Time, O(K) Space
    static int findWays(const std::vector<int>& arr, int k) {
        int n = arr.size();
        std::vector<int> dp(k + 1, 0);

        // Base case index 0
        if (arr[0] == 0) {
            dp[0] = 2; // pick 0 or not pick 0
        } else {
            dp[0] = 1; // not pick
            if (arr[0] <= k) dp[arr[0]] = 1; // pick
        }

        for (int i = 1; i < n; ++i) {
            std::vector<int> curr(k + 1, 0);
            for (int sum = 0; sum <= k; ++sum) {
                int notTake = dp[sum];
                int take = (arr[i] <= sum) ? dp[sum - arr[i]] : 0;
                curr[sum] = (notTake + take) % MOD;
            }
            dp = curr;
        }
        return dp[k];
    }
};

int main() {
    std::vector<int> a1 = {1, 2, 2, 3};
    int k1 = 3;
    assert(CountSubsetsWithSumK::findWays(a1, k1) == 3);

    // Testing zero handling
    std::vector<int> a2 = {0, 0, 1};
    int k2 = 1;
    // subsets: {1}, {0, 1}, {0, 1}, {0, 0, 1} -> 4 subsets
    assert(CountSubsetsWithSumK::findWays(a2, k2) == 4);

    std::vector<int> a3 = {1, 1, 1};
    int k3 = 2;
    assert(CountSubsetsWithSumK::findWays(a3, k3) == 3);

    std::cout << "All Count Subsets with Sum K tests passed successfully!\n";
    return 0;
}

