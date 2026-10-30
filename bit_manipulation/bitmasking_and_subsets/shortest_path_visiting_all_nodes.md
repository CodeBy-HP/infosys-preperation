# Shortest Path Visiting All Nodes (LeetCode 847)

## Problem Statement
You have an undirected, connected graph of `n` nodes labeled from `0` to `n - 1`. You are given an array `graph` where `graph[i]` is a list of all the nodes connected with node `i` by an edge.

Return the length of the shortest path that visits every node. You may start and stop at any node, you may revisit nodes multiple times, and you may reuse edges.

### Example 1:
```
Input: graph = [[1,2,3],[0],[0],[0]]
Output: 4
Explanation: One possible path is [1,0,2,0,3].
```

### Constraints:
- `n == graph.length`
- `1 <= n <= 12`
- `0 <= graph[i].length < n`
- Graph is connected.

---

## Pattern Insight: Multi-Source BFS on State Space `(node, mask)`
- Since nodes and edges can be revisited, a simple BFS over nodes cannot detect shortest paths that require back-tracking.
- However, $N \le 12$, so the set of visited nodes can be represented as an integer `mask` with $N$ bits.
- State is defined as `(curr_node, mask)`:
  - There are $N \cdot 2^N$ total possible states ($12 \times 4096 \approx 49152$).
- **Multi-Source BFS Initialization:**
  - Start from every node $i$ simultaneously with step 0: `queue.push({i, 1 << i})`, `dist[i][1 << i] = 0`.
- **Termination:**
  - The first time we dequeue a state with `mask == (1 << n) - 1`, that distance is guaranteed to be optimal!

---

## Complexity
- **Time Complexity:** $O(N^2 \cdot 2^N)$ BFS over states.
- **Space Complexity:** $O(N \cdot 2^N)$ for distance table.
