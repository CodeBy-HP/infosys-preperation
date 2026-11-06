# Number of Provinces (LeetCode 547)

## Problem Statement
There are `n` cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.

A **province** is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an `n x n` matrix `isConnected` where `isConnected[i][j] = 1` if the $i^{\text{th}}$ city and the $j^{\text{th}}$ city are directly connected, and `isConnected[i][j] = 0` otherwise.

Return the **total number of provinces**.

---

## Constraints
* `1 <= n <= 200`
* `n == isConnected.length`
* `n == isConnected[i].length`
* `isConnected[i][j]` is `1` or `0`.
* `isConnected[i][i] == 1` (a city is connected to itself).
* `isConnected[i][j] == isConnected[j][i]` (the connection graph is undirected).

---

## Examples

### Example 1
**Input:**
```text
isConnected = [
  [1, 1, 0],
  [1, 1, 0],
  [0, 0, 1]
]
```
**Output:**
```text
2
```
**Explanation:**
- City 0 and City 1 are connected to each other, forming Province 1.
- City 2 is isolated, forming Province 2.
Total provinces = 2.

```
(0) --- (1)       (2)
   Province 1     Province 2
```

---

### Example 2
**Input:**
```text
isConnected = [
  [1, 0, 0],
  [0, 1, 0],
  [0, 0, 1]
]
```
**Output:**
```text
3
```
**Explanation:**
None of the 3 cities are connected to each other. Each city forms its own independent province.

---

## Algorithmic Approaches

### Approach 1: Connected Components via DFS / BFS
The matrix `isConnected` is the adjacency matrix of an undirected graph with $V = n$ vertices.
1. Maintain a boolean array `visited` of size $n$, initialized to `false`.
2. Initialize `provinces = 0`.
3. Loop for `i = 0` to `n - 1`:
   - If `!visited[i]`:
     - Increment `provinces++`.
     - Launch `dfs(i)`:
       - Mark `visited[i] = true`.
       - For every city `j` from $0$ to $n-1$:
         - If `isConnected[i][j] == 1` and `!visited[j]`:
           - Recurse `dfs(j)`.
4. Return `provinces`.

### Approach 2: Disjoint Set Union (DSU)
1. Initialize a DSU with $n$ individual sets.
2. For every pair $(i, j)$ where $i < j$:
   - If `isConnected[i][j] == 1`:
     - `unionSets(i, j)`.
3. Count the number of unique set representatives (roots) among all nodes $0 \dots n-1$.

---

## Complexity Analysis
- **Time Complexity:** $O(N^2)$ — In DFS/BFS, inspecting the adjacency matrix requires scanning all $N \times N$ entries. In DSU, examining the upper triangle takes $O(N^2 \cdot \alpha(N))$.
- **Space Complexity:** $O(N)$ for the `visited` array and recursion call stack or DSU `parent` / `rank` arrays.
