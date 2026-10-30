#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0) return false;
        int target = sum / k;

        int n = nums.size();
        std::sort(nums.rbegin(), nums.rend()); // Pruning optimization
        if (nums[0] > target) return false;

        int totalStates = 1 << n;
        std::vector<int> dp(totalStates, -1);
        dp[0] = 0;

        for (int mask = 0; mask < totalStates; ++mask) {
            if (dp[mask] == -1) continue;

            for (int j = 0; j < n; ++j) {
                if (!(mask & (1 << j))) { // If nums[j] is not yet used
                    if (dp[mask] + nums[j] <= target) {
                        dp[mask | (1 << j)] = (dp[mask] + nums[j]) % target;
                    } else {
                        break; // Since nums is sorted descending, future elements won't fit either
                    }
                }
            }
        }

        return dp[totalStates - 1] == 0;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;

    std::cout << std::boolalpha;
    std::cout << "canPartitionKSubsets({4,3,2,3,5,2,1}, 4): " 
              << sol.canPartitionKSubsets(nums, k) << " (Expected: true)\n";

    return 0;
}
