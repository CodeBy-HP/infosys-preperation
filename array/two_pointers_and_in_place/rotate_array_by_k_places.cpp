#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * Rotate Array by K Places (Left and Right)
 * Demonstrates:
 * 1. Auxiliary buffer method
 * 2. Optimal 3-step reversal algorithm (O(N) Time, O(1) Space)
 */

class Solution {
private:
    void reverseRange(std::vector<int>& nums, int l, int r) {
        while (l < r) {
            std::swap(nums[l++], nums[r--]);
        }
    }

public:
    // Optimal Left Rotate by K places - O(N) Time, O(1) Space
    void leftRotateOptimal(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) return;
        k %= n;
        if (k == 0) return;

        reverseRange(nums, 0, k - 1);
        reverseRange(nums, k, n - 1);
        reverseRange(nums, 0, n - 1);
    }

    // Optimal Right Rotate by K places (LeetCode 189) - O(N) Time, O(1) Space
    void rightRotateOptimal(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) return;
        k %= n;
        if (k == 0) return;

        reverseRange(nums, 0, n - 1);
        reverseRange(nums, 0, k - 1);
        reverseRange(nums, k, n - 1);
    }

    // Better Left Rotate using Buffer - O(N) Time, O(K) Space
    std::vector<int> leftRotateBuffer(const std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) return nums;
        k %= n;
        std::vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = nums[(i + k) % n];
        }
        return res;
    }
};

int main() {
    Solution solver;

    // Test Left Rotate by k = 2
    std::vector<int> nums1 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> expected_left = {3, 4, 5, 6, 7, 1, 2};
    assert(solver.leftRotateBuffer(nums1, 2) == expected_left);
    solver.leftRotateOptimal(nums1, 2);
    assert(nums1 == expected_left);

    // Test Right Rotate by k = 3
    std::vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7};
    std::vector<int> expected_right = {5, 6, 7, 1, 2, 3, 4};
    solver.rightRotateOptimal(nums2, 3);
    assert(nums2 == expected_right);

    std::cout << "All Rotate Array by K Places tests passed successfully!" << std::endl;
    return 0;
}

