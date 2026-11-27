# 27. Number of Longest Increasing Subsequences / LIS Partition Count (LeetCode 673 + Dilworth Partition)

## Problem Statement

### Variant A (LeetCode 673 — Number of Longest Increasing Subsequences)
Given an integer array `nums`, return the **number of longest strictly increasing subsequences**.

### Variant B (Infosys — Minimum Partition into Strictly Increasing Subsequences)
Given an integer array `nums`, find the **minimum number of strictly increasing subsequences** needed to partition `nums` (every element belongs to exactly one subsequence).

---

## Examples

### Example 1 (Variant A — Count of LIS)
- **Input:** `nums = [1, 3, 5, 4, 7]`
- **Output:** `2`
- **Explanation:** The two longest increasing subsequences are `[1, 3, 4, 7]` and `[1, 3, 5, 7]`.

### Example 2 (Variant B — Min Increasing Partitions)
- **Input:** `nums = [5, 2, 6, 3, 7, 1]`
- **Output:** `3`
- **Explanation:** Partition into `[5, 6, 7]`, `[2, 3]`, `[1]` (3 increasing subsequences). By **Dilworth's Theorem**, this equals the length of the **Longest Non-Increasing Subsequence**: `[5, 2, 1]` or `[6, 3, 1]` (length 3).

---

## Constraints

- $1 \le \text{nums.length} \le 2000$
- $-10^6 \le \text{nums}[i] \le 10^6$

---

## Pattern Insight

1. **Count of LIS (LeetCode 673):**
   Maintain parallel arrays `len[i]` and `cnt[i]`:
   - If `len[j] + 1 > len[i]`: update `len[i] = len[j] + 1; cnt[i] = cnt[j];`.
   - Else if `len[j] + 1 == len[i]`: accumulate `cnt[i] += cnt[j]`.
2. **Minimum Increasing Partitions (Patience Sorting / Dilworth's Theorem):**
   Maintain the tail elements of active strictly increasing piles (`tails`). For each `x`, find the leftmost pile tail `>= x` via `lower_bound` (greedy placement). The number of piles created is the exact minimum!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Number of LIS (`len` + `cnt` DP)** | $O(N^2)$ | $O(N)$ |
| **Min Increasing Partitions (Patience Sorting)** | $O(N \log N)$ | $O(N)$ |
