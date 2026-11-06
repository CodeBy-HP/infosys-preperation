# Minimum Falling Path Sum

## Problem Overview
Given an $N \times N$ array of integers `matrix`, return the **minimum sum of any falling path** through `matrix`.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right:
Specifically, the next element from position $(row, col)$ will be $(row + 1, col - 1)$, $(row + 1, col)$, or $(row + 1, col + 1)$.

---

## Recurrence Formulation
Let $dp[i][j]$ be the minimum falling path sum ending at cell $(i, j)$:
$$dp[i][j] = matrix[i][j] + \min(dp[i-1][j-1], \; dp[i-1][j], \; dp[i-1][j+1])$$
(with boundary checks for $j-1 \ge 0$ and $j+1 < N$).

- **Base Case:** $dp[0][j] = matrix[0][j]$ for all $0 \le j < N$.
- **Answer:** $\min_{0 \le j < N} dp[N-1][j]$.

---

## Complexity Analysis
- **Tabulation (2D DP):** $O(N^2)$ Time, $O(N^2)$ Space.
- **Space-Optimized (Rolling Rows):** $O(N^2)$ Time, $O(N)$ Space using two rows (`prev` and `curr`).

