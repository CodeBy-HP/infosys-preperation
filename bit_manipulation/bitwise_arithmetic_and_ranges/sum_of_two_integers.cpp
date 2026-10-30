#include <iostream>
#include <cstdint>

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            int sumWithoutCarry = a ^ b;
            // Unsigned cast prevents signed integer overflow on negative numbers
            int carry = (uint32_t)(a & b) << 1;
            a = sumWithoutCarry;
            b = carry;
        }
        return a;
    }
};

int main() {
    Solution sol;
    std::cout << "getSum(1, 2):   " << sol.getSum(1, 2) << " (Expected: 3)\n";
    std::cout << "getSum(2, 3):   " << sol.getSum(2, 3) << " (Expected: 5)\n";
    std::cout << "getSum(-5, 8):  " << sol.getSum(-5, 8) << " (Expected: 3)\n";
    std::cout << "getSum(-10, -4): " << sol.getSum(-10, -4) << " (Expected: -14)\n";

    return 0;
}
