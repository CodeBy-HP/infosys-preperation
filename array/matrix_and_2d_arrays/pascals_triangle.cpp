#include <iostream>
#include <vector>
#include <cassert>

/**
 * Pascal's Triangle I (LeetCode 118)
 * Generates the first numRows of Pascal's Triangle.
 * Time Complexity: O(numRows^2)
 * Space Complexity: O(1) auxiliary space (excluding result)
 */

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> triangle;
        triangle.reserve(numRows);

        for (int i = 0; i < numRows; ++i) {
            std::vector<int> row(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(std::move(row));
        }

        return triangle;
    }
};

int main() {
    Solution solver;

    std::vector<std::vector<int>> expected5 = {
        {1},
        {1, 1},
        {1, 2, 1},
        {1, 3, 3, 1},
        {1, 4, 6, 4, 1}
    };

    assert(solver.generate(5) == expected5);
    assert(solver.generate(1) == std::vector<std::vector<int>>{{1}});

    std::cout << "All Pascal's Triangle I tests passed successfully!" << std::endl;
    return 0;
}

