#include <iostream>
#include <vector>
#include <numeric>
#include<bits/stdc++.h>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool canPartitionKSubsets(std::vector<int> &nums, int k)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum % k != 0)
            return false;
        int target = sum / k;

        // FIX 1: Sort ASCENDING (Smallest to Largest)
        // This makes the 'break' statement in the inner loop mathematically correct.
        std::sort(nums.begin(), nums.end());

        // FIX 2: Check the last element (which is now the largest)
        if (nums.back() > target)
            return false;

        int n = nums.size();
        int totalStates = 1 << n;

        // dp[mask] stores the weight of the currently open bucket.
        // -1 means the state is invalid/unreachable.
        std::vector<int> dp(totalStates, -1);
        dp[0] = 0;

        for (int mask = 0; mask < totalStates; ++mask)
        {
            if (dp[mask] == -1)
                continue;

            for (int j = 0; j < n; ++j)
            {
                if (!(mask & (1 << j)))
                { // If nums[j] is not yet used
                    if (dp[mask] + nums[j] <= target)
                    {
                        dp[mask | (1 << j)] = (dp[mask] + nums[j]) % target;
                    }
                    else
                    {
                        // SAFE TO BREAK: Because we sorted ascending,
                        // if nums[j] doesn't fit, nums[j+1] definitely won't fit either.
                        break;
                    }
                }
            }
        }

        return dp[totalStates - 1] == 0;
    }

    bool recursive_solution(vector<int> &arr, int k)
    {
        int n = arr.size();
        if (k > n)
            return false;

        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % k != 0)
            return false;

        int need = total / k;
        vector<int> vis(n, 0);

        // FIX 1: Actually sort the array descending
        sort(arr.rbegin(), arr.rend());

        // Quick prune: if the biggest element is larger than the bucket, impossible.
        if (arr[0] > need)
            return false;

        // FIX 2: Add startIdx to the lambda parameters
        auto helper = [&](int k, int currW, int startIdx, auto &self) -> bool
        {
            if (k == 1)
                return true;

            if (currW == need)
            {
                // Bucket sealed! Start the next bucket from index 0.
                return self(k - 1, 0, 0, self);
            }

            // Loop starts from startIdx, not 0
            for (int i = startIdx; i < n; i++)
            {

                if (vis[i] || currW + arr[i] > need)
                    continue;

                vis[i] = 1;

                // FIX 2: Pass i + 1 for the next item in the CURRENT bucket
                if (self(k, currW + arr[i], i + 1, self))
                    return true;

                vis[i] = 0;

                // FIX 3: The Empty Bucket Prune
                if (currW == 0)
                    break;
            }

            return false;
        };

        return helper(k, 0, 0, helper);
    }
};

int main()
{
    Solution sol;
    std::vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;

    std::cout << std::boolalpha;
    std::cout << "canPartitionKSubsets({4,3,2,3,5,2,1}, 4): "
              << sol.canPartitionKSubsets(nums, k) << " (Expected: true)\n";

    return 0;
}