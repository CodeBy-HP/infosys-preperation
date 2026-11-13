#include <iostream>
#include <string>

class Solution {
public:
    long long minBracketBalanceCost(const std::string& s, long long a, long long b) {
        const long long MOD = 1000000007;

        long long balance = 0;
        long long neededOpening = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                if (balance > 0) {
                    balance--; // Matches the most recent unmatched '('
                } else {
                    // Deficit: An opening bracket '(' must be inserted to the left
                    neededOpening++;
                }
            }
        }

        // Remaining unmatched '(' must be closed by inserting ')'
        long long neededClosing = balance;

        long long totalCost = ((neededOpening % MOD) * (a % MOD)) % MOD;
        totalCost = (totalCost + ((neededClosing % MOD) * (b % MOD)) % MOD) % MOD;

        return totalCost;
    }
};

int main() {
    Solution sol;

    std::string s1 = ")()(";
    std::cout << "Test 1 [s=\")()(\", a=3, b=5]: " 
              << sol.minBracketBalanceCost(s1, 3, 5) << " (Expected: 8)\n";

    std::string s2 = "(((";
    std::cout << "Test 2 [s=\"(((\", a=2, b=4]:   " 
              << sol.minBracketBalanceCost(s2, 2, 4) << " (Expected: 12)\n";

    std::string s3 = "()()";
    std::cout << "Test 3 [s=\"()()\", a=10, b=10]: " 
              << sol.minBracketBalanceCost(s3, 10, 10) << " (Expected: 0)\n";

    std::string s4 = "))))";
    std::cout << "Test 4 [s=\"))))\", a=7, b=1]:  " 
              << sol.minBracketBalanceCost(s4, 7, 1) << " (Expected: 28)\n";

    return 0;
}

