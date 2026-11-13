# Surrounded Regions (LeetCode 130)

## Problem Statement
Given an `m x n` matrix `board` containing `'X'` and `'O'`, **capture all regions that are 4-directionally surrounded by `'X'`**.

A region is **captured** by flipping all `'O'`s into `'X'`s in that surrounded region.

**Crucial Surrounding Rule:**
- An `'O'` is considered **surrounded** if it is impossible to walk to any boundary cell of the grid by only traversing 4-directionally connected `'O'`s.
- In other words, any `'O'` that is on the boundary or is connected 4-directionally to an `'O'` on the boundary **CANNOT** be captured!

---

## Constraints
* `m == board.length`
* `n == board[i].length`
* `1 <= m, n <= 200`
* `board[i][j]` is either `'X'` or `'O'`.

---

## Examples

### Example 1
**Input:**
```text
board = [
  ["X", "X", "X", "X"],
  ["X", "O", "O", "X"],
  ["X", "X", "O", "X"],
  ["X", "O", "X", "X"]
]
```
**Output:**
```text
[
  ["X", "X", "X", "X"],
  ["X", "X", "X", "X"],
  ["X", "X", "X", "X"],
  ["X", "O", "X", "X"]
]
```
**Explanation:**
- Notice the `'O'` at bottom row `(3, 1)`. Since it is on the boundary, it **cannot** be captured.
- The inner `'O'`s at `(1, 1)`, `(1, 2)`, and `(2, 2)` have no connection to any boundary `'O'`, so they are completely surrounded by `'X'`s and are flipped to `'X'`.

```
Initial Board:              Final Board:
X   X   X   X               X   X   X   X
X  (O) (O)  X     --->      X  [X] [X]  X
X   X  (O)  X               X   X  [X]  X
X  [O]  X   X               X  [O]  X   X
  (Boundary O)                (Survives!)
```

---

### Example 2
**Input:**
```text
board = [
  ["X"]
]
```
**Output:**
```text
[
  ["X"]
]
```

---

## Algorithmic Approaches

### Inversion Strategy: Boundary-Connected Flooding
Instead of checking whether every inner cell is surrounded (which requires searching for boundaries repeatedly), **reverse the thinking**:
*Any `'O'` connected to the outer boundary survives!*

1. **Phase 1: Identify and Protect Boundary `'O'`s**
   - Iterate through the 4 perimeter borders of the grid:
     - Row $0$ and Row $m - 1$ (for all $0 \le c < n$).
     - Col $0$ and Col $n - 1$ (for all $0 \le r < m$).
   - Whenever `board[r][c] == 'O'`, start a DFS/BFS to mark all reachable `'O'`s with a temporary sentinel `'#` (or `'T'`).
2. **Phase 2: Global Flip**
   - Traverse the entire grid:
     - If `board[r][c] == 'O'`: It was never reached from the boundary $\longrightarrow$ flip to `'X'`.
     - If `board[r][c] == '#'`: It was safely connected to the boundary $\longrightarrow$ restore back to `'O'`.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ — Phase 1 traverses boundary-connected cells once. Phase 2 scans the matrix once.
- **Space Complexity:** $O(M \times N)$ in the worst case for the recursion stack or BFS queue.
