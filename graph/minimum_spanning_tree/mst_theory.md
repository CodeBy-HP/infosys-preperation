# Minimum Spanning Tree (MST) Theory

## What is a Spanning Tree?
A **Spanning Tree** of a connected, undirected graph $G = (V, E)$ is a subgraph that:
1. Includes **all $V$ vertices** of $G$.
2. Is a **Tree** (connected and contains strictly **no cycles**).
3. Has exactly **$V - 1$ edges**.

A **Minimum Spanning Tree (MST)** is a spanning tree whose sum of edge weights is minimized:
$$\text{Weight}(T) = \sum_{e \in T} w(e) \quad \text{is minimal}$$

---

## Fundamental Cut & Cycle Properties

### 1. The Cut Property
For any cut $C = (S, V \setminus S)$ in the graph, if an edge $e$ crossing the cut has strictly smaller weight than all other edges crossing the cut, then **$e$ must belong to every MST**.
*(Basis for both Kruskal's and Prim's algorithms).*

### 2. The Cycle Property
For any cycle in the graph, if an edge $e$ in the cycle has strictly larger weight than all other edges in the cycle, then **$e$ cannot belong to any MST**.

---

## Kruskal's vs. Prim's Algorithm

| Attribute | Kruskal's Algorithm | Prim's Algorithm |
|---|---|---|
| **Strategy** | Edge-centric (Global Greedy) | Vertex-centric (Local Growing Component) |
| **Data Structure** | Disjoint Set Union (DSU) | Min-Heap Priority Queue |
| **Edge Sorting** | Requires sorting all $E$ edges upfront | Explores edges incident to growing tree |
| **Time Complexity** | $O(E \log E)$ | $O(E \log V)$ |
| **Ideal Graph Type** | **Sparse Graphs** ($E \approx V$) | **Dense Graphs** ($E \approx V^2$) |
| **Intermediate State**| A forest of trees merging together | Always a single connected growing tree |

---

## Algorithmic Workflow

### Kruskal's:
1. Sort all $E$ edges in non-decreasing order of weight.
2. Initialize DSU with $V$ disjoint sets.
3. For each edge $(u, v, w)$:
   - If `find(u) != find(v)`:
     - Edge does not form a cycle $\implies$ add $w$ to MST cost and union $(u, v)$.
   - Stop when $V - 1$ edges have been picked.

### Prim's:
1. Start at arbitrary root vertex $0$, add all incident edges to a min-heap.
2. Maintain a `visited[V]` array.
3. While min-heap is not empty and tree has $< V$ vertices:
   - Pop minimum edge $(w, u)$.
   - If `visited[u]`, skip.
   - Mark `visited[u] = true`, add $w$ to MST weight.
   - Push all edges $(u, v, w_{uv})$ where $v$ is not yet visited.

