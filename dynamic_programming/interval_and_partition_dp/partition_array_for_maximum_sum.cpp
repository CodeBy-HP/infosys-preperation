#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        
        // dp[i] represents the maximum sum for the first 'i' elements
        vector<int> dp(n + 1, 0);
        
        // Walk left to right across the array
        for (int i = 1; i <= n; i++) {
            
            int max_val_in_chunk = 0;
            int max_total_sum = 0;
            
            // Slide the Knife backward. 
            // The chunk length can be 1, 2... up to k (and we can't slice past index 0)
            for (int len = 1; len <= k && i - len >= 0; len++) {
                
                // As we slide back, keep track of the biggest number we've seen in this chunk
                // arr[i - len] looks at the exact number we just included in our slice
                max_val_in_chunk = max(max_val_in_chunk, arr[i - len]);
                
                // Calculate the score if we drop the knife right here
                int current_chunk_score = max_val_in_chunk * len;
                int previous_safe_pad_score = dp[i - len];
                
                // Is this the best knife drop so far?
                max_total_sum = max(max_total_sum, previous_safe_pad_score + current_chunk_score);
            }
            
            // Save the absolute best knife drop to our current pad
            dp[i] = max_total_sum;
        }
        
        // The final pad holds the max sum for the entire array
        return dp[n];
    }
};

int main() {
    std::vector<int> a1 = {1, 15, 7, 9, 2, 5, 10};
    int k1 = 3;
    assert(PartitionArrayMaxSum::maxSumAfterPartitioning(a1, k1) == 84);

    std::vector<int> a2 = {1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3};
    int k2 = 4;
    assert(PartitionArrayMaxSum::maxSumAfterPartitioning(a2, k2) == 83);

    std::vector<int> a3 = {1};
    int k3 = 1;
    assert(PartitionArrayMaxSum::maxSumAfterPartitioning(a3, k3) == 1);

    std::cout << "All Partition Array for Maximum Sum tests passed successfully!\n";
    return 0;
}

