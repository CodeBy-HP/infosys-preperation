# Is Graph Bipartite? (LeetCode 785)

## Problem Statement
There is an **undirected graph** with `n` nodes, where each node is numbered between `0` and `n - 1`. You are given a 2D array `graph`, where `graph[u]` is an array of nodes that node `u` is adjacent to.

A graph is **bipartite** if the nodes can be partitioned into two independent sets `A` and `B` such that every edge in the graph connects a node in set `A` and a node in set `B`.

Return `true` if and only if it is **bipartite**.

---

## Constraints
* `graph.length == n`
* `1 <= n <= 100`
* `0 <= graph[u].length < n`
* `0 <= graph[u][i] <= n - 1`
* `graph[u]` does not contain `u` (no self-loops).
* All the values of `graph[u]` are **unique**.
* The graph is undirected (if `v` is in `graph[u]`, then `u` is in `graph[v]`).
* The graph may be disconnected into multiple components.

---

## Examples

### Example 1
**Input:**
```text
graph = [
  [1, 2, 3],
  [0, 2],
  [0, 1, 3],
  [0, 2]
]
```
**Output:**
```text
false
```
**Explanation:**
Nodes 0, 1, and 2 form a triangle (an odd-length cycle of length 3):
- If node 0 is colored Red, then node 1 must be Blue and node 2 must be Blue.
- But an edge exists between 1 and 2, which both share the color Blue!
Thus, the graph cannot be 2-colored.

```
      (0) [Red]
     /   \
    /     \
[Blue] (1)---(2) [Blue]  <--- Conflict! Edge connects two Blue nodes!
```

---

### Example 2
**Input:**
```text
graph = [
  [1, 3],
  [0, 2],
  [1, 3],
  [0, 2]
]
```
**Output:**
```text
true
```
**Explanation:**
The nodes form an even-length square cycle: `0 - 1 - 2 - 3 - 0`.
Set A = {0, 2} (Red), Set B = {1, 3} (Blue). Every edge connects a node in Set A to Set B.

---

## Algorithmic Approaches

### The Fundamental Bipartite Theorem
A graph is bipartite **if and only if it contains NO odd-length cycle**.
This can be validated via **2-Coloring (BFS or DFS)**:

### 2-Coloring via BFS
1. Maintain a `color` array of size $n$, initialized to `-1` (uncolored).
2. For each node $i \in [0, n - 1]$ (to cover all disconnected components):
   - If `color[i] == -1`:
     - Assign `color[i] = 0`.
     - Push `i` into BFS queue.
     - While queue is non-empty:
       - Pop `curr`.
       - For each neighbor `next` of `curr`:
         - If `color[next] == -1`:
           - Assign opposite color: `color[next] = 1 - color[curr]`.
           - Push `next` into queue.
         - Else if `color[next] == color[curr]`:
           - Two adjacent nodes share the same color $\longrightarrow$ **Odd cycle exists, return `false`!**
3. Return `true` if all nodes are successfully 2-colored.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ — Each node and edge is inspected once during the 2-coloring traversal.
- **Space Complexity:** $O(V)$ — `color` array and BFS queue or recursion stack.
