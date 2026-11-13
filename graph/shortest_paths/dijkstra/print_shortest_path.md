# Print Shortest Path (Dijkstra with Path Reconstruction)

## Problem Statement
Given a weighted undirected graph with `n` vertices labeled from `1` to `n` and `m` edges, find the **shortest path** from vertex `1` to vertex `n`.

- Return a list containing the sequence of vertices in the shortest path starting from vertex `1` and ending at vertex `n`.
- If no path exists between vertex `1` and vertex `n`, return `[-1]`.
- If multiple shortest paths exist, return any one of them.

---

## Constraints
* `2 <= n <= 10^5`
* `0 <= m <= 2 * 10^5`
* Edge weights are positive integers: $1 \le w_i \le 10^9$.
* Vertices are 1-indexed: $1 \dots n$.

---

## Examples

### Example 1
**Input:**
```text
n = 5, m = 6
edges = [
  [1, 2, 2],
  [2, 5, 5],
  [2, 3, 4],
  [1, 4, 1],
  [4, 3, 3],
  [3, 5, 1]
]
```
**Output:**
```text
[1, 4, 3, 5]
```
**Explanation:**
- Path `1 -> 4 -> 3 -> 5` has total weight: $1 + 3 + 1 = 5$.
- Path `1 -> 2 -> 5` has total weight: $2 + 5 = 7$.
- Path `1 -> 2 -> 3 -> 5` has total weight: $2 + 4 + 1 = 7$.
Minimum cost is 5, achieved by path `[1, 4, 3, 5]`.

```
        (2) ---------(5)--------> (5)
       /   \                     ^
     (2)   (4)                  (1)
     /       \                  /
   (1)       (3) <--(3)-- (4) -+
     \                     ^
      +-------(1)---------+
```

---

### Example 2
**Input:**
```text
n = 4, m = 2
edges = [[1, 2, 2], [3, 4, 3]]
```
**Output:**
```text
[-1]
```
**Explanation:**
Vertex 4 is completely disconnected from vertex 1. No path exists.

---

## Algorithmic Approaches

### Parent Pointer Tracking during Dijkstra
To reconstruct the path, maintain a `parent` array of size $n + 1$:
1. Initialize `parent[i] = i` for all $i \in [1, n]$.
2. Initialize `dist` array with $\infty$, and set `dist[1] = 0`.
3. In Dijkstra's edge relaxation step:
   ```cpp
   if (dist[u] + weight < dist[v]) {
       dist[v] = dist[u] + weight;
       parent[v] = u; // Record parent on shortest path
       pq.push({dist[v], v});
   }
   ```
4. **Reconstruction:**
   - If `dist[n] == \infty`, destination is unreachable $\longrightarrow$ return `[-1]`.
   - Start from destination node `curr = n`.
   - Trace backwards: while `parent[curr] != curr`:
     - Append `curr` to `path`.
     - `curr = parent[curr]`.
   - Append `1` to `path`.
   - Reverse `path` to obtain order from $1 \to n$.

---

## Complexity Analysis
- **Time Complexity:** $O(E \log V)$ for Dijkstra + $O(V)$ for path reconstruction backtracking.
- **Space Complexity:** $O(V + E)$ for adjacency list and $O(V)$ for `parent` and `dist` arrays.
