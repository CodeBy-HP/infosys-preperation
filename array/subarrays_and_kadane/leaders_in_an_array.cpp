#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cassert>

/**
 * Leaders in an Array (Superior Elements)
 * Brute Force O(N^2) vs Right-to-Left Scan O(N).
 */

class Solution {
public:
    // Approach 1: Brute Force - O(N^2) Time, O(1) Auxiliary Space
    std::vector<int> leadersBrute(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        std::vector<int> leaders;

        for (int i = 0; i < n; ++i) {
            bool is_leader = true;
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    is_leader = false;
                    break;
                }
            }
            if (is_leader) {
                leaders.push_back(nums[i]);
            }
        }
        return leaders;
    }

    // Approach 2: Optimal Right-to-Left Scan - O(N) Time, O(1) Auxiliary Space
    std::vector<int> leadersOptimal(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n == 0) return {};

        std::vector<int> leaders;
        int max_from_right = INT_MIN;

        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] >= max_from_right) {
                leaders.push_back(nums[i]);
                max_from_right = nums[i];
            }
        }

        std::reverse(leaders.begin(), leaders.end());
        return leaders;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {16, 17, 4, 3, 5, 2};
    std::vector<int> expected1 = {17, 5, 2};

    assert(solver.leadersBrute(nums1) == expected1);
    assert(solver.leadersOptimal(nums1) == expected1);

    std::vector<int> nums2 = {1, 2, 3, 4, 0};
    std::vector<int> expected2 = {4, 0};
    assert(solver.leadersOptimal(nums2) == expected2);

    std::cout << "All Leaders in an Array tests passed successfully!" << std::endl;
    return 0;
}

