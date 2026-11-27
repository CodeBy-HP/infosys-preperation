# 13. Min Cost Climbing Stairs (LeetCode 746)

## Problem Statement

You are given an integer array `cost` where `cost[i]` is the cost of the $i$-th step on a staircase. Once you pay the cost, you can either climb **one** or **two** steps.

You can either start from the step with index `0`, or the step with index `1`.

Return the **minimum cost** to reach the top of the floor (past index `n - 1`).

---

## Examples

### Example 1
- **Input:** `cost = [10, 15, 20]`
- **Output:** `15`
- **Explanation:** Start at index 1, pay `15`, and climb two steps to reach the top.

### Example 2
- **Input:** `cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]`
- **Output:** `6`
- **Explanation:** Take steps `0 -> 2 -> 4 -> 6 -> 7 -> 9 -> top` paying `1+1+1+1+1+1 = 6`.

---

## Constraints

- $2 \le \text{cost.length} \le 1000$
- $0 \le \text{cost}[i] \le 999$

---

## Recurrence & Optimization

Let `dp[i]` be the minimum cost to reach step `i`:
$$dp[i] = \min(dp[i-1] + cost[i-1], \ dp[i-2] + cost[i-2])$$
With $dp[0] = 0, dp[1] = 0$. Rolling two variables gives **$O(N)$ time** and **$O(1)$ space**.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Rolling 2-Variable DP** | $O(N)$ | $O(1)$ |
| **1D Tabulation** | $O(N)$ | $O(N)$ |
