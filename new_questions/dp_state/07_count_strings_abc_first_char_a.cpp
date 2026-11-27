#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class Solution {
    static constexpr long long MOD = 1e9 + 7;

public:
    // Variant 1: First char must be 'a', at most 1 'b' and at most 2 'c's
    long long countStringsRestrictedCounts(long long n) {
        if (n <= 0) return 0;
        long long m = n - 1; // Remaining positions after fixing first char = 'a'
        long long inv2 = (MOD + 1) / 2;

        // 0b, 0c -> 1
        long long ans = 1;
        // 0b, 1c -> m
        ans = (ans + m) % MOD;
        // 1b, 0c -> m
        ans = (ans + m) % MOD;
        // 0b, 2c -> m*(m-1)/2
        if (m >= 2) {
            long long term = (m % MOD) * ((m - 1) % MOD) % MOD * inv2 % MOD;
            ans = (ans + term) % MOD;
            // 1b, 1c -> m*(m-1)
            long long term2 = (m % MOD) * ((m - 1) % MOD) % MOD;
            ans = (ans + term2) % MOD;
        }
        // 1b, 2c -> m*(m-1)*(m-2)/2
        if (m >= 3) {
            long long term3 = (m % MOD) * ((m - 1) % MOD) % MOD * ((m - 2) % MOD) % MOD * inv2 % MOD;
            ans = (ans + term3) % MOD;
        }
        return ans;
    }

    // Variant 2: First char must be 'a', no "cc" and no "bc"
    long long countStringsAdjacencyRules(int n) {
        if (n <= 0) return 0;
        // States: ending in a, b, c
        long long a = 1, b = 0, c = 0; // Length 1 fixed to 'a'

        for (int i = 2; i <= n; i++) {
            long long na = (a + b + c) % MOD;
            long long nb = (a + b + c) % MOD;
            long long nc = a % MOD; // cannot follow 'b' or 'c'
            a = na; b = nb; c = nc;
        }
        return (a + b + c) % MOD;
    }
};

int main() {
    Solution sol;
    assert(sol.countStringsRestrictedCounts(1) == 1);
    assert(sol.countStringsRestrictedCounts(3) == 8);
    assert(sol.countStringsAdjacencyRules(1) == 1);
    assert(sol.countStringsAdjacencyRules(3) == 7);
    cout << "07_count_strings_abc_first_char_a passed all tests!\n";
    return 0;
}
