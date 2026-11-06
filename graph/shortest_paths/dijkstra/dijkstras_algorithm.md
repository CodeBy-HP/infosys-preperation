# Dijkstra's Algorithm (Single-Source Shortest Path)

## Problem Statement
Given a weighted, directed or undirected graph with `V` vertices labeled from `0` to `V - 1` and non-negative edge weights, find the **shortest distance** from a given source vertex `src` to all other vertices in the graph.

---

## Constraints
* `1 <= V <= 10^5`
* `0 <= E <= 2 * 10^5`
* All edge weights $w \ge 0$ (**Crucial requirement: Dijkstra fails in the presence of negative edge weights**).
* $0 \le src < V$.

---

## Examples

### Example 1
**Input:**
```text
V = 3, E = 3, src = 2
edges = [
  [0, 1, 1],
  [1, 2, 3],
  [0, 2, 6]
]  (Undirected)
```
**Output:**
```text
[4, 3, 0]
```
**Explanation:**
- Shortest distance from 2 to 2 is 0.
- Shortest distance from 2 to 1 is 3 (direct edge `2 - 1`).
- Shortest distance from 2 to 0 is `2 - 1 - 0` with cost $3 + 1 = 4$ (better than direct edge `2 - 0` which costs 6).

```
(0) -----(1)-----> (1)
  \                 /
   (6)           (3)
     \           /
      v         v
         (2)
```

---

### Example 2
**Input:**
```text
V = 2, E = 0, src = 0
```
**Output:**
```text
[0, -1]  (Node 1 is unreachable)
```

---

## Algorithmic Approaches

### Min-Heap Priority Queue Implementation ($O((V + E) \log V)$)
1. Initialize a `dist` array of size $V$ with $\infty$, and set `dist[src] = 0`.
2. Initialize a min-priority queue `priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq` storing `{current_dist, node}`.
3. Push `{0, src}` into `pq`.
4. While `pq` is not empty:
   - Extract `{d, u} = pq.top()`. `pq.pop()`.
   - **Stale Entry Guard:** If `d > dist[u]`, continue (a shorter path to `u` was already finalized).
   - For each outgoing edge `(u -> v, weight)`:
     - If `dist[u] + weight < dist[v]`:
       - Update `dist[v] = dist[u] + weight`.
       - Push `{dist[v], v}` into `pq`.
5. Return `dist`.

### Why Dijkstra Fails on Negative Edge Weights
Dijkstra greedily finalizes the distance to a node the moment it is popped from the min-heap, assuming no future addition of non-negative weights can decrease it. Negative edge weights violate this greedy invariant, requiring Bellman-Ford or SPFA instead.

---

## Complexity Analysis
- **Time Complexity:** $O((V + E) \log V) = O(E \log V)$ — Each vertex is extracted once ($V \log V$), and each edge can trigger a relaxation push ($E \log V$).
- **Space Complexity:** $O(V + E)$ for adjacency list and $O(V)$ for priority queue and distance array.
