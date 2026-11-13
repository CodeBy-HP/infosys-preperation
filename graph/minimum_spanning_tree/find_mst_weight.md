# Minimum Spanning Tree (Prim's & Kruskal's Algorithms)

## Problem Statement
Given a weighted, undirected, and connected graph with `V` vertices labeled from `0` to `V - 1` and `E` edges represented as an adjacency list or edge list:
Find the **sum of the weights of the edges** in the **Minimum Spanning Tree (MST)** of the graph.

A **Spanning Tree** of a graph is a subgraph that is a tree (acyclic, connected) and connects all $V$ vertices using exactly $V - 1$ edges.
A **Minimum Spanning Tree (MST)** is a spanning tree whose sum of edge weights is the smallest possible.

---

## Constraints
* `2 <= V <= 10^5`
* `V - 1 <= E <= 2 * 10^5`
* `1 <= w_i <= 10^4`
* The graph is connected, undirected, and contains no self-loops.

---

## Examples

### Example 1
**Input:**
```text
V = 5, E = 6
edges = [
  [0, 1, 2],
  [0, 3, 6],
  [1, 2, 3],
  [1, 3, 8],
  [1, 4, 5],
  [2, 4, 7]
]
```
**Output:**
```text
16
```
**Explanation:**
The edges included in the MST are:
- `(0, 1)` with weight 2
- `(1, 2)` with weight 3
- `(1, 4)` with weight 5
- `(0, 3)` with weight 6
Total weight = $2 + 3 + 5 + 6 = 16$.
Total edges = $5 - 1 = 4$.

```
      (0)
     /   \ (6)
 (2)/     v
  (1)----(3)
  / \
(3) (5)
/     \
(2)   (4)
```

---

### Example 2
**Input:**
```text
V = 3, E = 3
edges = [
  [0, 1, 5],
  [1, 2, 10],
  [0, 2, 1]
]
```
**Output:**
```text
6
```
**Explanation:**
Select edges `(0, 2)` with weight 1 and `(0, 1)` with weight 5. Total MST weight = $1 + 5 = 6$.

---

## Algorithmic Approaches

### Approach 1: Prim's Algorithm (Greedy Frontier Expansion via Min-Heap)
- Maintains a growing tree component. Greedily adds the cheapest outgoing edge connecting a node in the tree to an unvisited node outside the tree.
1. Min-Heap stores `{weight, node}`.
2. Maintain `visited` array of size $V$, initialized to `false`.
3. Push `{0, 0}` into heap.
4. While heap is not empty:
   - Extract `{w, u}`.
   - If `visited[u] == true`, continue.
   - Mark `visited[u] = true`.
   - Add `mstWeight += w`.
   - For each neighbor `(v, weight)` of `u`:
     - If `!visited[v]`:
       - Push `{weight, v}` into heap.
5. Return `mstWeight`.
- **Complexity:** $O(E \log V)$.

---

### Approach 2: Kruskal's Algorithm (Edge Sorting + Disjoint Set Union)
- Greedily selects the overall cheapest edge that does not form a cycle.
1. Sort all $E$ edges in non-decreasing order of weight.
2. Initialize a DSU of size $V$.
3. For each edge `[u, v, w]` in sorted order:
   - If `dsu.unionBySize(u, v)` succeeds (meaning $u$ and $v$ belong to different components):
     - `mstWeight += w`.
     - `edgesCount++`.
     - If `edgesCount == V - 1`, break early.
4. Return `mstWeight`.
- **Complexity:** $O(E \log E + E \cdot \alpha(V)) = O(E \log E)$.

---

## Complexity Analysis
- **Time Complexity:**
  - Prim's Algorithm: $O(E \log V)$ using binary min-heap.
  - Kruskal's Algorithm: $O(E \log E)$ for sorting edges.
- **Space Complexity:**
  - Prim's: $O(V + E)$ for adjacency list and priority queue.
  - Kruskal's: $O(V + E)$ for edge list and DSU parent/size arrays.
