#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class MatrixChainMultiplication {
public:
    // Approach 1: Memoized Recursion - O(N^3) Time, O(N^2) Space
    static int solveMemo(int i, int j, const std::vector<int>& p, std::vector<std::vector<int>>& memo) {
        if (i == j) return 0;
        if (memo[i][j] != -1) return memo[i][j];

        int minCost = 1e9;
        for (int k = i; k < j; ++k) {
            int cost = solveMemo(i, k, p, memo) + 
                       solveMemo(k + 1, j, p, memo) + 
                       p[i - 1] * p[k] * p[j];
            minCost = std::min(minCost, cost);
        }
        return memo[i][j] = minCost;
    }

    static int mcmMemo(const std::vector<int>& p) {
        int n = p.size();
        std::vector<std::vector<int>> memo(n, std::vector<int>(n, -1));
        return solveMemo(1, n - 1, p, memo);
    }

    // Approach 2: Bottom-Up Tabulation - O(N^3) Time, O(N^2) Space
    static int mcmTabulation(const std::vector<int>& p) {
        int n = p.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // len is the chain length
        for (int len = 2; len < n; ++len) {
            for (int i = 1; i < n - len + 1; ++i) {
                int j = i + len - 1;
                dp[i][j] = 1e9;
                for (int k = i; k < j; ++k) {
                    int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                    dp[i][j] = std::min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n - 1];
    }
};

int main() {
    std::vector<int> p1 = {10, 20, 30, 40, 30};
    assert(MatrixChainMultiplication::mcmMemo(p1) == 30000);
    assert(MatrixChainMultiplication::mcmTabulation(p1) == 30000);

    std::vector<int> p2 = {10, 30, 5, 60};
    assert(MatrixChainMultiplication::mcmMemo(p2) == 4500);
    assert(MatrixChainMultiplication::mcmTabulation(p2) == 4500);

    std::cout << "All Matrix Chain Multiplication tests passed successfully!\n";
    return 0;
}

