# Number of Enclaves (LeetCode 1020)

## Problem Statement
You are given an `m x n` binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.

A **move** consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Return the **number of land cells** in `grid` for which we **cannot walk off the boundary** of the grid in any number of moves (i.e. strictly enclosed islands of land).

---

## Constraints
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 500`
* `grid[i][j]` is either `0` or `1`.

---

## Examples

### Example 1
**Input:**
```text
grid = [
  [0, 0, 0, 0],
  [1, 0, 1, 0],
  [0, 1, 1, 0],
  [0, 0, 0, 0]
]
```
**Output:**
```text
3
```
**Explanation:**
- The land cell at `(1, 0)` is on the border, so you can walk off the grid from it.
- The three land cells at `(1, 2)`, `(2, 1)`, and `(2, 2)` are completely surrounded by sea cells (`0`). You cannot reach any boundary from them.
Total enclaves = 3.

```
0   0   0   0
[1] 0  (1)  0    --->  [1] reaches boundary (invalid)
0  (1) (1)  0    --->  Three (1)s enclosed (valid enclaves!)
0   0   0   0
```

---

### Example 2
**Input:**
```text
grid = [
  [0, 1, 1, 0],
  [0, 0, 1, 0],
  [0, 0, 1, 0],
  [0, 0, 0, 0]
]
```
**Output:**
```text
0
```
**Explanation:**
All land cells are connected to the border at `(0, 1)` and `(0, 2)`. Walking off the boundary is possible from every land cell.

---

## Algorithmic Approaches

### Inversion Strategy: Boundary Connected Land Elimination
1. **Flood Fill from Perimeter:**
   - Any land cell (`1`) connected to the boundary can walk off the grid.
   - Scan all four perimeter borders:
     - Top row (`r = 0`) and bottom row (`r = m - 1`).
     - Left column (`c = 0`) and right column (`c = n - 1`).
   - If `grid[r][c] == 1`:
     - Run BFS or DFS to sink this boundary-connected island by setting visited cells to `0` (or `2`).
2. **Count Remaining Enclosed Land:**
   - Scan the interior of `grid` ($1 \le r < m - 1$, $1 \le c < n - 1$).
   - Count all remaining `grid[r][c] == 1` cells.
3. Return the total count.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ — Each cell is visited at most twice (once during the boundary flood-fill and once during the final count scan).
- **Space Complexity:** $O(M \times N)$ worst-case memory for the recursion call stack or BFS queue.
