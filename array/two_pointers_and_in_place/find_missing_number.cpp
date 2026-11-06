#include <iostream>
#include <vector>
#include <numeric>
#include <cassert>

/**
 * Missing Number (LeetCode 268)
 * Demonstrates:
 * 1. Mathematical Sum Formula - O(N) Time, O(1) Space
 * 2. Bitwise XOR Invariant - O(N) Time, O(1) Space (Zero overflow risk)
 */

class Solution {
public:
    // Approach 1: Mathematical Sum - O(N) Time, O(1) Space
    int missingNumberMath(const std::vector<int>& nums) {
        long long n = nums.size();
        long long expected_sum = n * (n + 1) / 2;
        long long actual_sum = 0;
        for (int x : nums) {
            actual_sum += x;
        }
        return static_cast<int>(expected_sum - actual_sum);
    }

    // Approach 2: Optimal Bitwise XOR - O(N) Time, O(1) Space
    int missingNumberXOR(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        int xor_all = 0;

        for (int i = 0; i <= n; ++i) {
            xor_all ^= i;
        }
        for (int x : nums) {
            xor_all ^= x;
        }

        return xor_all;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {3, 0, 1};
    assert(solver.missingNumberMath(nums1) == 2);
    assert(solver.missingNumberXOR(nums1) == 2);

    std::vector<int> nums2 = {0, 1};
    assert(solver.missingNumberMath(nums2) == 2);
    assert(solver.missingNumberXOR(nums2) == 2);

    std::vector<int> nums3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    assert(solver.missingNumberMath(nums3) == 8);
    assert(solver.missingNumberXOR(nums3) == 8);

    std::cout << "All Missing Number tests passed successfully!" << std::endl;
    return 0;
}

