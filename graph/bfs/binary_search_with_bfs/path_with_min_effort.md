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

### Approach 1: Binary Search on Answer + BFS Validation
Notice the monotonic property:
- If a route with effort $\le K$ is feasible, then any effort $> K$ is also trivially feasible!
- If a route with effort $\le K$ is impossible, no smaller effort can work.
- **Search Space:** `low = 0`, `high = 10^6`.
- **Predicate `canReach(limit)`:**
  - Launch standard 4-directional BFS from `(0, 0)`.
  - Only traverse into adjacent neighbor `(nr, nc)` if:
    $$|heights[r][c] - heights[nr][nc]| \le limit$$
  - If BFS reaches `(rows - 1, cols - 1)`, return `true`.
  - If queue empties, return `false`.

### Approach 2: Modified Dijkstra (Minimax Path)
$$\text{dist}[v] = \min \max(\text{dist}[u], \text{weight}(u, v))$$

---

## Complexity Analysis
- **Time Complexity:** $O(M \cdot N \cdot \log(\max H))$ where $\log(10^6) \approx 20$ iterations of $O(M \cdot N)$ BFS checks.
- **Space Complexity:** $O(M \cdot N)$ for the BFS queue and visited matrix.
