#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

/**
 * Largest Element in an Array
 * Brute Force (Sorting) vs Optimal (Single-pass linear scan).
 */

class Solution {
public:
    // Approach 1: Brute Force (Sorting) - O(N log N) Time, O(1) Space
    int findLargestBruteForce(std::vector<int> nums) {
        std::sort(nums.begin(), nums.end());
        return nums.back();
    }

    // Approach 2: Optimal (Single-Pass Scan) - O(N) Time, O(1) Space
    int findLargestOptimal(const std::vector<int>& nums) {
        int max_val = nums[0];
        for (size_t i = 1; i < nums.size(); ++i) {
            if (nums[i] > max_val) {
                max_val = nums[i];
            }
        }
        return max_val;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {2, 5, 1, 3, 0};
    assert(solver.findLargestBruteForce(nums1) == 5);
    assert(solver.findLargestOptimal(nums1) == 5);

    std::vector<int> nums2 = {-10, -5, -20, -1};
    assert(solver.findLargestBruteForce(nums2) == -1);
    assert(solver.findLargestOptimal(nums2) == -1);

    std::cout << "All Largest Element tests passed successfully!" << std::endl;
    return 0;
}

