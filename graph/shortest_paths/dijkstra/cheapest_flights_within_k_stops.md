# Cheapest Flights Within K Stops (LeetCode 787)

## Problem Statement
There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [from_i, to_i, price_i]` indicates that there is a flight from city $\text{from}_i$ to city $\text{to}_i$ with cost $\text{price}_i$.

You are also given three integers `src`, `dst`, and `k`, return the **cheapest price** from `src` to `dst` with **at most `k` stops**. If there is no such route, return `-1`.

*Note:* A path with $k$ stops contains at most $k + 1$ edges.

---

## Constraints
* `1 <= n <= 100`
* `0 <= flights.length <= (n * (n - 1) / 2)`
* `flights[i].length == 3`
* `0 <= from_i, to_i < n`
* `from_i != to_i`
* `1 <= price_i <= 10^4`
* There will not be any multiple flights between two directed cities.
* `0 <= src, dst, k < n`
* `src != dst`

---

## Examples

### Example 1
**Input:**
```text
n = 4, flights = [[0, 1, 100], [1, 2, 100], [2, 0, 100], [1, 3, 600], [2, 3, 200]], 
src = 0, dst = 3, k = 1
```
**Output:**
```text
700
```
**Explanation:**
- Path `0 -> 1 -> 3` takes 1 stop (city 1) and costs $100 + 600 = 700$.
- Path `0 -> 1 -> 2 -> 3` costs $100 + 100 + 200 = 400$, but it takes 2 stops (cities 1 and 2), which exceeds $k = 1$.
The cheapest path with at most 1 stop costs 700.

```
       (100)           (600)
 (0) ---------> (1) ------------> (3)  [1 stop, cost = 700]
                 |                 ^
               (100)             (200)
                 v                 |
                (2) ---------------+   [2 stops, cost = 400 (exceeds k=1!)]
```

---

### Example 2
**Input:**
```text
n = 3, flights = [[0, 1, 100], [1, 2, 100], [0, 2, 500]], 
src = 0, dst = 2, k = 1
```
**Output:**
```text
200
```
**Explanation:**
Path `0 -> 1 -> 2` takes 1 stop and costs $100 + 100 = 200$.

---

### Example 3
**Input:**
```text
n = 3, flights = [[0, 1, 100], [1, 2, 100], [0, 2, 500]], 
src = 0, dst = 2, k = 0
```
**Output:**
```text
500
```
**Explanation:**
With $k = 0$ stops, we must fly directly: `0 -> 2` costing 500.

---

## Algorithmic Approaches

### Why Plain Dijkstra on Cost Fails
Standard Dijkstra prioritizes by **cost**. A path with lower cost but more stops could be extracted first, exhausting the stop budget and erroneously pruning a slightly more expensive path with fewer stops that could reach the destination within $k$ stops!

### Approach 1: BFS Ordered Strictly by Stops (Queue)
Because the constraint on stops increases monotonically by $1$ per hop:
- Queue stores `{stops, node, cost}`.
- Sort priority is naturally ordered by **stops**!
- Maintain a `dist` array of size $n$, initialized to $\infty$.
- While queue is not empty:
  - Pop `{stops, u, cost}`.
  - If `stops > k`, prune (cannot proceed further).
  - For each outgoing flight `(u -> v, price)`:
    - If `cost + price < dist[v]`:
      - `dist[v] = cost + price`.
      - Push `{stops + 1, v, dist[v]}`.
- Return `dist[dst] == \infty ? -1 : dist[dst]`.

### Approach 2: Bellman-Ford Running Exactly $k + 1$ Iterations
Run $k + 1$ relaxations using a temporary distance copy to ensure distances only propagate across 1 edge per iteration.

---

## Complexity Analysis
- **Time Complexity:** $O(K \cdot E)$ where $E = \text{flights.length}$.
- **Space Complexity:** $O(V + E)$ for adjacency list and $O(V)$ for distance array and queue.
