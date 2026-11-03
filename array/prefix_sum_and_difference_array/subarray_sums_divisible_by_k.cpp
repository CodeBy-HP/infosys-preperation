#include <iostream>
#include <vector>
#include <cassert>

/**
 * Subarray Sums Divisible by K (LeetCode 974)
 * 
 * Problem:
 * Given an integer array nums and an integer k, return the number of non-empty
 * subarrays whose sum is strictly divisible by k.
 * 
 * Algorithm: Prefix Remainder + Hash/Array Frequency
 * Time Complexity: O(N)
 * Space Complexity: O(K)
 */

class Solution {
public:
    int subarraysDivByK(const std::vector<int>& nums, int k) {
        // Frequency array for remainders in range [0, k - 1]
        std::vector<int> rem_count(k, 0);
        // Base case: prefix sum of 0 has remainder 0 seen once
        rem_count[0] = 1;

        int prefix_sum = 0;
        int total_subarrays = 0;

        for (int x : nums) {
            prefix_sum += x;
            // Standard normalized modulo for C++ negative numbers
            int rem = ((prefix_sum % k) + k) % k;

            // All previously seen prefixes with this identical remainder form valid subarrays
            total_subarrays += rem_count[rem];
            rem_count[rem]++;
        }

        return total_subarrays;
    }
};

int main() {
    Solution solver;

    // Test 1: Example 1 from LeetCode 974
    {
        std::vector<int> nums = {4, 5, 0, -2, -3, 1};
        int k = 5;
        int ans = solver.subarraysDivByK(nums, k);
        std::cout << "Test 1: Expected = 7, Actual = " << ans << std::endl;
        assert(ans == 7);
    }

    // Test 2: Single element not divisible
    {
        std::vector<int> nums = {5};
        int k = 9;
        int ans = solver.subarraysDivByK(nums, k);
        std::cout << "Test 2: Expected = 0, Actual = " << ans << std::endl;
        assert(ans == 0);
    }

    // Test 3: All negative numbers
    {
        std::vector<int> nums = {-1, 2, 9};
        int k = 2;
        // Subarrays:
        // [-1] -> sum -1
        // [2] -> sum 2 (div by 2)
        // [9] -> sum 9
        // [-1, 2] -> sum 1
        // [2, 9] -> sum 11
        // [-1, 2, 9] -> sum 10 (div by 2)
        // Total = 2
        int ans = solver.subarraysDivByK(nums, k);
        std::cout << "Test 3: Expected = 2, Actual = " << ans << std::endl;
        assert(ans == 2);
    }

    std::cout << "All Subarray Sums Divisible by K test cases passed successfully!" << std::endl;
    return 0;
}

