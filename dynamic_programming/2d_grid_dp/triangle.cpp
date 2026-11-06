#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Triangle {
public:
    // Approach 1: Bottom-up 2D Tabulation - O(N^2) Time, O(N^2) Space
    static int minimumTotal2D(const std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        for (int j = 0; j < n; ++j) {
            dp[n - 1][j] = triangle[n - 1][j];
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[i][j] = triangle[i][j] + std::min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }

    // Approach 2: Space-Optimized 1D Vector - O(N^2) Time, O(N) Space
    static int minimumTotalOptimized(const std::vector<std::vector<int>>& triangle) {
        int n = triangle.size();
        std::vector<int> dp = triangle[n - 1];

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                dp[j] = triangle[i][j] + std::min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};

int main() {
    std::vector<std::vector<int>> t1 = {
        {2},
        {3, 4},
        {6, 5, 7},
        {4, 1, 8, 3}
    };
    assert(Triangle::minimumTotal2D(t1) == 11);
    assert(Triangle::minimumTotalOptimized(t1) == 11);

    std::vector<std::vector<int>> t2 = {
        {-10}
    };
    assert(Triangle::minimumTotal2D(t2) == -10);
    assert(Triangle::minimumTotalOptimized(t2) == -10);

    std::cout << "All Triangle tests passed successfully!\n";
    return 0;
}

