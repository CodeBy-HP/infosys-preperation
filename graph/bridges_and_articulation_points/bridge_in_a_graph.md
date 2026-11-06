# Critical Connections in a Network / Bridges in a Graph (LeetCode 1192)

## Problem Statement
There are `n` servers numbered from `0` to `n - 1` connected by undirected server-to-server `connections` forming a network where `connections[i] = [a_i, b_i]` represents a connection between servers $a_i$ and $b_i$. Any server can reach other servers directly or indirectly through the network.

A **critical connection (bridge)** is an edge that, if removed, will make some servers unable to reach some other server (i.e. increases the number of connected components in the graph).

Return all critical connections in the network in any order.

---

## Constraints
* `2 <= n <= 10^5`
* `n - 1 <= connections.length <= 10^5`
* `0 <= a_i, b_i < n`
* `a_i != b_i`
* There are no repeated connections.
* The graph is connected.

---

## Examples

### Example 1
**Input:**
```text
n = 4, connections = [[0, 1], [1, 2], [2, 0], [1, 3]]
```
**Output:**
```text
[[1, 3]]
```
**Explanation:**
- Nodes 0, 1, and 2 form a cycle (triangle). Removing any edge `[0, 1]`, `[1, 2]`, or `[2, 0]` leaves all nodes in the triangle connected.
- Edge `[1, 3]` is the only link connecting server 3 to the rest of the network. If `[1, 3]` is removed, server 3 is completely disconnected.
Therefore, `[1, 3]` is the only critical connection (bridge).

```
(0) --- (1) === [1, 3] === (3)
 \     /
  \   /
   (2)
```

---

### Example 2
**Input:**
```text
n = 2, connections = [[0, 1]]
```
**Output:**
```text
[[0, 1]]
```

---

## Algorithmic Approaches

### Tarjan's Bridge-Finding Algorithm (DFS Low-Link & Discovery Time)
To find bridges in a single $O(V + E)$ DFS pass, track two integer arrays:
1. `tin[u]`: **Time of insertion** (discovery timestamp) of node $u$.
2. `low[u]`: **Lowest discovery time** reachable from node $u$ using at most one back-edge.

### Bridge Invariant
When traversing from node $u$ to adjacent neighbor $v$ (where $v \ne \text{parent}$):
- **If $v$ is not yet visited:**
  - Recurse `dfs(v, u)`.
  - Upon return: `low[u] = min(low[u], low[v])`.
  - **Bridge Condition:**
    $$\text{low}[v] > \text{tin}[u]$$
    *Meaning:* There is no back-edge from $v$ (or any of $v$'s descendants) that can reach $u$ or any ancestor of $u$. The edge $(u, v)$ is the sole lifeline connecting $v$'s subtree to the rest of the graph $\implies$ **$(u, v)$ is a Bridge!**
- **If $v$ is already visited (Back-Edge):**
  - Update `low[u] = min(low[u], tin[v])`.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ — Every vertex and edge is explored exactly once in the DFS traversal.
- **Space Complexity:** $O(V + E)$ for adjacency list and $O(V)$ for `tin`, `low`, `vis` arrays and recursion call stack.
