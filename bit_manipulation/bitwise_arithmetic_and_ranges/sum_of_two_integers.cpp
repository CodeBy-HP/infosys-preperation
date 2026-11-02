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
    int getSum_brute_force(int a, int b) {
        int ans = 0;
        int carry = 0;
        
        for (int i = 0; i < 32; ++i) {
            // Extract the i-th bit of both numbers
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            
            // 1. Calculate the sum bit (1 if an odd number of inputs are 1)
            int currentBit = bitA ^ bitB ^ carry;
            
            // 2. Calculate the next carry (1 if at least two inputs are 1)
            carry = (bitA & bitB) | (bitA & carry) | (bitB & carry);
            
            // 3. If the sum bit is 1, turn on the i-th bit in our answer
            if (currentBit == 1) {
                ans |= (1U << i); // 1U (unsigned) prevents overflow errors on the 31st bit
            }
        }
        
        return ans;
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
