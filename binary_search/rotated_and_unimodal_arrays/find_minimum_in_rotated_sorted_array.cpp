#include <iostream>
#include <vector>

class Solution {
public:
    int findMin(const std::vector<int>& nums) {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] > nums[right]) {
                // Minimum must be in the right un-sorted portion
                left = mid + 1;
            } else {
                // Minimum is at mid or in the left portion
                right = mid;
            }
        }

        return nums[left];
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {3, 4, 5, 1, 2};
    std::cout << "findMin([3,4,5,1,2]):       " << sol.findMin(nums1) << " (Expected: 1)\n";

    std::vector<int> nums2 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << "findMin([4,5,6,7,0,1,2]):   " << sol.findMin(nums2) << " (Expected: 0)\n";

    std::vector<int> nums3 = {11, 13, 15, 17};
    std::cout << "findMin([11,13,15,17]):     " << sol.findMin(nums3) << " (Expected: 11)\n";

    return 0;
}
