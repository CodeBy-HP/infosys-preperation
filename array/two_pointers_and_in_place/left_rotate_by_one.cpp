#include <iostream>
#include <vector>
#include <cassert>

/**
 * Left Rotate Array by One
 * Auxiliary Array vs In-Place Shift.
 */

class Solution {
public:
    // Approach 1: Auxiliary Array - O(N) Time, O(N) Space
    std::vector<int> rotateLeftOneBrute(const std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) return nums;
        std::vector<int> res(n);
        for (int i = 1; i < n; ++i) {
            res[i - 1] = nums[i];
        }
        res[n - 1] = nums[0];
        return res;
    }

    // Approach 2: Optimal In-Place - O(N) Time, O(1) Space
    void rotateLeftOneOptimal(std::vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        if (n <= 1) return;

        int first = nums[0];
        for (int i = 1; i < n; ++i) {
            nums[i - 1] = nums[i];
        }
        nums[n - 1] = first;
    }
};

int main() {
    Solution solver;

    std::vector<int> nums1 = {1, 2, 3, 4, 5};
    std::vector<int> expected1 = {2, 3, 4, 5, 1};

    assert(solver.rotateLeftOneBrute(nums1) == expected1);

    solver.rotateLeftOneOptimal(nums1);
    assert(nums1 == expected1);

    std::cout << "All Left Rotate by One tests passed successfully!" << std::endl;
    return 0;
}

