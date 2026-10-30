#include <iostream>
#include <vector>

class Solution {
public:
    int singleNonDuplicate(const std::vector<int>& nums) {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;
            // Force mid to be even
            if (mid % 2 == 1) {
                mid--;
            }

            // If even mid equals mid + 1, the unique element is to the right
            if (nums[mid] == nums[mid + 1]) {
                left = mid + 2;
            } else {
                right = mid;
            }
        }

        return nums[left];
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    std::cout << "singleNonDuplicate([1,1,2,3,3,4,4,8,8]): " << sol.singleNonDuplicate(nums1) 
              << " (Expected: 2)\n";

    std::vector<int> nums2 = {3, 3, 7, 7, 10, 11, 11};
    std::cout << "singleNonDuplicate([3,3,7,7,10,11,11]): " << sol.singleNonDuplicate(nums2) 
              << " (Expected: 10)\n";

    return 0;
}
