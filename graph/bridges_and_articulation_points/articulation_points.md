# Articulation Points (Cut Vertices) in a Graph

## Problem Statement
Given an undirected, connected graph with `V` vertices labeled from `0` to `V - 1` and `E` edges represented as an adjacency list `adj`:
Find all the **articulation points (cut vertices)** of the graph.

An **articulation point** is a vertex whose removal (along with all edges incident to it) **increases the number of connected components** in the graph (i.e. disconnects the graph).

Return all articulation points in sorted ascending order. If no articulation point exists, return `[-1]`.

---

## Constraints
* `1 <= V <= 10^5`
* `0 <= E <= 2 * 10^5`
* The graph is connected and contains no self-loops.

---

## Examples

### Example 1
**Input:**
```text
V = 5, E = 5
edges = [[0, 1], [0, 2], [1, 2], [1, 3], [3, 4]]
```
**Output:**
```text
[1, 3]
```
**Explanation:**
- Removing vertex 1 disconnects the component `{3, 4}` from `{0, 2}`.
- Removing vertex 3 disconnects vertex 4 from the rest of the graph.
- Removing vertex 0 or 2 leaves the graph connected.
- Removing vertex 4 leaves `{0, 1, 2, 3}` connected.
Articulation points: `1` and `3`.

```
(0) --- (1) --- (3) --- (4)
 \     /
  \   /
   (2)
```

---

### Example 2
**Input:**
```text
V = 3, E = 3
edges = [[0, 1], [1, 2], [2, 0]]
```
**Output:**
```text
[-1]
```
**Explanation:**
The graph is a 3-cycle. Removing any single vertex leaves the remaining 2 vertices connected. No articulation point exists.

---

## Algorithmic Approaches

### Tarjan's Articulation Point Algorithm (DFS Low-Link)
Track `tin[u]` (discovery time) and `low[u]` (lowest reachable discovery time):
A node $u$ is an articulation point under two distinct cases:

### Case 1: Root of DFS Tree ($parent == -1$)
If the root node of the DFS tree has **2 or more independent children** in the DFS spanning tree:
$$\text{children} > 1 \implies \text{Root is an Articulation Point!}$$
*(Removing the root separates its independent child subtrees).*

### Case 2: Non-Root Node ($parent \ne -1$)
If an adjacent child $v$ satisfies:
$$\text{low}[v] \ge \text{tin}[u]$$
*(Meaning: Child $v$ has no back-edge reaching any strict ancestor of $u$. The only way $v$ can reach the rest of the graph is through $u$. Removing $u$ isolates $v$'s component).*

*Note on Back-Edge update:* For articulation points, when encountering an already visited node $v \ne parent$, use:
$$\text{low}[u] = \min(\text{low}[u], \; \text{tin}[v])$$
(We cannot take `low[v]` because $v$ might itself be disconnected!).

---

## Complexity Analysis
- **Time Complexity:** $O(V + 2E) = O(V + E)$ — Single DFS pass.
- **Space Complexity:** $O(V + E)$ for adjacency list and $O(V)$ for `tin`, `low`, `vis`, and `isArticulation` arrays.
