# Topological Sort (Kahn's Algorithm & DFS)

## Problem Overview
Given a Directed Acyclic Graph (DAG) with $V$ vertices and $E$ edges, find a **topological sort** of the graph.
A topological sort is a linear ordering of vertices such that for every directed edge $u \to v$, vertex $u$ appears before $v$ in the ordering.
*(Note: A topological sort exists if and only if the directed graph has NO directed cycles).*

---

## 1. Kahn's Algorithm (BFS via In-Degrees)
1. Compute the in-degree (number of incoming edges) for every vertex.
2. Push all vertices with `in_degree == 0` into a FIFO queue (these nodes have no prerequisites).
3. While the queue is not empty:
   - Pop vertex $u$ and add it to the topological ordering.
   - For every directed neighbor $v \in adj[u]$, decrement `in_degree[v]--`.
   - If `in_degree[v] == 0`, all its prerequisites have been satisfied $\implies$ push $v$ into the queue.
4. **Cycle Detection Property:** If the total count of popped nodes $< V$, the graph has a cycle!

---

## 2. DFS Post-Order Reversal
1. Run DFS. When a node's recursive exploration completely finishes, push it onto a stack.
2. The stack contents from top to bottom yield the topological sort.

---

## Complexity Analysis
- **Time Complexity:** $O(V + E)$
- **Space Complexity:** $O(V)$

