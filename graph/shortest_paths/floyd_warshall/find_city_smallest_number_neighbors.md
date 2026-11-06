# Find the City With the Smallest Number of Neighbors at a Threshold Distance (LeetCode 1334)

## Problem Statement
There are `n` cities numbered from `0` to `n - 1`. Given the array `edges` where `edges[i] = [from_i, to_i, weight_i]` represents a bidirectional and weighted edge between cities $\text{from}_i$ and $\text{to}_i$, and given the integer `distanceThreshold`.

Return the city with the **smallest number of cities** that are reachable through some path and whose distance is **at most** `distanceThreshold`.

If there are multiple such cities, return the city with the **greatest number** (largest city index).

Notice that the distance of a path connecting cities $i$ and $j$ is equal to the sum of the edges' weights along that path.

---

## Constraints
* `2 <= n <= 100`
* `1 <= edges.length <= n * (n - 1) / 2`
* `edges[i].length == 3`
* `0 <= from_i < to_i < n`
* `1 <= weight_i, distanceThreshold <= 10^4`
* All pairs $(\text{from}_i, \text{to}_i)$ are distinct.

---

## Examples

### Example 1
**Input:**
```text
n = 4, edges = [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]], 
distanceThreshold = 4
```
**Output:**
```text
3
```
**Explanation:**
The neighboring cities at a distanceThreshold = 4 for each city are:
- City 0 -> [City 1, City 2] (2 reachable cities: dist to 1 is 3, dist to 2 is 4)
- City 1 -> [City 0, City 2, City 3] (3 reachable cities: dist to 0 is 3, dist to 2 is 1, dist to 3 is 2)
- City 2 -> [City 0, City 1, City 3] (3 reachable cities: dist to 0 is 4, dist to 1 is 1, dist to 3 is 1)
- City 3 -> [City 1, City 2] (2 reachable cities: dist to 1 is 2, dist to 2 is 1)
Both City 0 and City 3 have 2 reachable cities. We return **City 3** as it has the larger index.

```
       (3)
 (0) ------- (1)
             / \
          (1)   (4)
           /     \
         (2) ---- (3)
             (1)
```

---

### Example 2
**Input:**
```text
n = 5, edges = [[0, 1, 2], [0, 4, 8], [1, 2, 3], [1, 4, 2], [2, 3, 1], [3, 4, 1]], 
distanceThreshold = 2
```
**Output:**
```text
0
```
**Explanation:**
- City 0 -> [City 1] (1 reachable city)
- City 1 -> [City 0, City 4] (2 reachable cities)
- City 2 -> [City 3] (1 reachable city)
- City 3 -> [City 2, City 4] (2 reachable cities)
- City 4 -> [City 1, City 3] (2 reachable cities)
Cities 0 and 2 both reach only 1 city. City 0 has index 0, City 2 has index 2... wait, City 2 reaches 3 (dist 1) and 4 (dist 2)! So City 2 reaches 2 cities. City 0 is the unique minimum.

---

## Algorithmic Approaches

### Approach 1: Floyd-Warshall All-Pairs Shortest Path (APSP)
Since $N \le 100$, an $O(N^3)$ All-Pairs Shortest Path is fast and concise:
1. Initialize `dist[n][n]` with $\infty$, and set `dist[i][i] = 0`.
2. Populate direct edges from `edges`: `dist[u][v] = dist[v][u] = w`.
3. Run Floyd-Warshall 3-nested loop with intermediate node $k$:
   ```cpp
   for (int k = 0; k < n; ++k)
       for (int i = 0; i < n; ++i)
           for (int j = 0; j < n; ++j)
               if (dist[i][k] != INF && dist[k][j] != INF)
                   dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
   ```
4. For each city `i` from $0$ to $n - 1$:
   - Count how many cities `j != i` have `dist[i][j] <= distanceThreshold`.
   - Track `minReachable` and `bestCity`. Update if `count <= minReachable` (with $\le$ naturally selecting the largest city index).

### Approach 2: $N$ Dijkstra Invocations
Run Dijkstra from each city $i$: $O(N \cdot E \log N)$.

---

## Complexity Analysis
- **Time Complexity:** $O(N^3)$ with Floyd-Warshall, which takes $\approx 10^6$ operations ($< 0.01$s for $N = 100$).
- **Space Complexity:** $O(N^2)$ for the distance matrix.
