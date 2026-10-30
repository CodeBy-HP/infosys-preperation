# Problem 4: Minimum Path Sum

## Problem Statement

Given an $m \times n$ grid filled with non-negative numbers, find a path from the top-left corner $(0, 0)$ to the bottom-right corner $(m - 1, n - 1)$ that **minimizes the sum of all numbers along its path**.

**Note:** You can only move either **down** or **right** at any point in time.

---

## Examples

### Example 1
```text
grid = [
  [1, 3, 1],
  [1, 5, 1],
  [4, 2, 1]
]
```
- **Output:** `7`
- **Explanation:** Path $1 \rightarrow 3 \rightarrow 1 \rightarrow 1 \rightarrow 1$ minimizes the sum: $1 + 3 + 1 + 1 + 1 = 7$.

### Example 2
```text
grid = [
  [1, 2, 3],
  [4, 5, 6]
]
```
- **Output:** `12`
- **Explanation:** Path $1 \rightarrow 2 \rightarrow 3 \rightarrow 6$ has sum $1 + 2 + 3 + 6 = 12$.

---

## Constraints

- $m == \text{grid.length}$
- $n == \text{grid}[i]\text{.length}$
- $1 \le m, n \le 200$
- $0 \le \text{grid}[i][j] \le 200$

---

## DP Logic: From Counting to Optimizing

1. **The State:**
   - $\text{dp}[r][c]$ represents the minimum path cost required to reach cell $(r, c)$ from $(0, 0)$.
2. **The Choice (Recurrence Relation):**
   - Since arrival at $(r, c)$ can only be from $(r - 1, c)$ or $(r, c - 1)$:
   $$\text{dp}[r][c] = \text{grid}[r][c] + \min(\text{dp}[r - 1][c],\, \text{dp}[r][c - 1])$$
3. **The Base Cases:**
   - Top-left starting cell: $\text{dp}[0][0] = \text{grid}[0][0]$.
   - First row: $\text{dp}[0][c] = \text{dp}[0][c - 1] + \text{grid}[0][c]$ (can only come from the left).
   - First column: $\text{dp}[r][0] = \text{dp}[r - 1][0] + \text{grid}[r][0]$ (can only come from above).
   - In recursion: out-of-bound cells return a large sentinel value ($\infty \approx 10^9$) so `min()` ignores them.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(M \times N)$ | $O(M \times N)$ | $O(M \times N)$ table + call stack |
| **Bottom-Up (2D Tabulation)** | $O(M \times N)$ | $O(M \times N)$ | Standard 2D table |
| **Space-Optimized Iterative** | $O(M \times N)$ | $O(N)$ | Rolling 1D array of width $N$ |
| **In-Place Tabulation** | $O(M \times N)$ | $O(1)$ | Directly mutates `grid` |

