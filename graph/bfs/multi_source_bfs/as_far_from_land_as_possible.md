# LeetCode 1162: As Far from Land as Possible

## Problem Statement

Given an `n x n` grid containing only values `0` and `1`, where:
* `0` represents water, and
* `1` represents land,

find a water cell such that its distance to the nearest land cell is maximized, and return the distance. If no land or water exists in the grid, return `-1`.

The distance used in this problem is the **Manhattan distance**: the distance between two cells `(x0, y0)` and `(x1, y1)` is `|x0 - x1| + |y0 - y1|`.

---

## Input / Output Format

### Function Signature
- **C++:** `int maxDistance(vector<vector<int>>& grid)`
- **Python:** `def maxDistance(self, grid: List[List[int]]) -> int`
- **Java:** `public int maxDistance(int[][] grid)`

### Return
- An integer representing the maximum Manhattan distance from any water cell to its nearest land cell.
- Return `-1` if the grid contains only water (`0`s) or only land (`1`s).

---

## Constraints

* `n == grid.length`
* `n == grid[i].length`
* `1 <= n <= 100`
* `grid[i][j]` is `0` or `1`.

---

## Examples

### Example 1

**Input:**
```text
grid = [
  [1, 0, 1],
  [0, 0, 0],
  [1, 0, 1]
]
```

**Output:**
```text
2
```

**Explanation:**
The cell `(1, 1)` is as far as possible from all the land with a distance of 2.

---

### Example 2

**Input:**
```text
grid = [
  [1, 0, 0],
  [0, 0, 0],
  [0, 0, 0]
]
```

**Output:**
```text
4
```

**Explanation:**
The cell `(2, 2)` is as far as possible from all the land with a distance of 4.
