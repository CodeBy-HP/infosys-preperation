#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CountIntegersWithTargetDigitSum {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + 3D Memoization)
    // Time Complexity: O(|N| * Target * 10)
    // Space Complexity: O(|N| * Target * 2)
    // =========================================================================
    int countNumbersWithSumMemo(const string& N, int target) {
        int len = N.length();
        // memo[idx][sum][tight]
        vector<vector<vector<int>>> memo(len, vector<vector<int>>(target + 1, vector<int>(2, -1)));
        return solveMemo(0, 0, 1, N, target, memo);
    }

private:
    int solveMemo(int idx, int currentSum, int tight, const string& N, int target, vector<vector<vector<int>>>& memo) {
        if (currentSum > target) return 0;
        if (idx == (int)N.length()) {
            return currentSum == target ? 1 : 0;
        }

        if (memo[idx][currentSum][tight] != -1) return memo[idx][currentSum][tight];

        int limit = tight ? (N[idx] - '0') : 9;
        int validNumbers = 0;

        for (int d = 0; d <= limit; d++) {
            int nextTight = tight && (d == limit);
            validNumbers += solveMemo(idx + 1, currentSum + d, nextTight, N, target, memo);
        }

        return memo[idx][currentSum][tight] = validNumbers;
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (3D Tabulation)
    // Time Complexity: O(|N| * Target * 10)
    // Space Complexity: O(|N| * Target * 2)
    // =========================================================================
    int countNumbersWithSumTabulation(const string& N, int target) {
        int len = N.length();
        // dp[idx][currentSum][tight]
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(target + 1, vector<int>(2, 0)));

        // Base case: idx == len, count is 1 if currentSum == target
        dp[len][target][0] = 1;
        dp[len][target][1] = 1;

        for (int idx = len - 1; idx >= 0; idx--) {
            for (int sum = 0; sum <= target; sum++) {
                for (int tight = 0; tight <= 1; tight++) {
                    int limit = tight ? (N[idx] - '0') : 9;
                    int validNumbers = 0;

                    for (int d = 0; d <= limit; d++) {
                        if (sum + d <= target) {
                            int nextTight = tight && (d == limit);
                            validNumbers += dp[idx + 1][sum + d][nextTight];
                        }
                    }

                    dp[idx][sum][tight] = validNumbers;
                }
            }
        }

        return dp[0][0][1];
    }
};

int main() {
    CountIntegersWithTargetDigitSum solver;

    string N = "324";
    int target = 5;
    cout << "Test N = \"324\", target = 5:\n";
    cout << "  Memoization: " << solver.countNumbersWithSumMemo(N, target) << "\n";
    cout << "  Tabulation:  " << solver.countNumbersWithSumTabulation(N, target) << " (Expected: 18)\n";

    return 0;
}

