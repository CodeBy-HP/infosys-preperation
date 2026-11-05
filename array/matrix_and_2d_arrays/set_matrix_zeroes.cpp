#include <iostream>
#include <vector>

using namespace std;

class SetMatrixZeroes {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        bool firstRowZero = false;
        bool firstColZero = false;

        // 1. Check if first column has any zeros
        for (int r = 0; r < n; r++) {
            if (matrix[r][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // 2. Check if first row has any zeros
        for (int c = 0; c < m; c++) {
            if (matrix[0][c] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // 3. Traverse the inner matrix and use first row/col as flags
        for (int r = 1; r < n; r++) {
            for (int c = 1; c < m; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // 4. Zero out inner matrix based on flags
        for (int r = 1; r < n; r++) {
            for (int c = 1; c < m; c++) {
                if (matrix[r][0] == 0 || matrix[0][c] == 0) {
                    matrix[r][c] = 0;
                }
            }
        }

        // 5. Zero out the first row if needed
        if (firstRowZero) {
            for (int c = 0; c < m; c++) {
                matrix[0][c] = 0;
            }
        }

        // 6. Zero out the first column if needed
        if (firstColZero) {
            for (int r = 0; r < n; r++) {
                matrix[r][0] = 0;
            }
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