#include <iostream>
#include <vector>

using namespace std;

class TwoSumII {
public:
    // =========================================================================
    // 1. Two-Pointer Convergent Scan
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    vector<int> twoSum(const vector<int>& numbers, int target) {
        int left = 0;
        int right = (int)numbers.size() - 1;

        while (left < right) {
            int currentSum = numbers[left] + numbers[right];

            if (currentSum == target) {
                return {left + 1, right + 1}; // 1-indexed
            } else if (currentSum < target) {
                left++;
            } else {
                right--;
            }
        }

        return {};
    }
};

int main() {
    TwoSumII solver;

    vector<int> nums1 = {2, 7, 11, 15};
    vector<int> res1 = solver.twoSum(nums1, 9);
    cout << "Test 1: [" << res1[0] << ", " << res1[1] << "] (Expected: [1, 2])\n";

    vector<int> nums2 = {2, 3, 4};
    vector<int> res2 = solver.twoSum(nums2, 6);
    cout << "Test 2: [" << res2[0] << ", " << res2[1] << "] (Expected: [1, 3])\n";

    return 0;
}
