#include <iostream>
#include <cstdint>

class Solution {
public:
    // Brian Kernighan's Algorithm: O(number of 1s)
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n > 0) {
            n &= (n - 1); // Clears the lowest set bit
            ++count;
        }
        return count;
    }

    // Built-in GCC/Clang intrinsic
    int hammingWeightBuiltin(uint32_t n) {
        return __builtin_popcount(n);
    }
};

int main() {
    Solution sol;
    uint32_t n1 = 11; // 1011 in binary -> 3
    uint32_t n2 = 128; // 10000000 -> 1
    uint32_t n3 = 2147483645; // 30 bits set

    std::cout << "hammingWeight(11):         " << sol.hammingWeight(n1) << " (Expected: 3)\n";
    std::cout << "hammingWeight(128):        " << sol.hammingWeight(n2) << " (Expected: 1)\n";
    std::cout << "hammingWeight(2147483645): " << sol.hammingWeight(n3) << " (Expected: 30)\n";
    std::cout << "Builtin popcount(11):      " << sol.hammingWeightBuiltin(n1) << " (Expected: 3)\n";

    return 0;
}
