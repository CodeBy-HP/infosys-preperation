# Network Delay Time (LeetCode 743)

## Problem Overview
You are given a network of $N$ nodes, labeled from $1$ to $N$. You are also given `times`, a list of travel times as directed edges `times[i] = (u_i, v_i, w_i)`.
We will send a signal from a given node $k$.
Return the **minimum time it takes for all the $N$ nodes to receive the signal**.
If it is impossible for all the $N$ nodes to receive the signal, return `-1`.

---

## Max-Distance Formulation via Dijkstra
The signal propagates concurrently across all network paths.
Thus, every node receives the signal at its **shortest path arrival time**:
1. Run Dijkstra's algorithm from source node $k$ on the directed weighted graph.
2. Maintain array `dist[1 ... N]` initialized to $\infty$.
3. The moment the last node receives the signal is the **maximum of all shortest path distances**:
   $$\text{Total Time} = \max_{1 \le i \le N} dist[i]$$
4. If any node has `dist[i] == \infty`, that node is unreachable $\implies$ return `-1`.

---

## Complexity Analysis
- **Time Complexity:** $O(E \log V)$
- **Space Complexity:** $O(V + E)$

