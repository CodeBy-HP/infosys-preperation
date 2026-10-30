#include <iostream>

class Solution {
public:
    // Approach 1: Finding common binary prefix via right shifts
    int rangeBitwiseAndShift(int left, int right) {
        int shiftCount = 0;
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shiftCount++;
        }
        return left << shiftCount;
    }

    // Approach 2: Clear lowest set bits of right until right <= left
    int rangeBitwiseAndKernighan(int left, int right) {
        while (right > left) {
            right &= (right - 1);
        }
        return right;
    }
};

int main() {
    Solution sol;
    std::cout << "rangeBitwiseAnd(5, 7):     " << sol.rangeBitwiseAndShift(5, 7) << " (Expected: 4)\n";
    std::cout << "rangeBitwiseAnd(0, 0):     " << sol.rangeBitwiseAndShift(0, 0) << " (Expected: 0)\n";
    std::cout << "rangeBitwiseAnd(1, 2147483647): " << sol.rangeBitwiseAndKernighan(1, 2147483647) << " (Expected: 0)\n";
    std::cout << "rangeBitwiseAnd(9, 12):    " << sol.rangeBitwiseAndKernighan(9, 12) << " (Expected: 8)\n";

    return 0;
}
