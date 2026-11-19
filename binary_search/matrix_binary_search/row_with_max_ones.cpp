#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RowWithMaxOnes {
private:
    // Helper to find the first index of 1 in a sorted row via binary search
    int firstOccurrenceOne(const vector<int>& row) {
        int left = 0, right = row.size() - 1;
        int ans = row.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (row[mid] == 1) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }

public:
    // =========================================================================
    // 1. Optimal Saddleback Staircase Search
    // Time Complexity: O(N + M)
    // Space Complexity: O(1)
    // =========================================================================
    int rowWithMax1sOptimal(const vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return -1;
        int m = mat[0].size();

        int maxRow = -1;
        int col = m - 1;

        for (int row = 0; row < n; row++) {
            while (col >= 0 && mat[row][col] == 1) {
                col--;
                maxRow = row; // Found a row with more 1's
            }
        }
        return maxRow;
    }

    // =========================================================================
    // 2. Binary Search Lower Bound on Each Row
    // Time Complexity: O(N * log M)
    // Space Complexity: O(1)
    // =========================================================================
    int rowWithMax1sBinarySearch(const vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return -1;
        int m = mat[0].size();

        int maxOnes = 0;
        int resultRow = -1;

        for (int i = 0; i < n; i++) {
            int firstIdx = firstOccurrenceOne(mat[i]);
            int onesCount = m - firstIdx;
            if (onesCount > maxOnes) {
                maxOnes = onesCount;
                resultRow = i;
            }
        }
        return resultRow;
    }

    // =========================================================================
    // 3. Brute Force Linear Scan
    // Time Complexity: O(N * M)
    // Space Complexity: O(1)
    // =========================================================================
    int rowWithMax1sBrute(const vector<vector<int>>& mat) {
        int n = mat.size();
        if (n == 0) return -1;
        int m = mat[0].size();

        int maxOnes = 0;
        int resultRow = -1;

        for (int i = 0; i < n; i++) {
            int ones = 0;
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 1) ones++;
            }
            if (ones > maxOnes) {
                maxOnes = ones;
                resultRow = i;
            }
        }
        return resultRow;
    }
};

int main() {
    RowWithMaxOnes solver;

    vector<vector<int>> mat1 = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0}
    };
    cout << "Test 1 Optimal (Staircase):    " << solver.rowWithMax1sOptimal(mat1) << " (Expected: 2)\n";
    cout << "Test 1 Binary Search (O(NlogM)): " << solver.rowWithMax1sBinarySearch(mat1) << " (Expected: 2)\n";

    vector<vector<int>> mat2 = {
        {0, 0},
        {0, 0}
    };
    cout << "Test 2 Optimal: " << solver.rowWithMax1sOptimal(mat2) << " (Expected: -1)\n";

    return 0;
}

