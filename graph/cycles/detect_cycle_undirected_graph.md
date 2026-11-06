# Detect Cycle in an Undirected Graph

## Problem Overview
Given an undirected graph with $V$ vertices and $E$ edges, determine whether the graph contains any **cycle**. Return `true` if a cycle is present, otherwise `false`.

---

## Parent Pointer Invariant
In an undirected graph, an edge between $u$ and $v$ exists in both directions ($u \to v$ and $v \to u$).
Therefore, when traversing from $u$ to $v$, node $u$ is the **parent** of $v$.
- **Cycle Condition:** If we encounter an adjacent node $adj$ that has **already been visited** AND $adj \ne parent$, then there must exist an alternative path closing a loop $\implies$ **A cycle exists!**

---

## Complexity Analysis
- **Time Complexity:** $O(V + 2E) = O(V + E)$
- **Space Complexity:** $O(V)$ for visited array, parent tracking, and recursion/queue buffer.

