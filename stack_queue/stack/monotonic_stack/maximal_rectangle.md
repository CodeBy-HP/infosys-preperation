# Maximal Rectangle (LeetCode 85)

## Problem Statement

Given a `rows x cols` binary `matrix` filled with `'0'`s and `'1'`s, find the largest rectangle containing only `'1'`s and return its area.

---

## Examples

### Example 1
- **Input:**
  ```text
  matrix = [
    ["1","0","1","0","0"],
    ["1","0","1","1","1"],
    ["1","1","1","1","1"],
    ["1","0","0","1","0"]
  ]
  ```
- **Output:** `6`
- **Explanation:** The maximal rectangle has area = 6 (height 2, width 3) spanning rows 1-2, columns 2-4.

### Example 2
- **Input:** `matrix = [["0"]]`
- **Output:** `0`

### Example 3
- **Input:** `matrix = [["1"]]`
- **Output:** `1`

---

## Constraints

- `rows == matrix.length`
- `cols == matrix[i].length`
- $1 \le \text{rows}, \text{cols} \le 200$
- `matrix[i][j]` is `'0'` or `'1'`.

---

## The Rolling Histogram Reduction

This problem reduces directly to **Largest Rectangle in Histogram (LeetCode 84)**:
1. Maintain a 1D array `heights` of size `cols`.
2. For each row $r$ from $0$ to $\text{rows}-1$:
   - For each column $c$:
     - If $\text{matrix}[r][c] == '1'$, increment $\text{heights}[c] += 1$.
     - If $\text{matrix}[r][c] == '0'$, reset $\text{heights}[c] = 0$.
3. Treat `heights` as a histogram and execute the $O(C)$ **Monotonic Increasing Stack** algorithm to find the largest rectangular area bounded by row $r$.
4. Track the global maximum across all rows.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Rolling Histogram + Monotonic Stack** | $O(R \times C)$ | $O(C)$ | Optimal single-pass stack per row |
| **DP (left, right, height arrays)** | $O(R \times C)$ | $O(C)$ | Boundary propagation |
| **Row-Pair Intersection Brute Force** | $O(R^2 \times C)$ | $O(C)$ | Checks bitwise AND of rows |

