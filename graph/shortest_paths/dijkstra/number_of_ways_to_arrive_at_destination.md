# Number of Ways to Arrive at Destination (LeetCode 1976)

## Problem Statement
You are in a city that consists of `n` intersections numbered from `0` to `n - 1` with bi-directional roads between some intersections. The inputs are given as an integer `n` and a 2D integer array `roads` where `roads[i] = [u_i, v_i, time_i]` indicates that there is a bidirectional road between intersections $u_i$ and $v_i$ that takes $\text{time}_i$ minutes to travel.

You want to know in how many ways you can travel from intersection `0` to intersection `n - 1` in the **shortest amount of time**.

Return the **number of ways** to reach the destination in the shortest time. Since the answer may be large, return it **modulo $10^9 + 7$**.

---

## Constraints
* `1 <= n <= 200`
* `n - 1 <= roads.length <= n * (n - 1) / 2`
* `roads[i].length == 3`
* `0 <= u_i, v_i <= n - 1`
* `u_i != v_i`
* `1 <= time_i <= 10^9`
* All pairs $(u_i, v_i)$ are unique.
* The graph is connected.

---

## Examples

### Example 1
**Input:**
```text
n = 7, roads = [
  [0, 6, 7],
  [0, 1, 2],
  [1, 2, 3],
  [1, 3, 3],
  [6, 3, 3],
  [3, 5, 1],
  [6, 5, 1],
  [2, 5, 1],
  [0, 4, 5],
  [4, 6, 2]
]
```
**Output:**
```text
4
```
**Explanation:**
The shortest path from intersection 0 to intersection 6 takes 7 minutes.
The 4 paths that each take exactly 7 minutes are:
1. `0 -> 6` (time = 7)
2. `0 -> 4 -> 6` (time = 5 + 2 = 7)
3. `0 -> 1 -> 2 -> 5 -> 6` (time = 2 + 3 + 1 + 1 = 7)
4. `0 -> 1 -> 3 -> 5 -> 6` (time = 2 + 3 + 1 + 1 = 7)

```
       (2)----(3)
      / |      | \
    (2)(3)    (1) \
    /   |      |   \
  (0)  (2)----(5)--(6)
    \               ^
    (5)----(4)-----(2)
```

---

### Example 2
**Input:**
```text
n = 2, roads = [[1, 0, 10]]
```
**Output:**
```text
1
```

---

## Algorithmic Approaches

### Dijkstra with Path Counting DP
Combine Dijkstra's algorithm with dynamic programming path-counting:
- `dist[i]`: Shortest distance from source `0` to node `i` (initialized to $\infty$, `dist[0] = 0`).
- `ways[i]`: Number of distinct shortest paths from `0` to `i` (initialized to `0`, `ways[0] = 1`).

### Relaxation Cases
When inspecting an edge $(u \to v, w)$:
- **Case 1: Found a Strictly Shorter Path (`dist[u] + w < dist[v]`):**
  - Update `dist[v] = dist[u] + w`.
  - Reset `ways[v] = ways[u]` (all previous longer paths are discarded; only paths through $u$ qualify).
  - Push `{dist[v], v}` to min-heap.
- **Case 2: Found an Equivalent Alternate Shortest Path (`dist[u] + w == dist[v]`):**
  - Add to ways: `ways[v] = (ways[v] + ways[u]) % (10^9 + 7)`.
  - (Do **NOT** re-push to priority queue; distance did not decrease).

---

## Complexity Analysis
- **Time Complexity:** $O((V + E) \log V) = O(E \log V)$ using a binary min-heap.
- **Space Complexity:** $O(V + E)$ for adjacency list and $O(V)$ for `dist` (using `long long` to prevent overflow) and `ways` arrays.
