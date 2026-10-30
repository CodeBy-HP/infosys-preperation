#include <iostream>
#include <vector>

using namespace std;

class SpiralMatrix {
public:
    // =========================================================================
    // 1. 4-Boundary Shrinking
    // Time Complexity: O(M * N)
    // Space Complexity: O(1) auxiliary space
    // =========================================================================
    vector<int> spiralOrder(const vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;

        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;

        while (top <= bottom && left <= right) {
            // 1. Traverse Right
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;

            // 2. Traverse Down
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--;

            // 3. Traverse Left
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--;
            }

            // 4. Traverse Up
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++;
            }
        }

        return result;
    }
};

int main() {
    SpiralMatrix solver;

    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> res = solver.spiralOrder(matrix);
    cout << "Spiral Order: [ ";
    for (int v : res) cout << v << " ";
    cout << "]\n(Expected: [ 1 2 3 6 9 8 7 4 5 ])\n";

    return 0;
}
