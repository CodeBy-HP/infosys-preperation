#include <iostream>
#include <vector>
#include <cassert>

/**
 * N-th Fibonacci Number via Matrix Exponentiation
 * Computes F_N % (10^9 + 7) for N <= 10^18 in O(log N).
 */

class FibonacciMatrix {
private:
    static const long long MOD = 1e9 + 7;
    using Matrix = std::vector<std::vector<long long>>;

    static Matrix multiply(const Matrix& A, const Matrix& B) {
        Matrix C(2, std::vector<long long>(2, 0));
        for (int i = 0; i < 2; ++i) {
            for (int k = 0; k < 2; ++k) {
                for (int j = 0; j < 2; ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    static Matrix power(Matrix A, long long p) {
        Matrix res = {{1, 0}, {0, 1}}; // Identity matrix
        while (p > 0) {
            if (p & 1) res = multiply(res, A);
            A = multiply(A, A);
            p >>= 1;
        }
        return res;
    }

public:
    static long long getFibonacci(long long n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        Matrix T = {{1, 1}, {1, 0}};
        Matrix Tn = power(T, n - 1);

        // F_n = Tn[0][0] * F_1 + Tn[0][1] * F_0 = Tn[0][0] * 1 + 0
        return Tn[0][0];
    }
};

int main() {
    // Test 1: First 10 Fibonacci numbers
    // 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
    assert(FibonacciMatrix::getFibonacci(0) == 0);
    assert(FibonacciMatrix::getFibonacci(1) == 1);
    assert(FibonacciMatrix::getFibonacci(2) == 1);
    assert(FibonacciMatrix::getFibonacci(3) == 2);
    assert(FibonacciMatrix::getFibonacci(4) == 3);
    assert(FibonacciMatrix::getFibonacci(5) == 5);
    assert(FibonacciMatrix::getFibonacci(10) == 55);

    // Test 2: Huge N = 10^18
    long long huge_n = 1000000000000000000LL;
    long long ans = FibonacciMatrix::getFibonacci(huge_n);
    std::cout << "F(10^18) % (10^9 + 7) = " << ans << std::endl;
    assert(ans >= 0 && ans < 1e9 + 7);

    std::cout << "All Fibonacci Matrix Exponentiation tests passed successfully!" << std::endl;
    return 0;
}

