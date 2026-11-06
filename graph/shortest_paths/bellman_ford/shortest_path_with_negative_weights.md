# Bellman-Ford Algorithm (Negative Weights & Cycle Detection)

## Problem Statement
Given a weighted, directed graph with `V` vertices labeled from `0` to `V - 1` and `E` edges where edge weights can be **negative**, and a source vertex `src`:

1. Find the **shortest distance** from `src` to all other vertices.
2. If the graph contains a **negative weight cycle** reachable from `src` (meaning shortest distances can be reduced infinitely to $-\infty$), return `[-1]`.

---

## Constraints
* `1 <= V <= 500`
* `1 <= E <= V * (V - 1)`
* `-1000 <= weight <= 1000`
* $0 \le src < V$.

---

## Examples

### Example 1
**Input:**
```text
V = 4, E = 4, src = 0
edges = [
  [0, 1, 1],
  [1, 2, -3],
  [2, 3, 2],
  [0, 2, 4]
]
```
**Output:**
```text
[0, 1, -2, 0]
```
**Explanation:**
- Path to 0: Distance = 0.
- Path to 1: `0 -> 1` (cost = 1).
- Path to 2: `0 -> 1 -> 2` (cost = $1 + (-3) = -2$).
- Path to 3: `0 -> 1 -> 2 -> 3` (cost = $1 + (-3) + 2 = 0$).

```
        (1)
 (0) ---------> (1)
  |              |
  |             (-3)
 (4)             |
  |              v
  +-----------> (2) ---------(2)--------> (3)
```

---

### Example 2 (Negative Weight Cycle)
**Input:**
```text
V = 3, E = 3, src = 0
edges = [
  [0, 1, 1],
  [1, 2, -2],
  [2, 0, -1]  (Cycle: 0 -> 1 -> 2 -> 0 has sum 1 + (-2) + (-1) = -2 < 0)
]
```
**Output:**
```text
[-1]  (Negative cycle detected)
```

---

## Algorithmic Approaches

### The $V - 1$ Edge Limit Theorem
In any simple path without cycles in a graph with $V$ vertices, there can be at most **$V - 1$ edges**:
1. If we relax **all $E$ edges** in the graph $V - 1$ consecutive times, every shortest path consisting of up to $V - 1$ edges is guaranteed to have converged to its optimal value!
2. **The $V^{\text{th}}$ Relaxation (Negative Cycle Detection):**
   - If we attempt to relax all edges one more time ($V^{\text{th}}$ iteration) and **any distance decreases**:
     $$\text{dist}[u] + w < \text{dist}[v]$$
   - Then that edge must be part of or reachable from a **negative weight cycle**!

### Step-by-Step Algorithm
1. Initialize `dist` array of size $V$ with $10^8$ ($\infty$), and set `dist[src] = 0`.
2. Relax all $E$ edges $V - 1$ times:
   ```cpp
   for (int i = 0; i < V - 1; ++i) {
       for (auto& edge : edges) {
           int u = edge[0], v = edge[1], w = edge[2];
           if (dist[u] != 1e8 && dist[u] + w < dist[v]) {
               dist[v] = dist[u] + w;
           }
       }
   }
   ```
3. Run the $V^{\text{th}}$ check:
   - For every edge `[u, v, w]`:
     - If `dist[u] != 1e8 && dist[u] + w < dist[v]`:
       - Return `{-1}` (Negative cycle detected!).
4. Return `dist`.

---

## Complexity Analysis
- **Time Complexity:** $O(V \cdot E)$ — Relaxing $E$ edges over $V$ rounds.
- **Space Complexity:** $O(V)$ — Distance array of size $V$.
