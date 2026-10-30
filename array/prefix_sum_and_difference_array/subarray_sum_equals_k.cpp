#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class SubarraySumEqualsK {
public:
    // =========================================================================
    // 1. Prefix Sum Hash Map
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    // =========================================================================
    int subarraySum(const vector<int>& nums, int k) {
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // Base case: prefix sum of empty subarray is 0

        int currentSum = 0;
        int totalSubarrays = 0;

        for (int num : nums) {
            currentSum += num;

            if (prefixCount.count(currentSum - k)) {
                totalSubarrays += prefixCount[currentSum - k];
            }

            prefixCount[currentSum]++;
        }

        return totalSubarrays;
    }
};

int main() {
    SubarraySumEqualsK solver;

    vector<int> nums1 = {1, 1, 1};
    cout << "Subarrays summing to 2: " << solver.subarraySum(nums1, 2) << " (Expected: 2)\n";

    vector<int> nums2 = {1, -1, 0};
    cout << "Subarrays summing to 0: " << solver.subarraySum(nums2, 0) << " (Expected: 3)\n";

    return 0;
}
