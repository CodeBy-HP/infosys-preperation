#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * Maximum Sum Circular Subarray (LeetCode 918)
 * 
 * Uses Dual Kadane's Algorithm in a single pass:
 * - max_sum: Maximum linear subarray sum via standard Kadane.
 * - min_sum: Minimum contiguous subarray sum via inverted Kadane.
 * - total_sum - min_sum: Maximum wrapping circular subarray sum.
 * - Edge case: If all numbers are negative, max_sum < 0, return max_sum.
 * 
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 */

class Solution {
public:
    int maxSubarraySumCircular(const std::vector<int>& nums) {
        int total_sum = 0;
        int current_max = 0;
        int max_sum = nums[0];
        int current_min = 0;
        int min_sum = nums[0];

        for (int x : nums) {
            // Standard Kadane's for maximum linear subarray
            current_max = std::max(x, current_max + x);
            max_sum = std::max(max_sum, current_max);

            // Inverted Kadane's for minimum contiguous subarray
            current_min = std::min(x, current_min + x);
            min_sum = std::min(min_sum, current_min);

            total_sum += x;
        }

        // If all elements are negative, max_sum < 0.
        // In this case, total_sum - min_sum = 0 (empty subarray), which is invalid.
        // Hence, return max_sum (the maximum single negative element).
        if (max_sum < 0) {
            return max_sum;
        }

        return std::max(max_sum, total_sum - min_sum);
    }
};

int main() {
    Solution solver;

    // Test 1: Example 1 from LeetCode 918 (no wrapping needed)
    {
        std::vector<int> nums = {1, -2, 3, -2};
        int ans = solver.maxSubarraySumCircular(nums);
        std::cout << "Test 1: Expected = 3, Actual = " << ans << std::endl;
        assert(ans == 3);
    }

    // Test 2: Example 2 (wrapping subarray [5, 5])
    {
        std::vector<int> nums = {5, -3, 5};
        int ans = solver.maxSubarraySumCircular(nums);
        std::cout << "Test 2: Expected = 10, Actual = " << ans << std::endl;
        assert(ans == 10);
    }

    // Test 3: Example 3 (all negative elements)
    {
        std::vector<int> nums = {-3, -2, -3};
        int ans = solver.maxSubarraySumCircular(nums);
        std::cout << "Test 3: Expected = -2, Actual = " << ans << std::endl;
        assert(ans == -2);
    }

    // Test 4: Single element array
    {
        std::vector<int> nums = {-5};
        assert(solver.maxSubarraySumCircular(nums) == -5);
    }

    // Test 5: All positive array
    {
        std::vector<int> nums = {1, 2, 3, 4};
        // Total = 10, min_sum = 1, total - min_sum = 9, max_sum = 10
        assert(solver.maxSubarraySumCircular(nums) == 10);
    }

    // Test 6: Wrapping with multiple negatives in the middle
    {
        std::vector<int> nums = {3, -1, 2, -1};
        // Wrapping [2, -1, 3] sum = 4
        assert(solver.maxSubarraySumCircular(nums) == 4);
    }

    std::cout << "All Maximum Sum Circular Subarray tests passed successfully!" << std::endl;
    return 0;
}

