# Introduction to Graphs

## Graph Definition & Representations
A **Graph** $G = (V, E)$ consists of a set of vertices (nodes) $V$ and a set of edges (connections) $E$.
Graphs can be:
- **Directed** (arcs with orientation $u \to v$) vs. **Undirected** (symmetric edges $(u, v)$).
- **Weighted** (each edge has a scalar cost $w$) vs. **Unweighted** (unit edge costs).
- **Cyclic** (contains at least one closed loop) vs. **Acyclic** (no cycles; a DAG is a Directed Acyclic Graph).

---

## Storage Paradigms

### 1. Adjacency Matrix
A 2D array `matrix[V][V]` where `matrix[u][v]` stores the edge weight (or 1 for unweighted).
- **Space:** $O(V^2)$
- **Edge Existence Check $(u, v)$:** $O(1)$
- **Find Neighbors of $u$:** $O(V)$
- **Ideal for:** Dense graphs ($E \approx V^2$).

### 2. Adjacency List
An array of lists / vectors `vector<vector<pair<int, int>>> adj(V)` where `adj[u]` contains all pairs `{v, weight}`.
- **Space:** $O(V + E)$ (or $O(V + 2E)$ for undirected)
- **Edge Existence Check $(u, v)$:** $O(\text{deg}(u))$
- **Find Neighbors of $u$:** $O(\text{deg}(u))$
- **Ideal for:** Sparse graphs ($E \ll V^2$), standard in 99% of competitive programming and interview problems.

---

## Complexity Comparison
| Operation | Adjacency Matrix | Adjacency List |
|---|---|---|
| Space Complexity | $O(V^2)$ | $O(V + E)$ |
| Add Edge | $O(1)$ | $O(1)$ |
| Remove Edge | $O(1)$ | $O(\text{deg}(u))$ |
| Query Edge $(u, v)$ | $O(1)$ | $O(\text{deg}(u))$ |
| Iterate Neighbors | $O(V)$ | $O(\text{deg}(u))$ |

