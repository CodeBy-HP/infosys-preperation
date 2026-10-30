#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaximumProductSubarray {
public:
    // =========================================================================
    // 1. Dual Sign Flip Tracking
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int maxProduct(const vector<int>& nums) {
        int globalMax = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            // Negative number inverts min and max
            if (nums[i] < 0) {
                swap(currMax, currMin);
            }

            currMax = max(nums[i], currMax * nums[i]);
            currMin = min(nums[i], currMin * nums[i]);

            globalMax = max(globalMax, currMax);
        }

        return globalMax;
    }
};

int main() {
    MaximumProductSubarray solver;

    vector<int> nums1 = {2, 3, -2, 4};
    cout << "Max Product 1: " << solver.maxProduct(nums1) << " (Expected: 6)\n";

    vector<int> nums2 = {-2, 3, -4};
    cout << "Max Product 2: " << solver.maxProduct(nums2) << " (Expected: 24)\n";

    return 0;
}
