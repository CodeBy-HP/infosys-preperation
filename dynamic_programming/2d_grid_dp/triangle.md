# Triangle (Minimum Total Path Sum)

## Problem Overview
Given a `triangle` array, return the **minimum path sum from top to bottom**.
For each step, you may move to an adjacent number of the row below. More formally, if you are at index `j` on the current row, you may move to either index `j` or index `j + 1` on the next row.

---

## Recurrence Formulation
Notice that top-down approaches require inspecting multiple starting points or carrying boundaries. **Bottom-up DP starting from the base of the triangle is vastly superior**.

Let $dp[i][j]$ be the minimum path sum from $(i, j)$ down to the base:
- **Base Case (Last Row $N-1$):**
  $$dp[N-1][j] = triangle[N-1][j]$$
- **Transition (from row $N-2$ down to $0$):**
  $$dp[i][j] = triangle[i][j] + \min(dp[i+1][j], \; dp[i+1][j+1])$$
- **Answer:** $dp[0][0]$.

---

## Complexity Analysis
- **Tabulation (2D DP):** $O(N^2)$ Time, $O(N^2)$ Space.
- **Space-Optimized (1D Row):** We only need an array of size $N$ initialized with the bottom row, shrinking upwards in-place.
  - **Time Complexity:** $O(N^2)$
  - **Auxiliary Space:** $O(N)$

