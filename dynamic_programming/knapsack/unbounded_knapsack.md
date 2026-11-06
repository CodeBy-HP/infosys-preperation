# Unbounded Knapsack

## Problem Overview
Given $N$ items, each with a given weight `wt[i]` and value `val[i]`, and a knapsack of capacity $W$.
Unlike 0/1 knapsack, here you can take **an unlimited number of copies** of each item.
Find the maximum value you can achieve without exceeding capacity $W$.

---

## Recurrence Formulation
Let $dp[i][w]$ be the maximum value from items $0 \dots i$ with capacity $w$:
- **Not Pick:** $dp[i - 1][w]$
- **Pick:** (and remain on index $i$ to allow further picks!)
  $$val[i] + dp[i][w - wt[i]]$$

$$dp[i][w] = \max(dp[i - 1][w], \; val[i] + dp[i][w - wt[i]])$$

### 1D Forward Loop Traversal
In 0/1 knapsack, we iterate backwards ($W \to wt[i]$) to avoid reuse.
In **Unbounded Knapsack**, we intentionally iterate **forward** ($wt[i] \to W$) so that a newly updated state $dp[w - wt[i]]$ can be picked multiple times in the same pass!

---

## Complexity Analysis
- **Tabulation (1D DP):**
  - **Time Complexity:** $O(N \times W)$
  - **Auxiliary Space:** $O(W)$

