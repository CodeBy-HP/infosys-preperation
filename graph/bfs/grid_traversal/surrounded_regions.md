# Surrounded Regions (LeetCode 130)

## Problem Overview
Given an $M \times N$ matrix `board` containing `'X'` and `'O'`, **capture all regions that are 4-directionally surrounded by `'X'`**.
A region is captured by flipping all `'O'`s into `'X'`s in that surrounded region.
Crucially: Any `'O'` located on the boundary of the grid—or connected 4-directionally to a boundary `'O'`—can **never** be surrounded and must not be flipped.

---

## Boundary Protection Strategy
1. Traverse all 4 outer boundaries of the board (first row, last row, first column, last column).
2. Whenever an `'O'` is found on the boundary, run a DFS / BFS from it and temporarily change all reachable `'O'` cells to an escape marker `'#'`.
3. Traverse the entire matrix:
   - Any remaining `'O'` is completely isolated from the border and is captured: flip to `'X'`.
   - Any `'#'` was a protected boundary-connected cell: restore back to `'O'`.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$
- **Space Complexity:** $O(M \times N)$ worst-case recursion stack.

