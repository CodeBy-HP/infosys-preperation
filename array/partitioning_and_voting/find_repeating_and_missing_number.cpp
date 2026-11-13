#include <iostream>
#include <vector>
#include <cassert>

/**
 * Find the Repeating and Missing Number
 * Demonstrates:
 * 1. Mathematical Sum & Sum of Squares - O(N) Time, O(1) Space
 * 2. Bitwise XOR Partitioning - O(N) Time, O(1) Space
 */

class Solution {
public:
    // Approach 1: Mathematical Equations - O(N) Time, O(1) Space
    std::pair<int, int> findMissingAndRepeatingMath(const std::vector<int>& nums) {
        long long n = nums.size();
        long long S = 0, S2 = 0;
        for (long long x : nums) {
            S += x;
            S2 += (x * x);
        }

        long long Sn = n * (n + 1) / 2;
        long long S2n = n * (n + 1) * (2 * n + 1) / 6;

        long long diff1 = S - Sn;               // A - B
        long long diff2 = S2 - S2n;             // A^2 - B^2
        long long sumAB = diff2 / diff1;        // A + B

        long long A = (diff1 + sumAB) / 2;      // Repeating
        long long B = sumAB - A;                // Missing

        return {static_cast<int>(A), static_cast<int>(B)};
    }

    // Approach 2: Bitwise XOR Partitioning - O(N) Time, O(1) Space
    std::pair<int, int> findMissingAndRepeatingXOR(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int xor_val = 0;

        for (int i = 0; i < n; ++i) {
            xor_val ^= nums[i];
            xor_val ^= (i + 1);
        }

        // Rightmost set bit
        int diff_bit = xor_val & (-xor_val);

        int bucket0 = 0, bucket1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & diff_bit) bucket1 ^= nums[i];
            else bucket0 ^= nums[i];

            int natural = i + 1;
            if (natural & diff_bit) bucket1 ^= natural;
            else bucket0 ^= natural;
        }

        // Determine which bucket holds the repeating number
        int count_bucket0 = 0;
        for (int x : nums) {
            if (x == bucket0) count_bucket0++;
        }

        if (count_bucket0 == 2) {
            return {bucket0, bucket1}; // {Repeating, Missing}
        }
        return {bucket1, bucket0};
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {3, 1, 2, 5, 3};
    std::pair<int, int> expected1 = {3, 4};
    assert(solver.findMissingAndRepeatingMath(nums1) == expected1);
    assert(solver.findMissingAndRepeatingXOR(nums1) == expected1);

    std::vector<int> nums2 = {3, 1, 3};
    std::pair<int, int> expected2 = {3, 2};
    assert(solver.findMissingAndRepeatingMath(nums2) == expected2);
    assert(solver.findMissingAndRepeatingXOR(nums2) == expected2);

    std::cout << "All Find Repeating and Missing Number tests passed successfully!" << std::endl;
    return 0;
}

