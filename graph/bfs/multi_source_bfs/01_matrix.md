# LeetCode 542: 01 Matrix

## Problem Statement

Given an `m x n` binary matrix `mat`, return *the distance of the nearest `0` for each cell*.

The distance between two adjacent cells sharing a common edge (up, down, left, or right) is `1`.

---

## Input / Output Format

### Function Signature
- **C++:** `vector<vector<int>> updateMatrix(vector<vector<int>>& mat)`
- **Python:** `def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]`
- **Java:** `public int[][] updateMatrix(int[][] mat)`

### Return
- An `m x n` matrix of integers where each cell contains the shortest distance to the nearest `0`.

---

## Constraints

* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 10^4`
* `1 <= m * n <= 10^4`
* `mat[i][j]` is either `0` or `1`.
* There is at least one `0` in `mat`.

---

## Examples

### Example 1

**Input:**
```text
mat = [
  [0, 0, 0],
  [0, 1, 0],
  [0, 0, 0]
]
```

**Output:**
```text
[
  [0, 0, 0],
  [0, 1, 0],
  [0, 0, 0]
]
```

---

### Example 2

**Input:**
```text
mat = [
  [0, 0, 0],
  [0, 1, 0],
  [1, 1, 1]
]
```

**Output:**
```text
[
  [0, 0, 0],
  [0, 1, 0],
  [1, 2, 1]
]
```

**Explanation:**
- The cell at `(2, 1)` has distance 2 to the nearest `0` (via `(1, 1)` to `(0, 1)` or `(1, 0)` or `(1, 2)`).
- All boundary `1`s directly border a `0`, so their distance is `1`.
