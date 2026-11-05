#include <iostream>
#include <cassert>

/**
 * Binary Exponentiation (Fast Power modulo M)
 * Computes (a^b) % m in O(log b) time and O(1) space.
 */

class FastExponentiation {
public:
    static long long power(long long a, long long b, long long m) {
        if (m == 1) return 0;
        a %= m;
        long long res = 1;

        while (b > 0) {
            if (b & 1) {
                res = (1LL * res * a) % m;
            }
            a = (1LL * a * a) % m;
            b >>= 1;
        }

        return res;
    }
};

int main() {
    const long long MOD = 1e9 + 7;

    // Test 1: Small power 2^10 = 1024
    assert(FastExponentiation::power(2, 10, MOD) == 1024);

    // Test 2: Base case b = 0 -> a^0 = 1
    assert(FastExponentiation::power(5, 0, MOD) == 1);

    // Test 3: Modulo 1 -> always 0
    assert(FastExponentiation::power(10, 15, 1) == 0);

    // Test 4: Huge power 3^(10^18) % (10^9 + 7)
    long long huge_exp = 1000000000000000000LL;
    long long ans = FastExponentiation::power(3, huge_exp, MOD);
    std::cout << "3^(10^18) % (10^9 + 7) = " << ans << std::endl;
    assert(ans >= 0 && ans < MOD);

    // Test 5: Standard competitive programming prime test
    // By Fermat's Little Theorem, 2^(MOD - 1) % MOD == 1
    assert(FastExponentiation::power(2, MOD - 1, MOD) == 1);

    std::cout << "All Binary Exponentiation tests passed successfully!" << std::endl;
    return 0;
}

