#include <iostream>
#include <vector>
#include <cassert>

using namespace std;


// Space optimised
long long countValidStrings(int n) {
    if (n <= 0) return 0;
    const long long MOD = 1e9 + 7;

    // Base case for length 1: "0", "1"
    long long end0 = 1;   // ends with '0'
    long long end1 = 1;   // ends with single '1'
    long long end11 = 0;  // ends with "11"
    long long end2 = 0;   // ends with '2' (valid prefix only)

    for (int i = 2; i <= n; ++i) {
        long long next0  = (end1 + end11) % MOD;
        long long next1  = (end0 + end2) % MOD;
        long long next11 = end1;
        long long next2  = (end1 + end11) % MOD;

        end0  = next0;
        end1  = next1;
        end11 = next11;
        end2  = next2;
    }

    // Exclude end2 since a valid string cannot end with '2'
    return (end0 + end1 + end11) % MOD;
}

class Solution {
    static constexpr long long MOD = 1e9 + 7;

public:
    // Space-Optimized Finite-State DP
    int countValidStrings(int n) {
        // State: dp[prev2][prev1], where 3 denotes "no character placed yet"
        long long dp[4][4] = {};
        dp[3][3] = 1;

        for (int i = 0; i < n; i++) {
            long long nextDp[4][4] = {};
            for (int prev2 = 0; prev2 < 4; prev2++) {
                for (int prev1 = 0; prev1 < 4; prev1++) {
                    long long ways = dp[prev2][prev1];
                    if (ways == 0) continue;

                    for (int curr = 0; curr <= 2; curr++) {
                        // If previous char was '2', current char MUST be '1'
                        if (prev1 == 2 && curr != 1) continue;
                        // Rule 1: No "00"
                        if (curr == 0 && prev1 == 0) continue;
                        // Rule 2: No "111"
                        if (curr == 1 && prev1 == 1 && prev2 == 1) continue;
                        // Rule 3: '2' must be preceded by '1' and cannot be at the last index
                        if (curr == 2 && (prev1 != 1 || i == n - 1)) continue;

                        nextDp[prev1][curr] = (nextDp[prev1][curr] + ways) % MOD;
                    }
                }
            }
            for (int r = 0; r < 4; r++)
                for (int c = 0; c < 4; c++)
                    dp[r][c] = nextDp[r][c];
        }

        long long total = 0;
        for (int prev2 = 0; prev2 < 4; prev2++) {
            for (int prev1 = 0; prev1 < 4; prev1++) {
                total = (total + dp[prev2][prev1]) % MOD;
            }
        }
        return total;
    }
};

int main() {
    Solution sol;
    assert(sol.countValidStrings(1) == 2); // "0", "1"
    assert(sol.countValidStrings(2) == 3); // "01", "10", "11"
    assert(sol.countValidStrings(3) == 5); // "010", "011", "101", "110", "121"
    cout << "04_count_strings_012_constrained passed all tests!\n";
    return 0;
}
