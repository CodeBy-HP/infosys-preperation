#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class MatrixMedian {
private:
    // Helper to count elements <= val across all rows using upper_bound
    int countLessEqual(const vector<vector<int>>& mat, int val) {
        int count = 0;
        for (const auto& row : mat) {
            count += upper_bound(row.begin(), row.end(), val) - row.begin();
        }
        return count;
    }

public:
    // =========================================================================
    // 1. Optimal Binary Search on Value Space
    // Time Complexity: O(R * log C * log(max - min))
    // Space Complexity: O(1)
    // =========================================================================
    int findMedianOptimal(const vector<vector<int>>& mat) {
        int r = mat.size();
        int c = mat[0].size();

        int left = INT_MAX;
        int right = INT_MIN;

        // Initialize range with actual min and max elements
        for (int i = 0; i < r; i++) {
            left = min(left, mat[i][0]);
            right = max(right, mat[i][c - 1]);
        }

        int required = (r * c) / 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int count = countLessEqual(mat, mid);

            if (count <= required) {
                left = mid + 1; // Median must be strictly greater than mid
            } else {
                right = mid - 1; // Candidate found, narrow down
            }
        }
        return left;
    }

    // =========================================================================
    // 2. Flatten and Sort (Brute Force baseline)
    // Time Complexity: O(R * C * log(R * C))
    // Space Complexity: O(R * C)
    // =========================================================================
    int findMedianBrute(const vector<vector<int>>& mat) {
        vector<int> elements;
        for (const auto& row : mat) {
            for (int val : row) {
                elements.push_back(val);
            }
        }
        sort(elements.begin(), elements.end());
        return elements[elements.size() / 2];
    }
};

int main() {
    MatrixMedian solver;

    vector<vector<int>> mat1 = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };
    cout << "Test 1 Optimal: " << solver.findMedianOptimal(mat1) << " (Expected: 5)\n";
    cout << "Test 1 Brute:   " << solver.findMedianBrute(mat1) << " (Expected: 5)\n";

    vector<vector<int>> mat2 = {
        {1, 3, 4},
        {2, 5, 6},
        {7, 8, 9}
    };
    cout << "Test 2 Optimal: " << solver.findMedianOptimal(mat2) << " (Expected: 5)\n";

    return 0;
}

