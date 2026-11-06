# Rod Cutting Problem

## Problem Overview
Given a rod of length $N$ inches and an array of prices `price` containing the prices of all pieces of size smaller than or equal to $N$.
Determine the **maximum value obtainable** by cutting up the rod and selling the pieces. You may make any number of cuts (or zero cuts), and pieces of the same length can be sold repeatedly.

---

## Direct Mapping to Unbounded Knapsack
- Knapsack capacity: $N$ (the total length of the rod).
- Available item weights: lengths $1, 2, 3, \dots, N$.
- Item values: `price[0], price[1], ..., price[N-1]`.
- Unlimited reuse: Any piece length can be cut multiple times.

$$dp[len] = \max_{1 \le i \le len} \big(price[i - 1] + dp[len - i]\big)$$

---

## Complexity Analysis
- **Tabulation (1D DP):**
  - **Time Complexity:** $O(N^2)$
  - **Auxiliary Space:** $O(N)$

