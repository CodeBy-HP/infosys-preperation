#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class PalindromePartitioningII {
public:
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(N^2)
    // Space Complexity: O(N^2)
    // =========================================================================
    int minCutMemo(const string& s) {
        int n = s.length();
        if (n <= 1) return 0;

        vector<vector<bool>> isPalin = precomputePalindromes(s);
        vector<int> memo(n, -1);

        return solveMemo(0, s, isPalin, memo) - 1;
    }

private:
    int solveMemo(int i, const string& s, const vector<vector<bool>>& isPalin, vector<int>& memo) {
        int n = s.length();
        if (i == n) return 0;
        if (memo[i] != -1) return memo[i];

        int minCuts = 1e9;
        for (int k = i; k < n; k++) {
            if (isPalin[i][k]) {
                int cuts = 1 + solveMemo(k + 1, s, isPalin, memo);
                minCuts = min(minCuts, cuts);
            }
        }

        return memo[i] = minCuts;
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (Iterative Front Partitioning)
    // Time Complexity: O(N^2)
    // Space Complexity: O(N^2) [for palindrome table + O(N) DP]
    // =========================================================================
    int minCutTabulation(const string& s) {
        int n = s.length();
        if (n <= 1) return 0;

        vector<vector<bool>> isPalin = precomputePalindromes(s);
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            int minCuts = 1e9;
            for (int k = i; k < n; k++) {
                if (isPalin[i][k]) {
                    minCuts = min(minCuts, 1 + dp[k + 1]);
                }
            }
            dp[i] = minCuts;
        }

        return dp[0] - 1; // Subtract 1 for internal cuts
    }

    // Returns minimum palindromic substrings (min_cuts + 1)
    int minSubstrings(const string& s) {
        return minCutTabulation(s) + 1;
    }

private:
    vector<vector<bool>> precomputePalindromes(const string& s) {
        int n = s.length();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || isPalin[i + 1][j - 1])) {
                    isPalin[i][j] = true;
                }
            }
        }

        return isPalin;
    }
};

int main() {
    PalindromePartitioningII solver;

    string s1 = "aab";
    cout << "Test 1 (\"aab\"):\n";
    cout << "  Min Cuts (Memo):       " << solver.minCutMemo(s1) << "\n";
    cout << "  Min Cuts (Tabulation): " << solver.minCutTabulation(s1) << " (Expected: 1)\n";
    cout << "  Min Substrings:        " << solver.minSubstrings(s1) << " (Expected: 2)\n";

    string s2 = "ababbbabbababa";
    cout << "Test 2 (\"ababbbabbababa\"):\n";
    cout << "  Min Cuts:              " << solver.minCutTabulation(s2) << " (Expected: 2)\n";
    cout << "  Min Substrings:        " << solver.minSubstrings(s2) << " (Expected: 3)\n";

    return 0;
}

