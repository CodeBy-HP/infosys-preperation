# Strongly Connected Components (Kosaraju's Algorithm)

## Problem Statement
Given a **directed graph** with `V` vertices labeled from `0` to `V - 1` and `E` edges represented as an adjacency list `adj`:
Find the **number of Strongly Connected Components (SCCs)** in the graph.

A **Strongly Connected Component (SCC)** is a maximal subgraph in a directed graph such that every vertex in the subgraph is reachable from any other vertex in the same subgraph (i.e. every pair $(u, v)$ has a directed path $u \to^* v$ and $v \to^* u$).

---

## Constraints
* `1 <= V <= 10^5`
* `0 <= E <= 2 * 10^5`
* Directed graph, may contain cycles and multiple disconnected components.

---

## Examples

### Example 1
**Input:**
```text
V = 5, E = 5
edges = [[0, 2], [2, 1], [1, 0], [0, 3], [3, 4]]
```
**Output:**
```text
3
```
**Explanation:**
- Vertices `{0, 1, 2}` form a 3-cycle: $0 \to 2 \to 1 \to 0$. Mutually reachable $\implies$ SCC 1.
- Vertex `3` has outgoing edge to 4, but 4 cannot reach 3 $\implies$ SCC 2 is `{3}`.
- Vertex `4` has no outgoing edges $\implies$ SCC 3 is `{4}`.
Total SCCs = 3.

```
(0) <----- (1)
 |   \      ^
 |    \    /
 |     v  /
 |      (2)
 v
(3) ----> (4)
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
1
```
**Explanation:**
All 3 vertices are part of a single mutual cycle $\implies$ 1 SCC.

---

## Algorithmic Approaches

### Kosaraju's Two-Pass Algorithm (Why Edge Inversion Works)
Consider condensing each SCC into a single super-node: the resulting condensed graph is strictly a **DAG**!
- If we finish a DFS on an SCC that has no outgoing edges in the condensed graph (a "sink" SCC), its vertices finish last in post-order.
- If we **reverse all edges** in the graph:
  - Inside each SCC, mutual reachability is **preserved** (a cycle reversed is still a cycle!).
  - Across different SCCs, directed edges point in the **opposite direction**!
  - Therefore, a DFS starting from the latest finishing vertices on the reversed graph will be completely trapped within its own SCC, unable to escape into other SCCs!

### Step-by-Step Algorithm
1. **Pass 1: Order by Finish Time (Original Graph)**
   - Run DFS on the original graph.
   - When all descendants of node $u$ are finished, push $u$ to a stack `st`.
2. **Pass 2: Graph Transposition (Reversal)**
   - Build reversed adjacency list `adjT` where $u \to v$ becomes $v \to u$.
3. **Pass 3: DFS in Topological Stack Order (Reversed Graph)**
   - Reset `visited` array to `false`.
   - While `st` is not empty:
     - Pop `curr = st.top()`.
     - If `!visited[curr]`:
       - Increment `sccCount++`.
       - Run DFS on `adjT` from `curr`, marking all reachable nodes in this SCC as visited.
4. Return `sccCount`.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ — Pass 1 takes $O(V + E)$, graph reversal takes $O(V + E)$, and Pass 2 takes $O(V + E)$.
- **Space Complexity:** $O(V + E)$ for reversed adjacency list `adjT` and $O(V)$ for stack and visited array.
