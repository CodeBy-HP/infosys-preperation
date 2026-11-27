# 45. Dynamic Graph Path Queries with Parity / Alternating Colors (LeetCode 1129 + Parity BFS)

## Problem Statement

### Variant A (LeetCode 1129 — Shortest Path with Alternating Colors)
You are given an integer `n`, the number of nodes in a directed graph labeled `0` to `n - 1`, where each edge is colored **red** or **blue** (`redEdges`, `blueEdges`). Self-edges and parallel edges are allowed.
Return an array `answer` of length `n` where `answer[x]` is the length of the shortest path from node `0` to node `x` such that edge colors **alternate** along the path (or `-1` if unreachable).

### Variant B (Infosys Parity-State Graph Shortest Path)
Given an unweighted undirected/directed graph, find the shortest path of **even length** and **odd length** (parity `0` vs `1`) from source `0` to every node `x` (or query shortest path avoiding forbidden parity states).

---

## Examples

### Example 1 (Variant A — Alternating Colors)
- **Input:** `n = 3`, `redEdges = [[0, 1], [1, 2]]`, `blueEdges = []`
- **Output:** `[0, 1, -1]`
- **Explanation:** `0 -> 1` (red) works, `1 -> 2` requires another red edge which breaks alternation.

### Example 2 (Variant B — Shortest Odd/Even Path)
- **Input:** `n = 4`, edges `[(0, 1), (1, 2), (2, 0), (1, 3)]`, target = `3`, targetParity = `0` (even)
- **Output:** `4`
- **Explanation:** Direct `0 -> 1 -> 3` has length `2` (already even!).

---

## Constraints

- $1 \le n \le 100$ (up to $10^5$ in Parity BFS)
- $0 \le \text{edges.length} \le 10^5$

---

## Pattern Insight: State-Space BFS `(node, color/parity)`

Standard `dist[node]` is insufficient because arriving at `node` via a red edge (or odd step count) unlocks different future edges than arriving via a blue edge (or even step count)!
Expand visited/distance state to `dist[node][2]`:
- Initialize BFS queue with `{0, 0}` and `{0, 1}` (for Variant A) or `{0, 0}` (for Variant B parity `0`).
- Toggle state bit on every step: `nextState = state ^ 1`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **State-Expanded BFS (`(node, state)`)** | $O(V + E)$ | $O(V + E)$ |
