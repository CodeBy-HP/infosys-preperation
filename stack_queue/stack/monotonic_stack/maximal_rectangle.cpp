#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class MaximalRectangle {
private:
    // Helper: Largest Rectangle in Histogram (LeetCode 84) using Monotonic Stack
    int largestRectangleArea(const vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // stores indices of non-decreasing heights
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];
            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * width);
            }
            st.push(i);
        }
        return maxArea;
    }

public:
    // =========================================================================
    // 1. Optimal: Rolling Histogram + Monotonic Stack
    // Time Complexity: O(R * C)
    // Space Complexity: O(C) for the heights array
    // =========================================================================
    int maximalRectangleOptimal(const vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> heights(cols, 0);
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1') {
                    heights[c] += 1;
                } else {
                    heights[c] = 0;
                }
            }
            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }

    // =========================================================================
    // 2. Dynamic Programming with Left, Right, Height bounds
    // Time Complexity: O(R * C)
    // Space Complexity: O(C)
    // =========================================================================
    int maximalRectangleDP(const vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<int> left(cols, 0);
        vector<int> right(cols, cols);
        vector<int> height(cols, 0);
        int maxArea = 0;

        for (int r = 0; r < rows; r++) {
            int curLeft = 0, curRight = cols;

            // Update height
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1') height[c]++;
                else height[c] = 0;
            }

            // Update left boundary
            for (int c = 0; c < cols; c++) {
                if (matrix[r][c] == '1') {
                    left[c] = max(left[c], curLeft);
                } else {
                    left[c] = 0;
                    curLeft = c + 1;
                }
            }

            // Update right boundary
            for (int c = cols - 1; c >= 0; c--) {
                if (matrix[r][c] == '1') {
                    right[c] = min(right[c], curRight);
                } else {
                    right[c] = cols;
                    curRight = c;
                }
            }

            // Compute area
            for (int c = 0; c < cols; c++) {
                maxArea = max(maxArea, height[c] * (right[c] - left[c]));
            }
        }

        return maxArea;
    }
};

int main() {
    MaximalRectangle solver;

    vector<vector<char>> matrix1 = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << "Test 1 Optimal (Stack): " << solver.maximalRectangleOptimal(matrix1) << " (Expected: 6)\n";
    cout << "Test 1 DP:              " << solver.maximalRectangleDP(matrix1) << " (Expected: 6)\n";

    vector<vector<char>> matrix2 = {{'0'}};
    cout << "Test 2 Optimal: " << solver.maximalRectangleOptimal(matrix2) << " (Expected: 0)\n";

    vector<vector<char>> matrix3 = {{'1'}};
    cout << "Test 3 Optimal: " << solver.maximalRectangleOptimal(matrix3) << " (Expected: 1)\n";

    return 0;
}

