#include <iostream>
#include <vector>

using namespace std;

class MajorityElement {
public:
    // =========================================================================
    // 1. Boyer-Moore Voting Algorithm
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int majorityElement(const vector<int>& nums) {
    // Phase 1: Find a candidate
    int candidate = nums[0];
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
        }
        count += (num == candidate) ? 1 : -1;
    }

    // Phase 2: Verify the candidate
    int actualCount = 0;
    for (int num : nums) {
        if (num == candidate) {
            actualCount++;
        }
    }

    // Check if it actually appears more than N/2 times
    if (actualCount > nums.size() / 2) {
        return candidate;
    } 

    // Return a default value or throw an error if no majority exists
    return -1; 
}
};

int main() {
    MajorityElement solver;

    vector<int> nums1 = {3, 2, 3};
    cout << "Majority Element 1: " << solver.majorityElement(nums1) << " (Expected: 3)\n";

    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    cout << "Majority Element 2: " << solver.majorityElement(nums2) << " (Expected: 2)\n";

    return 0;
}
