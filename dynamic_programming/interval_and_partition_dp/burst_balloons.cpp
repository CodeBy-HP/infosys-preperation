#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class BurstBalloons {
    // =========================================================================
    // 1. Top-Down Approach (Recursion + Memoization)
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    // =========================================================================
private:
    int solve(int i, int j, vector<int>& nums, vector<vector<int>>& memo) {
        // Base Case: If the pointers cross, there are no balloons left to pop
        if (i > j) return 0;
        
        if (memo[i][j] != -1) return memo[i][j];
        
        int max_coins = 0;
        
        // 'k' represents the LAST balloon to burst in the interval [i...j]
        for (int k = i; k <= j; k++) {
            
            // Destroy everything to the left of k
            int left_cost = solve(i, k - 1, nums, memo);
            
            // Destroy everything to the right of k
            int right_cost = solve(k + 1, j, nums, memo);
            
            // Pop k itself. Its neighbors are strictly outside the interval!
            int burst_cost = nums[i - 1] * nums[k] * nums[j + 1];
            
            int total_cost = left_cost + right_cost + burst_cost;
            
            // We want to MAXIMIZE our coins
            max_coins = max(max_coins, total_cost);
        }
        
        return memo[i][j] = max_coins;
    }

public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        
        // 1. Pad the boundaries with 1s to handle the edge cases seamlessly
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }
        
        vector<vector<int>> memo(n + 2, vector<int>(n + 2, -1));
        
        // 2. We want to burst the original balloons, which now sit from index 1 to n
        return solve(1, n, arr, memo);
    }

public:
    // =========================================================================
    // 2. Bottom-Up Approach (Interval DP Tabulation)
    // Loops i backwards from n to 1 and j forwards from i to n
    // Time Complexity: O(N^3)
    // Space Complexity: O(N^2)
    // =========================================================================
    int maxCoinsTabulation(const vector<int>& nums) {
        int n = nums.size();
        vector<int> a;
        a.push_back(1);
        for (int x : nums) a.push_back(x);
        a.push_back(1);

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        for (int i = n; i >= 1; i--) {
            for (int j = i; j <= n; j++) {
                int maxCoins = 0;
                for (int k = i; k <= j; k++) {
                    int coins = a[i - 1] * a[k] * a[j + 1]
                              + dp[i][k - 1]
                              + dp[k + 1][j];
                    maxCoins = max(maxCoins, coins);
                }
                dp[i][j] = maxCoins;
            }
        }

        return dp[1][n];
    }
};

int main() {
    BurstBalloons solver;

    vector<int> nums = {3, 1, 5, 8};
    cout << "Test [3, 1, 5, 8]:\n";
    cout << "  Memoization: " << solver.maxCoinsMemo(nums) << "\n";
    cout << "  Tabulation:  " << solver.maxCoinsTabulation(nums) << " (Expected: 167)\n";

    return 0;
}

