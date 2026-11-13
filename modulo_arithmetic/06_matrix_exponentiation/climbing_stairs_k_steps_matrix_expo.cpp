#include <iostream>
#include <vector>
#include <cassert>

/**
 * Climbing Stairs with K Steps (General Linear Recurrence via Matrix Exponentiation)
 * Computes dp[N] = sum_{j=1}^K dp[N - j] % (10^9 + 7) for N <= 10^18, K <= 10.
 * Time Complexity: O(K^3 log N)
 * Space Complexity: O(K^2)
 */

class KStepStairs {
private:
    static const long long MOD = 1e9 + 7;
    using Matrix = std::vector<std::vector<long long>>;

    static Matrix multiply(const Matrix& A, const Matrix& B, int K) {
        Matrix C(K, std::vector<long long>(K, 0));
        for (int i = 0; i < K; ++i) {
            for (int m = 0; m < K; ++m) {
                if (A[i][m] == 0) continue;
                for (int j = 0; j < K; ++j) {
                    C[i][j] = (C[i][j] + A[i][m] * B[m][j]) % MOD;
                }
            }
        }
        return C;
    }

    static Matrix power(Matrix A, long long p, int K) {
        Matrix res(K, std::vector<long long>(K, 0));
        for (int i = 0; i < K; ++i) res[i][i] = 1;

        while (p > 0) {
            if (p & 1) res = multiply(res, A, K);
            A = multiply(A, A, K);
            p >>= 1;
        }
        return res;
    }

public:
    static long long waysToClimb(long long N, int K) {
        if (N <= 0) return 1;

        // Base cases using linear DP for first K steps
        std::vector<long long> base(K, 0);
        base[0] = 1; // dp[0] = 1
        for (int i = 1; i < K; ++i) {
            for (int j = 1; j <= i; ++j) {
                base[i] = (base[i] + base[i - j]) % MOD;
            }
        }

        if (N < K) {
            return base[N];
        }

        // Construct K x K companion transition matrix
        Matrix T(K, std::vector<long long>(K, 0));
        for (int j = 0; j < K; ++j) {
            T[0][j] = 1; // First row: sum of previous K states
        }
        for (int i = 1; i < K; ++i) {
            T[i][i - 1] = 1; // Shift identity
        }

        // T^(N - K + 1)
        Matrix Tn = power(T, N - K + 1, K);

        long long ans = 0;
        for (int j = 0; j < K; ++j) {
            ans = (ans + Tn[0][j] * base[K - 1 - j]) % MOD;
        }

        return ans;
    }
};

int main() {
    // Test 1: Standard climbing stairs (K = 2)
    // N = 1: 1, N = 2: 2, N = 3: 3, N = 4: 5, N = 5: 8
    assert(KStepStairs::waysToClimb(1, 2) == 1);
    assert(KStepStairs::waysToClimb(2, 2) == 2);
    assert(KStepStairs::waysToClimb(3, 2) == 3);
    assert(KStepStairs::waysToClimb(4, 2) == 5);
    assert(KStepStairs::waysToClimb(5, 2) == 8);

    // Test 2: K = 3, N = 4 (Tribonacci)
    // dp[0]=1, dp[1]=1, dp[2]=2, dp[3]=4, dp[4] = 4+2+1 = 7
    assert(KStepStairs::waysToClimb(4, 3) == 7);

    // Test 3: Huge N = 10^18, K = 5
    long long ans = KStepStairs::waysToClimb(1000000000000000000LL, 5);
    std::cout << "Ways to climb 10^18 stairs with K=5: " << ans << std::endl;
    assert(ans >= 0 && ans < 1e9 + 7);

    std::cout << "All K-Step Climbing Stairs tests passed successfully!" << std::endl;
    return 0;
}

