# LeetCode 994: Rotting Oranges

## Problem Statement

You are given an `m x n` grid where each cell can have one of three values:

* `0` representing an empty cell,
* `1` representing a fresh orange, or
* `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** (up, down, left, or right) to a rotten orange becomes rotten.

Return *the minimum number of minutes that must elapse until no cell has a fresh orange*. If this is impossible, return `-1`.

---

## Input / Output Format

### Function Signature
- **C++:** `int orangesRotting(vector<vector<int>>& grid)`
- **Python:** `def orangesRotting(self, grid: List[List[int]]) -> int`
- **Java:** `public int orangesRotting(int[][] grid)`

### Return
- An integer representing the minimum number of minutes to rot all fresh oranges, or `-1` if some fresh oranges can never be reached.

---

## Constraints

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 10`
* `grid[i][j]` is `0`, `1`, or `2`.

---

## Examples

### Example 1

**Input:**
```text
grid = [[2,1,1],[1,1,0],[0,1,1]]
```

**Output:**
```text
4
```

**Explanation:**
- Minute 0: `[[2,1,1],[1,1,0],[0,1,1]]`
- Minute 1: `[[2,2,1],[2,1,0],[0,1,1]]`
- Minute 2: `[[2,2,2],[2,2,0],[0,1,1]]`
- Minute 3: `[[2,2,2],[2,2,0],[0,2,1]]`
- Minute 4: `[[2,2,2],[2,2,0],[0,2,2]]`
All fresh oranges rot after 4 minutes.

---

### Example 2

**Input:**
```text
grid = [[2,1,1],[0,1,1],[1,0,1]]
```

**Output:**
```text
-1
```

**Explanation:**
The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally and it is isolated.

---

### Example 3

**Input:**
```text
grid = [[0,2]]
```

**Output:**
```text
0
```

**Explanation:**
Since there are already no fresh oranges at minute 0, the answer is just 0.
