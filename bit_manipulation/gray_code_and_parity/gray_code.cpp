#include <iostream>
#include <vector>

class Solution {
public:
    // Approach 1: Direct formula G(i) = i ^ (i >> 1)
    std::vector<int> grayCode(int n) {
        int total = 1 << n;
        std::vector<int> result;
        result.reserve(total);

        for (int i = 0; i < total; ++i) {
            result.push_back(i ^ (i >> 1));
        }

        return result;
    }

    // Gray code to binary inversion
    int grayToBinary(int g) {
        int b = 0;
        for (; g > 0; g >>= 1) {
            b ^= g;
        }
        return b;
    }

    // LeetCode 1238: Circular permutation starting at 'start'
    std::vector<int> circularPermutation(int n, int start) {
        int total = 1 << n;
        std::vector<int> result;
        result.reserve(total);

        for (int i = 0; i < total; ++i) {
            result.push_back(start ^ (i ^ (i >> 1)));
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<int> gc = sol.grayCode(2);
    std::cout << "grayCode(2): [ ";
    for (int x : gc) std::cout << x << " ";
    std::cout << "]\n(Expected: [ 0 1 3 2 ])\n";

    // Test Gray to Binary inversion
    std::cout << "grayToBinary(3): " << sol.grayToBinary(3) << " (Expected: 2)\n";

    // Circular permutation
    std::vector<int> cp = sol.circularPermutation(3, 2);
    std::cout << "circularPermutation(n=3, start=2): [ ";
    for (int x : cp) std::cout << x << " ";
    std::cout << "]\n(Starts at 2, each adjacent differs by 1 bit)\n";

    return 0;
}
