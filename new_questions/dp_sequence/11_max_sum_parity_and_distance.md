# 11. Maximum Sum with Parity & Distance Constraint (Infosys House Robber Variant)

## Problem Statement

You are given an integer array `nums` of length `n` and an integer `dist` ($dist \ge 1$). You want to choose a subsequence of elements $nums[i_1], nums[i_2], \dots, nums[i_k]$ such that:
1. **Distance Constraint:** Any two consecutive chosen elements must be separated by at least `dist` indices: $i_{m+1} - i_m \ge dist$ (for House Robber, $dist = 2$).
2. **Parity Constraint:** Consecutive chosen elements must **alternate in parity** (i.e., an even value must be followed by an odd value, and an odd value must be followed by an even value).

Return the **maximum possible sum** of such a valid subsequence. (Assume negative numbers can be skipped; empty subsequence has sum 0).

---

## Examples

### Example 1
- **Input:** `nums = [2, 5, 4, 3, 6]`, `dist = 2`
- **Output:** `11`
- **Explanation:**
  - Pick index 0 (`2`, even), skip index 1 (`dist = 2`), pick index 3 (`3`, odd), index 4 too close. Sum = $2 + 3 = 5$.
  - Pick index 1 (`5`, odd), pick index 4 (`6`, even): $4 - 1 = 3 \ge 2$, parities alternate (odd $\to$ even)! Sum = $5 + 6 = 11$.

### Example 2
- **Input:** `nums = [4, 2, 6, 8]`, `dist = 2`
- **Output:** `8`
- **Explanation:** All elements are even, so you can pick at most 1 element. The maximum is `8`.

---

## Constraints

- $1 \le n \le 10^5$
- $1 \le \text{dist} \le n$
- $-10^4 \le \text{nums}[i] \le 10^4$

---

## Pattern Insight: Prefix-Best Parity DP with Distance Delay

Let `best[i][p]` be the maximum sum achievable using elements from `0..i` whose **last picked element** had parity `p \in {0 (even), 1 (odd)}`.
At index `i` with value `x = nums[i]` and parity `p = abs(x) % 2`:
- Previous valid element must be at index $\le i - dist$ and have opposite parity `1 - p`:
  $$\text{prevOpp} = (i - dist \ge 0) \ ? \ \text{best}[i - dist][1 - p] : 0$$
  (or `max(0LL, prevOpp)` since starting fresh at `i` is always allowed).
- `pick = x + max(0LL, prevOpp)`
- Update prefix maximums:
  `best[i][0] = max(best[i-1][0], p == 0 ? pick : 0)`
  `best[i][1] = max(best[i-1][1], p == 1 ? pick : 0)`

Runs in **$O(N)$ time**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Prefix-Best DP with Index Lag `i - dist`** | $O(N)$ | $O(N)$ (or $O(\text{dist})$) |
| **Naive Quadratic DP** | $O(N^2)$ | $O(N)$ |
