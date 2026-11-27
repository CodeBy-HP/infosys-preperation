#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long MOD = 1e9 + 7;

public:
    // Approach 1: Linear Rolling DP (for moderate N)
    long long countStringsDP(int n, int m) {
        if (n == 0) return 1;
        // dp[rem][last_digit]
        vector<vector<long long>> dp(m, vector<long long>(3, 0));
        for (int d = 0; d < 3; d++) {
            dp[d % m][d] = 1;
        }

        for (int step = 2; step <= n; step++) {
            vector<vector<long long>> nextDp(m, vector<long long>(3, 0));
            for (int rem = 0; rem < m; rem++) {
                for (int last = 0; last < 3; last++) {
                    if (dp[rem][last] == 0) continue;
                    for (int d = 0; d < 3; d++) {
                        if (last == 0 && d == 0) continue;
                        if (rem == m - 1 && d == 2) continue;
                        int nextRem = (rem * 3 + d) % m;
                        nextDp[nextRem][d] = (nextDp[nextRem][d] + dp[rem][last]) % MOD;
                    }
                }
            }
            dp.swap(nextDp);
        }

        long long ans = 0;
        for (int rem = 0; rem < m; rem++)
            for (int d = 0; d < 3; d++)
                ans = (ans + dp[rem][d]) % MOD;
        return ans;
    }

    // Approach 2: Matrix Exponentiation (handles N up to 10^15)
    long long countStringsMatrix(long long n, int m) {
        if (n == 0) return 1;
        int S = 3 * m;
        using Mat = vector<vector<long long>>;
        auto mul = [&](const Mat& A, const Mat& B) {
            Mat C(S, vector<long long>(S, 0));
            for (int i = 0; i < S; i++)
                for (int k = 0; k < S; k++)
                    if (A[i][k])
                        for (int j = 0; j < S; j++)
                            C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
            return C;
        };

        Mat T(S, vector<long long>(S, 0));
        for (int rem = 0; rem < m; rem++) {
            for (int last = 0; last < 3; last++) {
                int u = rem * 3 + last;
                for (int d = 0; d < 3; d++) {
                    if (last == 0 && d == 0) continue;
                    if (rem == m - 1 && d == 2) continue;
                    int nextRem = (rem * 3 + d) % m;
                    int v = nextRem * 3 + d;
                    T[u][v] = (T[u][v] + 1) % MOD;
                }
            }
        }

        Mat res(S, vector<long long>(S, 0));
        for (int i = 0; i < S; i++) res[i][i] = 1;

        long long p = n - 1;
        while (p > 0) {
            if (p & 1) res = mul(res, T);
            T = mul(T, T);
            p >>= 1;
        }

        vector<long long> init(S, 0);
        for (int d = 0; d < 3; d++) {
            init[(d % m) * 3 + d] = 1;
        }

        long long total = 0;
        for (int u = 0; u < S; u++) {
            if (init[u] == 0) continue;
            for (int v = 0; v < S; v++) {
                total = (total + init[u] * res[u][v]) % MOD;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    assert(sol.countStringsDP(1, 4) == 3);
    assert(sol.countStringsDP(2, 3) == 7);
    assert(sol.countStringsMatrix(2, 3) == 7);
    assert(sol.countStringsDP(10, 5) == sol.countStringsMatrix(10, 5));
    cout << "03_mod_state_digit_dp passed all tests!\n";
    return 0;
}
