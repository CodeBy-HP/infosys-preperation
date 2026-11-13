#include <iostream>
#include <vector>
#include <cassert>

/**
 * Linear Search
 * Includes Standard Linear Search and Sentinel Search.
 */

class Solution {
public:
    // Approach 1: Standard Linear Search - O(N) Time, O(1) Space
    int linearSearch(const std::vector<int>& nums, int target) {
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }

    // Approach 2: Sentinel Linear Search - O(N) Time, O(1) Space
    // Eliminates boundary checks inside the loop
    int sentinelSearch(std::vector<int> nums, int target) {
        int n = static_cast<int>(nums.size());
        if (n == 0) return -1;

        int last = nums[n - 1];
        nums[n - 1] = target; // Set sentinel

        int i = 0;
        while (nums[i] != target) {
            i++;
        }

        nums[n - 1] = last; // Restore original value

        if (i < n - 1 || nums[n - 1] == target) {
            return i;
        }
        return -1;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums = {2, 3, 4, 10, 40};
    assert(solver.linearSearch(nums, 10) == 3);
    assert(solver.sentinelSearch(nums, 10) == 3);

    assert(solver.linearSearch(nums, 6) == -1);
    assert(solver.sentinelSearch(nums, 6) == -1);

    std::cout << "All Linear Search tests passed successfully!" << std::endl;
    return 0;
}

