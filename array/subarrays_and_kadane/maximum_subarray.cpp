#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class MaximumSubarray {
public:
    // =========================================================================
    // 1. Kadane's Algorithm
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int maxSubArray(const vector<int>& nums) {
        int maxSum = INT_MIN;
        int currentSum = 0;

        for (int num : nums) {
            currentSum += num;
            maxSum = max(maxSum, currentSum);
            if (currentSum < 0) {
                currentSum = 0; // Reset negative accumulator
            }
        }

        return maxSum;
    }
};

int main() {
    MaximumSubarray solver;

    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max Subarray Sum: " << solver.maxSubArray(nums) << " (Expected: 6)\n";

    return 0;
}
