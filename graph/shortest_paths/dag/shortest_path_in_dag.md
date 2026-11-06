# Shortest Path in Directed Acyclic Graph (DAG)

## Problem Overview
Given a Directed Acyclic Graph (DAG) with $V$ vertices and weighted directed edges, find the **shortest path from a given source vertex $S$ to all other vertices**.
If a vertex is unreachable from $S$, assign its distance as $-1$ (or $\infty$).

---

## Linear Time Topological Relaxation ($O(V + E)$)
On general graphs with cycles, finding shortest paths requires Dijkstra ($O((V + E)\log V)$) or Bellman-Ford ($O(V \times E)$).
However, on a **DAG**, the topological sort enforces a linear causal timeline where **no future path can ever loop back to update an earlier node**:
1. Find a **Topological Sort** of the DAG (via DFS or Kahn's algorithm) in $O(V + E)$.
2. Initialize `dist[V]` with $\infty$, setting `dist[S] = 0`.
3. Iterate through vertices in **topological order**:
   - If `dist[u] != \infty`:
     For each directed outgoing edge $(u \to v, w)$:
     $$\text{dist}[v] = \min(\text{dist}[v], \; \text{dist}[u] + w)$$
4. Crucially: Because edges only point forward in topological order, by the time we process node $u$, `dist[u]` is mathematically guaranteed to be **final and optimal**!
5. This linear relaxation **natively handles negative edge weights** as long as the graph is a DAG!

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$
- **Space Complexity:** $O(V + E)$

