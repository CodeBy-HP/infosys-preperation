# Shortest Path in a Directed Acyclic Graph (DAG)

## Problem Statement
Given a **Directed Acyclic Graph (DAG)** with `V` vertices labeled from `0` to `V - 1` and `E` weighted directed edges, find the **shortest distance** from a given source vertex `src` to all other vertices.

If a vertex is unreachable from `src`, its shortest distance should be reported as `-1` (or $\infty$).

---

## Constraints
* `1 <= V <= 10^5`
* `0 <= E <= 2 * 10^5`
* Edge weights can be **positive, negative, or zero** (unlike Dijkstra's algorithm, negative edge weights are permitted in a DAG because cycles cannot exist).
* $0 \le src < V$.

---

## Examples

### Example 1
**Input:**
```text
V = 6, E = 7, src = 0
edges = [
  [0, 1, 2],
  [0, 4, 1],
  [1, 2, 3],
  [4, 2, 2],
  [4, 5, 4],
  [2, 3, 6],
  [5, 3, 1]
]
```
**Output:**
```text
[0, 2, 3, 6, 1, 5]
```
**Explanation:**
- Path to 0: Distance = 0.
- Path to 1: `0 -> 1`, Distance = 2.
- Path to 4: `0 -> 4`, Distance = 1.
- Path to 2: `0 -> 4 -> 2`, Distance = 1 + 2 = 3 (better than `0 -> 1 -> 2` which is 5).
- Path to 5: `0 -> 4 -> 5`, Distance = 1 + 4 = 5.
- Path to 3: `0 -> 4 -> 5 -> 3`, Distance = 1 + 4 + 1 = 6 (better than `0 -> 4 -> 2 -> 3` which is 9).

```
        (1) ---------(3)--------> (2)
       ^  |                        |  \
      /   |                        |   \
    (2)   | (edge)                 |    (6)
    /     v                        |     \
  (0)    (4) ---------(2)--------> (2)    v
    \     |                               (3)
    (1)   | (4)                          ^
      \   v                             /
        (4) ---------(4)--------> (5) -(1)
```

---

### Example 2
**Input:**
```text
V = 4, E = 2, src = 0
edges = [[0, 1, 2], [1, 2, 3]]
```
**Output:**
```text
[0, 2, 5, -1]  (Node 3 is unreachable)
```

---

## Algorithmic Approaches

### Why Topological Sort Outperforms Dijkstra ($O(V + E)$ vs $O(E \log V)$)
In a DAG, vertices can be linearized into a topological order such that all directed edges point exclusively from left to right:
1. By relaxing edges in **topological order**, when we arrive at vertex $u$, we are guaranteed that **all possible incoming paths to $u$ have already been relaxed and finalized**!
2. No future edge can ever loop back to modify $u$'s shortest distance.
3. Therefore, a single pass in topological order solves shortest paths in strictly **$O(V + E)$ linear time**, even in the presence of negative edge weights!

### Step-by-Step Algorithm
1. Compute topological sort of the graph using DFS or Kahn's algorithm.
2. Initialize `dist` array of size $V$ with $\infty$, and set `dist[src] = 0`.
3. Process vertices one by one in topological order:
   - If `dist[u] != \infty`:
     - For each outgoing edge $(u \to v, w)$:
       - If `dist[u] + w < dist[v]`:
         - `dist[v] = dist[u] + w`.
4. Replace all remaining $\infty$ with `-1`.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ — Topological sort takes $O(V + E)$ time; edge relaxation takes $O(V + E)$ time.
- **Space Complexity:** $O(V + E)$ for adjacency list and $O(V)$ for topological stack and distance array.
