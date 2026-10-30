#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int r = mid / n;
            int c = mid % n;
            int val = matrix[r][c];

            if (val == target) {
                return true;
            } else if (val < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {1,  3,  5,  7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    std::cout << std::boolalpha;
    std::cout << "searchMatrix(matrix, 3):  " << sol.searchMatrix(matrix, 3) << " (Expected: true)\n";
    std::cout << "searchMatrix(matrix, 13): " << sol.searchMatrix(matrix, 13) << " (Expected: false)\n";

    return 0;
}
