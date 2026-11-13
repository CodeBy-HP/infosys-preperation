# Find Eventual Safe States (LeetCode 802)

## Problem Statement
There is a directed graph of `n` nodes with each node labeled from `0` to `n - 1`. The graph is represented by a **0-indexed** 2D integer array `graph` where `graph[i]` is an integer array of nodes adjacent to node `i`, meaning there is a directed edge from node `i` to each node in `graph[i]`.

A node is a **terminal node** if there are no outgoing edges (`graph[i].empty()`).
A node is an **eventually safe node** if every possible path starting from that node leads to a **terminal node** (or another safe node), and never gets trapped in a cycle.

Return an array containing all the **eventually safe nodes** of the graph. The answer should be sorted in **ascending order**.

---

## Constraints
* `n == graph.length`
* `1 <= n <= 10^4`
* `0 <= graph[i].length <= n`
* `0 <= graph[i][j] <= n - 1`
* `graph[i]` is sorted in a strictly increasing order.
* The graph may contain self-loops.
* The number of edges in the graph will be in the range `[1, 4 * 10^4]`.

---

## Examples

### Example 1
**Input:**
```text
graph = [
  [1, 2],
  [2, 3],
  [5],
  [0],
  [5],
  [],
  []
]
```
**Output:**
```text
[2, 4, 5, 6]
```
**Explanation:**
- Nodes 5 and 6 are terminal nodes (no outgoing edges) $\longrightarrow$ Safe.
- Node 4 only points to 5 $\longrightarrow$ Safe.
- Node 2 only points to 5 $\longrightarrow$ Safe.
- Nodes 0, 1, 3 form a cycle: $0 \to 1 \to 3 \to 0$. Any path entering this cycle is trapped forever $\longrightarrow$ Unsafe.
Safe nodes in sorted order: `[2, 4, 5, 6]`.

```
(4) ---> (5) [Terminal]
          ^
          |
(0) ---> (1) ---> (2)
 ^                 |
 |                 |
 +------- (3) <----+
    (Cycle: 0-1-3-0)
```

---

### Example 2
**Input:**
```text
graph = [
  [1, 2, 3, 4],
  [1, 2],
  [3, 4],
  [0, 4],
  []
]
```
**Output:**
```text
[4]
```

---

## Algorithmic Approaches

### Approach 1: Topological Sort via Graph Reversal (Kahn's Algorithm)
- By definition, terminal nodes have **out-degree 0**.
- If we **reverse all edges** of the graph ($u \to v$ becomes $v \to u$):
  - Original terminal nodes now have **in-degree 0**!
  - We can run Kahn's algorithm starting from these terminal nodes:
    - Push all nodes with reversed `inDegree == 0` into queue.
    - As each node is processed, it is marked as safe.
    - Decrement the reversed in-degrees of its neighbors.
- Nodes that are part of or lead into a cycle will never have their in-degrees drop to 0.
- Collect all safe nodes and sort them ascending.

### Approach 2: DFS Cycle Detection (3-Coloring)
- State `0`: Unvisited.
- State `1`: Currently visiting (on active DFS call stack).
- State `2`: Safe (verified that all paths lead to terminal nodes).
If a DFS branch reaches a node with State `1`, a cycle is detected $\longrightarrow$ mark current path unsafe.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E) + O(V \log V)$ — Graph reversal and BFS take $O(V + E)$ time; sorting safe nodes takes $O(V \log V)$ time.
- **Space Complexity:** $O(V + E)$ for reversed adjacency list and $O(V)$ for queue and in-degree tracking.
