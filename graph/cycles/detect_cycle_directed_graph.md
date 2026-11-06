# Detect Cycle in a Directed Graph

## Problem Statement
Given a **directed graph** with `V` vertices labeled from `0` to `V - 1` and `E` directed edges represented as an adjacency list `adj`, determine whether the graph contains any **directed cycle**.

Return `true` if a cycle is present in the directed graph, otherwise return `false`.

---

## Constraints
* `1 <= V <= 10^5`
* `0 <= E <= 2 * 10^5`
* Edges are directional: an edge `u -> v` does not imply `v -> u`.
* The graph may be disconnected into multiple components.

---

## Examples

### Example 1
**Input:**
```text
V = 4, E = 4
Edges = [[0, 1], [1, 2], [2, 3], [3, 1]]
```
**Output:**
```text
true
```
**Explanation:**
The vertices `1 -> 2 -> 3 -> 1` form a directed cycle.

```
(0) ---> (1) ---> (2)
          ^        |
          |        v
         (3) <-----+
    (Cycle: 1 -> 2 -> 3 -> 1)
```

---

### Example 2
**Input:**
```text
V = 3, E = 2
Edges = [[0, 1], [0, 2]]
```
**Output:**
```text
false
```
**Explanation:**
Vertex 0 points to 1 and 2, but there are no back-edges. The graph is a Directed Acyclic Graph (DAG).

---

## Algorithmic Approaches

### Why Undirected Parent-Tracking Fails for Directed Graphs
In a directed graph, encountering an already visited node does **NOT** necessarily imply a cycle (it could simply be a **cross-edge** to another previously finished branch).
A directed cycle exists if and only if there is a **back-edge** to an ancestor currently residing in the **active recursion path**!

### Approach 1: DFS with Active Path Tracking (`pathVis` / 3-Coloring)
Maintain two state arrays:
- `vis[node]`: Marked `true` when a node is visited at all.
- `pathVis[node]`: Marked `true` when a node is currently on the active recursion call stack, and reset to `false` when backtracking.
1. When visiting `adj`:
   - If `!vis[adj]`: Recurse. If cycle found, return `true`.
   - Else if `pathVis[adj] == true`: We encountered an ancestor on the current path $\longrightarrow$ **Directed cycle detected!**

### Approach 2: Kahn's Algorithm (BFS In-Degree Topological Sort)
Topological sorting can **only** be performed on Directed Acyclic Graphs (DAGs).
1. Compute the in-degree of all $V$ nodes.
2. Push all nodes with `inDegree == 0` into a queue.
3. While queue is non-empty, pop node, increment `topoCount++`, and decrement `inDegree` of all neighbors. If neighbor's in-degree drops to 0, push it.
4. If `topoCount == V`, all nodes were ordered acyclically $\longrightarrow$ **No cycle (`false`)**.
5. If `topoCount < V`, cycle blocked the remaining nodes $\longrightarrow$ **Cycle exists (`true`)**.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ — Every vertex and directed edge is processed once.
- **Space Complexity:** $O(V)$ — `vis`, `pathVis`, or `inDegree` array and recursion call stack or queue.
