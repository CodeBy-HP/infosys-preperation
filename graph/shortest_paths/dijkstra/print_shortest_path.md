# Print Shortest Path (Dijkstra Path Reconstruction)

## Problem Overview
You are given a weighted undirected graph having $V$ vertices numbered from $1$ to $V$ and $M$ edges.
Find the **shortest path between vertex $1$ and vertex $V$**.
Return the sequence of vertices from $1$ to $V$ that constitute the shortest path.
If no path exists from $1$ to $V$, return `{-1}`.

---

## Parent Pointer Tracking
While standard Dijkstra only computes minimum scalar distances, we can reconstruct the actual physical sequence of nodes by maintaining a **`parent` pointer array**:
1. Initialize `parent[i] = i` for all $i \in [1, V]$.
2. In Dijkstra's relaxation step:
   $$\text{If } dist[u] + w < dist[v] \implies dist[v] = dist[u] + w, \quad parent[v] = u$$
3. After the min-heap finishes:
   - If `dist[V] == \infty`, target $V$ is unreachable $\implies$ return `{-1}`.
   - Otherwise, trace backward from node $V$ using `parent`:
     $$curr = parent[curr]$$
     until $curr == 1$.
   - Reverse the collected nodes to get the source-to-destination path.

---

## Complexity Analysis
- **Time Complexity:** $O(E \log V)$ for Dijkstra $+ O(V)$ for path backtracking.
- **Space Complexity:** $O(V + E)$

