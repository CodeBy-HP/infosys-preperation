# Dijkstra's Algorithm (Single Source Shortest Path)

## Problem Overview
Given a weighted, undirected (or directed) graph of $V$ vertices with non-negative edge weights and a source vertex $S$, compute the **shortest path distance** from $S$ to every other vertex in the graph.

---

## Min-Heap Greedy Formulation
Dijkstra's algorithm greedily expands the frontier node with the smallest tentative distance:
1. Initialize array `dist[V]` with $\infty$, setting `dist[S] = 0`.
2. Push `{0, S}` into a min-priority queue `std::priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>` storing `{current_dist, node}`.
3. While priority queue is not empty:
   - Pop top element `{d, u}`.
   - **Stale Entry Optimization:** If $d > dist[u]$, discard immediately (a shorter path to $u$ was already processed).
   - For each neighbor $v$ with edge weight $w$:
     $$\text{If } dist[u] + w < dist[v] \implies dist[v] = dist[u] + w, \quad \text{push } \{dist[v], v\}$$
4. **Non-Negative Weight Invariant:** Once a node $u$ is popped with minimum distance $d$, its shortest path is final. This property **fails** if negative edges are present (which requires Bellman-Ford).

---

## Complexity Analysis
- **Time Complexity:** $O(E \log V)$ using a binary heap.
- **Space Complexity:** $O(V + E)$

