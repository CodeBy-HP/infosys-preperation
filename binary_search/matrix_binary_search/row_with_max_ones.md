# Find Row with Maximum 1's

## Problem Statement

Given a boolean 2D array `mat` of dimensions $N \times M$ where each row is sorted in non-decreasing order (all `0`s precede all `1`s).

Find the 0-based index of the **first row that has the maximum number of 1's**. If no row has any 1's, return `-1`.

---

## Examples

### Example 1
- **Input:**
  ```text
  mat = [
    [0, 1, 1, 1],
    [0, 0, 1, 1],
    [1, 1, 1, 1],
    [0, 0, 0, 0]
  ]
  ```
- **Output:** `2`
- **Explanation:** Row 2 has four 1's, which is the maximum.

### Example 2
- **Input:**
  ```text
  mat = [
    [0, 0],
    [0, 0]
  ]
  ```
- **Output:** `-1`
- **Explanation:** There are no 1's in the matrix.

---

## Constraints

- $1 \le N, M \le 1000$
- `mat[i][j]` is either `0` or `1`.
- Each row of `mat` is sorted in non-decreasing order.

---

## Algorithmic Insights

### Approach 1: Binary Search per Row ($O(N \log M)$)
Since each row is sorted:
- Find the first occurrence of `1` in row $i$ using `lower_bound(1)`.
- If the first `1` is at index `firstIdx`, the number of 1's in that row is $M - \text{firstIdx}$.
- Track the maximum count across all rows.

### Approach 2: Optimal Saddleback Staircase ($O(N + M)$)
Start at the top-right corner: $(row = 0, col = M - 1)$:
1. If $\text{mat}[row][col] == 1$:
   - This row has at least $M - col$ ones.
   - We record this row as the current winner and move **left** (`col--`) to check if this row has even more 1's.
2. If $\text{mat}[row][col] == 0$:
   - This row has no more 1's to the left. We must move **down** (`row++`) to search in subsequent rows.
3. Terminate when either row goes out of bounds or column drops below 0.
This inspects each row and column at most once, achieving linear $O(N + M)$ time.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Saddleback Top-Right Staircase** | $O(N + M)$ | $O(1)$ |
| **Binary Search Lower Bound per Row** | $O(N \log M)$ | $O(1)$ |
| **Brute Force Linear Scan** | $O(N \times M)$ | $O(1)$ |

