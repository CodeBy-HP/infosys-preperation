# Network Delay Time (LeetCode 743)

## Problem Statement
You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (u_i, v_i, w_i)`, where $u_i$ is the source node, $v_i$ is the target node, and $w_i$ is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return the **minimum time** it takes for all the `n` nodes to receive the signal. If it is impossible for all the `n` nodes to receive the signal, return `-1`.

---

## Constraints
* `1 <= k <= n <= 100`
* `1 <= times.length <= 6000`
* `times[i].length == 3`
* `1 <= u_i, v_i <= n`
* `u_i != v_i`
* `0 <= w_i <= 100`
* All pairs $(u_i, v_i)$ are unique.

---

## Examples

### Example 1
**Input:**
```text
times = [
  [2, 1, 1],
  [2, 3, 1],
  [3, 4, 1]
], 
n = 4, k = 2
```
**Output:**
```text
2
```
**Explanation:**
- Signal sends from node 2 at $t = 0$.
- At $t = 1$, node 1 receives signal ($2 \to 1$).
- At $t = 1$, node 3 receives signal ($2 \to 3$).
- At $t = 2$, node 4 receives signal from node 3 ($3 \to 4$).
All nodes have received the signal by $t = 2$.

```
     (1)
    ^
(1)/
 (2) -----(1)-----> (3) -----(1)-----> (4)
(k=2, t=0)         (t=1)              (t=2)
```

---

### Example 2
**Input:**
```text
times = [[1, 2, 1]], n = 2, k = 1
```
**Output:**
```text
1
```

---

### Example 3
**Input:**
```text
times = [[1, 2, 1]], n = 2, k = 2
```
**Output:**
```text
-1
```
**Explanation:**
Sending from node 2: node 1 is unreachable. Return `-1`.

---

## Algorithmic Approaches

### Dijkstra's Single-Source Shortest Path
The minimum time for all nodes to receive the signal is the **maximum shortest path distance** from source node $k$ to all nodes:
$$\text{totalTime} = \max_{1 \le i \le n} \text{dist}[i]$$

1. Build adjacency list: `adj[u]` contains `{v, w}`.
2. Initialize `dist` array of size $n + 1$ with $\infty$, and set `dist[k] = 0`.
3. Min-Priority Queue stores `{time, u}`. Push `{0, k}`.
4. While `pq` is not empty:
   - Extract `{d, u}`.
   - If `d > dist[u]`, continue.
   - For each neighbor `(v, w)` of `u`:
     - If `dist[u] + w < dist[v]`:
       - `dist[v] = dist[u] + w`.
       - Push `{dist[v], v}` into `pq`.
5. Find `maxTime = max(dist[1...n])`.
6. If `maxTime == \infty` (any node unreachable), return `-1`; otherwise return `maxTime`.

---

## Complexity Analysis
- **Time Complexity:** $O(E \log V)$ where $V = n$ and $E = \text{times.length}$.
- **Space Complexity:** $O(V + E)$ for adjacency list and $O(V)$ for distance array and priority queue.
