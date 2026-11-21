#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class PrintLIS {
public:
    static std::vector<int> getLIS(const std::vector<int>& arr) {
        int n = arr.size();
        // dp[i] stores the length of LIS ending at index i. Every element is at least length 1.
        vector<int> dp(n, 1);
        
        // The Breadcrumb Log: parent[i] stores the index of the element that comes BEFORE i.
        // Initially, everyone is their own parent (no jumps made yet).
        vector<int> parent(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        
        int max_len = 1;
        int best_end_index = 0; // Where does the optimal timeline finish?
        
        // Evaluate every element as the potential END of a sequence
        for (int i = 0; i < n; i++) {
            
            // Look back at all previous elements to see if we can jump from them
            for (int prev = 0; prev < i; prev++) {
                
                // Action Edge: If the previous element is smaller, AND jumping from it 
                // gives us a strictly longer sequence than we currently have...
                if (arr[prev] < arr[i] && dp[prev] + 1 > dp[i]) {
                    
                    dp[i] = dp[prev] + 1;
                    
                    // DROP THE BREADCRUMB!
                    parent[i] = prev;
                }
            }
            
            // Update the global best sequence tracker
            if (dp[i] > max_len) {
                max_len = dp[i];
                best_end_index = i;
            }
        }
        
        // --- RECONSTRUCTION PHASE ---
        vector<int> lis;
        int curr = best_end_index;
        
        // Follow the breadcrumbs backward until an element is its own parent
        while (parent[curr] != curr) {
            lis.push_back(arr[curr]);
            curr = parent[curr];
        }
        // Push the very first element of the sequence
        lis.push_back(arr[curr]); 
        
        // We traced it backwards, so reverse it to get the correct chronological order
        reverse(lis.begin(), lis.end());
        
        return lis;
    }

    // optimized (nlogn) approach
    vector<int> longestIncreasingSubsequence_BINARY_SEARCH(int n, vector<int>& arr) {
        // buckets[len] stores the INDEX of the smallest ending element for a sequence of length 'len'
        vector<int> buckets; 
        
        // The standard memory log
        vector<int> parent(n, -1);
        
        for (int i = 0; i < n; i++) {
            // Binary search to find the correct bucket
            // We compare arr[i] against the values at the indices stored in the buckets
            auto it = lower_bound(buckets.begin(), buckets.end(), arr[i],
                [&arr](int index, int val) {
                    return arr[index] < val;
                });
            
            int bucket_pos = distance(buckets.begin(), it);
            
            // DROP THE BREADCRUMB: 
            // Our parent is whatever index is currently sitting in the previous bucket!
            if (bucket_pos > 0) {
                parent[i] = buckets[bucket_pos - 1];
            }
            
            // Overwrite the bucket (or create a new one) with our CURRENT INDEX
            if (bucket_pos == buckets.size()) {
                buckets.push_back(i);
            } else {
                buckets[bucket_pos] = i;
            }
        }
        
        // --- RECONSTRUCTION PHASE ---
        vector<int> lis;
        // The last bucket holds the index of the end of the longest sequence
        int curr = buckets.back();
        
        while (curr != -1) {
            lis.push_back(arr[curr]);
            curr = parent[curr]; // Walk backwards
        }
        
        reverse(lis.begin(), lis.end());
        return lis;
    }
};



// Recursive Approach
class Solution {
    int solveMemo(int curr, int prev, const vector<int>& nums, vector<vector<int>>& memo) {
        if (curr == (int)nums.size()) return 0;
        if (memo[curr][prev + 1] != -1) return memo[curr][prev + 1];

        // Choice A: Skip current number
        int notTake = solveMemo(curr + 1, prev, nums, memo);

        // Choice B: Take current number (if strictly increasing)
        int take = 0;
        if (prev == -1 || nums[curr] > nums[prev]) {
            take = 1 + solveMemo(curr + 1, curr, nums, memo);
        }

        return memo[curr][prev + 1] = max(take, notTake);
    }

public:
    vector<int> reconstructLIS(vector<int>& nums) {
        int n = nums.size();
        
        // n rows, n+1 columns (to handle prev = -1 mapping to 0)
        vector<vector<int>> memo(n, vector<int>(n + 1, -1));
        
        // 1. Build the map (Run your exact recursion)
        solveMemo(0, -1, nums, memo);
        
        // 2. Reconstruct the path using the filled map
        vector<int> lis;
        int curr = 0;
        int prev = -1;
        
        while (curr < n) {
            // Find what the score would be if we DID NOT take the current element
            int notTakeScore = 0;
            if (curr + 1 < n) {
                notTakeScore = memo[curr + 1][prev + 1];
            }
            
            // If our current memoized score is DIFFERENT from the notTake score,
            // it physically guarantees that taking this element gave us a better path!
            if (memo[curr][prev + 1] != notTakeScore) {
                lis.push_back(nums[curr]); // We took it!
                prev = curr;               // Update our previous element
            }
            
            // Move to the next index regardless
            curr++;
        }
        
        return lis;
    }
};



int main() {
    std::vector<int> a1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::vector<int> res1 = PrintLIS::getLIS(a1);
    assert(res1.size() == 4);
    // Elements must be strictly increasing
    for (size_t i = 1; i < res1.size(); ++i) {
        assert(res1[i] > res1[i - 1]);
    }

    std::vector<int> a2 = {5, 4, 11, 1, 16, 8};
    std::vector<int> res2 = PrintLIS::getLIS(a2);
    assert(res2.size() == 3);

    std::cout << "All Print Longest Increasing Subsequence tests passed successfully!\n";
    return 0;
}

