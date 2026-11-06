# Coin Change II (Number of Combinations)

## Problem Overview
You are given an integer array `coins` representing coins of different denominations and an integer `amount` representing a total amount of money.
Return the **number of combinations** that make up that amount. You may assume that you have an infinite number of each kind of coin.

---

## Combinations vs Permutations Invariant
- If the outer loop iterates over `coins` and inner loop iterates over `amount`:
  $$dp[a] += dp[a - coin]$$
  Each coin denomination is considered in a fixed order, ensuring that combinations like $(1, 2)$ and $(2, 1)$ are counted **only once**!
- Because coins can be reused indefinitely (unbounded knapsack), the inner loop iterates **forward** from $coin$ to $amount$.

---

## Complexity Analysis
- **Tabulation (2D DP):** $O(N \times \text{amount})$ Time, $O(N \times \text{amount})$ Space.
- **Space-Optimized (1D DP):**
  - **Time Complexity:** $O(N \times \text{amount})$
  - **Auxiliary Space:** $O(\text{amount})$

