# Topological Sort & Kahn's Algorithm

## Problem Statement
Given a **Directed Acyclic Graph (DAG)** with `V` vertices labeled from `0` to `V - 1` and `E` directed edges represented as an adjacency list `adj`:
Return any valid **topological ordering** of the vertices.

A **topological sort** of a directed graph is a linear ordering of its vertices such that for every directed edge $u \to v$, vertex $u$ comes before vertex $v$ in the ordering.
If the graph contains a directed cycle, no topological sort is possible.

---

## Constraints
* `1 <= V <= 10^5`
* `0 <= E <= 2 * 10^5`
* Graph may be disconnected.
* Input is guaranteed to be a DAG for topological ordering (or returns empty array if cycle present).

---

## Examples

### Example 1
**Input:**
```text
V = 6, E = 6
adj = [
  [],
  [],
  [3],
  [1],
  [0, 1],
  [0, 2]
]
```
**Output:**
```text
[5, 4, 2, 3, 1, 0]  (or [4, 5, 0, 2, 3, 1])
```
**Explanation:**
- 5 points to 0 and 2. 4 points to 0 and 1.
- Both 5 and 4 have in-degree 0 and can come first.
- In every valid output, each node appears strictly before all nodes it points to.

```
(5) ---> (0) <--- (4)
 |                 |
 v                 v
(2) ---> (3) ---> (1)
```

---

### Example 2
**Input:**
```text
V = 2, E = 2
Edges: [[0, 1], [1, 0]]
```
**Output:**
```text
[]  (Cycle detected: no topological ordering exists)
```

---

## Algorithmic Approaches

### Approach 1: Kahn's Algorithm (BFS In-Degree Dependency Resolution)
1. **Compute In-Degrees:** Count how many incoming directed edges each vertex has:
   ```cpp
   vector<int> inDegree(V, 0);
   for (int u = 0; u < V; ++u)
       for (int v : adj[u]) inDegree[v]++;
   ```
2. **Initialize Queue:** Push all vertices with `inDegree[u] == 0` into the queue (nodes with zero prerequisites).
3. **Process Dependencies:**
   - While queue is not empty:
     - Pop `curr`. Append `curr` to `topoOrder`.
     - For each neighbor `next` of `curr`:
       - Decrement its in-degree: `inDegree[next]--`.
       - If `inDegree[next] == 0`: all dependencies satisfied! Push `next` into queue.
4. **Cycle Validation:**
   - If `topoOrder.size() == V`: Valid DAG, return `topoOrder`.
   - Else: A directed cycle prevented some in-degrees from reaching 0. Return empty array.

### Approach 2: DFS Post-Order Reversal (Stack)
1. Maintain `visited` array and a stack `st`.
2. For each unvisited node, launch DFS:
   - For each unvisited neighbor, recurse.
   - Upon finishing all descendants, push `node` to `st`.
3. Pop all elements from `st` to obtain the topological ordering.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ — Every vertex enters the queue once, and every directed edge is decremented once.
- **Space Complexity:** $O(V)$ — `inDegree` array, queue, and topological order result buffer.
