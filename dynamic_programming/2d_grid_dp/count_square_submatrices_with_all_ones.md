# Count Square Submatrices with All Ones

## Problem Overview
Given an $M \times N$ matrix of ones and zeros, return how many **square submatrices** have all ones.

---

## Recurrence Formulation
Let $dp[i][j]$ represent the side length of the largest square submatrix whose **bottom-right corner** is at $(i, j)$.
Crucially: if the largest square ending at $(i, j)$ has side length $K$, then $(i, j)$ also serves as the bottom-right corner for squares of size $1, 2, \dots, K$.
Therefore, cell $(i, j)$ contributes exactly $dp[i][j]$ squares to the total count!

- If `matrix[i][j] == 0`:
  $$dp[i][j] = 0$$
- If `matrix[i][j] == 1`:
  $$dp[i][j] = 1 + \min(dp[i - 1][j], \; dp[i][j - 1], \; dp[i - 1][j - 1])$$
  (with base cases along row $0$ and col $0$ equal to $matrix[i][j]$).

The total count is:
$$\text{Total Squares} = \sum_{i=0}^{M-1} \sum_{j=0}^{N-1} dp[i][j]$$

---

## Complexity Analysis
- **Tabulation (2D DP):** $O(M \times N)$ Time, $O(M \times N)$ Space.
- **Space-Optimized (1D Row):** $O(M \times N)$ Time, $O(N)$ Space using a 1D DP array and a `prevDiag` variable.

