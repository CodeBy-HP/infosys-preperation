#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <cassert>

class TargetSum {
public:
    static int findTargetSumWays(const std::vector<int>& nums, int target) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);

        if (std::abs(target) > totalSum || (totalSum + target) % 2 != 0) {
            return 0;
        }

        int s1 = (totalSum + target) / 2;
        int n = nums.size();
        std::vector<int> dp(s1 + 1, 0);

        if (nums[0] == 0) {
            dp[0] = 2;
        } else {
            dp[0] = 1;
            if (nums[0] <= s1) dp[nums[0]] = 1;
        }

        for (int i = 1; i < n; ++i) {
            std::vector<int> curr(s1 + 1, 0);
            for (int sum = 0; sum <= s1; ++sum) {
                int notTake = dp[sum];
                int take = (nums[i] <= sum) ? dp[sum - nums[i]] : 0;
                curr[sum] = notTake + take;
            }
            dp = curr;
        }
        return dp[s1];
    }
};

int main() {
    std::vector<int> nums1 = {1, 1, 1, 1, 1};
    int target1 = 3;
    assert(TargetSum::findTargetSumWays(nums1, target1) == 5);

    std::vector<int> nums2 = {1};
    int target2 = 1;
    assert(TargetSum::findTargetSumWays(nums2, target2) == 1);

    std::vector<int> nums3 = {1, 0};
    int target3 = 1;
    assert(TargetSum::findTargetSumWays(nums3, target3) == 2);

    std::cout << "All Target Sum tests passed successfully!\n";
    return 0;
}

