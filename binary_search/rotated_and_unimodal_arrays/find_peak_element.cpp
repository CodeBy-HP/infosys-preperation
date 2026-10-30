#include <iostream>
#include <vector>

class Solution {
public:
    int findPeakElement(const std::vector<int>& nums) {
        int left = 0;
        int right = (int)nums.size() - 1;

        while (left < right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] < nums[mid + 1]) {
                // Uphill slope: a peak must exist to the right
                left = mid + 1;
            } else {
                // Downhill slope: mid itself or something to the left is a peak
                right = mid;
            }
        }

        return left;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 2, 3, 1};
    std::cout << "findPeakElement([1,2,3,1]): " << sol.findPeakElement(nums1) 
              << " (Expected: 2)\n";

    std::vector<int> nums2 = {1, 2, 1, 3, 5, 6, 4};
    int peak = sol.findPeakElement(nums2);
    std::cout << "findPeakElement([1,2,1,3,5,6,4]): " << peak 
              << " (Expected: 1 or 5)\n";

    return 0;
}
