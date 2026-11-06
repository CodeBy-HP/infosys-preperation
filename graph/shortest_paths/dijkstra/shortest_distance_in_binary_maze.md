# Shortest Distance in a Binary Maze

## Problem Overview
Given an $M \times N$ binary grid `grid` where `0` represents an empty navigable cell and `1` represents an obstacle.
Given source coordinates `source = (srcR, srcC)` and destination coordinates `destination = (dstR, dstC)`.
Find the **shortest distance** (number of cell steps) to navigate from source to destination moving along adjacent cells. If no path exists, return `-1`.

---

## BFS Queue Property on Uniform Unit Edges
Because every step between adjacent cells incurs a cost of exactly $1$, running Dijkstra with a priority queue adds an unnecessary $O(\log(M \times N))$ factor.
**Standard BFS with a FIFO queue is strictly optimal ($O(M \times N)$)**:
1. If `grid[srcR][srcC] == 1` or `grid[dstR][dstC] == 1`, return `-1` immediately.
2. Initialize a 2D distance matrix `dist[M][N]` with $\infty$, setting `dist[srcR][srcC] = 0`.
3. Push `{0, srcR, srcC}` into a queue.
4. Process cells level-by-level:
   - When neighbor $(nr, nc)$ satisfies `grid[nr][nc] == 0` and `dist[r][c] + 1 < dist[nr][nc]`:
     $$\text{dist}[nr][nc] = \text{dist}[r][c] + 1$$
     If $(nr, nc) == (dstR, dstC)$, return $\text{dist}[nr][nc]$.
5. If queue exhausts without reaching destination, return `-1`.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$
- **Space Complexity:** $O(M \times N)$

