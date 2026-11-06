# Number of Enclaves (LeetCode 1020)

## Problem Overview
You are given an $M \times N$ binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.
A move consists of walking from one land cell to another adjacent (4-directional) land cell or walking off the boundary of the grid.
Return the **number of land cells in grid for which we cannot walk off the boundary** of the grid in any number of moves.

---

## Boundary-First Inversion Strategy
Any land cell that can reach the boundary can walk off the grid.
Therefore, instead of checking each interior cell:
1. Traverse all land cells `1` located on the **4 outer boundaries** (row $0$, row $M-1$, col $0$, col $N-1$).
2. Run BFS / DFS starting from these boundary land cells to mark / sink all boundary-connected land.
3. Traverse the entire grid and count all remaining `1`s. These are precisely the **enclosed enclaves**!

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$
- **Space Complexity:** $O(M \times N)$ for queue / recursion buffer.

