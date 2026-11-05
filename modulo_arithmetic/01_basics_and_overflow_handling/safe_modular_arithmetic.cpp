#include <iostream>
#include <cassert>

/**
 * Safe Modular Arithmetic Wrapper
 * Demonstrates proper handling of negative operands, overflow avoidance,
 * and canonical modular operations.
 */

template <long long MOD>
struct Mint {
    long long val;

    Mint(long long v = 0) {
        val = (v % MOD + MOD) % MOD;
    }

    Mint operator+(const Mint& o) const {
        long long res = val + o.val;
        if (res >= MOD) res -= MOD;
        return Mint(res);
    }

    Mint operator-(const Mint& o) const {
        long long res = val - o.val;
        if (res < 0) res += MOD;
        return Mint(res);
    }

    Mint operator*(const Mint& o) const {
        return Mint((val * o.val) % MOD);
    }

    bool operator==(const Mint& o) const {
        return val == o.val;
    }
};

// Standalone functional utility functions
long long modAdd(long long a, long long b, long long m) {
    long long res = (a % m + b % m);
    if (res >= m) res -= m;
    if (res < 0) res += m;
    return res;
}

long long modSub(long long a, long long b, long long m) {
    long long res = (a % m - b % m);
    if (res < 0) res += m;
    return res;
}

long long modMul(long long a, long long b, long long m) {
    return (1LL * ((a % m + m) % m) * ((b % m + m) % m)) % m;
}

long long modNormalize(long long a, long long m) {
    return ((a % m) + m) % m;
}

int main() {
    const long long MOD = 1e9 + 7;

    // Test 1: Negative Modulo Normalization
    assert(modNormalize(-7, 5) == 3);
    assert(modNormalize(-25, 10) == 5);
    assert(modNormalize(17, 5) == 2);

    // Test 2: Subtraction yielding negative intermediary
    assert(modSub(2, 5, 5) == 2);
    assert(modSub(3, 10, 7) == 0); // 3 - 3 = 0 % 7

    // Test 3: Large Product without 32-bit overflow
    long long a = 1000000000LL;
    long long b = 1000000000LL;
    long long expected_mul = (1LL * a * b) % MOD;
    assert(modMul(a, b, MOD) == expected_mul);

    // Test 4: Mint struct syntax
    using Z = Mint<MOD>;
    Z x(-5);
    Z y(8);
    Z z = x + y; // -5 + 8 = 3
    assert(z.val == 3);

    Z diff = x - y; // -5 - 8 = -13 = MOD - 13
    assert(diff.val == MOD - 13);

    std::cout << "All Safe Modular Arithmetic tests passed successfully!" << std::endl;
    return 0;
}

