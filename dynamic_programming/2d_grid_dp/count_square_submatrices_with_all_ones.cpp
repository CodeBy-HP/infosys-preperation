#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class CountSquares {
public:
    // Approach 1: 2D Tabulation - O(M * N) Time, O(M * N) Space
    static int countSquares2D(const std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
        int totalSquares = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
                    }
                    totalSquares += dp[i][j];
                }
            }
        }
        return totalSquares;
    }

    // Approach 2: Space-Optimized 1D Vector - O(M * N) Time, O(N) Space
    static int countSquaresOptimized(const std::vector<std::vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        std::vector<int> dp(n, 0);
        int totalSquares = 0;

        for (int i = 0; i < m; ++i) {
            int prevDiag = 0;
            for (int j = 0; j < n; ++j) {
                int temp = dp[j];
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[j] = 1;
                    } else {
                        dp[j] = 1 + std::min({dp[j], dp[j - 1], prevDiag});
                    }
                    totalSquares += dp[j];
                } else {
                    dp[j] = 0;
                }
                prevDiag = temp;
            }
        }
        return totalSquares;
    }
};

int main() {
    std::vector<std::vector<int>> m1 = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    assert(CountSquares::countSquares2D(m1) == 15);
    assert(CountSquares::countSquaresOptimized(m1) == 15);

    std::vector<std::vector<int>> m2 = {
        {1, 0, 1},
        {1, 1, 0},
        {1, 1, 0}
    };
    assert(CountSquares::countSquares2D(m2) == 7);
    assert(CountSquares::countSquaresOptimized(m2) == 7);

    std::cout << "All Count Square Submatrices with All Ones tests passed successfully!\n";
    return 0;
}

