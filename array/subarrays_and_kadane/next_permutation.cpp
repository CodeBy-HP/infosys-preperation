#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class NextPermutation {
public:
    // =========================================================================
    // 1. Pivot Detection and Suffix Inversion
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: If pivot found, find element just larger than nums[i]
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse suffix after pivot
        reverse(nums.begin() + i + 1, nums.end());
    }
};

int main() {
    NextPermutation solver;

    vector<int> nums1 = {1, 2, 3};
    solver.nextPermutation(nums1);
    cout << "Next Permutation [1, 2, 3]: [ ";
    for (int v : nums1) cout << v << " ";
    cout << "]\n(Expected: [ 1 3 2 ])\n";

    vector<int> nums2 = {3, 2, 1};
    solver.nextPermutation(nums2);
    cout << "Next Permutation [3, 2, 1]: [ ";
    for (int v : nums2) cout << v << " ";
    cout << "]\n(Expected: [ 1 2 3 ])\n";

    return 0;
}
