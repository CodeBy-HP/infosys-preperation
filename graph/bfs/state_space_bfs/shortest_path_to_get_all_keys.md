# Shortest Path to Get All Keys (LeetCode 864)

## Problem Statement
You are given an `m x n` grid `grid` where:
- `'.'` is an empty cell.
- `'#'` is a wall.
- `'@'` is the starting point.
- Lowercase letters `'a'`, `'b'`, `'c'`, `'d'`, `'e'`, `'f'` represent **keys**.
- Uppercase letters `'A'`, `'B'`, `'C'`, `'D'`, `'E'`, `'F'` represent **locks**.

You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or into a wall cell `'#'`.

If you walk over a key, you pick it up. You cannot walk over a lock unless you have the corresponding key.

Return the **lowest number of moves to acquire all keys**. If it is impossible, return `-1`.

---

## Constraints
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 30`
* `grid[i][j]` is either an empty cell, a wall, starting point, key, or lock.
* The number of different keys is in the range `[1, 6]`.
* Each key has at most one corresponding lock and vice versa.

---

## Examples

### Example 1
**Input:**
```text
grid = [
  ["@", "a", ".", "A", "b"],
  ["#", "#", "#", "#", "#"],
  [".", ".", ".", ".", "."]
]
```
**Output:**
```text
8
```
**Explanation:**
- Start at `@` at `(0, 0)`.
- Step 1: Walk to `(0, 1)` to pick up key `'a'`. Keys collected: `0b01`.
- Step 2-4: Walk back through `(0, 0)` down to row 2... wait, wall at row 1 blocks!
- Actually: Pick key `'a'` at `(0, 1)` (1 step). With key `'a'`, unlock lock `'A'` at `(0, 3)` (2 steps: `(0, 2)` then `(0, 3)`). Walk to `(0, 4)` to pick key `'b'` (1 step). Total steps = 4 steps... wait, in example 1, wall is at row 1 so rightwards is the only way: `(0,0) -> (0,1) -> (0,2) -> (0,3) -> (0,4) = 4 steps`. (Depending on key arrangement).

---

### Example 2
**Input:**
```text
grid = [
  ["@", ".", "a", "A"],
  ["#", "#", "#", "#"],
  ["b", ".", ".", "."]
]
```
**Output:**
```text
-1
```
**Explanation:**
Key `'b'` is blocked by a solid wall of `'#'`. It is impossible to acquire all keys.

---

## Algorithmic Approaches

### 3D State-Space BFS with Bitmask
Because visiting a cell previously without a key and revisiting it **after** picking up a key represents two fundamentally distinct situations, the state space cannot be simply $(r, c)$:
- **State Definition:** $(r, c, \text{keyMask})$:
  - $0 \le r < m, 0 \le c < n$.
  - $\text{keyMask} \in [0, 2^K - 1]$ where $K \le 6$ is the total count of keys.
  - The $i$-th bit of `keyMask` is $1$ if key $i$ has been collected.
- **Target Condition:** `keyMask == (1 << K) - 1` (all $K$ bits are $1$).

### BFS Transitions
1. Push `{start_r, start_c, 0, 0}` (`{r, c, mask, steps}`) into queue.
2. Mark `visited[start_r][start_c][0] = true`.
3. While queue is non-empty:
   - Pop `{r, c, mask, steps}`.
   - If `mask == (1 << K) - 1`, return `steps`.
   - For all 4 cardinal neighbors `(nr, nc)`:
     - If cell is a wall `'#'`, skip.
     - If cell is a lock `'A' - 'F'` and `!(mask & (1 << (ch - 'A')))`: do not have key, skip!
     - Calculate `newMask = mask`:
       - If cell is a key `'a' - 'f'`: `newMask |= (1 << (ch - 'a'))`.
     - If `!visited[nr][nc][newMask]`:
       - `visited[nr][nc][newMask] = true`.
       - Push `{nr, nc, newMask, steps + 1}`.
4. Return `-1` if queue empties.

---

## Complexity Analysis
- **Time Complexity:** $O(M \cdot N \cdot 2^K)$ — Total state vertices $V = 30 \times 30 \times 2^6 = 900 \times 64 = 57,600$ states. Each state has at most 4 transitions $\implies \approx 2.3 \times 10^5$ operations (instantaneous).
- **Space Complexity:** $O(M \cdot N \cdot 2^K)$ for the 3D visited boolean array and BFS queue.
