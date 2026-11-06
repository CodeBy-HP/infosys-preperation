# Find the Minimum Spanning Tree (MST) Weight

## Problem Overview
Given a weighted, undirected, and connected graph of $V$ vertices and $E$ edges, find the **sum of weights of the edges** of the Minimum Spanning Tree (MST).

---

## 1. Kruskal's Algorithm (Edge Sorting + DSU)
1. Store all edges as `{weight, u, v}` and sort them in non-decreasing order of weight.
2. Initialize a Disjoint Set Union (DSU) structure of size $V$.
3. Maintain `mstWeight = 0` and `edgesCount = 0`.
4. For each edge `{w, u, v}`:
   - If `ds.find(u) != ds.find(v)`:
     - `ds.unionBySize(u, v)`
     - `mstWeight += w`
     - `edgesCount++`
   - If `edgesCount == V - 1`, the MST is complete; break early.

---

## 2. Prim's Algorithm (Priority Queue + Visited)
1. Min-heap priority queue stores `{weight, node}`.
2. Push `{0, 0}` to start at vertex `0`.
3. While priority queue is not empty:
   - Pop `{w, u}`.
   - If `visited[u]`, continue.
   - Mark `visited[u] = true`, add `w` to `mstWeight`.
   - For all neighbors $v$ of $u$ where `!visited[v]`:
     Push `{weight_uv, v}`.

---

## Complexity Analysis
- **Kruskal's Algorithm:** $O(E \log E) + O(E \cdot \alpha(V))$ Time, $O(V + E)$ Space.
- **Prim's Algorithm:** $O(E \log V)$ Time, $O(V + E)$ Space.

