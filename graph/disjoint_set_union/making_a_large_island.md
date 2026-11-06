# Making a Large Island (LeetCode 827)

## Problem Overview
You are given an $N \times N$ binary matrix `grid`. You are allowed to change **at most one `0` to `1`**.
Return the **size of the largest island** in `grid` after applying this operation.
An island is a 4-directionally connected group of `1`s.

---

## 2D to 1D Disjoint Set Union Architecture
1. Flatten each 2D cell coordinate $(r, c)$ into a unique 1D index:
   $$\text{nodeId} = r \times N + c$$
2. **Phase 1: Union Existing Land Components**
   - Traverse the grid: for every cell $(r, c)$ where `grid[r][c] == 1`, union it with any 4-directional adjacent land cells using `unionBySize`.
   - Maintain the maximum existing component size.
3. **Phase 2: Evaluate Every Flippable `0`**
   - For every cell $(r, c)$ where `grid[r][c] == 0`:
     - Inspect all 4 neighbors $(nr, nc)$.
     - If neighbor is land (`grid[nr][nc] == 1`), find its root: $root = \text{findUPar}(nr \times N + nc)$.
     - Insert $root$ into an `unordered_set<int> uniqueRoots` to **prevent double-counting the same island** connected on multiple sides!
     - Potential merged island size:
       $$\text{mergedSize} = 1 + \sum_{root \in uniqueRoots} \text{size}[root]$$
     - Maximize with global best.

---

## Complexity Analysis
- **Time Complexity:** $O(N^2 \cdot \alpha(N^2)) \approx O(N^2)$
- **Space Complexity:** $O(N^2)$ for DSU structures.

