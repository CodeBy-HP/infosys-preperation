# LeetCode 1293: Shortest Path in a Grid with Obstacles Elimination

## Problem Statement

You are given an `m x n` integer matrix `grid` where each cell is either `0` (empty) or `1` (obstacle).

You can move up, down, left, or right from and to an empty cell in one step.

Return the **minimum number of steps** to walk from the upper-left corner `(0, 0)` to the lower-right corner `(m - 1, n - 1)` given that you can eliminate **at most** `k` obstacles. If it is not possible to find such a walk, return `-1`.

---

## Input / Output Format

### Function Signature
- **C++:** `int shortestPath(vector<vector<int>>& grid, int k)`
- **Python:** `def shortestPath(self, grid: List[List[int]], k: int) -> int`
- **Java:** `public int shortestPath(int[][] grid, int k)`

### Return
- Minimum number of steps from `(0, 0)` to `(m - 1, n - 1)` with at most `k` eliminations, or `-1` if unreachable.

---

## Constraints

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 40`
* `1 <= k <= m * n`
* `grid[i][j]` is either `0` or `1`.
* `grid[0][0] == grid[m - 1][n - 1] == 0` (The starting and destination cells are always empty).

---

## Examples

### Example 1

**Input:**
```text
grid = [
  [0, 0, 0],
  [1, 1, 0],
  [0, 0, 0],
  [0, 1, 1],
  [0, 0, 0]
], 
k = 1
```

**Output:**
```text
6
```

**Explanation:**
- The shortest path without eliminating any obstacle is 10 steps.
- The shortest path with one obstacle elimination at position `(3, 2)` takes only 6 steps:
  `(0, 0) -> (0, 1) -> (0, 2) -> (1, 2) -> (2, 2) -> (3, 2) [eliminate] -> (4, 2)`

---

### Example 2

**Input:**
```text
grid = [
  [0, 1, 1],
  [1, 1, 1],
  [1, 0, 0]
], 
k = 1
```

**Output:**
```text
-1
```

**Explanation:**
We need to eliminate at least two obstacles to find any walk to `(2, 2)`, but `k = 1`, so it is impossible.

---

## State Representation (Key Idea)

Because you can visit a cell `(r, c)` with different numbers of remaining obstacle eliminations:
- Standard 2D `visited[r][c]` is insufficient.
- You need a 3D state: `visited[r][c][eliminations_remaining]` (or store the maximum remaining `k` reached for cell `(r, c)`).
- A state is uniquely identified by `(row, col, remaining_k)`.



## Confusion
Because BFS explores strictly minute-by-minute, if the first path (Path A) that visited that node had already reached the end, **the entire program would have stopped immediately.** The fact that the BFS is still running and allowing a slower second path (Path B) to revisit that node is absolute proof that Path A has not won yet.

There are exactly two things that could have happened to Path A after it left that node:

* **It died (hit a wall):** Path A moved forward but encountered a thick block of obstacles. Because it arrived with a low `k`, it couldn't break through, ran out of valid moves, and its branch of the BFS silently faded away.
* **It is still wandering:** Path A survived and is still exploring other parts of the grid, but it hasn't found the exit yet.

By letting Path B overwrite the visited state with a higher `k`, the algorithm essentially says, "Path A got here first, but it might fail or get blocked because it is too weak. Let's allow Path B to follow behind it, just in case Path B's extra `k` is needed to blast through a wall that Path A couldn't handle."


Let's say Path A reached (5,5) earlier with k = 4. The array recorded visited[5][5] = 4.
Now, Path B arrives at (5,5) later with k = 2.
The code checks: Is 2 > 4? No.

Because the condition is false, Path B is not added to the queue. It is instantly deleted.

Why is this mathematically safe?
Because Path A is strictly better in every way.

Path A is faster: Because BFS explores layer-by-layer, if Path A reached the cell before Path B, Path A took fewer steps.

Path A is stronger: Path A arrived with 4 obstacle breaks, while Path B only has 2.

If Path A is both faster and stronger, there is absolutely zero reason to let Path B continue. Anything Path B could possibly do from this point forward, Path A can do better and faster. Killing Path B immediately prevents the algorithm from doing useless, redundant work.