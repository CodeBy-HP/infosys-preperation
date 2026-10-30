#include <iostream>

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        for (int i = 0; i < 32; ++i) {
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;

            if (bitC == 1) {
                if (bitA == 0 && bitB == 0) {
                    flips += 1; // Flip either bitA or bitB to 1
                }
            } else {
                // bitC == 0: both bitA and bitB must be 0
                flips += (bitA + bitB); // Each 1 bit requires 1 flip
            }
        }
        return flips;
    }
};

int main() {
    Solution sol;
    std::cout << "minFlips(2, 6, 5): " << sol.minFlips(2, 6, 5) << " (Expected: 3)\n";
    std::cout << "minFlips(4, 2, 7): " << sol.minFlips(4, 2, 7) << " (Expected: 1)\n";
    std::cout << "minFlips(1, 2, 3): " << sol.minFlips(1, 2, 3) << " (Expected: 0)\n";

    return 0;
}
