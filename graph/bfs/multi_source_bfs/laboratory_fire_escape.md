# Laboratory Fire Escape (Two-Phase Multi-Source BFS)

## Problem Statement
A research laboratory is represented as an `N x M` grid containing walls, empty cells, fire sources, and one human. Each cell contains one of the following characters:
* `'#'` → Wall
* `'.'` → Empty cell
* `'F'` → Fire source
* `'H'` → Human

Every minute:
1. Fire spreads simultaneously to all 4 adjacent cells (up, down, left, right).
2. The human can also move one step in any of the four directions.

The human **cannot**:
* Move through walls.
* Move into a cell already occupied by fire.
* Move into a cell where fire reaches at the same time or earlier.

The human escapes successfully if they reach **any boundary cell** (row 0, row $N - 1$, col 0, or col $M - 1$) before the fire reaches that cell.
Determine whether escape is possible. Print `YES` if the human can escape, otherwise print `NO`.

---

## Constraints
* `1 <= N, M <= 1000`
* Grid consists only of `'#'`, `'.'`, `'F'`, and `'H'`.
* There is exactly one human `'H'`.
* There may be zero, one, or multiple fire sources `'F'`.

---

## Examples

### Example 1
**Input:**
```text
5 6
######
#H...#
#.##F#
#....#
.....#
```
**Output:**
```text
YES
```
**Explanation:**
The human at `(1, 1)` can move down: `(1, 1) -> (2, 1) -> (3, 1) -> (4, 1)` or `(4, 0)` reaching the boundary before the fire from `(2, 4)` spreads across the walls. Output is `YES`.

---

## Algorithmic Approaches

### Two-Phase Multi-Source BFS
This problem is mathematically identical to CSES Monsters / LeetCode Escape the Spreading Fire.

1. **Phase 1: Multi-Source Fire Spread BFS**
   - Initialize `fireTime[N][M]` with $\infty$.
   - Push all fire cells `'F'` into a queue with `fireTime = 0`.
   - Run standard BFS: for each adjacent empty cell `(nr, nc)`, if `fireTime[r][c] + 1 < fireTime[nr][nc]`:
     - `fireTime[nr][nc] = fireTime[r][c] + 1`.
     - Push `(nr, nc)` into the fire queue.

2. **Phase 2: Human Escape BFS**
   - Initialize `humanTime[N][M]` with $\infty$, and set `humanTime[start_r][start_c] = 0`.
   - Push human's start position into a queue.
   - While human queue is not empty:
     - Pop `(r, c)`.
     - **Escape Condition:** If `(r, c)` is on any border ($r == 0$ or $r == N - 1$ or $c == 0$ or $c == M - 1$), the human has reached the exit! Return **`YES`**.
     - For all 4 cardinal neighbors `(nr, nc)`:
       - If cell is within bounds, not a wall `'#'`, and has not been visited by human:
         - **Fire Safety Invariant:** The human can only step into `(nr, nc)` if the human arrives **strictly before** the fire:
           $$\text{humanTime}[r][c] + 1 < \text{fireTime}[nr][nc]$$
         - If safe:
           - `humanTime[nr][nc] = humanTime[r][c] + 1`.
           - Push `(nr, nc)` into human queue.

3. If human queue empties without reaching a border, escape is impossible $\longrightarrow$ return **`NO`**.

---

## Complexity Analysis
- **Time Complexity:** $O(N \times M)$ — Phase 1 fire BFS visits each cell once in $O(N \times M)$. Phase 2 human BFS visits each cell once in $O(N \times M)$.
- **Space Complexity:** $O(N \times M)$ for `fireTime`, `humanTime` matrices and BFS queues.
