#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

class CountPartitionsWithDiff {
public:
    static const int MOD = 1e9 + 7;

    static int countPartitions(int n, int d, const std::vector<int>& arr) {
        int totalSum = std::accumulate(arr.begin(), arr.end(), 0);

        if (totalSum - d < 0 || (totalSum + d) % 2 != 0) {
            return 0;
        }

        int target = (totalSum + d) / 2;
        std::vector<int> dp(target + 1, 0);

        // Base case for element 0
        if (arr[0] == 0) {
            dp[0] = 2;
        } else {
            dp[0] = 1;
            if (arr[0] <= target) dp[arr[0]] = 1;
        }

        for (int i = 1; i < n; ++i) {
            std::vector<int> curr(target + 1, 0);
            for (int sum = 0; sum <= target; ++sum) {
                int notTake = dp[sum];
                int take = (arr[i] <= sum) ? dp[sum - arr[i]] : 0;
                curr[sum] = (notTake + take) % MOD;
            }
            dp = curr;
        }
        return dp[target];
    }
};

int main() {
    std::vector<int> a1 = {5, 2, 6, 4};
    int d1 = 3;
    assert(CountPartitionsWithDiff::countPartitions(4, d1, a1) == 1);

    std::vector<int> a2 = {1, 1, 1, 1};
    int d2 = 0;
    // target = (4 + 0)/2 = 2. Choose 2 from 4: C(4, 2) = 6
    assert(CountPartitionsWithDiff::countPartitions(4, d2, a2) == 6);

    std::cout << "All Count Partitions with Given Difference tests passed successfully!\n";
    return 0;
}

