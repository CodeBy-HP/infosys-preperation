#include <iostream>
#include <vector>

class Solution {
public:
    // Top-Right Corner Staircase Search: O(m + n)
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int r = 0;
        int c = n - 1;

        while (r < m && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                c--; // Move left: eliminate column c
            } else {
                r++; // Move down: eliminate row r
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {1,   4,  7, 11, 15},
        {2,   5,  8, 12, 19},
        {3,   6,  9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    std::cout << std::boolalpha;
    std::cout << "searchMatrix(target=5):  " << sol.searchMatrix(matrix, 5) << " (Expected: true)\n";
    std::cout << "searchMatrix(target=20): " << sol.searchMatrix(matrix, 20) << " (Expected: false)\n";

    return 0;
}
