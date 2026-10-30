# Search a 2D Matrix I (LeetCode 74)

## Problem Statement
You are given an `m x n` integer matrix `matrix` with the following two properties:
- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` if `target` is in `matrix` or `false` otherwise.

You must write a solution in $O(\log(m \times n))$ time complexity.

### Example 1:
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

### Constraints:
- `m == matrix.length`
- `n == matrix[i].length`
- `1 <= m, n <= 100`
- `-10^4 <= matrix[i][j], target <= 10^4`

---

## Pattern Insight: Virtual 1D Flattening
- Because the entire matrix is strictly sorted in row-major order from top-left to bottom-right, it is conceptually equivalent to a sorted 1D array of length $m \times n$.
- We can perform standard binary search on index range $[0, m \times n - 1]$ without copying the data:
  $$\text{row} = \frac{\text{mid}}{n}, \quad \text{col} = \text{mid} \pmod n$$
- Value at `mid` is simply `matrix[row][col]`.

---

## Complexity
- **Time Complexity:** $O(\log(m \cdot n))$ logarithmic time.
- **Space Complexity:** $O(1)$.
