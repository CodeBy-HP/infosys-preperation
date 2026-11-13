# Shortest Path in an Unweighted Graph (Breadth-First Search)

## Problem Statement

Given an unweighted, undirected graph with $V$ vertices (labeled from $0$ to $V - 1$) and $E$ edges represented as an edge list, calculate the **shortest distance** (the minimum number of edges) from a designated **source node $0$** to all other nodes in the graph.

If a node is unreachable from node $0$, its distance should be $-1$.

---

## Examples

### Example 1
```text
    0 --- 1 --- 3
    |     |
    2 --- 4
```
- **Input:** $V = 5$, `edges = [[0, 1], [0, 2], [1, 3], [1, 4], [2, 4]]`, `source = 0`
- **Output:** `dist = [0, 1, 1, 2, 2]`
- **Explanation:**
  - Distance to 0 is 0.
  - Nodes 1 and 2 are adjacent to 0 $\to$ distance = 1.
  - Node 3 is reachable from 1 $\to$ distance = $1 + 1 = 2$.
  - Node 4 is reachable from 1 or 2 $\to$ distance = $1 + 1 = 2$.

### Example 2 (Disconnected Components)
- **Input:** $V = 4$, `edges = [[0, 1], [2, 3]]`, `source = 0`
- **Output:** `dist = [0, 1, -1, -1]`
- **Explanation:** Nodes 2 and 3 belong to a separate connected component and cannot be reached from node 0.

---

## Constraints

- $1 \le V \le 10^5$
- $0 \le E \le 2 \times 10^5$
- $0 \le u, v < V$

---

## Algorithmic Paradigm: Breadth-First Search (BFS)

### Why BFS Finds the Shortest Path in Unweighted Graphs
In an unweighted graph where every edge has identical unit cost $1$, BFS explores nodes in strictly non-decreasing order of their distance from the source:
- Level 0: The source node itself.
- Level 1: All immediate neighbors of the source.
- Level $d$: All unvisited nodes that have an edge from a node at level $d - 1$.

Because the first time BFS reaches a node $v$, it does so along the fewest possible number of edges, the first recorded distance is guaranteed to be minimal.

### Step-by-Step Algorithm
1. Construct the adjacency list from the input edge list:
   $$\text{adj}[u].\text{push\_back}(v), \quad \text{adj}[v].\text{push\_back}(u)$$
2. Initialize a distance array `dist` of size $V$ with `-1`.
3. Set `dist[source] = 0` and push `source` into a standard FIFO queue `std::queue<int>`.
4. While the queue is not empty:
   - Dequeue the front node `u`.
   - For every adjacent neighbor `v` in $\text{adj}[u]$:
     - If `dist[v] == -1` (unvisited):
       - `dist[v] = dist[u] + 1`
       - Enqueue `v`.
5. Return `dist`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(V + E)$ (each vertex and edge visited once) |
| **Space Complexity** | $\mathcal{O}(V + E)$ for adjacency list and BFS queue |

