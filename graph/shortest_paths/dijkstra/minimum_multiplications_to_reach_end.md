# Minimum Multiplications to Reach End (GFG)

## Problem Statement
Given an integer array `arr` of positive integers and two integers `start` and `end`, find the **minimum number of multiplications** needed to transform `start` into `end`.

In each step, you can multiply the current number by any integer from `arr` and take the modulo $100000$ ($10^5$):
$$\text{next} = (\text{curr} \times \text{arr}[i]) \pmod{100000}$$

If it is impossible to reach `end`, return `-1`.

---

## Constraints
* `1 <= arr.length <= 10^4`
* `1 <= arr[i] <= 10^4`
* `0 <= start, end < 100000`
* Modulo arithmetic is strictly over $MOD = 100000$.

---

## Examples

### Example 1
**Input:**
```text
arr = [2, 5, 7]
start = 3, end = 30
```
**Output:**
```text
2
```
**Explanation:**
- Step 1: $3 \times 2 = 6$ (or $3 \times 5 = 15$, $3 \times 7 = 21$)
- Step 2: From 6, multiply by 5: $(6 \times 5) \pmod{100000} = 30$.
Minimum multiplications = 2.

---

### Example 2
**Input:**
```text
arr = [3, 4, 65]
start = 7, end = 66175
```
**Output:**
```text
4
```
**Explanation:**
$7 \xrightarrow{\times 3} 21 \xrightarrow{\times 3} 63 \xrightarrow{\times 65} 4095 \xrightarrow{\times 65} 266175 \pmod{100000} = 66175$.
Total steps = 4.

---

## Algorithmic Approaches

### State-Space BFS on Modulo Graph
Notice that all intermediate values are strictly bounded within the range:
$$[0, 99999] \implies \text{Total States } V = 100000$$

Every multiplication operation represents an edge of **unit weight $1$**:
- Because edge weights are uniformly $1$, standard **BFS with a FIFO queue** is strictly optimal ($O(V + E)$) without requiring Dijkstra's min-heap!
1. Initialize `dist` array of size $100000$ filled with $\infty$, and set `dist[start] = 0`.
2. Push `{start, 0}` (`{node, steps}`) into a queue.
3. While queue is not empty:
   - Pop `{node, steps}`.
   - If `node == end`, return `steps`.
   - For each multiplier `x` in `arr`:
     - `next = (node * x) % 100000`.
     - If `steps + 1 < dist[next]`:
       - `dist[next] = steps + 1`.
       - Push `{next, steps + 1}` into queue.
4. If queue is exhausted, return `-1`.

---

## Complexity Analysis
- **Time Complexity:** $O(100000 \times N)$ — There are at most $10^5$ reachable numbers, each having at most $N$ outgoing transitions.
- **Space Complexity:** $O(100000)$ — Distance array of size $10^5$ and queue holding at most $10^5$ elements.
