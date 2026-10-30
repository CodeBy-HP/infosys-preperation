#include <iostream>
#include <vector>

class Solution {
public:
    int search(const std::vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2; // Prevents integer overflow
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1; // Target not found
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    std::cout << "search([-1,0,3,5,9,12], 9): " << sol.search(nums, 9) << " (Expected: 4)\n";
    std::cout << "search([-1,0,3,5,9,12], 2): " << sol.search(nums, 2) << " (Expected: -1)\n";

    return 0;
}
