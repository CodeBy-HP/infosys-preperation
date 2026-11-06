# Floyd-Warshall Algorithm (All-Pairs Shortest Path)

## Problem Statement
The problem is to find the **shortest distances between every pair of vertices** in a directed/undirected weighted graph with `V` vertices.

The graph is given as an adjacency matrix `matrix[V][V]`, where:
- `matrix[i][j]` is the weight of the directed edge from $i$ to $j$.
- If there is no edge from $i$ to $j$, `matrix[i][j] = -1`.
- `matrix[i][i] = 0`.

Update `matrix` in-place such that `matrix[i][j]` stores the shortest distance from $i$ to $j$. If no path exists, keep `matrix[i][j] = -1`.
Also detect if the graph contains any **negative weight cycle**.

---

## Constraints
* `1 <= V <= 100` (or `400` in standard problem sets)
* `-1000 <= matrix[i][j] <= 1000` (can be negative!)
* Matrix dimensions: `V x V`.

---

## Examples

### Example 1
**Input:**
```text
matrix = [
  [0,   2, -1, -1],
  [1,   0,  3, -1],
  [-1, -1,  0, -1],
  [3,   5,  4,  0]
]
```
**Output:**
```text
[
  [0, 2, 5, -1],
  [1, 0, 3, -1],
  [-1, -1, 0, -1],
  [3, 5, 4, 0]
]
```
**Explanation:**
- From node 0 to 2: Path `0 -> 1 -> 2` costs $2 + 3 = 5$.
- Node 3 can reach 0, 1, and 2.
- No node can reach 3 from {0, 1, 2}.

```
(0) <======(1)======> (1)
  \                    |
   \--- (path = 5) ---> (2)
```

---

### Example 2 (Negative Cycle Detection)
**Input:**
```text
matrix = [
  [ 0,  1, -1],
  [-1,  0, -1],
  [-1, -2,  0]  (cycle with negative sum)
]
```
If after running Floyd-Warshall, `matrix[i][i] < 0` for any vertex $i$, then vertex $i$ is part of a **negative weight cycle**!

---

## Algorithmic Approaches

### The Dynamic Programming Intermediate Node Paradigm
Let $D^k[i][j]$ be the shortest distance from vertex $i$ to vertex $j$ using only intermediate vertices from the subset $\{0, 1, \dots, k\}$.

$$\text{Transition: } D^k[i][j] = \min(D^{k-1}[i][j], \; D^{k-1}[i][k] + D^{k-1}[k][j])$$

### Step-by-Step Algorithm
1. Replace `-1` with $\infty$ (except on diagonal `matrix[i][i] = 0`).
2. Run three nested loops where the **outer loop $k$ must be the intermediate vertex**:
   ```cpp
   for (int k = 0; k < V; ++k) {
       for (int i = 0; i < V; ++i) {
           for (int j = 0; j < V; ++j) {
               if (matrix[i][k] != INF && matrix[k][j] != INF) {
                   matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
               }
           }
       }
   }
   ```
3. **Negative Cycle Check:**
   - Scan diagonal: If `matrix[i][i] < 0` for any $i$, report a negative cycle.
4. Convert remaining $\infty$ entries back to `-1`.

---

## Complexity Analysis
- **Time Complexity:** $O(V^3)$ — Strictly 3 nested loops of length $V$.
- **Space Complexity:** $O(1)$ auxiliary memory when updating the adjacency matrix in-place ($O(V^2)$ for the matrix itself).
