# Minimum Falling Path Sum (LeetCode 931)

## Problem Statement

Given an $n \times n$ array of integers `matrix`, return the **minimum sum of any falling path** through `matrix`.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position $(row, col)$ will be:
- $(row + 1, col - 1)$
- $(row + 1, col)$
- $(row + 1, col + 1)$

---

## Examples

### Example 1:
```text
Input: matrix = [
  [2, 1, 3],
  [6, 5, 4],
  [7, 8, 9]
]
Output: 13
Explanation:
Falling path with minimum sum: 1 -> 5 -> 7 (or 1 -> 4 -> 8):
1 + 5 + 7 = 13.
1 + 4 + 8 = 13.
Minimum path sum is 13.
```

### Example 2:
```text
Input: matrix = [
  [-19, 57],
  [-40, -5]
]
Output: -59
Explanation:
The falling path with minimum sum is -19 -> -40 = -59.
```

---

## Constraints

- `n == matrix.length == matrix[i].length`
- `1 <= n <= 100`
- `-100 <= matrix[i][j] <= 100`

---

## Recurrence Formulation & Algorithmic Approaches

### 1. State Definition
Let $dp[i][j]$ represent the minimum falling path sum ending at cell $(i, j)$ in row $i$ and column $j$.

### 2. State Transition
From row $i - 1$, cell $(i, j)$ can be reached from $(i - 1, j - 1)$, $(i - 1, j)$, or $(i - 1, j + 1)$ (guarding against column boundaries):
$$dp[i][j] = matrix[i][j] + \min\Big( dp[i-1][j-1] \; (\text{if } j > 0), \; dp[i-1][j], \; dp[i-1][j+1] \; (\text{if } j < n - 1) \Big)$$

### 3. Base Case & Final Result
- **Base Case ($i = 0$):** $dp[0][j] = matrix[0][j]$ for all $0 \le j < n$.
- **Final Result:** The answer is the minimum value in the last row:
  $$\text{Min Falling Path Sum} = \min_{0 \le j < n} dp[n - 1][j]$$

### 4. Space Optimization ($O(N)$)
Notice that each row $i$ only accesses values from row $i - 1$. We can maintain two 1D vectors `prev` and `curr` of length $n$, or update `matrix` in-place.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Recursive + Memoization** | $O(N^2)$ | $O(N^2)$ table + $O(N)$ stack |
| **Tabulation (2D DP)** | $O(N^2)$ | $O(N^2)$ |
| **Space-Optimized (Rolling Rows)** | $O(N^2)$ | $O(N)$ |
| **In-Place Tabulation** | $O(N^2)$ | $O(1)$ |
