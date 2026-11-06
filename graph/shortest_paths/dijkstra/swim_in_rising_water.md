# Swim in Rising Water (LeetCode 778)

## Problem Statement
You are given an `n x n` integer matrix `grid` where each value `grid[i][j]` represents the elevation at that point `(i, j)`.

The rain starts to fall. At time `t`, the depth of the water everywhere is `t`. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares is **at most `t`**. You can swim infinite distances in zero time within connected water.

You start at the top left square `(0, 0)`. What is the **minimum time `t`** until you can reach the bottom right square `(n - 1, n - 1)`?

---

## Constraints
* `n == grid.length`
* `n == grid[i].length`
* `1 <= n <= 50`
* `0 <= grid[i][j] < n^2`
* Each value `grid[i][j]` is **unique**.

---

## Examples

### Example 1
**Input:**
```text
grid = [
  [0, 2],
  [1, 3]
]
```
**Output:**
```text
3
```
**Explanation:**
At time 0, you are at `(0, 0)` with elevation 0. You cannot swim anywhere because adjacent cells have elevation 1 and 2.
At time 1, you can swim to `(1, 0)`.
You cannot reach `(1, 1)` until time $t = 3$, when the water level rises to cover `grid[1][1] = 3`.

---

### Example 2
**Input:**
```text
grid = [
  [0,  1,  2,  3,  4],
  [24, 23, 22, 21, 5],
  [12, 13, 14, 15, 16],
  [11, 17, 18, 19, 20],
  [10,  9,  8,  7,  6]
]
```
**Output:**
```text
16
```
**Explanation:**
The final route `[0, 1, 2, 3, 4, 5, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6]` stays within cells with elevation $\le 16$.
We need to wait until $t = 16$ so that cell `(1, 4)` (elevation 5) connects to `(2, 4)` (elevation 16).

---

## Algorithmic Approaches

### Approach 1: Modified Dijkstra (Minimax Path)
The time to traverse a path is determined by the **maximum elevation** encountered along that path:
$$\text{cost}(\text{path}) = \max_{(r, c) \in \text{path}} \text{grid}[r][c]$$

1. Maintain `dist[r][c]`: Minimum possible water level required to reach `(r, c)`.
2. Min-Priority Queue stores `{time, r, c}`.
3. Push `{grid[0][0], 0, 0}` into `pq`.
4. While `pq` is not empty:
   - Pop `{t, r, c}`.
   - If `r == n - 1 && c == n - 1`, return `t`.
   - If `t > dist[r][c]`, continue.
   - For all 4 adjacent neighbors `(nr, nc)`:
     - `newTime = max(t, grid[nr][nc])`.
     - If `newTime < dist[nr][nc]`:
       - `dist[nr][nc] = newTime`.
       - Push `{newTime, nr, nc}` into `pq`.

### Approach 2: Binary Search on Answer + BFS
- Range for $t$: $[0, n^2 - 1]$.
- Test if `(n - 1, n - 1)` is reachable through cells with elevation $\le mid$ using standard BFS in $O(N^2)$ time.

---

## Complexity Analysis
- **Time Complexity:** $O(N^2 \log(N^2)) = O(N^2 \log N)$ — Using Dijkstra min-heap over $N^2$ cells.
- **Space Complexity:** $O(N^2)$ for the distance matrix and priority queue.
