# Find City With Smallest Number of Neighbors at a Threshold Distance (LeetCode 1334)

## Problem Overview
There are $N$ cities numbered from $0$ to $N - 1$. Given the array `edges` where `edges[i] = [from_i, to_i, weight_i]`, and an integer `distanceThreshold`.
Return the **city with the smallest number of cities that are reachable** through some path and whose distance is at most `distanceThreshold`.
If there are multiple such cities, return the **city with the greatest numerical index**.

---

## Floyd-Warshall Formulation
Because $N \le 100$, computing All-Pairs Shortest Path (APSP) using **Floyd-Warshall** takes $O(N^3)$ time ($10^6$ operations), running in under $5\text{ ms}$:
1. Initialize an $N \times N$ matrix `dist` with $\infty$, setting `dist[i][i] = 0`.
2. Populate direct edge weights from `edges`.
3. Run the triple nested loop over intermediate pivot vertex $k$:
   $$\text{dist}[i][j] = \min(\text{dist}[i][j], \; \text{dist}[i][k] + \text{dist}[k][j])$$
4. For each city $i$:
   - Count vertices $j \ne i$ where `dist[i][j] <= distanceThreshold`.
5. Return city with minimum count (breaking ties by largest index $i$).

---

## Complexity Analysis
- **Time Complexity:** $O(N^3)$ via Floyd-Warshall (or $O(N \cdot E \log N)$ via $N$ Dijkstra runs).
- **Space Complexity:** $O(N^2)$ for the distance matrix.

