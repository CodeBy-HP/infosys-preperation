#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Recursive Solution
class Solution {
private:
    long long int MOD = 1e9 + 7;
    
    long long int solve(string& s, int i, int j, vector<vector<long long>>& memo) {
        // Base Case 1: If pointers cross, the substring is empty
        if (i > j) return 0;
        
        // Base Case 2: A single character is exactly 1 palindrome
        if (i == j) return 1;
        
        // If we already calculated this specific substring, return the cached answer
        if (memo[i][j] != -1) return memo[i][j];
        
        if (s[i] == s[j]) {
            // MATCH: Right-Shrink + Left-Shrink + 1
            memo[i][j] = (solve(s, i, j - 1, memo) + 
                          solve(s, i + 1, j, memo) + 1) % MOD;
        } else {
            // MISMATCH: Right-Shrink + Left-Shrink - Overlap
            // We add MOD before the final modulo to prevent C++ from yielding negative numbers
            memo[i][j] = (solve(s, i, j - 1, memo) + 
                          solve(s, i + 1, j, memo) - 
                          solve(s, i + 1, j - 1, memo) + MOD) % MOD;
        }
        
        return memo[i][j];
    }

public:
    long long int countPS(string str) {
        int n = str.length();
        
        // Initialize the memoization table with -1
        vector<vector<long long>> memo(n, vector<long long>(n, -1));
        
        // Start the recursion with the entire string's boundaries
        return solve(str, 0, n - 1, memo);
    }
};

// iterative solution
class CountPalindromicSubsequences {
public:
    static long long countPalindromes(const std::string& s) {
        int n = s.length();
        long long MOD = 1e9 + 7;
        
        // dp[i][j] = count of palindromes from index i to j
        vector<vector<long long>> dp(n, vector<long long>(n, 0));
        
        // Base case: Every single character is a palindrome of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Length of the substring we are currently checking
        for (int len = 2; len <= n; len++) {
            
            // i is the start index, j is the end index
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                
                if (s[i] == s[j]) {
                    // Match: Left-Shrink + Right-Shrink + 1 (the overlap cancels out)
                    dp[i][j] = (dp[i][j-1] + dp[i+1][j] + 1) % MOD;
                } else {
                    // Mismatch: Left-Shrink + Right-Shrink - Overlap
                    // (We add MOD before modulo to prevent negative numbers in C++)
                    dp[i][j] = (dp[i][j-1] + dp[i+1][j] - dp[i+1][j-1] + MOD) % MOD;
                }
                
            }
        }
        
        // The top-right bucket holds the answer for the full string (index 0 to n-1)
        return dp[0][n-1];
    }
};

int main() {
    assert(CountPalindromicSubsequences::countPalindromes("abcd") == 4);
    assert(CountPalindromicSubsequences::countPalindromes("aab") == 4); // "a", "a", "b", "aa"
    assert(CountPalindromicSubsequences::countPalindromes("aaaa") == 15); // 2^4 - 1 = 15

    std::cout << "All Count Palindromic Subsequences tests passed successfully!\n";
    return 0;
}

