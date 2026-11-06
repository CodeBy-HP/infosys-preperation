# Cheapest Flights Within K Stops (LeetCode 787)

## Problem Overview
There are $N$ cities connected by some number of flights. You are given an array `flights` where `flights[i] = [from_i, to_i, price_i]`.
You are also given three integers `src`, `dst`, and `K`.
Return the **cheapest price from `src` to `dst` with at most $K$ stops**. If no such route exists, return `-1`.

---

## Why Standard Dijkstra Fails
In standard Dijkstra, the priority queue is ordered by **accumulated cost**.
A cheaper flight might arrive at city $u$ using $K+2$ stops, updating `dist[u]` and blocking an alternate path with cost $\$5$ higher that arrives with only $1$ stop!
The alternate path would have been able to reach `dst` within $K$ stops, but was pruned.

### The Invariant: Prioritize Stops Monotonically
Instead of sorting by cost, **traverse in order of stops**:
1. Use a standard FIFO queue storing `{stops, node, cost}`.
2. Because each edge transition increments `stops` by $1$, the queue naturally processes all 0-stop paths, then 1-stop paths, ..., up to $K+1$ edges ($K$ stops)!
3. Relaxation:
   $$\text{If } stops \le K \quad \text{and} \quad cost + price < dist[nextCity]:$$
   $$\text{dist}[nextCity] = cost + price, \quad \text{push } \{stops + 1, nextCity, dist[nextCity]\}$$
4. (Equivalently, Bellman-Ford run for exactly $K + 1$ rounds).

---

## Complexity Analysis
- **Time Complexity:** $O(K \times E)$
- **Space Complexity:** $O(V + E)$

