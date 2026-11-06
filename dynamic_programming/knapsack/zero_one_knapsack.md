# 0/1 Knapsack Problem

## Problem Overview
Given $N$ items, each with a given weight `wt[i]` and value `val[i]`, and a knapsack of maximum capacity $W$.
You cannot divide items (either pick an item completely or skip it—0/1 property).
Find the maximum total value that can be put in the knapsack.

---

## Recurrence Formulation
Let $dp[i][w]$ be the maximum value obtained using a subset of items from index $0$ to $i$ with knapsack capacity $w$:
- **Not Pick:** $dp[i - 1][w]$
- **Pick:** (if $wt[i] \le w$) $val[i] + dp[i - 1][w - wt[i]]$

$$dp[i][w] = \max(dp[i - 1][w], \; (wt[i] \le w \; ? \; val[i] + dp[i - 1][w - wt[i]] : 0))$$

### 1D In-Place Optimization
Because $dp[w]$ depends only on $dp[w - wt[i]]$ from the **previous row**, iterating $w$ **backwards** from $W$ down to $wt[i]$ prevents overwrite of values needed for smaller capacities!

---

## Complexity Analysis
- **Tabulation (2D DP):** $O(N \times W)$ Time, $O(N \times W)$ Space.
- **Single Array In-Place:**
  - **Time Complexity:** $O(N \times W)$
  - **Auxiliary Space:** $O(W)$

