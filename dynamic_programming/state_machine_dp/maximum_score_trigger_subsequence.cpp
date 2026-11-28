// Maximum Score with Trigger-Based Subsequence Earnings
// Trigger-based reward system: every k-th item collected triggers double value for next item

#include <bits/stdc++.h>
using namespace std;


// Recursive -> call solve(0, 0, k, nums, dp) dp is initialized to size n by k + 1 filled with LLONG_MIN.
long long solve(int ind, int state, int k, vector<int>& nums, vector<vector<long long>>& dp) {
    if (ind == nums.size()) return 0;
    if (dp[ind][state] != LLONG_MIN) return dp[ind][state];

    // Take
    long long gain = nums[ind];
    int next_state;
    if (state == k) {
        gain *= 2;       // Immediately after a trigger checkpoint
        next_state = 1;  // Start of next cycle
    } else {
        next_state = state + 1;
    }
    long long take = gain + solve(ind + 1, next_state, k, nums, dp);

    // Not take
    long long not_take = solve(ind + 1, state, k, nums, dp);

    return dp[ind][state] = max(take, not_take);
}

class Solution {
public:
    // Approach 1: Recursive DP with Memoization
    // State: dp[i][count_mod_k] = max earnings from index i onwards
    // count_mod_k = number of items picked so far modulo k
    // Special handling when count_mod_k == 0 and count > 0 (trigger checkpoint reached)
    
    int n, k;
    vector<int> nums;
    map<pair<int, int>, int> memo;
    
    int solve(int idx, int countMod) {
        // Base case: processed all elements
        if (idx >= n) return 0;
        
        // Memoization check
        auto key = make_pair(idx, countMod);
        if (memo.find(key) != memo.end()) return memo[key];
        
        // Option 1: Skip current element
        int skip = solve(idx + 1, countMod);
        
        // Option 2: Take current element
        int value = nums[idx];
        int nextMod;
        
        // Determine if this pick gets double value
        // Double value happens when countMod == 0 AND we've already picked at least one item
        // But we track state differently: countMod represents items picked % k
        // When countMod == k (special state), next item gets doubled
        
        if (countMod == k) {
            // Just triggered a checkpoint, next item gets doubled
            value = 2 * nums[idx];
            nextMod = (k == 1) ? k : 1;
        } else if (countMod == 0) {
            // First item or regular state
            value = nums[idx];
            nextMod = (k == 1) ? k : 1;
        } else {
            // Regular pick
            value = nums[idx];
            nextMod = countMod + 1;
            if (nextMod == k) {
                nextMod = k; // Reached checkpoint
            }
        }
        
        int take = value + solve(idx + 1, nextMod);
        
        return memo[key] = max(skip, take);
    }
    
    int maxScore(vector<int>& nums, int k) {
        this->nums = nums;
        this->n = nums.size();
        this->k = k;
        memo.clear();
        return solve(0, 0); // Start from index 0, 0 items picked
    }
    
    // Approach 2: Iterative DP with state machine (k+1 states)
    int maxScoreIterative(vector<int>& nums, int k) {
        int n = nums.size();
        
        // dp[state] = max earnings with 'state' items picked mod k
        // state k+1 special: just triggered checkpoint, next item doubles
        vector<int> dp(k + 2, INT_MIN);
        dp[0] = 0; // Start state: 0 items picked
        
        for (int val : nums) {
            vector<int> newDp = dp;
            
            // Try taking current element from each state
            for (int state = 0; state <= k + 1; state++) {
                if (dp[state] == INT_MIN) continue;
                
                int value = val;
                int nextState;
                
                if (state == 0) {
                    // First pick
                    value = val;
                    nextState = (k == 1) ? k : 1;
                } else if (state == k) {
                    // Just reached checkpoint, next gets doubled
                    value = 2 * val;
                    nextState = (k == 1) ? k : 1;
                } else if (state < k - 1) {
                    // Regular state
                    value = val;
                    nextState = state + 1;
                } else { // state == k - 1
                    // About to reach checkpoint
                    value = val;
                    nextState = k;
                }
                
                newDp[nextState] = max(newDp[nextState], dp[state] + value);
            }
            
            dp = newDp;
        }
        
        int result = 0;
        for (int state = 0; state <= k + 1; state++) {
            result = max(result, dp[state]);
        }
        
        return result;
    }
};

int main() {
    Solution sol;
    
    // Test case 1
    vector<int> nums1 = {10, 20, 30, 40};
    cout << "Test 1: " << sol.maxScore(nums1, 2) << endl; // Expected: 130
    
    // Test case 2
    vector<int> nums2 = {1, 2, 3, 4, 5};
    cout << "Test 2: " << sol.maxScore(nums2, 2) << endl;
    
    // Test case 3
    vector<int> nums3 = {5, -3, 8, -2, 10};
    cout << "Test 3: " << sol.maxScore(nums3, 3) << endl;
    
    return 0;
}
