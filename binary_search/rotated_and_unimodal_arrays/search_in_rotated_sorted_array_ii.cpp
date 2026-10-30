#include <iostream>
#include <vector>

class Solution {
public:
    bool search(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // Ambiguity case: cannot determine which half is sorted
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                ++left;
                --right;
            }
            // Left half is sorted
            else if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha;
    std::vector<int> nums1 = {2, 5, 6, 0, 0, 1, 2};
    std::cout << "search([2,5,6,0,0,1,2], 0): " << sol.search(nums1, 0) << " (Expected: true)\n";

    std::vector<int> nums2 = {1, 0, 1, 1, 1};
    std::cout << "search([1,0,1,1,1], 0):     " << sol.search(nums2, 0) << " (Expected: true)\n";
    std::cout << "search([1,0,1,1,1], 2):     " << sol.search(nums2, 2) << " (Expected: false)\n";

    return 0;
}
