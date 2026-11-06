# Connected Components in Undirected Graphs

## Problem Overview
Given an undirected graph with $V$ vertices, find the number of **connected components**.
A connected component is a maximal set of vertices such that every vertex in the set is reachable from every other vertex in the set.

---

## Outer Loop Traversal Invariant
A standard BFS or DFS starting from a node $u$ only traverses the single component containing $u$.
To find all components in a disconnected graph:
1. Initialize an array `visited` of size $V$ with `false`.
2. Iterate through all nodes $i \in [0, V-1]$:
   - If node $i$ is not yet visited, increment `componentCount`, and trigger a full traversal (BFS or DFS) starting from $i$.
3. Upon loop completion, `componentCount` holds the exact number of disjoint components.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$ since each node and edge is visited a constant number of times.
- **Space Complexity:** $O(V)$ for the visited array and recursion/queue buffer.

