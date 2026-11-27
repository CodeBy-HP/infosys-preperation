# 29. Grid Path with One Row Skip (Infosys OA PYQ)

## Problem Statement

You are given an `m x n` integer grid `grid` containing positive cell costs (or obstacles `-1` in some rows). You start at the **top-left cell** `(0, 0)` and want to reach the **bottom-right cell** `(m - 1, n - 1)`.

At any cell `(r, c)`, you can move:
1. **Right:** `(r, c + 1)`
2. **Down:** `(r + 1, c)`
3. **One-Time Row Skip:** At most **once** during your journey, you may jump straight down by 2 rows from `(r, c)` directly to `(r + 2, c)`, completely skipping cell `(r + 1, c)` and its cost! (Valid when `r + 2 < m`.)

Return the **minimum total cost** from `(0, 0)` to `(m - 1, n - 1)` (including start and end cell costs), plus the **number of unique paths** variant in code.

---

## Examples

### Example 1
- **Input:**
  ```text
  grid = [
    [1, 100, 1],
    [50, 50, 50],
    [1,  1,  1]
  ]
  ```
- **Output:** `4`
- **Explanation:**
  Start `(0,0)` [cost `1`] $\to$ **Row Skip** straight down to `(2,0)` [cost `1`] $\to$ `(2,1)` [cost `1`] $\to$ `(2,2)` [cost `1`]. Total = $1 + 1 + 1 + 1 = 4$, completely bypassing the expensive middle row!

---

## Constraints

- $1 \le m, n \le 500$
- $0 \le \text{grid}[i][j] \le 10^4$ (or `-1` for blocked cells)

---

## Pattern Insight: 3D Layered Grid DP `dp[r][c][usedSkip]`

Expand the standard grid DP state with a boolean flag `usedSkip \in {0, 1}`:
- Normal transitions from `(r-1, c)` or `(r, c-1)` preserve `usedSkip`.
- Skip transition into `(r, c)` (`usedSkip = 1`) comes from `(r - 2, c)` with `usedSkip = 0`.
Final answer: $\min(dp[m-1][n-1][0], \ dp[m-1][n-1][1])$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **3D Tabular Grid DP** | $O(M \cdot N)$ | $O(M \cdot N)$ (or $O(N)$ rolling 2 rows) |
