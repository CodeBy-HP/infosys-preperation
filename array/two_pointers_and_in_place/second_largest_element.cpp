#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

/**
 * Second Largest Element in an Array
 * Brute Force vs Better (2-pass) vs Optimal (1-pass).
 */

class Solution {
public:
    // Approach 1: Brute Force (Sorting) - O(N log N) Time, O(1) Space
    int findSecondLargestBrute(std::vector<int> nums) {
        int n = static_cast<int>(nums.size());
        if (n < 2) return -1;
        std::sort(nums.begin(), nums.end());
        int largest = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            if (nums[i] < largest) {
                return nums[i];
            }
        }
        return -1;
    }

    // Approach 2: Better (Two Passes) - O(2N) Time, O(1) Space
    int findSecondLargestBetter(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n < 2) return -1;

        int largest = INT_MIN;
        for (int x : nums) {
            if (x > largest) largest = x;
        }

        int second = INT_MIN;
        for (int x : nums) {
            if (x > second && x < largest) {
                second = x;
            }
        }
        return (second == INT_MIN) ? -1 : second;
    }

    // Approach 3: Optimal (Single Pass) - O(N) Time, O(1) Space
    int findSecondLargestOptimal(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n < 2) return -1;

        int largest = INT_MIN;
        int second = INT_MIN;

        for (int x : nums) {
            if (x > largest) {
                second = largest;
                largest = x;
            } else if (x < largest && x > second) {
                second = x;
            }
        }

        return (second == INT_MIN) ? -1 : second;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {1, 2, 4, 7, 7, 5};
    assert(solver.findSecondLargestBrute(nums1) == 5);
    assert(solver.findSecondLargestBetter(nums1) == 5);
    assert(solver.findSecondLargestOptimal(nums1) == 5);

    std::vector<int> nums2 = {10, 10, 10};
    assert(solver.findSecondLargestBrute(nums2) == -1);
    assert(solver.findSecondLargestBetter(nums2) == -1);
    assert(solver.findSecondLargestOptimal(nums2) == -1);

    std::cout << "All Second Largest Element tests passed successfully!" << std::endl;
    return 0;
}

