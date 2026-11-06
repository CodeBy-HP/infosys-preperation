# Unique Paths II (Grid with Obstacles)

## Problem Overview
You are given an $M \times N$ integer array `obstacleGrid`. A robot is located at the top-left corner `(0, 0)` and wishes to reach the bottom-right corner `(M-1, N-1)`.
The robot can only move either **down** or **right** at any point in time.
An obstacle and space are marked as `1` or `0` respectively in `obstacleGrid`. A path that encounters an obstacle is blocked.
Find the number of possible unique paths to reach the bottom-right corner.

---

## Recurrence Formulation
Let $dp[i][j]$ be the number of unique paths from `(0, 0)` to `(i, j)`.
- If `obstacleGrid[i][j] == 1`, then $dp[i][j] = 0$.
- Otherwise:
  $$dp[i][j] = (i > 0 \; ? \; dp[i-1][j] : 0) + (j > 0 \; ? \; dp[i][j-1] : 0)$$
- Base case: $dp[0][0] = (\text{obstacleGrid}[0][0] == 0 \; ? \; 1 : 0)$.

---

## Complexity Analysis
- **Tabulation (2D DP):** $O(M \times N)$ Time, $O(M \times N)$ Space.
- **Space-Optimized (1D DP):** $O(M \times N)$ Time, $O(N)$ Space using a rolling row array.

