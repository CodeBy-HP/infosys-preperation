#include <iostream>
#include <cassert>
#include <tuple>

/**
 * Modular Multiplicative Inverse
 * Computes a^-1 % m using:
 * 1. Fermat's Little Theorem (for prime moduli)
 * 2. Extended Euclidean Algorithm (for arbitrary coprime moduli)
 */

class ModularInverse {
private:
    static long long power(long long base, long long exp, long long mod) {
        base %= mod;
        long long res = 1;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }

    // Extended Euclidean Algorithm: returns {g, x, y} such that a*x + b*y = g = gcd(a, b)
    static std::tuple<long long, long long, long long> extGcd(long long a, long long b) {
        if (b == 0) {
            return {a, 1, 0};
        }
        auto [g, x1, y1] = extGcd(b, a % b);
        long long x = y1;
        long long y = x1 - (a / b) * y1;
        return {g, x, y};
    }

public:
    // Method 1: Fermat's Little Theorem (requires prime mod)
    static long long inversePrime(long long a, long long p) {
        return power(a, p - 2, p);
    }

    // Method 2: Extended Euclidean Algorithm (works for any coprime mod)
    static long long inverseGeneral(long long a, long long m) {
        auto [g, x, y] = extGcd(a, m);
        if (g != 1) {
            return -1; // Inverse does not exist
        }
        return (x % m + m) % m;
    }
};

int main() {
    // Test 1: Prime modulus 10^9 + 7
    long long MOD = 1e9 + 7;
    long long a = 3;
    long long inv_flt = ModularInverse::inversePrime(a, MOD);
    long long inv_eea = ModularInverse::inverseGeneral(a, MOD);

    assert(inv_flt == inv_eea);
    assert((1LL * a * inv_flt) % MOD == 1);
    std::cout << "3^-1 mod 10^9+7 = " << inv_flt << std::endl;

    // Test 2: Composite modulus m = 10, a = 3 (gcd(3, 10) = 1)
    // 3 * 7 = 21 = 1 mod 10 -> inverse is 7
    assert(ModularInverse::inverseGeneral(3, 10) == 7);

    // Test 3: Non-coprime case m = 10, a = 4 (gcd(4, 10) = 2 != 1)
    assert(ModularInverse::inverseGeneral(4, 10) == -1);

    std::cout << "All Modular Inverse tests passed successfully!" << std::endl;
    return 0;
}

