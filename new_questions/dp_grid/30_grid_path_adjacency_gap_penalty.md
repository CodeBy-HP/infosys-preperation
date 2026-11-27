# 30. Grid Path with Adjacency Gap Penalty (Infosys SP OA Variant)

## Problem Statement

You are given an `m x n` integer grid `grid` where `grid[r][c]` represents the elevation/cost at cell `(r, c)`.

Starting from `(0, 0)`, you must travel to `(m - 1, n - 1)` by moving only **Right** `(r, c + 1)` or **Down** `(r + 1, c)`.
In addition to paying the cell value `grid[nr][nc]` (or solely transitioning via step differences), every transition from `(r, c)` to `(nr, nc)` incurs an **Adjacency Gap Penalty** equal to:
$$\text{penalty} = \text{grid}[nr][nc] + w \cdot |\text{grid}[nr][nc] - \text{grid}[r][c]|$$
*(Note: Some variants minimize purely the accumulated gap penalties $\sum |\text{grid}[nr][nc] - \text{grid}[r][c]|$ without cell costs.)*

Return the **minimum total cost** to reach `(m - 1, n - 1)`.

---

## Examples

### Example 1 (Gap Penalty Only: `w = 1`, cell values ignored after start)
- **Input:**
  ```text
  grid = [
    [1, 3, 5],
    [10, 2, 6],
    [4, 8, 7]
  ]
  ```
- **Output:** `4`
- **Explanation:**
  Suppose path chooses `(0,0)[1] -> (0,1)[3]` (gap 2) $\to$ `(1,1)[2]` (gap 1) $\to$ `(1,2)[6]` (gap 4) $\to$ `(2,2)[7]` (gap 1) $\implies 2+1+4+1 = 8$.
  Wait: `(0,0)[1] -> (0,1)[3]` (2) $\to$ `(0,2)[5]` (2) $\to$ `(1,2)[6]` (1) $\to$ `(2,2)[7]` (1) $\implies 2 + 2 + 1 + 1 = 6$!

---

## Constraints

- $1 \le m, n \le 500$
- $0 \le \text{grid}[i][j] \le 10^6$

---

## Pattern Insight: 2D Grid Transition DP

Since movement is strictly Right or Down (acyclic DAG), the state at `(r, c)` only depends on `(r - 1, c)` and `(r, c - 1)`:
$$dp[r][c] = \min\Big(dp[r-1][c] + \text{stepCost}((r-1,c) \to (r,c)), \ dp[r][c-1] + \text{stepCost}((r,c-1) \to (r,c))\Big)$$
Rolling array space optimization reduces memory to **$O(N)$**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Rolling Row 1D DP** | $O(M \cdot N)$ | $O(N)$ |
| **2D Tabular DP** | $O(M \cdot N)$ | $O(M \cdot N)$ |
