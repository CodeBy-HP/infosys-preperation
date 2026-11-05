#include <iostream>
#include <vector>
#include <cassert>

/**
 * Subarray Sums Divisible by K (LeetCode 974)
 * Frequency array over remainders [0...k-1] with negative modulo normalization.
 * Time Complexity: O(N)
 * Space Complexity: O(K)
 */

class Solution {
public:
    int subarraysDivByK(const std::vector<int>& nums, int k) {
        std::vector<int> rem_count(k, 0);
        rem_count[0] = 1; // Empty prefix sum at index 0

        int prefix_sum = 0;
        int total = 0;

        for (int x : nums) {
            prefix_sum += x;
            int rem = ((prefix_sum % k) + k) % k;

            total += rem_count[rem];
            rem_count[rem]++;
        }

        return total;
    }
};

int main() {
    Solution solver;

    // Test 1: [4, 5, 0, -2, -3, 1], k = 5 -> 7
    std::vector<int> nums1 = {4, 5, 0, -2, -3, 1};
    assert(solver.subarraysDivByK(nums1, 5) == 7);

    // Test 2: [5], k = 9 -> 0
    std::vector<int> nums2 = {5};
    assert(solver.subarraysDivByK(nums2, 9) == 0);

    std::cout << "All Subarray Sums Divisible by K tests passed successfully!" << std::endl;
    return 0;
}

