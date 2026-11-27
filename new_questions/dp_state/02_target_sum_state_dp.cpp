#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;

class Solution {
public:
    // Optimal 1D Subset Sum DP Reduction
    int findTargetSumWays(const vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }

        int subsetTarget = (totalSum + target) / 2;
        vector<int> dp(subsetTarget + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int s = subsetTarget; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }
        return dp[subsetTarget];
    }
};

int main() {
    Solution sol;
    assert(sol.findTargetSumWays({1, 1, 1, 1, 1}, 3) == 5);
    assert(sol.findTargetSumWays({1}, 1) == 1);
    assert(sol.findTargetSumWays({0, 0, 0, 0, 0, 0, 0, 0, 1}, 1) == 256);
    cout << "02_target_sum_state_dp passed all tests!\n";
    return 0;
}
