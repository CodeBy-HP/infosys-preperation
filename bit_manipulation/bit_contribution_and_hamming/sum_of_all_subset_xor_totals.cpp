#include <iostream>
#include <vector>

class Solution {
public:
    // Approach 1: Mathematical O(N) bitwise OR deduction
    int subsetXORSumOptimal(const std::vector<int>& nums) {
        int bitwiseOr = 0;
        for (int x : nums) {
            bitwiseOr |= x;
        }
        // Each bit set in bitwiseOr appears in exactly 2^(n-1) subsets
        return bitwiseOr << (nums.size() - 1);
    }

    // Approach 2: Recursive DFS / Backtracking O(2^N)
    int subsetXORSumDFS(const std::vector<int>& nums) {
        return dfs(nums, 0, 0);
    }

private:
    int dfs(const std::vector<int>& nums, int idx, int currentXor) {
        if (idx == (int)nums.size()) {
            return currentXor;
        }
        // Choice 1: Include nums[idx], Choice 2: Exclude nums[idx]
        return dfs(nums, idx + 1, currentXor ^ nums[idx]) + 
               dfs(nums, idx + 1, currentXor);
    }
};

int main() {
    Solution sol;
    std::vector<int> nums1 = {1, 3};
    std::cout << "Test 1 [1, 3] Optimal: " << sol.subsetXORSumOptimal(nums1) 
              << " (Expected: 6)\n";
    std::cout << "Test 1 [1, 3] DFS:     " << sol.subsetXORSumDFS(nums1) 
              << " (Expected: 6)\n";

    std::vector<int> nums2 = {5, 1, 6};
    std::cout << "Test 2 [5, 1, 6]:      " << sol.subsetXORSumOptimal(nums2) 
              << " (Expected: 28)\n";

    return 0;
}
