#include <iostream>
#include <vector>
#include <cassert>

/**
 * Precomputing nCr modulo Prime in O(N + log P) precomputation and O(1) query.
 */

class Combinatorics {
private:
    const long long MOD;
    int max_n;
    std::vector<long long> fact;
    std::vector<long long> invFact;

    long long power(long long base, long long exp) {
        base %= MOD;
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }

public:
    Combinatorics(int n, long long mod = 1e9 + 7) : MOD(mod), max_n(n), fact(n + 1), invFact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) {
            fact[i] = (fact[i - 1] * i) % MOD;
        }

        // Backward sweep for inverse factorials
        invFact[n] = power(fact[n], MOD - 2);
        for (int i = n - 1; i >= 0; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
        }
    }

    long long nCr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
    }

    long long nPr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[n - r] % MOD;
    }
};

int main() {
    Combinatorics C(1000000);

    // Test 1: 5C2 = 10
    assert(C.nCr(5, 2) == 10);

    // Test 2: 5C0 = 1, 5C5 = 1
    assert(C.nCr(5, 0) == 1);
    assert(C.nCr(5, 5) == 1);

    // Test 3: r > n -> 0
    assert(C.nCr(5, 6) == 0);

    // Test 4: Large query 1000000 C 500000 mod 10^9+7
    long long large_comb = C.nCr(1000000, 500000);
    std::cout << "1000000 C 500000 mod 10^9+7 = " << large_comb << std::endl;
    assert(large_comb >= 0 && large_comb < 1e9 + 7);

    std::cout << "All nCr Modulo Prime tests passed successfully!" << std::endl;
    return 0;
}

