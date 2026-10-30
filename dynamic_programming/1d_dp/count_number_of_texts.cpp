#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CountNumberOfTexts {
private:
    static const int MOD = 1e9 + 7;

    int getMaxPresses(char ch) const {
        return (ch == '7' || ch == '9') ? 4 : 3;
    }

public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(N)
    // Space Complexity: O(N) [Memo array + Call stack]
    // =========================================================================
    int countTextsMemo(const string& pressedKeys) {
        int n = pressedKeys.size();
        vector<int> memo(n, -1);
        return solveMemo(0, pressedKeys, memo);
    }

private:
    int solveMemo(int ind, const string& s, vector<int>& memo) {
        int n = s.size();
        if (ind == n) return 1;
        if (memo[ind] != -1) return memo[ind];

        int maxPresses = getMaxPresses(s[ind]);
        long long ways = 0;

        for (int k = 0; k < maxPresses; k++) {
            int next_ind = ind + k;
            if (next_ind >= n || s[next_ind] != s[ind]) break;
            ways = (ways + solveMemo(next_ind + 1, s, memo)) % MOD;
        }

        return memo[ind] = ways;
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (Iterative Tabulation)
    // Time Complexity: O(N)
    // Space Complexity: O(N) [DP array]
    // =========================================================================
    int countTextsTabulation(const string& pressedKeys) {
        int n = pressedKeys.size();
        vector<int> dp(n + 1, 0);
        dp[n] = 1; // Base case: 1 valid way for empty suffix

        for (int ind = n - 1; ind >= 0; ind--) {
            int maxPresses = getMaxPresses(pressedKeys[ind]);
            long long ways = 0;

            for (int k = 0; k < maxPresses; k++) {
                int next_ind = ind + k;
                if (next_ind >= n || pressedKeys[next_ind] != pressedKeys[ind]) break;
                ways = (ways + dp[next_ind + 1]) % MOD;
            }

            dp[ind] = ways;
        }

        return dp[0];
    }

    // =========================================================================
    // 3. Space-Optimized Approach (Rolling Window of Size 5)
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    // =========================================================================
    int countTextsSpaceOptimized(const string& pressedKeys) {
        int n = pressedKeys.size();
        // dp[k] stores ways for index (n - k) relative to recent 5 states
        vector<int> dp(5, 0);
        dp[0] = 1; // Base case: empty suffix

        for (int i = 1; i <= n; i++) {
            int maxPresses = getMaxPresses(pressedKeys[i - 1]);
            long long ways = 0;

            for (int len = 1; len <= maxPresses && i - len >= 0; len++) {
                if (pressedKeys[i - len] == pressedKeys[i - 1]) {
                    ways = (ways + dp[len - 1]) % MOD;
                } else {
                    break;
                }
            }

            // Shift states right
            for (int j = 4; j >= 1; j--) {
                dp[j] = dp[j - 1];
            }
            dp[0] = ways;
        }

        return dp[0];
    }
};

int main() {
    CountNumberOfTexts solver;

    string s1 = "22233";
    cout << "Test 1 (\"22233\"):\n";
    cout << "  Memoization:     " << solver.countTextsMemo(s1) << " (Expected: 8)\n";
    cout << "  Tabulation:      " << solver.countTextsTabulation(s1) << " (Expected: 8)\n";
    cout << "  Space-Optimized: " << solver.countTextsSpaceOptimized(s1) << " (Expected: 8)\n";

    return 0;
}

