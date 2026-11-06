# Graph Traversal Techniques (BFS & DFS)

## Overview
Graph traversal visits every reachable vertex from a source vertex exactly once using a `visited` array to prevent infinite cycles.

---

## 1. Breadth-First Search (BFS)
BFS explores the graph **level-by-level** (radially outward) using a FIFO queue.
- **Invariant:** When visiting node $u$ at distance $d$, all nodes at distance $< d$ have already been visited.
- **Shortest Path Property:** On unweighted graphs, BFS finds the shortest path (minimum edge count) between any source and destination.
- **Time Complexity:** $O(V + E)$
- **Space Complexity:** $O(V)$ for queue and visited array.

---

## 2. Depth-First Search (DFS)
DFS plunges as deep as possible along each branch before **backtracking** using recursion (or an explicit LIFO call stack).
- **Invariant:** Explores subtrees completely before backtracking to parent nodes.
- **Applications:** Cycle detection, topological sorting, connected components, biconnectivity (bridges/articulation points).
- **Time Complexity:** $O(V + E)$
- **Space Complexity:** $O(V)$ for recursive call stack.

