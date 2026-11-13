#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class NonAdjacentMaxSum {
public:
    // Approach 1: Memoized Recursion - O(N) Time, O(N) Space
    static int solveMemo(int i, const std::vector<int>& nums, std::vector<int>& memo) {
        if (i < 0) return 0;
        if (i == 0) return std::max(0, nums[0]);
        if (memo[i] != -1) return memo[i];

        int pick = nums[i] + solveMemo(i - 2, nums, memo);
        int notPick = solveMemo(i - 1, nums, memo);

        return memo[i] = std::max(pick, notPick);
    }

    static int maximumNonAdjacentSumMemo(const std::vector<int>& nums) {
        if (nums.empty()) return 0;
        std::vector<int> memo(nums.size(), -1);
        return solveMemo(nums.size() - 1, nums, memo);
    }

    // Approach 2: Space-Optimized Tabulation - O(N) Time, O(1) Space
    static int maximumNonAdjacentSumOptimized(const std::vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return std::max(0, nums[0]);

        int prev2 = 0;
        int prev1 = std::max(0, nums[0]);

        for (int i = 1; i < n; ++i) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            int curr = std::max(pick, notPick);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    std::vector<int> nums1 = {2, 1, 4, 9};
    assert(NonAdjacentMaxSum::maximumNonAdjacentSumMemo(nums1) == 11);
    assert(NonAdjacentMaxSum::maximumNonAdjacentSumOptimized(nums1) == 11);

    std::vector<int> nums2 = {1, 2, 4};
    assert(NonAdjacentMaxSum::maximumNonAdjacentSumMemo(nums2) == 5);
    assert(NonAdjacentMaxSum::maximumNonAdjacentSumOptimized(nums2) == 5);

    std::vector<int> nums3 = {9, 9, 8, 2};
    assert(NonAdjacentMaxSum::maximumNonAdjacentSumMemo(nums3) == 17);
    assert(NonAdjacentMaxSum::maximumNonAdjacentSumOptimized(nums3) == 17);

    std::cout << "All Maximum Sum of Non-Adjacent Elements tests passed successfully!\n";
    return 0;
}

