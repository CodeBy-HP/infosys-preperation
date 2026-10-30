#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

class Solution {
public:
    int constrainedSubsetSum(const std::vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> dp(n);
        std::deque<int> dq; // Stores indices of dp in decreasing order of value

        int maxSum = nums[0];

        for (int i = 0; i < n; ++i) {
            // 1. Evict elements outside the window [i - k, i - 1]
            if (!dq.empty() && dq.front() < i - k) {
                dq.pop_front();
            }

            // 2. Compute dp[i] using the maximum dp in window
            int bestPrev = dq.empty() ? 0 : std::max(0, dp[dq.front()]);
            dp[i] = nums[i] + bestPrev;
            maxSum = std::max(maxSum, dp[i]);

            // 3. Maintain monotonic decreasing order in deque
            while (!dq.empty() && dp[dq.back()] <= dp[i]) {
                dq.pop_back();
            }

            // 4. Push current index
            dq.push_back(i);
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {10, 2, -10, 5, 20};
    int k1 = 2;
    std::cout << "Test 1: " << sol.constrainedSubsetSum(nums1, k1) << " (Expected: 37)\n";

    std::vector<int> nums2 = {-1, -2, -3};
    int k2 = 1;
    std::cout << "Test 2: " << sol.constrainedSubsetSum(nums2, k2) << " (Expected: -1)\n";

    return 0;
}
