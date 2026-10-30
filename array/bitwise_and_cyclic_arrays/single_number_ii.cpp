#include <iostream>
#include <vector>

using namespace std;

class SingleNumberII {
public:
    // =========================================================================
    // 1. Bitwise Sum Modulo 3
    // Time Complexity: O(32 * N) = O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int singleNumber(const vector<int>& nums) {
        int result = 0;

        for (int bit = 0; bit < 32; bit++) {
            int bitCount = 0;
            for (int num : nums) {
                if ((num >> bit) & 1) {
                    bitCount++;
                }
            }
            // If bit count is not a multiple of 3, the unique number has this bit set
            if (bitCount % 3 != 0) {
                result |= (1U << bit);
            }
        }

        return result;
    }
};

int main() {
    SingleNumberII solver;

    vector<int> nums1 = {2, 2, 3, 2};
    cout << "Single Number 1: " << solver.singleNumber(nums1) << " (Expected: 3)\n";

    vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};
    cout << "Single Number 2: " << solver.singleNumber(nums2) << " (Expected: 99)\n";

    return 0;
}
