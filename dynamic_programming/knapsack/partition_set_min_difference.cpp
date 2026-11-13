#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <algorithm>
#include <cassert>

class MinSubsetDifference {
public:
    static int minSubsetSumDifference(int n, const std::vector<int>& arr) {
        int totalSum = std::accumulate(arr.begin(), arr.end(), 0);
        int target = totalSum / 2;

        std::vector<bool> dp(target + 1, false);
        dp[0] = true;
        if (arr[0] <= target) dp[arr[0]] = true;

        for (int i = 1; i < n; ++i) {
            std::vector<bool> curr(target + 1, false);
            curr[0] = true;
            for (int s = 1; s <= target; ++s) {
                bool notTake = dp[s];
                bool take = (arr[i] <= s) ? dp[s - arr[i]] : false;
                curr[s] = notTake || take;
            }
            dp = curr;
        }

        int minDiff = 1e9;
        for (int s1 = 0; s1 <= target; ++s1) {
            if (dp[s1]) {
                int s2 = totalSum - s1;
                minDiff = std::min(minDiff, std::abs(s1 - s2));
            }
        }
        return minDiff;
    }
};

int main() {
    std::vector<int> a1 = {1, 2, 3, 4};
    assert(MinSubsetDifference::minSubsetSumDifference(4, a1) == 0);

    std::vector<int> a2 = {8, 6, 5};
    assert(MinSubsetDifference::minSubsetSumDifference(3, a2) == 3);

    std::vector<int> a3 = {1, 6, 11, 5};
    assert(MinSubsetDifference::minSubsetSumDifference(4, a3) == 1);

    std::cout << "All Partition Set With Min Absolute Sum Difference tests passed successfully!\n";
    return 0;
}

