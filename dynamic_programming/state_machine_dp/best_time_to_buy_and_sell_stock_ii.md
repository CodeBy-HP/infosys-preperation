# Best Time to Buy and Sell Stock II (Infinite Transactions)

## Problem Overview
You are given an integer array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.
On each day, you may decide to buy and/or sell the stock. You can only hold **at most one** share of the stock at any time. However, you can buy it and then immediately sell it on the same day.
Find and return the **maximum profit** you can achieve.

---

## Recurrence Formulation
At each day $i$, we can be in one of two states:
- `buy` (can buy): We either do nothing or buy stock at `prices[i]`:
  $$dp[i][1] = \max(dp[i - 1][1], \; dp[i - 1][0] - \text{prices}[i])$$
- `sell` (holding stock, can sell): We either do nothing or sell at `prices[i]`:
  $$dp[i][0] = \max(dp[i - 1][0], \; dp[i - 1][1] + \text{prices}[i])$$

Greedy Equivalence: Since transactions have no cost, every positive price jump $\text{prices}[i] > \text{prices}[i-1]$ contributes to profit:
$$\text{profit} = \sum_{i=1}^{N-1} \max(0, \; \text{prices}[i] - \text{prices}[i - 1])$$

---

## Complexity Analysis
- **DP / Greedy Approach:**
  - **Time Complexity:** $O(N)$
  - **Auxiliary Space:** $O(1)$

