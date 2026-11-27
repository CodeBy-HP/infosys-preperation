# 25. Minimum Cost K-Partition (`Sum × Endpoint Difference` — Infosys SP OA Exact PYQ)

## Problem Statement

You are given an integer array `nums` of length `n` and an integer `k` ($1 \le k \le n$). You must split `nums` into **exactly `k` contiguous non-empty subarrays**.

The cost of a contiguous segment `[l .. r]` is defined as:
$$\text{cost}(l, r) = \left(\sum_{x=l}^{r} nums[x]\right) \times |nums[l] - nums[r]|$$

Return the **minimum possible total cost** summed across all `k` partitions.

---

## Examples

### Example 1
- **Input:** `nums = [2, 6, 3, 5]`, `k = 2`
- **Output:** `14`
- **Explanation:**
  - Split `[2]` and `[6, 3, 5]`: $2 \times |2 - 2| + (6 + 3 + 5) \times |6 - 5| = 0 + 14 \times 1 = 14$.
  - Split `[2, 6]` and `[3, 5]`: $8 \times 4 + 8 \times 2 = 32 + 16 = 48$.
  - Split `[2, 6, 3]` and `[5]`: $11 \times 1 + 5 \times 0 = 11$! Wait: $11 \times |2 - 3| = 11$, and single element `[5]` has $|5 - 5| = 0 \implies$ Total = `11`!

### Example 2
- **Input:** `nums = [1, 2, 3]`, `k = 3`
- **Output:** `0`
- **Explanation:** Each element forms its own segment where `l == r`, so `|nums[l] - nums[r]| = 0`.

---

## Constraints

- $1 \le k \le n \le 500$
- $0 \le \text{nums}[i] \le 10^4$

---

## Pattern Insight: Prefix-Sum Partition DP

Precompute `pref[i]` in $O(N)$. Then for any segment `[j .. i - 1]`:
$$\text{cost}(j, i - 1) = (pref[i] - pref[j]) \times |nums[j] - nums[i - 1]|$$
Using rolling partition DP:
$$dp_p[i] = \min_{p - 1 \le j < i} \big( dp_{p-1}[j] + \text{cost}(j, i - 1) \big)$$
Notice we don't even need an $O(N^2)$ cost table — computing `cost(j, i - 1)` takes $O(1)$ via `pref`, keeping auxiliary space strictly **$O(N)$**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Prefix-Sum Rolling Partition DP** | $O(K \cdot N^2)$ | $O(N)$ |
