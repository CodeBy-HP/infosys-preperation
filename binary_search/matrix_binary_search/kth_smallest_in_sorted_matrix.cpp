#include <iostream>
#include <vector>

class Solution {
private:
    int countLessOrEqual(const std::vector<std::vector<int>>& matrix, int mid, int n) {
        int count = 0;
        int r = n - 1;
        int c = 0;

        // Staircase traversal from bottom-left
        while (r >= 0 && c < n) {
            if (matrix[r][c] <= mid) {
                count += (r + 1); // Entire column segment from 0 to r is <= mid
                c++;
            } else {
                r--;
            }
        }

        return count;
    }

public:
    int kthSmallest(const std::vector<std::vector<int>>& matrix, int k) {
        int n = matrix.size();
        int left = matrix[0][0];
        int right = matrix[n - 1][n - 1];

        while (left < right) {
            int mid = left + (right - left) / 2;
            int count = countLessOrEqual(matrix, mid, n);

            if (count < k) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }

        return left;
    }
};

int main() {
    Solution sol;
    std::vector<std::vector<int>> matrix = {
        {1,  5,  9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;

    std::cout << "kthSmallest(matrix, 8): " << sol.kthSmallest(matrix, k) 
              << " (Expected: 13)\n";

    return 0;
}
