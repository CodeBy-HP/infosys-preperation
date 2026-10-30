#include <iostream>
#include <string>
#include <climits>

using namespace std;

class StringToIntegerAtoi {
public:
    // =========================================================================
    // 1. Single-Pass Deterministic State Machine with Overflow Detection
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int myAtoi(const string& s) {
        int i = 0;
        int n = s.size();

        // Step 1: Skip leading whitespace
        while (i < n && s[i] == ' ') i++;
        if (i == n) return 0;

        // Step 2: Handle sign
        int sign = 1;
        if (s[i] == '+' || s[i] == '-') {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits with overflow check
        int result = 0;
        while (i < n && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check overflow before multiplying by 10
            if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return result * sign;
    }
};

int main() {
    StringToIntegerAtoi solver;

    cout << "\"42\":          " << solver.myAtoi("42") << " (Expected: 42)\n";
    cout << "\"   -042\":     " << solver.myAtoi("   -042") << " (Expected: -42)\n";
    cout << "\"1337c0d3\":    " << solver.myAtoi("1337c0d3") << " (Expected: 1337)\n";
    cout << "\"-91283472332\": " << solver.myAtoi("-91283472332") << " (Expected: -2147483648)\n";

    return 0;
}
