# Search a 2D Matrix II (LeetCode 240)

## Problem Statement
Write an efficient algorithm that searches for a value `target` in an `m x n` integer matrix `matrix`. This matrix has the following properties:
- Integers in each row are sorted in ascending from left to right.
- Integers in each column are sorted in ascending from top to bottom.

### Example 1:
```
Input: matrix = [
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
], target = 5
Output: true
```

### Constraints:
- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= n, m <= 300`
- `-10^9 <= matrix[i][j], target <= 10^9`

---

## Pattern Insight: Top-Right Saddleback Staircase Search
- Unlike Matrix I, the first element of a row is NOT necessarily greater than the last of the previous row. 1D flattening does not apply.
- Start at the **top-right corner** $(r = 0, c = n - 1)$:
  - All elements in column $c$ below are greater.
  - All elements in row $r$ to the left are smaller.
- Comparison:
  - If `matrix[r][c] == target`: Found!
  - If `matrix[r][c] > target`: Target cannot be in column $c$ $\to$ `c--`.
  - If `matrix[r][c] < target`: Target cannot be in row $r$ $\to$ `r++`.
- Each step eliminates an entire row or column. Runs in $O(m + n)$ time!

---

## Complexity
- **Time Complexity:** $O(m + n)$.
- **Space Complexity:** $O(1)$.
