#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDominance(vector<int>& A, int K) {
        int n = A.size();
        
        // dp[k][i] = max dominance using exactly 'k' subarrays for prefix A[0...i]
        // Initialize with -1 to represent "impossible state"
        vector<vector<int>> dp(K + 1, vector<int>(n, -1));
        
        // STEP 1: Fill the ground floor (k = 1)
        unordered_map<int, int> freq;
        int max_f = 0;
        for (int i = 0; i < n; i++) {
            freq[A[i]]++;
            max_f = max(max_f, freq[A[i]]);
            dp[1][i] = max_f;
        }
        
        // STEP 2: Climb the floors (k = 2 to K)
        for (int k = 2; k <= K; k++) {
            
            // i starts at k-1, because you need at least 'k' elements 
            // to physically create 'k' non-empty subarrays
            for (int i = k - 1; i < n; i++) { 
                
                unordered_map<int, int> chunk_freq;
                int current_max_freq = 0;
                
                // Slide the Knife 'j' backward.
                // j must stop at k-1 to ensure the left chunk has enough elements
                for (int j = i; j >= k - 1; j--) {
                    
                    // Instantly update the dominance score of our Right Chunk
                    chunk_freq[A[j]]++;
                    current_max_freq = max(current_max_freq, chunk_freq[A[j]]);
                    
                    // Look BACK and DOWN to the safe pad on the previous floor
                    if (dp[k - 1][j - 1] != -1) {
                        dp[k][i] = max(dp[k][i], dp[k - 1][j - 1] + current_max_freq);
                    }
                }
            }
        }
        
        // The final answer is on the top floor (K), at the very end of the array (n-1)
        return dp[K][n - 1];
    }
};


class Solution {
private:
    int solve(int idx, int k, vector<int>& A, vector<vector<int>>& memo) {
        int n = A.size();
        
        // Base Case 1: Perfect Partition!
        // We reached the end of the array AND we have exactly 0 tickets left.
        if (idx == n && k == 0) return 0;
        
        // Base Case 2: Invalid State
        // We ran out of elements but still have tickets, or we ran out of tickets but have elements.
        if (idx == n || k == 0) return -1e9; 
        
        // Base Case 3: Physical Impossibility (Pruning)
        // If we have 3 tickets left, but only 2 elements remaining, we can't make non-empty subarrays.
        if (n - idx < k) return -1e9;
        
        if (memo[idx][k] != -1) return memo[idx][k];
        
        int max_score = -1e9;
        unordered_map<int, int> freq;
        int current_max_freq = 0;
        
        // The Knife Drop:
        // Try dropping the knife at every valid 'j'. 
        // We must stop at 'n - k' to ensure we leave enough elements for the remaining 'k-1' tickets.
        for (int j = idx; j <= n - k; j++) {
            
            // Instantly update the dominance score for our current Left Chunk (idx to j)
            freq[A[j]]++;
            current_max_freq = max(current_max_freq, freq[A[j]]);
            
            // Hand over the rest of the array (j + 1) and exactly 1 less ticket (k - 1)
            int next_score = solve(j + 1, k - 1, A, memo);
            
            // If the recursive path actually survived (was mathematically possible)
            if (next_score != -1e9) {
                max_score = max(max_score, current_max_freq + next_score);
            }
        }
        
        return memo[idx][k] = max_score;
    }
    
public:
    int maxDominance(vector<int>& A, int K) {
        int n = A.size();
        
        // memo[idx][k] initialized with -1
        vector<vector<int>> memo(n, vector<int>(K + 1, -1));
        
        // Start at index 0, holding K tickets.
        return solve(0, K, A, memo);
    }
};