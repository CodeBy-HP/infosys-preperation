# Unique Paths III (LeetCode 980)

## Problem Statement
You are given an `m x n` integer array `grid` where:
- `1` represents the **starting square**. There is exactly one starting square.
- `2` represents the **ending square**. There is exactly one ending square.
- `0` represents **empty squares** we can walk over.
- `-1` represents **obstacles** that we cannot walk over.

Return the **number of 4-directional walks** from the starting square to the ending square, that **walk over every non-obstacle square exactly once** (a Hamiltonian path).

---

## Constraints
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 20`
* `1 <= m * n <= 20` (Crucial constraint: $M \times N \le 20$ makes backtracking factorial/exponential search feasible!).
* `-1 <= grid[i][j] <= 2`
* There is exactly one starting cell (`1`) and exactly one ending cell (`2`).

---

## Examples

### Example 1
**Input:**
```text
grid = [
  [1, 0, 0, 0],
  [0, 0, 0, 0],
  [0, 0, 2, -1]
]
```
**Output:**
```text
2
```
**Explanation:**
We have the following two paths:
1. `(0,0),(0,1),(0,2),(0,3),(1,3),(1,2),(1,1),(1,0),(2,0),(2,1),(2,2)`
2. `(0,0),(1,0),(2,0),(2,1),(1,1),(0,1),(0,2),(0,3),(1,3),(1,2),(2,2)`
Both paths visit every empty square exactly once before reaching the ending square `2`.

```
1  0  0  0
0  0  0  0
0  0  2 -1
Total non-obstacle squares to visit: 11
Paths covering all 11 squares: 2
```

---

### Example 2
**Input:**
```text
grid = [
  [1, 0, 0, 0],
  [0, 0, 0, 0],
  [0, 0, 0, 2]
]
```
**Output:**
```text
4
```

---

### Example 3
**Input:**
```text
grid = [
  [0, 1],
  [2, 0]
]
```
**Output:**
```text
0
```
**Explanation:**
There is no path that can visit both empty cells and end at 2 without crossing a cell twice.

---

## Algorithmic Approaches

### Exact Backtracking (Hamiltonian Path DFS)
1. **Count Required Steps:**
   - Scan the grid to locate the starting cell `(start_r, start_c)`.
   - Count the total number of walk-able cells: `emptyCount = 1` (counting start `1`) + every cell with `0`.
2. **Backtracking Invariant:**
   - At current cell `(r, c)`:
     - If `grid[r][c] == 2`:
       - If `remain == 0`, we have visited every non-obstacle square $\longrightarrow$ return `1`.
       - Else return `0` (ended too early).
     - Save original value `temp = grid[r][c]`.
     - Mark current cell as visited: `grid[r][c] = -1`.
     - Total paths = sum of `dfs(nr, nc, remain - 1)` for all 4 cardinal neighbors `(nr, nc)` where `grid[nr][nc] != -1`.
     - **Backtrack:** Restore original value: `grid[r][c] = temp`.
3. Return total paths.

---

## Complexity Analysis
- **Time Complexity:** $O(4^{M \cdot N})$ worst-case, but heavily pruned by obstacles and boundaries. For $M \cdot N \le 20$, total recursive states $\le 10^5$, easily executing in $< 5$ ms.
- **Space Complexity:** $O(M \cdot N)$ for the recursion call stack.
