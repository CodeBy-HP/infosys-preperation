#include <iostream>
#include <cstdint>
#include <bitset>

class Solution {
public:
    // Approach 1: Linear 32-step bit shifting
    uint32_t reverseBitsLoop(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; ++i) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }

    // Approach 2: Divide and Conquer parallel mask swapping (O(1) 5 operations)
    uint32_t reverseBitsFast(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};

int main() {
    Solution sol;
    uint32_t n = 43261596; // 00000010100101000001111010011100

    uint32_t r1 = sol.reverseBitsLoop(n);
    uint32_t r2 = sol.reverseBitsFast(n);

    std::cout << "Original:  " << std::bitset<32>(n) << " (" << n << ")\n";
    std::cout << "Reversed:  " << std::bitset<32>(r1) << " (" << r1 << ")\n";
    std::cout << "Fast Swap: " << std::bitset<32>(r2) << " (" << r2 << ")\n";
    std::cout << "Expected:  964176192\n";

    return 0;
}
