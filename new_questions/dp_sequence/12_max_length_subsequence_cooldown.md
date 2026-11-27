# 12. Maximum Profit / Subsequence with Cooldown (LeetCode 309 & Infosys Cooldown Twist)

## Problem Statement

### Variant A (LeetCode 309 — Best Time to Buy and Sell Stock with Cooldown)
You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.
Find the **maximum profit** you can achieve. You may complete as many transactions as you like with the following restrictions:
- After you sell your stock, you cannot buy stock on the next day (i.e., cooldown 1 day).
- You may not engage in multiple transactions simultaneously (must sell before buying again).

### Variant B (Infosys OA — Maximum Length Subsequence with Value Gap Cooldown)
Given an array `nums` and an integer `cooldownGap`, find the **longest subsequence** where for every pair of picked indices $i < j$, either $j - i > 1$ (if values clash) or $|nums[j] - nums[i]| \le k$ (Longest Ideal Subsequence / Cooldown-style DP).

---

## Examples

### Example 1 (Variant A — Stock with Cooldown)
- **Input:** `prices = [1, 2, 3, 0, 2]`
- **Output:** `3`
- **Explanation:** `transactions = [buy, sell, cooldown, buy, sell]`, profit = $(2 - 1) + (2 - 0) = 3$.

### Example 2 (Variant A)
- **Input:** `prices = [1]`
- **Output:** `0`

---

## Constraints

- $1 \le \text{prices.length} \le 5000$
- $0 \le \text{prices}[i] \le 1000$

---

## Pattern Insight: 3-State Finite State Machine

Maintain three states across each day:
1. **`hold`**: Max profit currently holding a stock (`max(hold, rest - price)`).
2. **`sold`**: Max profit having just sold a stock today (`hold + price`).
3. **`rest`**: Max profit in cooldown/idle (`max(rest, sold)`).

Answer is `max(sold, rest)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **State-Machine DP** | $O(N)$ | $O(1)$ |
| **2D Tabular DP** | $O(N)$ | $O(N)$ |
