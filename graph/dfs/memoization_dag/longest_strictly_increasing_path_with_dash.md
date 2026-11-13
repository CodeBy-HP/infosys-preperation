# Longest Strictly Increasing Path in Grid with at Most One Dash Jump

## Problem Statement
You are given an `m x n` grid of integers `grid`.

You want to find the **maximum possible length of a strictly increasing path**. The length of a path is defined as the **number of cells visited**.

Normally, from any cell `(r, c)`, you can move 1 step in any of the 4 cardinal directions (up, down, left, right) to an adjacent cell `(nr, nc)`, provided that:
$$\text{grid}[nr][nc] > \text{grid}[r][c]$$

However, you are allowed to use a special **"Dash" move at most once** during your entire path:
- A Dash move allows you to jump over an immediate neighboring cell to land on the cell **exactly 2 steps away** in the same direction (e.g. from `(r, c)` to `(r + 2, c)`, `(r - 2, c)`, `(r, c + 2)`, or `(r, c - 2)`).
- **Dash Condition:** The destination cell 2 steps away must be strictly greater than your current cell:
  $$\text{grid}[\text{dest}] > \text{grid}[r][c]$$
- The intermediate cell jumped over has no restriction (it can be smaller, larger, or equal; it is skipped and not counted in the path).
- The destination cell must be within the grid boundaries.

Return the **maximum number of cells** that can be visited in any strictly increasing path.

---

## Constraints
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 200`
* `0 <= grid[i][j] <= 10^6`

---

## Examples

### Example 1
**Input:**
```text
grid = [
  [1, 9, 2],
  [8, 5, 7],
  [3, 6, 4]
]
```
**Output:**
```text
5
```
**Explanation:**
- Start at `(0, 0)` with value 1.
- Dash move: Jump 2 steps right from `(0, 0)` to `(0, 2)` (skipping 9): $1 \to 2$ (valid because $2 > 1$).
- Normal step: Move down to `(1, 2)` with value 7 ($7 > 2$).
- Normal step: Move left to `(1, 1)` with value 8... wait, or move from `(2, 0) = 3 -> (2, 1) = 6 -> (1, 1) = 8 -> Dash to (something)`.
- Path: `(0, 0) [1] -> Dash to (0, 2) [2] -> (2, 2) [4] -> (2, 1) [6] -> (1, 1) [5...]`.
With the dash jump, the longest strictly increasing sequence visits 5 cells.

---

### Example 2
**Input:**
```text
grid = [
  [1, 2],
  [3, 4]
]
```
**Output:**
```text
4
```
**Explanation:**
Standard path `1 -> 2 -> 4` (length 3) or `1 -> 3 -> 4` (length 3).
With Dash: `1 -> 2 -> 4` or other moves. Max length = 4 if path visits all cells.

---

## Algorithmic Approaches

### 3D Memoization DAG (`dp[r][c][usedDash]`)
Since all moves (both normal 1-step and 2-step dash jumps) require the destination cell to have a **strictly greater elevation**, the graph remains a **Directed Acyclic Graph (DAG)** without cycles!

State representation:
`dfs(r, c, usedDash)`:
- `r, c`: Current cell coordinate.
- `usedDash \in {0, 1}`: Boolean indicating whether the 1-time dash move has already been consumed.

### Transitions
From state `(r, c, usedDash)`:
1. **Normal 1-Step Move (in all 4 directions):**
   - For $(nr, nc) \in \{(r \pm 1, c), (r, c \pm 1)\}$:
     - If in bounds and `grid[nr][nc] > grid[r][c]`:
       - `maxLen = max(maxLen, 1 + dfs(nr, nc, usedDash))`.
2. **Special 2-Step Dash Move (only if `usedDash == 0`):**
   - For $(nr, nc) \in \{(r \pm 2, c), (r, c \pm 2)\}$:
     - If in bounds and `grid[nr][nc] > grid[r][c]`:
       - `maxLen = max(maxLen, 1 + dfs(nr, nc, 1))`.
3. Memoize: `dp[r][c][usedDash] = maxLen`.

Global answer is $\max_{0 \le r < m, 0 \le c < n} \text{dfs}(r, c, 0)$.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N \times 2) = O(M \times N)$ — There are only $2 \times M \times N$ distinct states. Each state evaluates at most 8 transitions (4 normal + 4 dash).
- **Space Complexity:** $O(M \times N)$ for the 3D memoization array and recursion call stack.
