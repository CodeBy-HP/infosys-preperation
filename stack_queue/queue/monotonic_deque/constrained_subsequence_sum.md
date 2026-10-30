# Constrained Subsequence Sum (LeetCode 1425)

## Problem Statement
Given an integer array `nums` and an integer `k`, return the maximum sum of a non-empty subsequence of that array such that for every two consecutive integers in the subsequence, `nums[i]` and `nums[j]`, where `i < j`, the condition `j - i <= k` is satisfied.

A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, leaving the remaining elements in their original order.

### Example 1:
```
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].
```

### Example 2:
```
Input: nums = [-1,-2,-3], k = 1
Output: -1
```

### Constraints:
- `1 <= k <= nums.length <= 10^5`
- `-10^4 <= nums[i] <= 10^4`

---

## Pattern Insight: DP + Monotonic Deque Optimization
- Define $dp[i]$ as the maximum sum of a valid subsequence ending at index $i$:
  $$dp[i] = nums[i] + \max\left(0, \max_{i - k \le j < i} dp[j]\right)$$
- Finding $\max_{i - k \le j < i} dp[j]$ naively takes $O(k)$ per state, leading to $O(N \cdot k)$ total time.
- By using a **Monotonic Decreasing Deque**:
  - The front of the deque always holds index $j$ with the largest $dp[j]$ in the sliding window $[i-k, i-1]$.
  - Expire out-of-window indices from the front: `dq.front() < i - k`.
  - Calculate $dp[i]$.
  - Maintain decreasing order of $dp$ values in the deque by popping smaller elements from the back before pushing $i$.
  - Time drops from $O(N \cdot k)$ to optimal $O(N)$!

---

## Complexity
- **Time Complexity:** $O(N)$ — Each index enters and leaves the deque at most once.
- **Space Complexity:** $O(N)$ — DP array and deque.
