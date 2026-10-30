# Partition to K Equal Sum Subsets (LeetCode 698)

## Problem Statement
Given an integer array `nums` and an integer `k`, return `true` if it is possible to divide this array into `k` non-empty subsets whose sums are all equal.

### Example 1:
```
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It's possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.
```

### Constraints:
- `1 <= k <= nums.length <= 16`
- `0 <= nums[i] <= 10^4`
- The frequency of each element is in the range `[1, 4]`.

---

## Pattern Insight: Bitmask DP / Memoization
- Total sum $S = \sum nums$. If $S \pmod k \ne 0$, return `false`. Target subset sum is $T = S / k$.
- Since $N \le 16$, the subset of chosen numbers can be encoded as a 16-bit integer `mask`.
- Define `dp[mask]`: the remainder of the current subset sum when the elements picked so far correspond to `mask`.
- If `dp[mask] == -1`, state is invalid/unreachable.
- Initial state: `dp[0] = 0`.
- Transition for `mask` from $0$ to $(1 \ll N) - 1$:
  - If `dp[mask] == -1`, continue.
  - For each unpicked element $j$ (`(mask & (1 << j)) == 0`):
    - If `dp[mask] + nums[j] <= T`:
      - Next state `next_mask = mask | (1 << j)`.
      - `dp[next_mask] = (dp[mask] + nums[j]) % T`.
- If `dp[(1 << N) - 1] == 0`, return `true`!

---

## Complexity
- **Time Complexity:** $O(N \cdot 2^N)$.
- **Space Complexity:** $O(2^N)$ for DP table.
