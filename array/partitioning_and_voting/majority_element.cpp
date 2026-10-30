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
        int candidate = nums[0];
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        return candidate;
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
