# Making A Large Island (LeetCode 827)

## Problem Statement
You are given an `n x n` binary matrix `grid`. You are allowed to change **at most one** `0` to be `1`.

Return the **size of the largest island** in `grid` after applying this operation.

An **island** is a 4-directionally connected group of `1`s.

---

## Constraints
* `n == grid.length`
* `n == grid[i].length`
* `1 <= n <= 500`
* `grid[i][j]` is either `0` or `1`.

---

## Examples

### Example 1
**Input:**
```text
grid = [
  [1, 0],
  [0, 1]
]
```
**Output:**
```text
3
```
**Explanation:**
Change one `0` to `1` (e.g. at `(0, 1)`). The grid becomes:
```text
[1, 1]
[0, 1]
```
All three `1`s are connected into an island of size 3.

---

### Example 2
**Input:**
```text
grid = [
  [1, 1],
  [1, 0]
]
```
**Output:**
```text
4
```
**Explanation:**
Change the `0` at `(1, 1)` to `1` to connect all 4 cells. Largest island = 4.

---

### Example 3
**Input:**
```text
grid = [
  [1, 1],
  [1, 1]
]
```
**Output:**
```text
4
```
**Explanation:**
The grid already consists entirely of `1`s. Maximum size remains 4.

---

## Algorithmic Approaches

### Two-Phase DSU Component Synthesis
1. **Phase 1: Build Connected Components of Existing Land**
   - Flatten 2D coordinate `(r, c)` to $r \times n + c$.
   - Initialize a DSU with `n * n` nodes.
   - For every cell `(r, c)` where `grid[r][c] == 1`:
     - For each of its 4 neighbors `(nr, nc)`:
       - If within bounds and `grid[nr][nc] == 1`:
         - `dsu.unionBySize(r * n + c, nr * n + nc)`.
   - Track `maxIsland = max(dsu.size[root])` (handles case where grid is already full of `1`s).

2. **Phase 2: Try Flipping Each `0` Cell**
   - For every cell `(r, c)` where `grid[r][c] == 0`:
     - Flipping this cell to `1` connects all distinct neighboring islands!
     - Use a `std::unordered_set<int> uniqueRoots` to deduplicate neighbors belonging to the **same** island.
     - For each of the 4 neighbors `(nr, nc)`:
       - If within bounds and `grid[nr][nc] == 1`:
         - `uniqueRoots.insert(dsu.findUPar(nr * n + nc))`.
     - Calculate potential combined size:
       $$\text{potentialSize} = 1 + \sum_{\text{root} \in \text{uniqueRoots}} \text{dsu.size}[\text{root}]$$
     - `maxIsland = max(maxIsland, potentialSize)`.

3. Return `maxIsland`.

---

## Complexity Analysis
- **Time Complexity:** $O(N^2 \cdot \alpha(N^2))$ — Phase 1 unions all adjacent land cells. Phase 2 checks 4 neighbors for each zero.
- **Space Complexity:** $O(N^2)$ for DSU parent and size arrays.
