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


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int low = 0, high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            bool sameAsLeft = (mid > 0 && nums[mid] == nums[mid - 1]);
            bool sameAsRight = (mid < n - 1 && nums[mid] == nums[mid + 1]);

            // Neither neighbor matches -> found the single element
            if (!sameAsLeft && !sameAsRight) {
                return nums[mid];
            }

            // O(1) replacement for lower_bound: starting index of this pair
            int firstIdx = sameAsLeft ? mid - 1 : mid;

            if (firstIdx % 2 == 0) {
                low = mid + 1;  // Still (even, odd) -> single element is on the right
            } else {
                high = mid - 1; // Shifted to (odd, even) -> single element is on the left
            }
        }

        return -1;
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
