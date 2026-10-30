#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    // Approach 1: Masking with 0x55555555 (1s at bit 0, 2, 4, 6...)
    bool isPowerOfFourMask(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555);
    }

    // Approach 2: Modulo 3 arithmetic (4^k % 3 == 1)
    bool isPowerOfFourModulo(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n % 3 == 1);
    }
};

int main() {
    Solution sol;
    std::cout << std::boolalpha;
    std::cout << "isPowerOfTwo(16): " << sol.isPowerOfTwo(16) << " (Expected: true)\n";
    std::cout << "isPowerOfTwo(18): " << sol.isPowerOfTwo(18) << " (Expected: false)\n";
    std::cout << "isPowerOfTwo(0):  " << sol.isPowerOfTwo(0)  << " (Expected: false)\n";

    std::cout << "isPowerOfFour(16): " << sol.isPowerOfFourMask(16) << " (Expected: true)\n";
    std::cout << "isPowerOfFour(8):  " << sol.isPowerOfFourMask(8)  << " (Expected: false)\n";
    std::cout << "isPowerOfFour(64): " << sol.isPowerOfFourModulo(64) << " (Expected: true)\n";

    return 0;
}
