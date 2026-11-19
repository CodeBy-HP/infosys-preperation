# Find a Peak Element II (LeetCode 1901)

## Problem Statement

A **peak element** in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed $m \times n$ matrix `mat` where no two adjacent cells are equal, find **any peak element** `[R, C]` and return its coordinates.

You may assume that the entire matrix is surrounded by an outer perimeter of `-1`s.

You must write an algorithm that runs in **$O(m \log n)$ or $O(n \log m)$ time**.

---

## Examples

### Example 1
- **Input:**
  ```text
  mat = [
    [1, 4],
    [3, 2]
  ]
  ```
- **Output:** `[0, 1]` (value 4) or `[1, 0]` (value 3).
- **Explanation:** Both 4 and 3 are strictly greater than all their adjacent neighbors.

### Example 2
- **Input:**
  ```text
  mat = [
    [10, 20, 15],
    [21, 30, 14],
    [7,  16, 32]
  ]
  ```
- **Output:** `[1, 1]` (value 30) or `[2, 2]` (value 32).

---

## Constraints

- $m == \text{mat.length}$
- $n == \text{mat}[i]\text{.length}$
- $1 \le m, n \le 500$
- $1 \le \text{mat}[i][j] \le 10^5$
- No two adjacent cells are equal.

---

## The Column-Bisection Invariant

A 1D peak search uses slope gradients: if $A[i] < A[i+1]$, an uphill peak must exist to the right.
In 2D, we apply this across entire column profiles:

1. **Pick the Middle Column:** $\text{midCol} = \frac{leftCol + rightCol}{2}$.
2. **Find the Maximum in that Column:**
   - Scan all rows $0 \dots m - 1$ to find `maxRow` such that $\text{mat}[maxRow][midCol]$ is maximized.
   - **Key Property:** Because it is the column maximum, it is already strictly greater than its top and bottom neighbors.
3. **Compare with Horizontal Neighbors:**
   - Left neighbor: $L = \text{mat}[maxRow][midCol - 1]$ (or $-1$ if boundary).
   - Right neighbor: $R = \text{mat}[maxRow][midCol + 1]$ (or $-1$ if boundary).
4. **Gradient Navigation:**
   - If $\text{mat}[maxRow][midCol] > L$ and $\text{mat}[maxRow][midCol] > R$: It is strictly greater than all 4 neighbors $\implies$ **Peak Found!**
   - If $L > \text{mat}[maxRow][midCol]$: The uphill gradient points left $\implies$ a 2D peak is mathematically guaranteed in $[leftCol, midCol - 1]$.
   - Else ($R > \text{mat}[maxRow][midCol]$): The uphill gradient points right $\implies$ search in $[midCol + 1, rightCol]$.

Each step eliminates half the remaining columns in $O(m)$ work, yielding optimal **$O(m \log n)$** time.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Column Bisection Binary Search** | $O(m \log n)$ | $O(1)$ |
| **Row Bisection Binary Search** | $O(n \log m)$ | $O(1)$ |
| **2D Gradient Descent / Local Search** | $O(m \times n)$ | $O(1)$ |
| **Global Maximum Search** | $O(m \times n)$ | $O(1)$ |

