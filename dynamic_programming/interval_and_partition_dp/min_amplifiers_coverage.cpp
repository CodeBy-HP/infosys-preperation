class Solution {
private:
    int solve(int i, int k, vector<int>& posts, int r, vector<vector<int>>& memo) {
        int n = posts.size();
        
        // Base Case: If we've advanced past the last post, we need 0 more amplifiers
        if (i >= n) return 0;
        
        if (memo[i][k] != -1) return memo[i][k];
        
        // --- OPTION 1: Use a Normal Amplifier ---
        // Blast radius goes up to posts[i] + 2r
        int next_i_normal = i;
        while (next_i_normal < n && posts[next_i_normal] <= posts[i] + 2 * r) {
            next_i_normal++;
        }
        int min_amps = 1 + solve(next_i_normal, k, posts, r, memo);
        
        // --- OPTION 2: Use a Super Amplifier (If tickets remain) ---
        if (k > 0) {
            // Blast radius goes up to posts[i] + 4r
            int next_i_super = i;
            while (next_i_super < n && posts[next_i_super] <= posts[i] + 4 * r) {
                next_i_super++;
            }
            int super_cost = 1 + solve(next_i_super, k - 1, posts, r, memo);
            
            // Take the absolute best choice
            min_amps = min(min_amps, super_cost);
        }
        
        return memo[i][k] = min_amps;
    }

public:
    int minAmplifiers(vector<int>& posts, int r, int K) {
        int n = posts.size();
        
        // Memoization table: memo[idx][tickets_left]
        vector<vector<int>> memo(n, vector<int>(K + 1, -1));
        
        // Start at index 0, with K super tickets
        return solve(0, K, posts, r, memo);
    }
};