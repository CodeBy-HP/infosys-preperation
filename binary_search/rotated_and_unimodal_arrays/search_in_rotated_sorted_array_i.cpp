#include <iostream>
#include <vector>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Check if left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1; // Target lies inside sorted left half
                } else {
                    left = mid + 1;
                }
            } 
            // Otherwise, right half must be sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1; // Target lies inside sorted right half
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << "search([4,5,6,7,0,1,2], 0): " << sol.search(nums, 0) << " (Expected: 4)\n";
    std::cout << "search([4,5,6,7,0,1,2], 3): " << sol.search(nums, 3) << " (Expected: -1)\n";

    return 0;
}
