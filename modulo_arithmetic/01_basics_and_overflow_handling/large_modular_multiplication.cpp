#include <iostream>
#include <cassert>

/**
 * Large Modular Multiplication (64-bit safe)
 * Computes (a * b) % m where a, b, m <= 10^18.
 */

class LargeModMul {
public:
    // Approach 1: Binary Multiplication (Russian Peasant / Double-and-Add) in O(log b)
    static long long multiplyBinary(long long a, long long b, long long m) {
        a %= m;
        b %= m;
        long long res = 0;

        while (b > 0) {
            if (b & 1) {
                res = (res + a) % m;
            }
            a = (a + a) % m;
            b >>= 1;
        }

        return res;
    }

    // Approach 2: __int128 Cast in O(1)
    static long long multiply128(long long a, long long b, long long m) {
        return static_cast<long long>((static_cast<__int128>(a % m) * (b % m)) % m);
    }
};

int main() {
    // Test 1: Numbers that would overflow 64-bit int (10^18 * 10^18)
    long long a = 1000000000000000000LL; // 10^18
    long long b = 1000000000000000000LL; // 10^18
    long long m = 1000000000000000007LL; // 10^18 + 7

    long long ans_binary = LargeModMul::multiplyBinary(a, b, m);
    long long ans_128 = LargeModMul::multiply128(a, b, m);

    std::cout << "Test 1 Binary: " << ans_binary << std::endl;
    std::cout << "Test 1 __int128: " << ans_128 << std::endl;

    assert(ans_binary == ans_128);
    // (10^18 * 10^18) % (10^18 + 7):
    // 10^18 = m - 7 = -7 mod m
    // (-7 * -7) = 49 mod m
    assert(ans_binary == 49);

    // Test 2: Standard values
    assert(LargeModMul::multiplyBinary(7, 6, 11) == 9);
    assert(LargeModMul::multiply128(7, 6, 11) == 9);

    std::cout << "All Large Modular Multiplication tests passed successfully!" << std::endl;
    return 0;
}

