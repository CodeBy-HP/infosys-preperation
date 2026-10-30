#include <iostream>
#include <vector>

using namespace std;

class SetMatrixZeroes {
public:
    // =========================================================================
    // 1. In-Place 1st Row & 1st Col Flagging
    // Time Complexity: O(M * N)
    // Space Complexity: O(1)
    // =========================================================================
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        bool firstColZero = false;

        // Step 1: Record zero flags in 1st row and 1st column
        for (int r = 0; r < m; r++) {
            if (matrix[r][0] == 0) firstColZero = true;
            for (int c = 1; c < n; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // Step 2: Use flags to set inner cells to zero
        for (int r = 1; r < m; r++) {
            for (int c = 1; c < n; c++) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Step 3: Zero first row if flagged
        if (matrix[0][0] == 0) {
            for (int c = 0; c < n; c++) matrix[0][c] = 0;
        }

        // Step 4: Zero first column if flagged
        if (firstColZero) {
            for (int r = 0; r < m; r++) matrix[r][0] = 0;
        }
    }
};

int main() {
    SetMatrixZeroes solver;

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    solver.setZeroes(matrix);
    cout << "Matrix after Set Zeroes:\n";
    for (const auto& row : matrix) {
        cout << "  [ ";
        for (int v : row) cout << v << " ";
        cout << "]\n";
    }

    return 0;
}
