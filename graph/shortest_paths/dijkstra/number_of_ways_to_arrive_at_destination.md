# Number of Ways to Arrive at Destination (LeetCode 1976)

## Problem Overview
You are in a city that consists of $N$ intersections numbered from $0$ to $N - 1$ with bi-directional weighted roads.
You want to know the **number of ways you can travel from intersection $0$ to intersection $N - 1$ in the shortest amount of time**.
Return the number of ways modulo $10^9 + 7$.

---

## Dual State Dijkstra (Distance & Path Combinatorics)
We maintain two arrays alongside Dijkstra's min-priority queue:
- `dist[u]`: Minimum time to reach node $u$ (use 64-bit integer `long long` to prevent overflow).
- `ways[u]`: Number of distinct shortest paths from $0$ to $u$ modulo $10^9 + 7$.

### Relaxation Transitions
When examining adjacent node $v$ from $u$ with edge weight $w$:
1. **Strictly Shorter Path Found ($dist[u] + w < dist[v]$):**
   A new global shortest distance is established:
   $$dist[v] = dist[u] + w$$
   $$ways[v] = ways[u]$$
   Push $\{dist[v], v\}$ into the min-priority queue.
2. **Alternative Equal-Length Path Found ($dist[u] + w == dist[v]$):**
   Another route achieves the exact same optimal distance:
   $$ways[v] = (ways[v] + ways[u]) \pmod{10^9 + 7}$$
   (No need to push into priority queue again since $dist[v]$ did not decrease).

---

## Complexity Analysis
- **Time Complexity:** $O(E \log V)$
- **Space Complexity:** $O(V + E)$

