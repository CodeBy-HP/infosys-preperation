# Distance of Nearest Cell Having 1 (0/1 Matrix Dual)

## Problem Overview
Given a binary grid of $N \times M$. Find the distance of the nearest cell having `1` for each cell.
The distance between two adjacent cells sharing a common edge is `1`.

---

## Multi-Source BFS Formulation
Running BFS from every single cell of value `0` would take $O((N \times M)^2)$ time, causing TLE.
Instead, use **Multi-Source BFS**:
1. Initialize a `dist` matrix of size $N \times M$ with `-1`.
2. Push all coordinates $(r, c)$ where `grid[r][c] == 1` into the BFS queue with distance `0`, and set `dist[r][c] = 0`.
3. Process nodes level-by-level. For each neighbor $(nr, nc)$ where `dist[nr][nc] == -1`:
   $$\text{dist}[nr][nc] = \text{dist}[r][c] + 1$$
   Push $(nr, nc)$ into the queue.
4. By BFS level properties, the first time a cell is reached, it is reached via the **globally shortest distance**.

---

## Complexity Analysis
- **Time Complexity:** $O(N \times M)$
- **Space Complexity:** $O(N \times M)$ for queue and distance matrix.

