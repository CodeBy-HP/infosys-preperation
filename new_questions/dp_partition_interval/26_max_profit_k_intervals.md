# 26. Maximum Profit with K Intervals (LeetCode 1751 / 1235 Weighted Job Scheduling)

## Problem Statement

You are given an array `events` where `events[i] = [startDay_i, endDay_i, value_i]`, representing an interval starting at `startDay_i`, ending at `endDay_i`, and earning `value_i`. You are also given an integer `k`, the **maximum number of non-overlapping intervals** you can attend.

You can only attend one interval at a time. Two intervals are compatible if one finishes strictly before the next begins (or $\le$ depending on half-open vs inclusive intervals; here we provide strict `<` as in LeetCode 1751 and inclusive `<=` as in LeetCode 1235).

Return the **maximum sum of values** you can receive by attending at most `k` intervals (if `k == n`, reduces to unbounded Weighted Job Scheduling — LeetCode 1235).

---

## Examples

### Example 1 (LeetCode 1751 — Inclusive intervals, strict `<`)
- **Input:** `events = [[1, 2, 4], [3, 4, 3], [2, 3, 1]]`, `k = 2`
- **Output:** `7`
- **Explanation:** Choose `[1, 2, 4]` and `[3, 4, 3]` for total value $4 + 3 = 7$.

### Example 2
- **Input:** `events = [[1, 2, 4], [3, 4, 3], [2, 3, 10]]`, `k = 2`
- **Output:** `10`
- **Explanation:** Choose `[2, 3, 10]` alone (value 10), which beats $4 + 3 = 7$.

---

## Constraints

- $1 \le k \le \text{events.length} \le 10^6$
- $1 \le k \cdot \text{events.length} \le 10^6$
- $1 \le \text{startDay}_i \le \text{endDay}_i \le 10^9$
- $1 \le \text{value}_i \le 10^6$

---

## Pattern Insight: Sort by Start/End + Binary Search `dp[i][c]`

Sort `events` ascending by `startDay`:
1. For each event `i`, precompute `nextIdx[i]` = first index `j > i` where `events[j].start > events[i].end` using `upper_bound`.
2. Let `dp[c][i]` be the max value choosing at most `c` intervals from `events[i..n-1]`:
   $$dp[c][i] = \max\Big(dp[c][i + 1], \ value_i + dp[c - 1][\text{nextIdx}[i]]\Big)$$
   Rolling `c` from `1` to `k` keeps space at $O(N)$!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sorting + Binary Search + Rolling DP (`k` cap)** | $O(N \log N + k \cdot N)$ | $O(N)$ |
| **Unbounded `k` (LeetCode 1235)** | $O(N \log N)$ | $O(N)$ |
