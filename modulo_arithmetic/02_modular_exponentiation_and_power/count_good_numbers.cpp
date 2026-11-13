#include <iostream>
#include <cassert>

/**
 * Count Good Numbers (LeetCode 1922)
 * Computes (5^ceil(n/2) * 4^floor(n/2)) % (10^9 + 7) in O(log n).
 */

class Solution {
private:
    const long long MOD = 1e9 + 7;

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
    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;

        long long ways_even = power(5, even_count);
        long long ways_odd = power(4, odd_count);

        return (ways_even * ways_odd) % MOD;
    }
};

int main() {
    Solution solver;

    // Test 1: n = 1 -> 5
    assert(solver.countGoodNumbers(1) == 5);

    // Test 2: n = 4 -> 400
    assert(solver.countGoodNumbers(4) == 400);

    // Test 3: n = 50 -> 564908303
    assert(solver.countGoodNumbers(50) == 564908303);

    // Test 4: Huge n = 10^15
    long long huge_n = 1000000000000000LL;
    int ans = solver.countGoodNumbers(huge_n);
    std::cout << "Good numbers for n = 10^15: " << ans << std::endl;
    assert(ans >= 0 && ans < 1e9 + 7);

    std::cout << "All Count Good Numbers tests passed successfully!" << std::endl;
    return 0;
}

