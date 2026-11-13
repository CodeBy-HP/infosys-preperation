# Min Cost to Connect All Points (LeetCode 1584)

## Problem Statement
You are given an array `points` representing integer coordinates of some points on a 2D-plane, where `points[i] = [x_i, y_i]`.

The cost of connecting two points `[x_i, y_i]` and `[x_j, y_j]` is the **Manhattan distance** between them:
$$\text{dist}(i, j) = |x_i - x_j| + |y_i - y_j|$$

Return the **minimum cost** to make all points connected. All points are connected if there is **exactly one simple path** between any pair of points.

---

## Constraints
* `1 <= points.length <= 1000`
* `-10^6 <= x_i, y_i <= 10^6`
* All pairs `(x_i, y_i)` are distinct.

---

## Examples

### Example 1
**Input:**
```text
points = [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]
```
**Output:**
```text
20
```
**Explanation:**
Connect points to form a minimum spanning tree:
- Connect `(0, 0)` to `(2, 2)` with cost 4.
- Connect `(2, 2)` to `(5, 2)` with cost 3.
- Connect `(5, 2)` to `(7, 0)` with cost 4.
- Connect `(2, 2)` to `(3, 10)` with cost 9.
Total cost = $4 + 3 + 4 + 9 = 20$.

```
(3,10)
  |
 (9)
  |
(2,2) --(3)-- (5,2)
  |             |
 (4)           (4)
  |             |
(0,0)         (7,0)
```

---

### Example 2
**Input:**
```text
points = [[3, 12], [-2, 5], [-4, 1]]
```
**Output:**
```text
18
```

---

## Algorithmic Approaches

### Why Prim's with Dense Array Outperforms Kruskal's Here
This problem represents a **complete graph** where every point has an edge to every other point:
$$V = N, \quad E = \frac{N(N - 1)}{2} \approx 5 \times 10^5 \text{ edges}$$
- **Kruskal's Algorithm:** Generating and sorting all $5 \times 10^5$ edges takes $O(N^2 \log(N^2))$ time and high memory.
- **Dense Prim's Algorithm (Without Priority Queue):**
  - Maintains `minDist[i]`: Minimum distance to connect point $i$ to the currently formed MST component.
  - In each step:
    - Find the unvisited point $u$ with minimum `minDist[u]` in $O(N)$ linear scan.
    - Mark $u$ as visited.
    - Add `minDist[u]` to total cost.
    - Update `minDist[v] = min(minDist[v], manhattanDistance(u, v))` for all unvisited points $v$ in $O(N)$ time.
  - Total Time: $O(N^2)$ without any heap overhead!

---

## Complexity Analysis
- **Time Complexity:** $O(N^2)$ using dense Prim's array representation ($1000^2 = 10^6$ operations $\approx 3$ ms).
- **Space Complexity:** $O(N)$ for `minDist` and `visited` arrays (no explicit edge list stored).
