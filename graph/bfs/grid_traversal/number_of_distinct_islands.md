# Number of Distinct Islands (LeetCode 694)

## Problem Statement
Given an `m x n` binary matrix `grid`, return the **number of distinct islands**.

An island is considered to be the same as another if and only if one island can be translated (and **not** rotated or reflected) to equal the other.

An island is formed by connecting adjacent lands (`1`s) horizontally or vertically (4-directional).

---

## Constraints
* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `grid[i][j]` is either `0` or `1`.

---

## Examples

### Example 1
**Input:**
```text
grid = [
  [1, 1, 0, 0, 0],
  [1, 1, 0, 0, 0],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 1, 1]
]
```
**Output:**
```text
1
```
**Explanation:**
- Island 1 is at top-left: a `2 x 2` block.
- Island 2 is at bottom-right: a `2 x 2` block.
Translating Island 1 by moving right 3 units and down 2 units exactly matches Island 2. Since their shapes are identical without rotation/reflection, there is only **1 distinct island**.

---

### Example 2
**Input:**
```text
grid = [
  [1, 1, 0, 1, 1],
  [1, 0, 0, 0, 0],
  [0, 0, 0, 0, 1],
  [1, 1, 0, 1, 1]
]
```
**Output:**
```text
3
```
**Explanation:**
- Island 1 (top-left): shape `[[1, 1], [1, 0]]` (L-shape pointing up-left).
- Island 2 (top-right): shape `[[1, 1]]` (horizontal line of length 2).
- Island 3 (middle-right): single isolated cell `[[1]]`.
- Island 4 (bottom-left): shape `[[1, 1]]` (same as top-right).
- Island 5 (bottom-right): shape `[[1, 1]]` (same as top-right).
Distinct shapes = 3.

---

## Algorithmic Approaches

### Relative Coordinate Encoding via Hash Set
Two islands are identical under translation if and only if their coordinates shifted relative to their respective base starting cells $(r_0, c_0)$ are identical!

1. Maintain a `std::set<vector<pair<int, int>>>` (or `set<string>`).
2. Iterate through every cell `(r, c)` of `grid`:
   - When encountering an unvisited `grid[r][c] == 1`:
     - Set base origin `(r0, c0) = (r, c)`.
     - Initialize a list `currentIslandShape`.
     - Launch DFS/BFS:
       - For each visited land cell `(curr_r, curr_c)`:
         - Record relative offset: `(curr_r - r0, curr_c - c0)`.
         - Mark cell as visited (`grid[curr_r][curr_c] = 0`).
         - Explore 4 cardinal neighbors in a deterministic fixed order (e.g. Up, Down, Left, Right).
     - Insert `currentIslandShape` into the set.
3. The answer is simply `distinctShapesSet.size()`.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N \cdot \log K)$ — Every cell is visited once during DFS. Inserting each island's coordinate vector into the set takes $O(K \log K)$ where $K$ is the number of cells in the island.
- **Space Complexity:** $O(M \times N)$ — Storing the relative coordinates of all land cells in the set.
