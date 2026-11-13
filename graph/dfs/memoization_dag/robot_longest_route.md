# Longest Increasing Path in a Matrix / Robot Longest Route (LeetCode 329)

## Problem Statement
A robotics company has developed an autonomous robot that navigates through an `m x n` terrain matrix `matrix`. Each cell of the terrain contains an integer representing its elevation.

The robot can move in four directions: **up, down, left, right**. The robot can move to a neighboring cell **if and only if** the neighboring cell has a **strictly greater elevation** than the current cell:
$$\text{matrix}[nr][nc] > \text{matrix}[r][c]$$

Determine the **length of the longest possible increasing route** that the robot can travel anywhere in the matrix. Return the maximum number of cells visited along any strictly increasing path.

---

## Constraints
* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 200`
* `0 <= matrix[i][j] <= 2^{31} - 1`

---

## Examples

### Example 1
**Input:**
```text
matrix = [
  [9, 9, 4],
  [6, 6, 8],
  [2, 1, 1]
]
```
**Output:**
```text
4
```
**Explanation:**
The longest increasing path is `[1, 2, 6, 9]`:
`(2, 1) -> (2, 0) -> (1, 0) -> (0, 0)`.
Notice that `[3, 4, 5, 6, 7]` is not possible because consecutive cells must be strictly greater and adjacent.

```
[9]  9   4
 ^
[6]  6   8
 ^
[2]<-[1] 1   (Length = 4)
```

---

### Example 2
**Input:**
```text
matrix = [
  [3, 4, 5],
  [3, 2, 6],
  [2, 2, 1]
]
```
**Output:**
```text
4
```
**Explanation:**
The longest increasing path is `[3, 4, 5, 6]`. Moving diagonally is not allowed.

---

### Example 3
**Input:**
```text
matrix = [[1]]
```
**Output:**
```text
1
```

---

## Algorithmic Approaches

### Why Strictly Increasing Paths Form an Implicit DAG
Because each step must strictly increase in elevation:
$$v_1 < v_2 < v_3 < \dots < v_k$$
It is mathematically **impossible for a path to ever loop back on itself** or create a cycle!
- Therefore, the grid represents an **implicit Directed Acyclic Graph (DAG)**.
- We do **NOT** need a `visited` array to prevent infinite cycles.
- The longest path starting at any cell `(r, c)` is fixed and can be **cached using dynamic programming / memoization**!

### DFS + Memoization Algorithm
1. Initialize a 2D memo table `dp[m][n]` filled with `0`.
2. Function `dfs(r, c)`:
   - If `dp[r][c] != 0`, return `dp[r][c]`.
   - Initialize `maxLen = 1`.
   - For all 4 cardinal neighbors `(nr, nc)`:
     - If $0 \le nr < m$, $0 \le nc < n$, and `matrix[nr][nc] > matrix[r][c]`:
       - `maxLen = max(maxLen, 1 + dfs(nr, nc))`.
   - Return `dp[r][c] = maxLen`.
3. Scan all cells: `ans = max(dfs(r, c))` for all $0 \le r < m, 0 \le c < n$.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ — Due to memoization, `dfs(r, c)` computes the answer for each cell exactly once. Across all cells, each 4-directional transition is evaluated at most 4 times.
- **Space Complexity:** $O(M \times N)$ for the `dp` memoization table and recursion call stack.
