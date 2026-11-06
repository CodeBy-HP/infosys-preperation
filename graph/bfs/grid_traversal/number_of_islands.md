# Number of Islands (LeetCode 200)

## Problem Overview
Given an $M \times N$ 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return the **number of islands**.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically (4-directional).
You may assume all four edges of the grid are all surrounded by water.

---

## 2D Connected Component Traversal
Every cell $(r, c)$ with `'1'` represents a graph vertex connected to its 4 cardinal neighbors $(r \pm 1, c)$ and $(r, c \pm 1)$.
1. Scan every cell $(r, c)$ in the $M \times N$ grid.
2. If `grid[r][c] == '1'`:
   - Increment `islandCount`.
   - Run BFS or DFS to sink the island (mark visited cells as `'0'` or use a `visited` matrix).
3. Sinking visited land directly in-place achieves $O(1)$ auxiliary space beyond the traversal stack/queue.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ since every cell is visited a constant number of times.
- **Space Complexity:** $O(M \times N)$ in the worst case (grid full of land) for recursion or queue buffer.

