#include <iostream>
#include <unordered_map>
#include <cmath>
#include <cassert>

/**
 * Baby-Step Giant-Step (BSGS) Algorithm
 * Solves the Discrete Logarithm: a^x = b (mod m) in O(sqrt(m)) time.
 */

class DiscreteLogarithm {
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

public:
    static long long solve(long long a, long long b, long long m) {
        a %= m;
        b %= m;
        if (b == 1) return 0; // a^0 = 1

        long long k = static_cast<long long>(std::ceil(std::sqrt(m)));

        // Step 1: Baby Steps
        // table[ (b * a^j) % m ] = j for j in [0...k-1]
        std::unordered_map<long long, long long> table;
        long long cur = b;
        for (long long j = 0; j < k; ++j) {
            table[cur] = j; // Later values overwrite earlier ones, maximizing j
            cur = (cur * a) % m;
        }

        // Step 2: Giant Steps
        // C = a^k % m
        long long C = power(a, k, m);
        long long giant = 1;

        for (long long i = 1; i <= k; ++i) {
            giant = (giant * C) % m;
            if (table.count(giant)) {
                long long ans = i * k - table[giant];
                return ans;
            }
        }

        return -1; // No solution
    }
};

int main() {
    // Test 1: 2^x = 8 (mod 11) -> x = 3
    assert(DiscreteLogarithm::solve(2, 8, 11) == 3);

    // Test 2: 2^x = 7 (mod 13) -> x = 11
    assert(DiscreteLogarithm::solve(2, 7, 13) == 11);

    // Test 3: Unsolvable case 3^x = 7 (mod 13) -> -1 (powers of 3 mod 13 are only {1, 3, 9})
    assert(DiscreteLogarithm::solve(3, 7, 13) == -1);

    // Test 3: Large prime modulus m = 10^9 + 7
    // 5^x = 5^123456 (mod 10^9 + 7)
    long long mod = 1e9 + 7;
    long long expected_x = 123456;
    // Compute b = 5^expected_x % mod
    long long b = 1;
    long long base = 5;
    long long e = expected_x;
    while (e > 0) {
        if (e & 1) b = (b * base) % mod;
        base = (base * base) % mod;
        e >>= 1;
    }

    long long solved_x = DiscreteLogarithm::solve(5, b, mod);
    std::cout << "5^x = " << b << " (mod 10^9+7), solved x = " << solved_x << std::endl;
    assert(solved_x == expected_x);

    std::cout << "All Baby-Step Giant-Step tests passed successfully!" << std::endl;
    return 0;
}
