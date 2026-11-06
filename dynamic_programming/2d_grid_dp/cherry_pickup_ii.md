# Cherry Pickup II (Dual Robot 3D DP)

## Problem Overview
You are given a `rows x cols` matrix `grid` representing a field of cherries where `grid[i][j]` represents the number of cherries that you can collect from `(i, j)`.
You have two robots that can collect cherries for you:
- **Robot #1** is located at the top-left corner `(0, 0)`.
- **Robot #2** is located at the top-right corner `(0, cols - 1)`.

Both robots move simultaneously from row $i$ to row $i + 1$. From `(i, c)`, a robot can move to `(i + 1, c - 1)`, `(i + 1, c)`, or `(i + 1, c + 1)`.
When both robots pass through the same cell, only one of them takes the cherries.
Return the **maximum number of cherries collected** by both robots reaching the bottom row.

---

## Recurrence Formulation
Because both robots always advance one row per step, their row coordinate $i$ is identical!
We define state $dp[i][j_1][j_2]$: maximum cherries collected starting from row $i$ with Robot 1 at column $j_1$ and Robot 2 at column $j_2$.

- Cherries at current cell:
  $$\text{cherries} = (j_1 == j_2) \; ? \; grid[i][j_1] : (grid[i][j_1] + grid[i][j_2])$$
- Transition:
  $$dp[i][j_1][j_2] = \text{cherries} + \max_{\Delta_1, \Delta_2 \in \{-1, 0, 1\}} dp[i + 1][j_1 + \Delta_1][j_2 + \Delta_2]$$
- Base Case: At $i = \text{rows} - 1$, return $\text{cherries}$.

---

## Complexity Analysis
- **Tabulation (3D DP):** $O(R \times C^2 \times 9) = O(R \times C^2)$ Time, $O(R \times C^2)$ Space.
- **Space-Optimized (2D DP):** Since row $i$ only depends on row $i+1$, we maintain a $C \times C$ table.
  - **Time Complexity:** $O(R \times C^2)$
  - **Auxiliary Space:** $O(C^2)$

