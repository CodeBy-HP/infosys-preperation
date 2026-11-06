# Shortest Path in Binary Matrix / Maze (LeetCode 1091)

## Problem Statement
Given an `n x n` binary matrix `grid`, return the **length of the shortest clear path** in the matrix. If there is no clear path, return `-1`.

A **clear path** in a binary matrix is a path from the **top-left cell** `(0, 0)` to the **bottom-right cell** `(n - 1, n - 1)` such that:
1. All the visited cells of the path are `0`.
2. All the adjacent cells of the path are **8-directionally connected** (i.e., horizontally, vertically, or diagonally).

The **length of a clear path** is the number of visited cells of this path.

---

## Constraints
* `n == grid.length`
* `n == grid[i].length`
* `1 <= n <= 100`
* `grid[i][j]` is either `0` or `1`.

---

## Examples

### Example 1
**Input:**
```text
grid = [
  [0, 1],
  [1, 0]
]
```
**Output:**
```text
2
```
**Explanation:**
The path is `(0, 0) -> (1, 1)` (diagonal step). Both cells are `0`. Length = 2.

---

### Example 2
**Input:**
```text
grid = [
  [0, 0, 0],
  [1, 1, 0],
  [1, 1, 0]
]
```
**Output:**
```text
4
```
**Explanation:**
Path: `(0, 0) -> (0, 1) -> (0, 2) -> (1, 2) -> (2, 2)` or via diagonal `(0, 0) -> (0, 1) -> (1, 2) -> (2, 2)`. Shortest length = 4.

---

### Example 3
**Input:**
```text
grid = [
  [1, 0, 0],
  [1, 1, 0],
  [1, 1, 0]
]
```
**Output:**
```text
-1
```
**Explanation:**
The starting cell `(0, 0)` is blocked (`grid[0][0] == 1`). No path can begin.

---

## Algorithmic Approaches

### Why Plain Queue BFS Outperforms Dijkstra Here ($O(N^2)$ vs $O(N^2 \log N)$)
Because all 8 directional step weights are **unit uniform weight ($w = 1$)**:
- Standard BFS using a FIFO queue naturally explores cells in strictly non-decreasing order of distance.
- There is **no need for a priority queue / Dijkstra min-heap**, saving the $O(\log(N^2))$ overhead!

### Step-by-Step BFS Algorithm
1. Check base conditions: If `grid[0][0] != 0` or `grid[n - 1][n - 1] != 0`, return `-1`.
2. If $n == 1$, return `1`.
3. Initialize queue with `{0, 0, 1}` (`{row, col, distance}`) and mark `grid[0][0] = 1` (to serve as visited).
4. While queue is not empty:
   - Pop `{r, c, d}`.
   - If `r == n - 1 && c == n - 1`, return `d`.
   - Explore all 8 adjacent directions: $\Delta r \in \{-1, 0, 1\}, \Delta c \in \{-1, 0, 1\}$ (excluding $(0, 0)$):
     - If $0 \le nr < n$, $0 \le nc < n$, and `grid[nr][nc] == 0`:
       - Mark `grid[nr][nc] = 1` immediately (prevent duplicate enqueueing).
       - Push `{nr, nc, d + 1}`.
5. If queue empties without reaching `(n - 1, n - 1)`, return `-1`.

---

## Complexity Analysis
- **Time Complexity:** $O(N^2)$ — In an $N \times N$ grid, each cell enters and exits the queue at most once.
- **Space Complexity:** $O(N^2)$ for the BFS queue in the worst case.
