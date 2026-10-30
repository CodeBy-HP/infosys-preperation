#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class ContinuousSubarraySum {
public:
    // =========================================================================
    // 1. Modulo Remainder Hash Map with Earliest Index
    // Time Complexity: O(N)
    // Space Complexity: O(min(N, k))
    // =========================================================================
    bool checkSubarraySum(const vector<int>& nums, int k) {
        unordered_map<int, int> remainderIndex;
        remainderIndex[0] = -1; // Base case: remainder 0 before starting array

        int runningSum = 0;

        for (int i = 0; i < (int)nums.size(); i++) {
            runningSum += nums[i];
            int rem = runningSum % k;

            if (remainderIndex.count(rem)) {
                if (i - remainderIndex[rem] >= 2) {
                    return true;
                }
            } else {
                remainderIndex[rem] = i; // Store only the first occurrence
            }
        }

        return false;
    }
};

int main() {
    ContinuousSubarraySum solver;

    vector<int> nums1 = {23, 2, 4, 6, 7};
    cout << "Test 1: " << (solver.checkSubarraySum(nums1, 6) ? "true" : "false") << " (Expected: true)\n";

    vector<int> nums2 = {23, 2, 6, 4, 7};
    cout << "Test 2: " << (solver.checkSubarraySum(nums2, 13) ? "true" : "false") << " (Expected: false)\n";

    return 0;
}
