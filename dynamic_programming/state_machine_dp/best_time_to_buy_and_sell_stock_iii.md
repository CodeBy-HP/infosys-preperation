# Best Time to Buy and Sell Stock III (At Most 2 Transactions)

## Problem Overview
You are given an array `prices` where `prices[i]` is the price of a given stock on the $i$-th day.
Find the maximum profit you can achieve. You may complete **at most two transactions**.
Note: You may not engage in multiple transactions simultaneously (i.e. you must sell the stock before you buy again).

---

## Recurrence Formulation
We extend our state with a transaction counter `cap` ($cap \in \{0, 1, 2\}$) representing remaining allowed transactions:
$dp[i][buy][cap]$:
- If $buy == 1$:
  $$dp[i][1][cap] = \max(-\text{prices}[i] + dp[i + 1][0][cap], \; dp[i + 1][1][cap])$$
- If $buy == 0$: (completing a transaction decrements $cap$):
  $$dp[i][0][cap] = \max(\text{prices}[i] + dp[i + 1][1][cap - 1], \; dp[i + 1][0][cap])$$
- Base cases: $dp[n][buy][cap] = 0$, and $dp[i][buy][0] = 0$.

### 4-State Optimization
Alternatively, track four finite states:
- `buy1 = max(buy1, -prices[i])`
- `sell1 = max(sell1, buy1 + prices[i])`
- `buy2 = max(buy2, sell1 - prices[i])`
- `sell2 = max(sell2, buy2 + prices[i])`

---

## Complexity Analysis
- **3D DP Tabulation:** $O(N \times 2 \times 3) = O(N)$ Time, $O(N \times 2 \times 3)$ Space.
- **Space-Optimized (4 Variables):**
  - **Time Complexity:** $O(N)$
  - **Auxiliary Space:** $O(1)$

