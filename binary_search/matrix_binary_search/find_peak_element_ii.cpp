#include <iostream>
#include <vector>

using namespace std;

class FindPeakElementII {
private:
    // Helper to find the row index of the maximum element in a given column
    int findMaxRowInColumn(const vector<vector<int>>& mat, int col, int m) {
        int maxRow = 0;
        int maxVal = -1;
        for (int r = 0; r < m; r++) {
            if (mat[r][col] > maxVal) {
                maxVal = mat[r][col];
                maxRow = r;
            }
        }
        return maxRow;
    }

public:
    // =========================================================================
    // 1. Optimal Column-Bisection Binary Search
    // Time Complexity: O(m * log n)
    // Space Complexity: O(1)
    // =========================================================================
    vector<int> findPeakGridOptimal(const vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int leftCol = 0, rightCol = n - 1;

        while (leftCol <= rightCol) {
            int midCol = leftCol + (rightCol - leftCol) / 2;

            // Find the maximum element in midCol
            int maxRow = findMaxRowInColumn(mat, midCol, m);

            int currentVal = mat[maxRow][midCol];
            int leftNeighbor = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
            int rightNeighbor = (midCol + 1 < n) ? mat[maxRow][midCol + 1] : -1;

            if (currentVal > leftNeighbor && currentVal > rightNeighbor) {
                // Since it's the maximum in midCol, it's already > top and bottom neighbors
                return {maxRow, midCol};
            } else if (leftNeighbor > currentVal) {
                // Peak guaranteed to exist in the left columns
                rightCol = midCol - 1;
            } else {
                // Peak guaranteed to exist in the right columns
                leftCol = midCol + 1;
            }
        }

        return {-1, -1};
    }

    // =========================================================================
    // 2. Global Maximum (Brute Force baseline)
    // The absolute maximum in the grid is guaranteed to be a peak
    // Time Complexity: O(m * n)
    // Space Complexity: O(1)
    // =========================================================================
    vector<int> findPeakGridBrute(const vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int maxVal = -1;
        vector<int> peak = {-1, -1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] > maxVal) {
                    maxVal = mat[i][j];
                    peak = {i, j};
                }
            }
        }
        return peak;
    }
};

int main() {
    FindPeakElementII solver;

    vector<vector<int>> mat1 = {
        {1, 4},
        {3, 2}
    };
    auto res1 = solver.findPeakGridOptimal(mat1);
    cout << "Test 1 Peak: [" << res1[0] << ", " << res1[1] << "] (Value: " << mat1[res1[0]][res1[1]] << ")\n";

    vector<vector<int>> mat2 = {
        {10, 20, 15},
        {21, 30, 14},
        {7,  16, 32}
    };
    auto res2 = solver.findPeakGridOptimal(mat2);
    cout << "Test 2 Peak: [" << res2[0] << ", " << res2[1] << "] (Value: " << mat2[res2[0]][res2[1]] << ")\n";

    return 0;
}

