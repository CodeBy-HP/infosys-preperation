#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>
#include <cassert>

/**
 * Fraction to Recurring Decimal (LeetCode 166)
 * Simulates modulo long division and detects remainder cycles via hash mapping.
 */

class Solution {
public:
    std::string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        std::string result;

        // Step 1: Sign determination
        if ((numerator < 0) ^ (denominator < 0)) {
            result += "-";
        }

        // Use long long to prevent overflow on INT_MIN (-2147483648)
        long long num = std::abs(static_cast<long long>(numerator));
        long long den = std::abs(static_cast<long long>(denominator));

        // Step 2: Integer part
        result += std::to_string(num / den);
        long long rem = num % den;

        if (rem == 0) {
            return result;
        }

        result += ".";

        // Step 3: Fractional part with remainder cycle detection
        std::unordered_map<long long, int> seen_remainders;

        while (rem != 0) {
            if (seen_remainders.count(rem)) {
                // Repeating remainder cycle found!
                int insert_idx = seen_remainders[rem];
                result.insert(insert_idx, "(");
                result += ")";
                break;
            }

            seen_remainders[rem] = static_cast<int>(result.size());

            rem *= 10;
            result += std::to_string(rem / den);
            rem %= den;
        }

        return result;
    }
};

int main() {
    Solution solver;

    // Test 1: 1 / 2 = 0.5
    assert(solver.fractionToDecimal(1, 2) == "0.5");

    // Test 2: 2 / 1 = 2
    assert(solver.fractionToDecimal(2, 1) == "2");

    // Test 3: 4 / 333 = 0.(012)
    assert(solver.fractionToDecimal(4, 333) == "0.(012)");

    // Test 4: Negative fraction
    assert(solver.fractionToDecimal(-50, 8) == "-6.25");

    // Test 5: INT_MIN edge case
    std::string ans = solver.fractionToDecimal(-1, -2147483648);
    assert(!ans.empty());

    std::cout << "All Fraction to Recurring Decimal tests passed successfully!" << std::endl;
    return 0;
}

