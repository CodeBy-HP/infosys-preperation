# Path With Minimum Effort (LeetCode 1631)

## Problem Statement
You are a hiker preparing for an upcoming hike. You are given `heights`, a 2D array of size `rows x columns`, where `heights[row][col]` represents the height of cell `(row, col)`.

You are situated in the top-left cell, `(0, 0)`, and you hope to travel to the bottom-right cell, `(rows - 1, columns - 1)` (0-indexed). You can move up, down, left, or right (4 directions).

You wish to find a route that requires the **minimum effort**.
A route's **effort** is the **maximum absolute difference** in heights between two consecutive cells of the route:
$$\text{effort}(\text{path}) = \max_{(u, v) \in \text{path}} |h_u - h_v|$$

Return the **minimum effort** required to travel from the top-left cell to the bottom-right cell.

---

## Constraints
* `rows == heights.length`
* `columns == heights[i].length`
* `1 <= rows, columns <= 100`
* `1 <= heights[i][j] <= 10^6`

---

## Examples

### Example 1
**Input:**
```text
heights = [
  [1, 2, 2],
  [3, 8, 2],
  [5, 3, 5]
]
```
**Output:**
```text
2
```
**Explanation:**
The route `[1, 2, 2, 2, 5]` has consecutive differences `[1, 0, 0, 3]` which has max difference 3.
However, route `[1, 3, 5, 3, 5]` has consecutive differences of $|1-3|=2$, $|3-5|=2$, $|5-3|=2$, $|3-5|=2$. The maximum difference is **2**, which is optimal.

```
(1) ---> (2) ---> (2)
                   |
(3)      (8)      (2)
                   |
(5) <--- (3) <--- (5)   (Path with max step diff = 2)
```

---

### Example 2
**Input:**
```text
heights = [
  [1, 2, 3],
  [3, 8, 4],
  [5, 3, 5]
]
```
**Output:**
```text
1
```
**Explanation:**
Route: `[1, 2, 3, 4, 5]`. Consecutive differences: $|1-2|=1, |2-3|=1, |3-4|=1, |4-5|=1$. Maximum difference is 1.

---

## Algorithmic Approaches

### Approach 1: Modified Dijkstra's Algorithm (Minimax Path)
Instead of standard additive distance ($d_u + w$), the path effort metric is the **bottleneck maximum edge weight**:
$$\text{effort}[v] = \min_{(u, v)} \max(\text{effort}[u], |h_u - h_v|)$$

1. Initialize `dist[r][c] = \infty`, and set `dist[0][0] = 0`.
2. Min-Priority Queue stores `{current_max_effort, r, c}`.
3. Push `{0, 0, 0}` into `pq`.
4. While `pq` is not empty:
   - Pop `{d, r, c}`.
   - If `r == rows - 1 && c == cols - 1`, return `d` (early termination).
   - If `d > dist[r][c]`, continue.
   - For all 4 cardinal neighbors `(nr, nc)`:
     - `newEffort = max(d, abs(heights[r][c] - heights[nr][nc]))`.
     - If `newEffort < dist[nr][nc]`:
       - `dist[nr][nc] = newEffort`.
       - Push `{newEffort, nr, nc}` into `pq`.

### Approach 2: Binary Search on Answer + BFS / DFS
- Search range for answer: `low = 0`, `high = 10^6`.
- Midpoint `mid`: Can we reach `(rows-1, cols-1)` using only steps with $|h_u - h_v| \le mid$?
- Check feasibility with a standard BFS/DFS in $O(M \times N)$ time.
- If reachable, `ans = mid; high = mid - 1;` else `low = mid + 1;`.

---

## Complexity Analysis
- **Time Complexity:**
  - Dijkstra: $O(M \cdot N \log(M \cdot N))$ — Total vertices $V = M \cdot N$, each cell relaxed via 4 edges.
  - Binary Search: $O(M \cdot N \log(\max H))$ where $\log(10^6) \approx 20$ iterations.
- **Space Complexity:** $O(M \times N)$ for effort matrix and priority queue or visited matrix.
