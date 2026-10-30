#include <iostream>
#include <vector>

class Solution {
private:
    int findBound(const std::vector<int>& nums, int target, bool isFirst) {
        int left = 0, right = (int)nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ans = mid;
                if (isFirst) {
                    right = mid - 1; // Look left for first position
                } else {
                    left = mid + 1;  // Look right for last position
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

public:
    std::vector<int> searchRange(const std::vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) return {-1, -1};
        int last = findBound(nums, target, false);
        return {first, last};
    }
};

int main() {
    Solution sol;
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};

    std::vector<int> res1 = sol.searchRange(nums, 8);
    std::cout << "searchRange(8): [ " << res1[0] << ", " << res1[1] << " ] (Expected: [ 3, 4 ])\n";

    std::vector<int> res2 = sol.searchRange(nums, 6);
    std::cout << "searchRange(6): [ " << res2[0] << ", " << res2[1] << " ] (Expected: [ -1, -1 ])\n";

    return 0;
}
