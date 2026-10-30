#include <iostream>
#include <vector>

class Solution {
public:
    // Approach 1: Finite State Machine (ones, twos)
    int singleNumberFSM(const std::vector<int>& nums) {
        int ones = 0, twos = 0;
        for (int num : nums) {
            ones = (ones ^ num) & ~twos;
            twos = (twos ^ num) & ~ones;
        }
        return ones;
    }

    // Approach 2: Bit counting modulo 3
    int singleNumberBitSum(const std::vector<int>& nums) {
        int result = 0;
        for (int b = 0; b < 32; ++b) {
            int bitCount = 0;
            for (int num : nums) {
                if ((num >> b) & 1) {
                    bitCount++;
                }
            }
            if (bitCount % 3 != 0) {
                result |= (1U << b);
            }
        }
        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {2, 2, 3, 2};
    std::vector<int> nums2 = {0, 1, 0, 1, 0, 1, 99};

    std::cout << "Test 1 [2, 2, 3, 2]: " << sol.singleNumberFSM(nums1) 
              << " (Expected: 3)\n";
    std::cout << "Test 2 [0, 1, ... 99]: " << sol.singleNumberBitSum(nums2) 
              << " (Expected: 99)\n";

    return 0;
}
