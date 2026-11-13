# Distance of Nearest Cell Having 1 / 01 Matrix (LeetCode 542)

## Problem Statement
Given an `m x n` binary matrix `mat`, return the distance of the nearest `1` for each cell (or nearest `0` in LeetCode 542 convention).

The distance between two adjacent cells `(r1, c1)` and `(r2, c2)` is $|r1 - r2| + |c1 - c2|$ (Manhattan distance).

---

## Constraints
* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 10^4`
* `1 <= m * n <= 10^5`
* `mat[i][j]` is either `0` or `1`.
* There is at least one target cell in `mat`.

---

## Examples

### Example 1
**Input:**
```text
mat = [
  [0, 0, 0],
  [0, 1, 0],
  [0, 0, 0]
]
```
*(Finding nearest 1)*
**Output:**
```text
[
  [2, 1, 2],
  [1, 0, 1],
  [2, 1, 2]
]
```
**Explanation:**
- Cell `(1, 1)` has value 1, so its distance to nearest 1 is `0`.
- Cells `(0, 1)`, `(1, 0)`, `(1, 2)`, and `(2, 1)` are 1 step away from `(1, 1)`.
- The 4 corner cells are 2 steps away from `(1, 1)`.

---

### Example 2
**Input:**
```text
mat = [
  [1, 0, 1],
  [1, 1, 0],
  [1, 0, 0]
]
```
**Output:**
```text
[
  [0, 1, 0],
  [0, 0, 1],
  [0, 1, 2]
]
```

---

## Algorithmic Approaches

### Multi-Source Breadth-First Search (BFS)
- Searching from every `0` independently using single-source BFS takes $O((M \times N)^2)$ time, which TLEs for $M \times N = 10^5$.
- **Multi-Source BFS Insight:**
  - Start BFS from **all target cells simultaneously** at time $t = 0$!
  - Initialize a distance matrix `dist` with `-1` (or $\infty$).
  - Push all target cells `(r, c)` where `mat[r][c] == 1` into the queue and set `dist[r][c] = 0`.
  - While queue is not empty:
    - Pop `(r, c)`.
    - For each 4-directional neighbor `(nr, nc)`:
      - If `0 <= nr < m`, `0 <= nc < n`, and `dist[nr][nc] == -1`:
        - `dist[nr][nc] = dist[r][c] + 1`.
        - Push `(nr, nc)` into the queue.
  - Return `dist`.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ — Every cell enters and exits the BFS queue at most once.
- **Space Complexity:** $O(M \times N)$ — Distance matrix and queue buffer.
