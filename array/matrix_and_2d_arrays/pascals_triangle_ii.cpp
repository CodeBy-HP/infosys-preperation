#include <iostream>
#include <vector>
#include <cassert>

/**
 * Pascal's Triangle II (LeetCode 119)
 * Backward DP O(K^2) vs Optimal Multiplicative Formula O(K).
 */

class Solution {
public:
    // Approach 1: 1D Backward Sweep DP - O(K^2) Time, O(K) Space
    std::vector<int> getRowDP(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 0);
        row[0] = 1;

        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j >= 1; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }

    // Approach 2: Optimal Combinatorial Progression - O(K) Time, O(1) Auxiliary Space
    std::vector<int> getRowOptimal(int rowIndex) {
        std::vector<int> row(rowIndex + 1);
        row[0] = 1;

        long long val = 1;
        for (int c = 1; c <= rowIndex; ++c) {
            val = val * (rowIndex - c + 1) / c;
            row[c] = static_cast<int>(val);
        }

        return row;
    }
};

int main() {
    Solution solver;

    std::vector<int> expected3 = {1, 3, 3, 1};
    assert(solver.getRowDP(3) == expected3);
    assert(solver.getRowOptimal(3) == expected3);

    std::vector<int> expected0 = {1};
    assert(solver.getRowDP(0) == expected0);
    assert(solver.getRowOptimal(0) == expected0);

    std::vector<int> expected4 = {1, 4, 6, 4, 1};
    assert(solver.getRowOptimal(4) == expected4);

    std::cout << "All Pascal's Triangle II tests passed successfully!" << std::endl;
    return 0;
}

