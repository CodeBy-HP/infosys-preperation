# 24. Minimum Cost K-Partition with Range Cost (Infosys SP OA Exact PYQ)

## Problem Statement

You are given an integer array `nums` of size `n` and an integer `k` ($1 \le k \le n$). You must partition `nums` into **exactly `k` contiguous non-empty subarrays** (segments).

The cost of a contiguous subarray `[l .. r]` is defined as:
$$\text{cost}(l, r) = \big(\max_{l \le x \le r} nums[x] - \min_{l \le x \le r} nums[x]\big) + |nums[l] - nums[r]|$$
*(Note: Some Infosys slots drop the `|nums[l] - nums[r]|` term or keep `(max - min)` alone; both follow the exact same partition DP structure.)*

Return the **minimum possible total cost** across all `k` segments.

---

## Examples

### Example 1
- **Input:** `nums = [1, 5, 2, 8]`, `k = 2`
- **Output:** `8`
- **Explanation:**
  - Split `[1, 5, 2]` and `[8]`:
    - Segment `[1, 5, 2]`: $(\max 5 - \min 1) + |1 - 2| = 4 + 1 = 5$.
    - Segment `[8]`: $(8 - 8) + |8 - 8| = 0$.
    - Total = `5`.
  - Split `[1]` and `[5, 2, 8]`:
    - Segment `[1]`: `0`.
    - Segment `[5, 2, 8]`: $(8 - 2) + |5 - 8| = 6 + 3 = 9$.
  - Split `[1, 5]` and `[2, 8]`: $(4 + 4) + (6 + 6) = 20$.
  - Minimum total cost = `5`!

---

## Constraints

- $1 \le k \le n \le 500$
- $0 \le \text{nums}[i] \le 10^9$

---

## Pattern Insight: 2D Partition DP with Precomputed Segment Costs

Precompute `cost[l][r]` in $O(N^2)$ time by expanding `r` from `l` to `n - 1` while rolling `curMin` and `curMax` in $O(1)$ per cell.
Then define `dp[p][i]` = minimum cost to partition prefix `nums[0..i-1]` into `p` contiguous segments:
$$dp[p][i] = \min_{p-1 \le j < i} \big(dp[p - 1][j] + \text{cost}(j, i - 1)\big)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Precomputed Range Cost + Partition DP** | $O(K \cdot N^2)$ | $O(N^2)$ (or $O(N)$ rolling DP + on-the-fly backward sweep) |
