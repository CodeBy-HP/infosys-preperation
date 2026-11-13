# Flood Fill (LeetCode 733)

## Problem Statement
An image is represented by an `m x n` integer grid `image` where `image[i][j]` represents the pixel value of the image.

You are also given three integers `sr`, `sc`, and `color`. You should perform a **flood fill** on the image starting from the pixel `image[sr][sc]`.

To perform a flood fill:
1. Begin with the starting pixel `image[sr][sc]` and its initial color `initialColor = image[sr][sc]`.
2. Perform a 4-directional search (up, down, left, right) to find all pixels connected to the starting pixel that share the **exact same initial color**.
3. Replace the color of all of these connected pixels with the new `color`.
4. Return the modified `image` after performing the flood fill.

---

## Constraints
* `m == image.length`
* `n == image[i].length`
* `1 <= m, n <= 50`
* `0 <= image[i][j], color < 2^16`
* `0 <= sr < m`
* `0 <= sc < n`

---

## Examples

### Example 1
**Input:**
```text
image = [
  [1, 1, 1],
  [1, 1, 0],
  [1, 0, 1]
]
sr = 1, sc = 1, color = 2
```
**Output:**
```text
[
  [2, 2, 2],
  [2, 2, 0],
  [2, 0, 1]
]
```
**Explanation:**
From the center of the image at `(sr, sc) = (1, 1)` (colored 1), all pixels connected 4-directionally with color 1 are changed to color 2. The bottom-right pixel `(2, 2)` is colored 1, but it is not 4-directionally connected to the starting component because it is diagonally isolated by zeros.

```
Initial:          After Flood Fill:
[1, 1, 1]        [2, 2, 2]
[1, 1, 0]  --->  [2, 2, 0]
[1, 0, 1]        [2, 0, 1]
```

---

### Example 2
**Input:**
```text
image = [
  [0, 0, 0],
  [0, 0, 0]
]
sr = 0, sc = 0, color = 0
```
**Output:**
```text
[
  [0, 0, 0],
  [0, 0, 0]
]
```
**Explanation:**
The starting pixel is already colored `0`, which is identical to the target `color`. No modifications are needed.

---

## Algorithmic Approaches

### Approach 1: Depth-First Search (DFS)
- **Critical Guard Condition:** If `image[sr][sc] == color`, the starting pixel already has the target color. Returning immediately prevents infinite recursion cycles without requiring an explicit $O(M \times N)$ `visited` array.
- Store `initialColor = image[sr][sc]`.
- Change `image[sr][sc] = color`.
- For each of the 4 cardinal directions $(nr, nc) \in \{(r+1, c), (r-1, c), (r, c+1), (r, c-1)\}$:
  - If $0 \le nr < m$, $0 \le nc < n$, and `image[nr][nc] == initialColor`:
    - Recursively invoke `dfs(nr, nc)`.

### Approach 2: Breadth-First Search (BFS)
- If `image[sr][sc] == color`, return `image`.
- Push `{sr, sc}` into a queue and set `image[sr][sc] = color`.
- While queue is non-empty:
  - Pop `{r, c}`.
  - For each valid 4-neighbor $(nr, nc)$ where `image[nr][nc] == initialColor`:
    - Overwrite `image[nr][nc] = color`.
    - Push `{nr, nc}` into the queue.

---

## Complexity Analysis
- **Time Complexity:** $O(M \times N)$ — In the worst case, every pixel in the image shares the initial color and is visited exactly once.
- **Space Complexity:** $O(M \times N)$ — In the worst case (e.g. a completely uniform grid), the DFS recursion stack or BFS queue holds up to $M \times N$ cells.
