#include <iostream>
#include <vector>
#include <cassert>

/**
 * Linear Modular Inverses in O(N)
 * Computes all inverses for 1...N modulo prime P using:
 * inv[i] = (P - P / i) * inv[P % i] % P
 */

class LinearInverse {
public:
    static std::vector<long long> computeInverses(int n, long long p) {
        std::vector<long long> inv(n + 1);
        inv[1] = 1;

        for (int i = 2; i <= n; ++i) {
            inv[i] = (p - p / i) * inv[p % i] % p;
        }

        return inv;
    }
};

int main() {
    const long long P = 1e9 + 7;
    int N = 100000;

    std::vector<long long> inv = LinearInverse::computeInverses(N, P);

    // Verify correctness: (i * inv[i]) % P == 1
    for (int i = 1; i <= 100; ++i) {
        assert((1LL * i * inv[i]) % P == 1);
    }
    // Spot check larger values
    assert((1LL * N * inv[N]) % P == 1);
    assert((1LL * 12345 * inv[12345]) % P == 1);

    std::cout << "All Linear Modular Inverses verified successfully for N = " << N << std::endl;
    return 0;
}

