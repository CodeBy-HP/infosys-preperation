# Most Stones Removed with Same Row or Column (LeetCode 947)

## Problem Statement
On a 2D plane, we place `n` stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be **removed** if it shares **either the same row or the same column** as another stone that has not been removed.

Given an array `stones` of length `n` where `stones[i] = [r_i, c_i]` represents the location of the $i^{\text{th}}$ stone, return the **largest possible number of stones that can be removed**.

---

## Constraints
* `1 <= stones.length <= 1000`
* `0 <= r_i, c_i <= 10^4`
* No two stones are placed on the exact same coordinate.

---

## Examples

### Example 1
**Input:**
```text
stones = [[0, 0], [0, 1], [1, 0], [1, 2], [2, 1], [2, 2]]
```
**Output:**
```text
5
```
**Explanation:**
- Remove stone `[2, 2]` since it shares row 2 with `[2, 1]`.
- Remove stone `[2, 1]` since it shares col 1 with `[0, 1]`.
- Remove stone `[1, 2]` since it shares row 1 with `[1, 0]`.
- Remove stone `[1, 0]` since it shares col 0 with `[0, 0]`.
- Remove stone `[0, 1]` since it shares row 0 with `[0, 0]`.
Stone `[0, 0]` cannot be removed because no other stone remains.
Total removed = 5 (out of 6).

```
(0,0) --- (0,1)
  |
(1,0) ----------- (1,2)
            |       |
          (2,1) - (2,2)
All 6 stones form 1 connected component -> 6 - 1 = 5 removals!
```

---

### Example 2
**Input:**
```text
stones = [[0, 0], [0, 2], [1, 1], [2, 0], [2, 2]]
```
**Output:**
```text
3
```
**Explanation:**
- Stones `[0,0]`, `[0,2]`, `[2,0]`, `[2,2]` form Component 1 of size 4 $\longrightarrow$ 3 stones can be removed, leaving 1.
- Stone `[1,1]` is isolated in Component 2 of size 1 $\longrightarrow$ 0 stones can be removed.
Total removed = $3 + 0 = 3$.

---

## Algorithmic Approaches

### The Connected Component Removal Theorem
Consider a connected component of stones where two stones are connected if they share a row or column:
1. In any connected component of size $S$, we can always greedily remove stones one by one down a spanning tree, leaving **exactly 1 anchor stone**!
2. Therefore, if the entire set of $N$ stones forms $C$ connected components:
   $$\text{Max Stones Removed} = N - C = \text{Total Stones} - \text{Number of Connected Components}$$

### Row-Column Bipartite Projection via DSU
To avoid comparing all $O(N^2)$ pairs of stones:
- Treat every row $r$ and every column $c$ as nodes in a graph.
- To prevent row index $r$ from colliding with column index $c$, shift columns by an offset:
  $$\text{colNode} = c + 10001$$
- For each stone `[r, c]`:
  - Union row $r$ with column $(c + 10001)$:
    `dsu.unionBySize(r, c + 10001)`.
- The number of unique set representatives among all stone nodes equals $C$.
- Return $N - C$.

---

## Complexity Analysis
- **Time Complexity:** $O(N \cdot \alpha(\max(R, C)))$ — Inserting $N$ stones into the DSU takes near-linear time ($< 1$ ms for $N = 1000$).
- **Space Complexity:** $O(\max R + \max C)$ for DSU parent and size maps/arrays.
