# Number of Operations to Make Network Connected (LeetCode 1319)

## Problem Statement
There are `n` computers numbered from `0` to `n - 1` connected by ethernet cables `connections` where `connections[i] = [a_i, b_i]` represents a connection between computers $a_i$ and $b_i$. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network `connections`. You can extract certain cables between already connected computers, and place them between any pair of disconnected computers to make them connected.

Return the **minimum number of times you need to do this** in order to make all the computers connected. If it is impossible, return `-1`.

---

## Constraints
* `1 <= n <= 10^5`
* `1 <= connections.length <= min(n * (n - 1) / 2, 10^5)`
* `connections[i].length == 2`
* `0 <= a_i, b_i < n`
* `a_i != b_i`
* There are no repeated connections.
* No computer is connected to more than one cable to the same computer.

---

## Examples

### Example 1
**Input:**
```text
n = 4, connections = [[0, 1], [0, 2], [1, 2]]
```
**Output:**
```text
1
```
**Explanation:**
- Computers 0, 1, 2 form a triangle with 3 cables (1 redundant cable).
- Computer 3 is isolated.
- Disconnect edge `[1, 2]` and connect `[1, 3]` (or `[2, 3]`). All 4 computers are now connected using 1 operation.

```
Initial:                     Rewired:
(0) --- (1)                  (0) --- (1) --- (3)
 \     /                      \
  \   /                        \
   (2)       (3) [isolated]     (2)
```

---

### Example 2
**Input:**
```text
n = 6, connections = [[0, 1], [0, 2], [0, 3], [1, 2], [1, 3]]
```
**Output:**
```text
2
```
**Explanation:**
There are 2 redundant cables and 3 connected components (Component 1: {0,1,2,3}, Component 2: {4}, Component 3: {5}). We need 2 cable rewirings to connect the 3 components.

---

### Example 3
**Input:**
```text
n = 6, connections = [[0, 1], [0, 2], [0, 3], [1, 2]]
```
**Output:**
```text
-1
```
**Explanation:**
To connect $n$ computers into a single spanning tree requires at least **$n - 1$ total cables**. Here we only have 4 cables ($4 < 6 - 1 = 5$), so it is mathematically impossible. Return `-1`.

---

## Algorithmic Approaches

### The Component & Redundant Edge Theorem
1. **Physical Feasibility Check:**
   To connect $N$ nodes into a single connected graph requires at least **$N - 1$ edges**.
   If `connections.length < n - 1`, return `-1` immediately!
2. **Component Reduction:**
   Suppose the graph currently has $C$ connected components.
   To connect $C$ disjoint components into a single component requires strictly **$C - 1$ bridges**.
3. Since we already guaranteed that total edges $\ge n - 1$, there are mathematically enough redundant cables in the network to supply the $C - 1$ bridges!
4. **Conclusion:** The answer is simply:
   $$\text{Operations} = C - 1 = (\text{Number of Connected Components}) - 1$$

### Implementation with Disjoint Set Union (DSU)
1. Initialize DSU with $n$ components (`components = n`).
2. For each edge `[u, v]`:
   - If `dsu.unionBySize(u, v)` succeeds (i.e. roots were different):
     - Decrement `components--`.
3. Return `components - 1`.

---

## Complexity Analysis
- **Time Complexity:** $O(E \cdot \alpha(V))$ where $V = n$ and $E = \text{connections.length}$.
- **Space Complexity:** $O(V)$ for DSU parent and size arrays.
