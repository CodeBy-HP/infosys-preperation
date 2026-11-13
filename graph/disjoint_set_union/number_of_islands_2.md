# Number of Islands II (LeetCode 305 / Dynamic Islands)

## Problem Statement
You are given an empty 2D binary grid of size `m x n`. The grid represents a map where `0` represents water and `1` represents land. Initially, all cells are water.

We may perform an **add land** operation which turns the water at position `(row, col)` into land. You are given an array `positions` where `positions[i] = [r_i, c_i]` is the position at which we should operate at the $i^{\text{th}}$ step.

Return an array of integers `ans` where `ans[i]` is the **number of islands** after turning the cell `positions[i]` into land.

An **island** is formed by connecting adjacent lands horizontally or vertically (4-directional). You may assume all four edges of the grid are surrounded by water. Duplicate operations at the same position should not alter the island count.

---

## Constraints
* `1 <= m, n <= 10^4`
* `1 <= m * n <= 10^5`
* `1 <= positions.length <= 10^4`
* `0 <= r_i < m`, `0 <= c_i < n`

---

## Examples

### Example 1
**Input:**
```text
m = 3, n = 3, positions = [[0, 0], [0, 1], [1, 2], [2, 1]]
```
**Output:**
```text
[1, 1, 2, 3]
```
**Explanation:**
- Initially, the 2D grid is all water (`0`).
- Step 1: Add land at `(0, 0)` $\implies$ 1 island.
- Step 2: Add land at `(0, 1)` $\implies$ connected to `(0, 0)`, merges into 1 island.
- Step 3: Add land at `(1, 2)` $\implies$ isolated, total 2 islands.
- Step 4: Add land at `(2, 1)` $\implies$ isolated, total 3 islands.

```
Operation 1:     Operation 2:     Operation 3:     Operation 4:
1  0  0          1--1  0          1--1  0          1--1  0
0  0  0  --->    0  0  0  --->    0  0  1  --->    0  0  1
0  0  0          0  0  0          0  0  0          0  1  0
(count = 1)      (count = 1)      (count = 2)      (count = 3)
```

---

### Example 2
**Input:**
```text
m = 1, n = 2, positions = [[0, 1], [0, 0]]
```
**Output:**
```text
[1, 1]
```

---

## Algorithmic Approaches

### Why Plain BFS/DFS TLEs
Re-running BFS/DFS after every position update takes $O(K \times M \times N)$ where $K = 10^4$ and $M \times N = 10^5$ $\implies 10^9$ operations!
We need **incremental, dynamic component merging** in near $O(1)$ time per query $\implies$ **Disjoint Set Union (DSU)**.

### Dynamic DSU Algorithm
1. Flatten 2D coordinates to 1D index:
   $$\text{nodeId} = r \times n + c$$
2. Initialize `visited` matrix (or set) and a DSU of size $m \times n$.
3. Maintain running count `islandCount = 0`.
4. For each `[r, c]` in `positions`:
   - If `visited[r][c] == 1`:
     - Already land! Duplicate operation $\longrightarrow$ append current `islandCount` and continue.
   - Mark `visited[r][c] = 1`.
   - Increment `islandCount++` (treat new land as a new independent island).
   - Check all 4 cardinal neighbors `(nr, nc)`:
     - If $0 \le nr < m$, $0 \le nc < n$, and `visited[nr][nc] == 1`:
       - `int u = r * n + c`, `int v = nr * n + nc`.
       - If `dsu.unionBySize(u, v)` returns `true` (two previously disconnected components merged):
         - Decrement `islandCount--`.
   - Append `islandCount` to result list.
5. Return result.

---

## Complexity Analysis
- **Time Complexity:** $O(K \cdot \alpha(M \cdot N))$ where $K = \text{positions.length}$. Each position checks 4 neighbors with near $O(1)$ DSU operations.
- **Space Complexity:** $O(M \cdot N)$ for DSU parent, size, and visited arrays.
