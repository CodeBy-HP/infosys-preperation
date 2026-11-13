#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>

/**
 * Two Sum (LeetCode 1)
 * Brute Force O(N^2) vs Sort+TwoPointers O(N log N) vs One-Pass Hash Map O(N).
 */

class Solution {
public:
    // Approach 1: Brute Force - O(N^2) Time, O(1) Space
    std::vector<int> twoSumBrute(const std::vector<int>& nums, int target) {
        int n = static_cast<int>(nums.size());
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }

    // Approach 2: One-Pass Hash Map - O(N) Time, O(N) Space
    std::vector<int> twoSumOptimal(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> seen;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            int complement = target - nums[i];
            if (seen.count(complement)) {
                return {seen[complement], i};
            }
            seen[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {2, 7, 11, 15};
    std::vector<int> expected1 = {0, 1};
    assert(solver.twoSumBrute(nums1, 9) == expected1);
    assert(solver.twoSumOptimal(nums1, 9) == expected1);

    std::vector<int> nums2 = {3, 2, 4};
    std::vector<int> expected2 = {1, 2};
    assert(solver.twoSumOptimal(nums2, 6) == expected2);

    std::vector<int> nums3 = {3, 3};
    std::vector<int> expected3 = {0, 1};
    assert(solver.twoSumOptimal(nums3, 6) == expected3);

    std::cout << "All Two Sum tests passed successfully!" << std::endl;
    return 0;
}

