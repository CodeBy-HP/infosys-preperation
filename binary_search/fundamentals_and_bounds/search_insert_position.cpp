#include <iostream>
#include <vector>

class Solution {
public:
    int searchInsert(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left; // left is the lower bound index
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {1, 3, 5, 6};

    std::cout << "searchInsert([1,3,5,6], 5): " << sol.searchInsert(nums, 5) << " (Expected: 2)\n";
    std::cout << "searchInsert([1,3,5,6], 2): " << sol.searchInsert(nums, 2) << " (Expected: 1)\n";
    std::cout << "searchInsert([1,3,5,6], 7): " << sol.searchInsert(nums, 7) << " (Expected: 4)\n";

    return 0;
}
