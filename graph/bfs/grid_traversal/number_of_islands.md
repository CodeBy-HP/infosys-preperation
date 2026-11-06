# Number of Islands (LeetCode 200)

## Problem Statement
Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return the **number of islands**.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically (4-directional: up, down, left, right). You may assume all four edges of the grid are entirely surrounded by water.

---

## Constraints
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 300`
* `grid[i][j]` is either `'0'` or `'1'`.

---

## Examples

### Example 1
**Input:**
```text
grid = [
  ["1", "1", "1", "1", "0"],
  ["1", "1", "0", "1", "0"],
  ["1", "1", "0", "0", "0"],
  ["0", "0", "0", "0", "0"]
]
```
**Output:**
```text
1
```
**Explanation:**
All `'1'`s form a single connected contiguous component.

---

### Example 2
**Input:**
```text
grid = [
  ["1", "1", "0", "0", "0"],
  ["1", "1", "0", "0", "0"],
  ["0", "0", "1", "0", "0"],
  ["0", "0", "0", "1", "1"]
]
```
**Output:**
```text
3
```
**Explanation:**
- Island 1: Top-left `2 x 2` block of `'1'`s.
- Island 2: Isolated center `'1'` at `(2, 2)`.
- Island 3: Bottom-right pair of `'1'`s at `(3, 3)` and `(3, 4)`.

---

## Algorithmic Approaches

### Approach 1: Connected Component Traversal (Sinking Islands via DFS)
1. Initialize `count = 0`.
2. Iterate through every cell `(r, c)` of the grid ($0 \le r < m, 0 \le c < n$).
3. When `grid[r][c] == '1'`:
   - Increment `count++`.
   - Start a DFS/BFS traversal from `(r, c)`.
   - **Sinking the Island:** Mark visited land as `'0'` (or `'2'`) directly in `grid` to prevent re-visiting and eliminate the need for an auxiliary `visited` matrix.
   - For all 4 adjacent neighbors $(nr, nc) \in \{(r+1, c), (r-1, c), (r, c+1), (r, c-1)\}$:
     - If within bounds and `grid[nr][nc] == '1'`, recurse.
4. Return `count`.

### Approach 2: Breadth-First Search (BFS)
- Replace recursion with an explicit queue `std::queue<pair<int, int>>`.
- When popping a cell, sink and enqueue all 4 valid neighbors.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ — Every cell is scanned once. Sinking ensures each land cell is explored at most once across all traversals.
- **Space Complexity:** $O(M \times N)$ in the worst case (grid completely filled with `'1'`s) for the recursion call stack or BFS queue.
