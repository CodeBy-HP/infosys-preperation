#include <iostream>
#include <vector>
#include <cassert>
#include <tuple>

/**
 * Chinese Remainder Theorem (CRT)
 * Solves x = a_i (mod m_i) for pairwise coprime moduli using Gauss's construction.
 */

class ChineseRemainderTheorem {
private:
    static std::tuple<long long, long long, long long> extGcd(long long a, long long b) {
        if (b == 0) return {a, 1, 0};
        auto [g, x1, y1] = extGcd(b, a % b);
        long long x = y1;
        long long y = x1 - (a / b) * y1;
        return {g, x, y};
    }

    static long long modInverse(long long a, long long m) {
        auto [g, x, y] = extGcd(a, m);
        if (g != 1) return -1;
        return (x % m + m) % m;
    }

public:
    static long long solve(const std::vector<long long>& a, const std::vector<long long>& m) {
        int k = static_cast<int>(a.size());
        long long M = 1;
        for (long long mod : m) {
            M *= mod;
        }

        long long x = 0;
        for (int i = 0; i < k; ++i) {
            long long M_i = M / m[i];
            long long y_i = modInverse(M_i, m[i]);

            long long term = (a[i] * M_i) % M;
            term = static_cast<long long>((static_cast<__int128>(term) * y_i) % M);

            x = (x + term) % M;
        }

        return (x % M + M) % M;
    }
};

int main() {
    // Test 1: x = 2 mod 3, x = 3 mod 5, x = 2 mod 7 -> x = 23 mod 105
    std::vector<long long> a1 = {2, 3, 2};
    std::vector<long long> m1 = {3, 5, 7};
    long long x1 = ChineseRemainderTheorem::solve(a1, m1);
    std::cout << "Test 1 solution: x = " << x1 << std::endl;
    assert(x1 == 23);
    assert(x1 % 3 == 2);
    assert(x1 % 5 == 3);
    assert(x1 % 7 == 2);

    // Test 2: x = 1 mod 2, x = 2 mod 3 -> x = 5 mod 6
    std::vector<long long> a2 = {1, 2};
    std::vector<long long> m2 = {2, 3};
    long long x2 = ChineseRemainderTheorem::solve(a2, m2);
    assert(x2 == 5);

    std::cout << "All Chinese Remainder Theorem tests passed successfully!" << std::endl;
    return 0;
}

