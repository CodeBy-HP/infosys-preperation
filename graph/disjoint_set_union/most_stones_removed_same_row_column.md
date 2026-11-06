# Most Stones Removed with Same Row or Column (LeetCode 947)

## Problem Overview
On a 2D plane, we place $N$ stones at integer coordinates `stones[i] = [x_i, y_i]`.
A stone can be removed if it shares **either the same row or the same column** with another stone that has not been removed.
Given the array `stones`, return the **largest possible number of stones that can be removed**.

---

## Connected Component Theorem & Coordinate Union
If a cluster of $K$ stones forms a connected component (sharing rows or columns transitively), we can always build a spanning tree of stones and remove leaves one-by-one until **exactly 1 stone remains**:
$$\text{Removable Stones in Component} = K - 1$$
Summing across all $C$ connected components:
$$\text{Total Removed} = \sum (K_i - 1) = \sum K_i - \sum 1 = N - C$$

### Bipartite Row-Column Coordinate DSU
Instead of comparing all $O(N^2)$ stone pairs:
1. Treat each row index $r$ and column index $c$ as vertices in a bipartite DSU graph.
2. Offset the column index $c$ by a large constant (e.g., $c' = c + 10001$) to prevent collision with row indices.
3. For each stone at $(r, c)$:
   $$\text{dsu.unionNodes}(r, \; c + 10001)$$
4. Track all active coordinates in an `unordered_set`.
5. The number of components $C$ is the number of unique roots among the active coordinates.
6. The answer is $N - C$.

---

## Complexity Analysis
- **Time Complexity:** $O(N \cdot \alpha(V))$
- **Space Complexity:** $O(N)$

