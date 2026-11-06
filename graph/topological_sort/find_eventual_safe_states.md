# Find Eventual Safe States (LeetCode 802)

## Problem Overview
A directed graph of $V$ nodes is given, where `graph[i]` is a list of all nodes $j$ for which there is a directed edge from $i$ to $j$.
A node is a **terminal node** if there are no outgoing edges.
A node is an **eventual safe node** if every possible path starting from that node leads to a terminal node (or another safe node).
Return an array containing all the safe nodes of the graph in **sorted ascending order**.

---

## 1. Reversed Graph + Kahn's Algorithm
- Any node that is part of a cycle or leads into a cycle is **unsafe**.
- In the original graph, terminal nodes have `out-degree == 0`.
- If we **reverse all directed edges** ($u \to v$ becomes $v \to u$):
  - Original terminal nodes now have `in-degree == 0`!
  - We can run standard Kahn's BFS starting from these zero in-degree nodes.
  - Every node that gets processed by Kahn's algorithm is guaranteed to be safe!

---

## 2. 3-Coloring DFS (Cycle Check)
- State 0: Unvisited
- State 1: Visiting (currently on active recursion path)
- State 2: Safe (all outgoing paths verified acyclic)
If a path touches a node with state 1, a cycle exists $\implies$ unsafe.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$
- **Space Complexity:** $O(V + E)$

