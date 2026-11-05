#include <iostream>
#include <vector>
#include <cassert>

/**
 * Lucas' Theorem
 * Computes nCr % p for huge n, r <= 10^18 and small prime p <= 10^5.
 */

class LucasTheorem {
private:
    int p;
    std::vector<long long> fact;
    std::vector<long long> invFact;

    long long power(long long base, long long exp) {
        base %= p;
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % p;
            base = (base * base) % p;
            exp >>= 1;
        }
        return res;
    }

    long long small_nCr(int n, int r) const {
        if (r < 0 || r > n) return 0;
        return fact[n] * invFact[r] % p * invFact[n - r] % p;
    }

public:
    LucasTheorem(int prime) : p(prime), fact(prime), invFact(prime) {
        fact[0] = 1;
        for (int i = 1; i < p; ++i) {
            fact[i] = (fact[i - 1] * i) % p;
        }
        invFact[p - 1] = power(fact[p - 1], p - 2);
        for (int i = p - 2; i >= 0; --i) {
            invFact[i] = (invFact[i + 1] * (i + 1)) % p;
        }
    }

    long long compute(long long n, long long r) const {
        if (r < 0 || r > n) return 0;
        if (r == 0) return 1;

        int n_mod = n % p;
        int r_mod = r % p;

        if (r_mod > n_mod) return 0;

        return (compute(n / p, r / p) * small_nCr(n_mod, r_mod)) % p;
    }
};

int main() {
    int p = 13;
    LucasTheorem lucas(p);

    // Test 1: Small values 5C2 % 13 = 10 % 13 = 10
    assert(lucas.compute(5, 2) == 10);

    // Test 2: n >= p: 14C3 % 13
    // 14C3 = (14 * 13 * 12) / 6 = 364
    // 364 = 28 * 13 + 0 -> 364 % 13 == 0!
    assert(lucas.compute(14, 3) == 0);

    // Test 3: Huge values n = 10^18, r = 10^9 mod 13
    long long ans = lucas.compute(1000000000000000000LL, 1000000000LL);
    std::cout << "10^18 C 10^9 mod 13 = " << ans << std::endl;
    assert(ans >= 0 && ans < 13);

    std::cout << "All Lucas' Theorem tests passed successfully!" << std::endl;
    return 0;
}

