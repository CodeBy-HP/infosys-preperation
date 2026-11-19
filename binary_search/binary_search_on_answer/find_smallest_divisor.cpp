#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SmallestDivisor {
private:
    // Helper to compute sum of ceilings using integer arithmetic
    long long computeSum(const vector<int>& nums, int divisor) {
        long long sum = 0;
        for (int num : nums) {
            sum += (num + divisor - 1) / divisor;
        }
        return sum;
    }

public:
    // =========================================================================
    // 1. Optimal Binary Search on Answer Space
    // Time Complexity: O(N * log(max(nums)))
    // Space Complexity: O(1)
    // =========================================================================
    int smallestDivisorOptimal(const vector<int>& nums, int threshold) {
        int left = 1;
        int right = *max_element(nums.begin(), nums.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (computeSum(nums, mid) <= threshold) {
                ans = mid;        // Feasible, attempt smaller divisor
                right = mid - 1;
            } else {
                left = mid + 1;   // Sum exceeded threshold, increase divisor
            }
        }
        return ans;
    }

    // =========================================================================
    // 2. Linear Scan (Brute Force baseline)
    // Time Complexity: O(N * max(nums))
    // Space Complexity: O(1)
    // =========================================================================
    int smallestDivisorLinear(const vector<int>& nums, int threshold) {
        int maxVal = *max_element(nums.begin(), nums.end());
        for (int d = 1; d <= maxVal; d++) {
            if (computeSum(nums, d) <= threshold) {
                return d;
            }
        }
        return maxVal;
    }
};

int main() {
    SmallestDivisor solver;

    vector<int> nums1 = {1, 2, 5, 9};
    int threshold1 = 6;
    cout << "Test 1 Optimal: " << solver.smallestDivisorOptimal(nums1, threshold1) << " (Expected: 5)\n";
    cout << "Test 1 Linear:  " << solver.smallestDivisorLinear(nums1, threshold1) << " (Expected: 5)\n";

    vector<int> nums2 = {44, 22, 33, 11, 1};
    int threshold2 = 5;
    cout << "Test 2 Optimal: " << solver.smallestDivisorOptimal(nums2, threshold2) << " (Expected: 44)\n";

    return 0;
}

