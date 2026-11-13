# Detect Cycle in an Undirected Graph

## Problem Statement
Given an **undirected graph** with `V` vertices labeled from `0` to `V - 1` and `E` edges represented as an adjacency list `adj`, determine whether the graph contains any **cycle**.

Return `true` if a cycle is present in the graph, otherwise return `false`.

---

## Constraints
* `1 <= V <= 10^5`
* `0 <= E <= 2 * 10^5`
* The graph may be disconnected (composed of multiple disconnected components).
* No self-loops or multiple edges between the same pair of vertices.

---

## Examples

### Example 1
**Input:**
```text
V = 5, E = 5
Edges = [[0, 1], [1, 2], [2, 3], [3, 4], [4, 1]]
```
**Output:**
```text
true
```
**Explanation:**
The vertices `1 -> 2 -> 3 -> 4 -> 1` form a closed loop (cycle).

```
(0) --- (1) --- (2)
         |       |
        (4) --- (3)
    (Cycle: 1-2-3-4-1)
```

---

### Example 2
**Input:**
```text
V = 4, E = 3
Edges = [[0, 1], [1, 2], [2, 3]]
```
**Output:**
```text
false
```
**Explanation:**
The graph is a simple line tree without any back-edges or cycles.

```
(0) --- (1) --- (2) --- (3)
       (Acyclic Tree)
```

---

## Algorithmic Approaches

### The Parent-Tracking Invariant
In an undirected graph, an edge between $u$ and $v$ exists in both directions ($u \to v$ and $v \to u$).
Therefore, when traversing from $u$ to $v$, node $u$ is the **immediate parent** of $v$.
- **Cycle Condition:** If we encounter an adjacent neighbor $w$ that has **already been visited** AND $w \ne \text{parent}$, there must exist an alternative path leading back to $w$ $\implies$ **A cycle is detected!**

### Approach 1: Breadth-First Search (BFS)
1. Initialize `visited` array of size $V$ with `false`.
2. For each node $i \in [0, V - 1]$ (handling disconnected components):
   - If `!visited[i]`:
     - Push `{i, -1}` into queue (`{current_node, parent}`).
     - Mark `visited[i] = true`.
     - While queue is not empty:
       - Pop `{node, parent}`.
       - For each adjacent node `adj` of `node`:
         - If `!visited[adj]`:
           - Mark `visited[adj] = true`.
           - Push `{adj, node}` into queue.
         - Else if `adj != parent`:
           - Visited node that is not parent $\implies$ return `true`.
3. Return `false` if all components are explored without detecting a cycle.

### Approach 2: Depth-First Search (DFS)
```cpp
bool dfs(int node, int parent, vector<bool>& vis, vector<int> adj[]) {
    vis[node] = true;
    for (int next : adj[node]) {
        if (!vis[next]) {
            if (dfs(next, node, vis, adj)) return true;
        } else if (next != parent) {
            return true; // Cycle detected
        }
    }
    return false;
}
```

---

## Complexity Analysis
- **Time Complexity:** $O(V + 2E) = O(V + E)$ — Every vertex is queued/visited once, and every undirected edge is inspected twice.
- **Space Complexity:** $O(V)$ — `visited` array, parent tracking, and BFS queue or DFS recursion stack.
