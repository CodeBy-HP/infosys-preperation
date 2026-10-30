#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class RotateImage {
public:
    // =========================================================================
    // 1. Transpose and Reverse Rows
    // Time Complexity: O(N^2)
    // Space Complexity: O(1)
    // =========================================================================
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

int main() {
    RotateImage solver;

    vector<vector<int>> m = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    solver.rotate(m);
    cout << "Rotated Matrix 90 degrees:\n";
    for (const auto& row : m) {
        cout << "  [ ";
        for (int v : row) cout << v << " ";
        cout << "]\n";
    }

    return 0;
}
