# Best Time to Buy and Sell Stock IV (At Most K Transactions)

## Problem Overview
You are given an integer array `prices` where `prices[i]` is the price of a given stock on the $i$-th day, and an integer $k$.
Find the maximum profit you can achieve. You may complete at most $k$ transactions: i.e. you may buy at most $k$ times and sell at most $k$ times.

---

## Recurrence Formulation
Generalizing Stock III, let $cap \in [0, k]$:
- If $buy == 1$:
  $$dp[i][1][cap] = \max(-\text{prices}[i] + dp[i + 1][0][cap], \; dp[i + 1][1][cap])$$
- If $buy == 0$:
  $$dp[i][0][cap] = \max(\text{prices}[i] + dp[i + 1][1][cap - 1], \; dp[i + 1][0][cap])$$

Corner Case Optimization: If $k \ge N / 2$, you can make as many transactions as there are price increases, which degenerates to Stock II in $O(N)$ time.

---

## Complexity Analysis
- **Space-Optimized Tabulation:**
  - **Time Complexity:** $O(N \times K)$
  - **Auxiliary Space:** $O(K)$ using two rolling rows of size $2 \times (K + 1)$.

