#include <iostream>
#include <cassert>

/**
 * Pascal's Triangle III: Element at Row R, Column C (1-indexed)
 * Computes nCr where n = r - 1, k = c - 1 in O(c) time and O(1) space.
 */

class Solution {
public:
    // Optimal nCr approach - O(c) Time, O(1) Space
    long long getPascalElement(int r, int c) {
        int n = r - 1;
        int k = c - 1;

        // Optimization: C(n, k) == C(n, n - k)
        if (k > n - k) {
            k = n - k;
        }

        long long res = 1;
        for (int i = 0; i < k; ++i) {
            res = res * (n - i);
            res = res / (i + 1);
        }

        return res;
    }
};

int main() {
    Solution solver;

    assert(solver.getPascalElement(5, 3) == 6);
    assert(solver.getPascalElement(1, 1) == 1);
    assert(solver.getPascalElement(6, 2) == 5);
    assert(solver.getPascalElement(5, 1) == 1);
    assert(solver.getPascalElement(5, 5) == 1);

    std::cout << "All Pascal's Triangle III tests passed successfully!" << std::endl;
    return 0;
}

