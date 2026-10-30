#include <iostream>
#include <climits>
#include <cmath>

class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow edge case: INT_MIN / -1 = INT_MAX + 1 -> overflows 32-bit signed int
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Determine sign of quotient
        bool negative = (dividend < 0) ^ (divisor < 0);

        long long dvd = std::abs((long long)dividend);
        long long dvs = std::abs((long long)divisor);
        long long quotient = 0;

        // Try subtracting divisor * 2^i starting from 31 down to 0
        for (int i = 31; i >= 0; --i) {
            if ((dvd >> i) >= dvs) {
                quotient += (1LL << i);
                dvd -= (dvs << i);
            }
        }

        long long result = negative ? -quotient : quotient;
        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;
        return (int)result;
    }
};

int main() {
    Solution sol;
    std::cout << "divide(10, 3):    " << sol.divide(10, 3) << " (Expected: 3)\n";
    std::cout << "divide(7, -3):    " << sol.divide(7, -3) << " (Expected: -2)\n";
    std::cout << "divide(INT_MIN, -1): " << sol.divide(INT_MIN, -1) << " (Expected: 2147483647)\n";

    return 0;
}
