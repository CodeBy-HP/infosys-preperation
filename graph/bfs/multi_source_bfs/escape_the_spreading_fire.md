# LeetCode 2258: Escape the Spreading Fire

## Problem Statement

You are given a `0`-indexed `2D` integer array `grid` of size `m x n` which represents a field. Each cell has one of three values:

* `0` represents grass,
* `1` represents fire,
* `2` represents a wall that neither you nor fire can pass through.

You are situated in the top-left cell `(0, 0)`, and you want to travel to the safehouse at the bottom-right cell `(m - 1, n - 1)`.

Every minute:
1. You may move to an adjacent grass cell (or stay in place if waiting at the start).
2. After your move, every fire cell spreads to all adjacent cells that are not walls.

Return the **maximum number of minutes** that you can stay in your initial position before moving while still safely reaching the safehouse.
* If it is impossible to safely reach the safehouse, return `-1`.
* If you can always reach the safehouse regardless of the minutes stayed, return `10^9`.

### Important Notes:
* Even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as **safely reaching the safehouse**.
* However, along the path (any cell other than the safehouse), you cannot enter a cell at or after the time fire reaches it.
* A cell is adjacent to another cell if it is directly north, east, south, or west (4 directions).

---

## Input / Output Format

### Function Signature
- **C++:** `int maximumMinutes(vector<vector<int>>& grid)`
- **Python:** `def maximumMinutes(self, grid: List[List[int]]) -> int`
- **Java:** `public int maximumMinutes(int[][] grid)`

### Return
- Maximum integer minutes to wait at `(0, 0)` before starting your escape.
- `-1` if escape is impossible.
- `10^9` (or `1000000000`) if the safehouse can be reached with indefinite wait time.

---

## Constraints

* `m == grid.length`
* `n == grid[i].length`
* `2 <= m, n <= 300`
* `4 <= m * n <= 2 * 10^4`
* `grid[i][j]` is either `0`, `1`, or `2`.
* `grid[0][0] == grid[m - 1][n - 1] == 0` (starting position and safehouse are always grass initially).

---

## Examples

### Example 1

**Input:**
```text
grid = [
  [0, 2, 0, 0, 0, 0, 0],
  [0, 0, 0, 2, 2, 1, 0],
  [0, 2, 0, 0, 1, 2, 0],
  [0, 0, 2, 2, 2, 0, 2],
  [0, 0, 0, 0, 0, 0, 0]
]
```

**Output:**
```text
3
```

**Explanation:**
You can stay in the initial position `(0, 0)` for at most 3 minutes.
If you start moving at minute 3, you can follow an optimal path and reach `(4, 6)` safely before or at the same minute the fire arrives at the safehouse. Staying 4 or more minutes makes it impossible to escape.

---

### Example 2

**Input:**
```text
grid = [
  [0, 0, 0, 0],
  [0, 1, 2, 0],
  [0, 2, 0, 0]
]
```

**Output:**
```text
-1
```

**Explanation:**
Even if you start moving immediately at minute 0, the fire intercepts any valid path to the safehouse. Thus, it is impossible to escape safely.

---

### Example 3

**Input:**
```text
grid = [
  [0, 0, 0],
  [2, 2, 0],
  [1, 2, 0]
]
```

**Output:**
```text
1000000000
```

**Explanation:**
The fire is completely walled off by obstacles `2` and cannot reach the corridor to the safehouse. You can wait indefinitely, so `10^9` is returned.
