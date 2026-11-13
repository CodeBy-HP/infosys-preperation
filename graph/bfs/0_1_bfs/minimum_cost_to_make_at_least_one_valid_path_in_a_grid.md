# Minimum Cost to Make at Least One Valid Path in a Grid (LeetCode 1368)

## Problem Statement
Given an `m x n` grid. Each cell of the grid has a sign pointing to the next cell you should visit if you are currently in this cell:
- `1` which means go to the cell to the right. (i.e. to the cell `(r, c + 1)`)
- `2` which means go to the cell to the left. (i.e. to the cell `(r, c - 1)`)
- `3` which means go to the cell down. (i.e. to the cell `(r + 1, c)`)
- `4` which means go to the cell up. (i.e. to the cell `(r - 1, c)`)

Notice that there could be some signs on the cells of the grid which point outside the grid.

You initially start at the upper left cell `(0, 0)`. A valid path in the grid is a path which starts from the upper left cell `(0, 0)` and ends at the bottom-right cell `(m - 1, n - 1)` following the signs on the cells. The valid path does not have to be the shortest.

You can modify the sign on a cell with `cost = 1`. You can modify the sign on a cell **at most once**.

Return the **minimum cost** to make at least one valid path.

---

## Constraints
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 100`
* `1 <= grid[i][j] <= 4`

---

## Examples

### Example 1
**Input:**
```text
grid = [
  [1, 1, 1, 1],
  [2, 2, 2, 2],
  [1, 1, 1, 1],
  [2, 2, 2, 2]
]
```
**Output:**
```text
3
```
**Explanation:**
- Start at `(0, 0)`. Sign points right: follow signs without cost to `(0, 3)`.
- Change sign at `(0, 3)` from right (`1`) to down (`3`) with cost 1.
- Move down to `(1, 3)`. Change sign from left (`2`) to down (`3`) with cost 1.
- Move down to `(2, 3)`. Change sign from right (`1`) to down (`3`) with cost 1.
- Move down to `(3, 3)`. Total cost = 3.

---

### Example 2
**Input:**
```text
grid = [
  [1, 1, 3],
  [3, 2, 2],
  [1, 1, 4]
]
```
**Output:**
```text
0
```
**Explanation:**
You can follow the existing signs from `(0, 0)` all the way to `(2, 2)` without modifying any cell. Cost = 0.

---

## Algorithmic Approaches

### Why 0-1 BFS is Strictly Optimal ($O(M \times N)$ vs Dijkstra $O(MN \log(MN))$)
Observe the edge weights:
- Moving in the direction the current cell **already points to** costs **$0$**.
- Moving in any of the other 3 directions requires modifying the sign, costing **$1$**.
Because edge weights are strictly binary $\{0, 1\}$:
- Standard Dijkstra's priority queue takes $O(V \log V)$ time.
- **0-1 BFS with `std::deque` takes strictly $O(V)$ linear time**:
  - If the transition cost is $0$: push to the **FRONT** of the deque.
  - If the transition cost is $1$: push to the **BACK** of the deque.
  This maintains the invariant that the deque is always sorted by distance!

### Algorithm
1. Initialize `dist[m][n]` with $\infty$, and set `dist[0][0] = 0`.
2. Push `{0, 0}` to front of `deque<pair<int, int>> dq`.
3. While `dq` is not empty:
   - Pop `{r, c}` from front.
   - If `r == m - 1 && c == n - 1`, return `dist[r][c]`.
   - Direction vectors: `dr = [0, 0, 1, -1]`, `dc = [1, -1, 0, 0]` corresponding to signs $1, 2, 3, 4$.
   - For $k = 0 \dots 3$:
     - `nr = r + dr[k]`, `nc = c + dc[k]`.
     - `edgeCost = (grid[r][c] == k + 1) ? 0 : 1`.
     - If $0 \le nr < m$, $0 \le nc < n$, and `dist[r][c] + edgeCost < dist[nr][nc]`:
       - `dist[nr][nc] = dist[r][c] + edgeCost`.
       - If `edgeCost == 0`: `dq.push_front({nr, nc})`.
       - Else: `dq.push_back({nr, nc})`.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ — Each cell is popped from the front of the deque at most once.
- **Space Complexity:** $O(M \times N)$ for the distance matrix and deque.
