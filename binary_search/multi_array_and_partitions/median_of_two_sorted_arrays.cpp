#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <iomanip>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        // Ensure nums1 is the shorter array to achieve O(log(min(m, n)))
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int left = 0, right = m;
        int halfLen = (m + n + 1) / 2;

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = halfLen - i;

            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == m) ? INT_MAX : nums1[i];

            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == n) ? INT_MAX : nums2[j];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                // Partition is valid
                if ((m + n) % 2 == 1) {
                    return std::max(maxLeft1, maxLeft2);
                } else {
                    return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
                }
            } else if (maxLeft1 > minRight2) {
                right = i - 1; // i is too large
            } else {
                left = i + 1;  // i is too small
            }
        }

        return 0.0;
    }
};

int main() {
    Solution sol;
    std::cout << std::fixed << std::setprecision(5);

    std::vector<int> a1 = {1, 3}, b1 = {2};
    std::cout << "Median [1,3] and [2]:   " << sol.findMedianSortedArrays(a1, b1) 
              << " (Expected: 2.00000)\n";

    std::vector<int> a2 = {1, 2}, b2 = {3, 4};
    std::cout << "Median [1,2] and [3,4]: " << sol.findMedianSortedArrays(a2, b2) 
              << " (Expected: 2.50000)\n";

    return 0;
}
