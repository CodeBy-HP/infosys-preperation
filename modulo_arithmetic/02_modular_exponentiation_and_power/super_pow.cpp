#include <iostream>
#include <vector>
#include <cassert>

/**
 * Super Pow (LeetCode 372)
 * Calculates a^b % 1337 where b is a large number represented as an array of digits.
 */

class Solution {
private:
    const int MOD = 1337;

    int powMod(int a, int k) {
        a %= MOD;
        int res = 1;
        while (k > 0) {
            if (k & 1) res = (res * a) % MOD;
            a = (a * a) % MOD;
            k >>= 1;
        }
        return res;
    }

public:
    // Approach 1: Horner's Recursive Method
    int superPow(int a, std::vector<int>& b) {
        if (b.empty()) return 1;

        int last_digit = b.back();
        b.pop_back();

        int part1 = powMod(superPow(a, b), 10);
        int part2 = powMod(a, last_digit);

        return (part1 * part2) % MOD;
    }

    // Approach 2: Euler's Totient Theorem Reduction
    // phi(1337) = (7 - 1) * (191 - 1) = 1140
    int superPowEuler(int a, const std::vector<int>& b) {
        const int PHI = 1140;
        int exp = 0;
        for (int digit : b) {
            exp = (exp * 10 + digit) % PHI;
        }
        // If exponent is smaller than phi, handling standard modulo power
        return powMod(a, exp == 0 ? PHI : exp);
    }
};

int main() {
    Solution solver;

    // Test 1: a = 2, b = [3] -> 8
    {
        std::vector<int> b = {3};
        assert(solver.superPow(2, b) == 8);
    }

    // Test 2: a = 2, b = [1, 0] -> 1024
    {
        std::vector<int> b = {1, 0};
        assert(solver.superPow(2, b) == 1024);
    }

    // Test 3: a = 1, b = [4, 3, 3, 8, 5, 2] -> 1
    {
        std::vector<int> b = {4, 3, 3, 8, 5, 2};
        assert(solver.superPow(1, b) == 1);
    }

    // Test 4: a = 2147483647, b = [2, 0, 0]
    {
        std::vector<int> b = {2, 0, 0};
        int ans = solver.superPow(2147483647, b);
        assert(ans >= 0 && ans < 1337);
    }

    std::cout << "All Super Pow tests passed successfully!" << std::endl;
    return 0;
}

