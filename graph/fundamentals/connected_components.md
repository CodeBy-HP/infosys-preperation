# Connected Components in Graphs

## Problem Statement
Given an **undirected graph** with `V` vertices labeled from `0` to `V - 1` and `E` edges represented as an adjacency list `adj`:
1. Find the **total number of connected components**.
2. Return a list of all vertices grouped by their respective connected component.

A **connected component** is a maximal subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.

---

## Constraints
* `1 <= V <= 10^5`
* `0 <= E <= 2 * 10^5`
* Undirected graph with no self-loops.

---

## Examples

### Example 1
**Input:**
```text
V = 7, E = 4
Edges: [[0, 1], [1, 2], [3, 4], [5, 6]]
```
**Output:**
```text
Number of Components: 3
Components:
- Component 1: [0, 1, 2]
- Component 2: [3, 4]
- Component 3: [5, 6]
```
**Explanation:**
- Vertices 0, 1, 2 are mutually reachable.
- Vertices 3 and 4 form a separate disjoint component.
- Vertices 5 and 6 form a third disjoint component.

```
(0)---(1)---(2)      (3)---(4)      (5)---(6)
  Component 1       Component 2    Component 3
```

---

### Example 2
**Input:**
```text
V = 4, E = 0 (No edges)
```
**Output:**
```text
Number of Components: 4
```
**Explanation:**
Each isolated vertex forms its own singleton connected component.

---

## Algorithmic Approaches

### Approach 1: Outer Traversal Sweep (BFS / DFS)
1. Initialize `visited` array of size $V$ with `false`.
2. Initialize `componentsCount = 0`, `allComponents = []`.
3. Loop for `i = 0` to `V - 1`:
   - If `!visited[i]`:
     - Increment `componentsCount++`.
     - Initialize `currentComponent = []`.
     - Run DFS/BFS starting from vertex `i`, adding every reached vertex to `currentComponent` and marking `visited = true`.
     - Append `currentComponent` to `allComponents`.
4. Return `componentsCount`.

### Approach 2: Disjoint Set Union (DSU)
1. Initialize DSU of size $V$.
2. For each edge `[u, v]`:
   - `dsu.unionBySize(u, v)`.
3. Count the number of distinct set representatives (`findUPar(i) == i`).

---

## Complexity Analysis
- **Time Complexity:** $O(V + 2E) = O(V + E)$ — Every vertex and edge is visited exactly once across all component traversals.
- **Space Complexity:** $O(V)$ for the `visited` array and recursion call stack or BFS queue.
