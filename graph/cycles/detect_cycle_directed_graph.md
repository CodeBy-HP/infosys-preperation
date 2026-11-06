# Detect Cycle in a Directed Graph

## Problem Overview
Given a Directed Graph with $V$ vertices and $E$ edges, determine if the graph contains any **directed cycle**. Return `true` if a cycle exists, otherwise `false`.

---

## 1. Kahn's Algorithm BFS Invariant
Topological Sort can **only** be generated on Directed Acyclic Graphs (DAGs).
If a graph contains a directed cycle, the in-degrees of nodes in the cycle will never drop to 0, and they will never enter the BFS queue.
- Maintain a counter `count` of nodes popped from the queue.
- **Cycle Condition:** If $\text{count} < V$, then at least one node could not be resolved $\implies$ **Cycle exists!**

---

## 2. DFS Path-Visited Tracking
In an undirected graph, checking `visited[neighbor]` and `neighbor != parent` is sufficient.
In a **directed graph**, an edge $u \to v$ where $v$ was visited in an *unrelated earlier branch* does NOT constitute a cycle!
A cycle only exists if $v$ is on the **current active recursion path** (a **Back-Edge**).
- Maintain two boolean arrays: `visited[V]` and `pathVisited[V]`.
- On entering node $u$: `visited[u] = true`, `pathVisited[u] = true`.
- For each $v \in adj[u]$:
  - If not visited, recurse.
  - If already `visited[v] && pathVisited[v]` $\implies$ **Cycle detected!**
- On exiting node $u$ (backtracking): `pathVisited[u] = false`.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$
- **Space Complexity:** $O(V)$

