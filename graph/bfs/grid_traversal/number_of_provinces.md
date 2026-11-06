# Number of Provinces (LeetCode 547)

## Problem Overview
There are $N$ cities. Some of them are connected, while some are not. If city `a` is connected directly with city `b`, and city `b` is connected directly with city `c`, then city `a` is connected indirectly with city `c`.
A **province** is a group of directly or indirectly connected cities and no other cities outside of the group.
Given an $N \times N$ matrix `isConnected` where `isConnected[i][j] = 1` if the $i$-th city and the $j$-th city are directly connected, return the total number of **provinces**.

---

## Graph Model & Traversal
The matrix `isConnected` is an adjacency matrix of an undirected graph with $N$ vertices.
A province is simply a **connected component**!
1. Maintain a boolean array `visited` of size $N$.
2. For each city $i \in [0, N-1]$:
   - If city $i$ has not been visited, we discovered a new province (`provinces++`).
   - Run DFS/BFS from city $i$ to visit all reachable cities in this province.

---

## Complexity Analysis
- **Time Complexity:** $O(N^2)$ because we inspect all entries of the $N \times N$ adjacency matrix.
- **Space Complexity:** $O(N)$ for the `visited` array and recursive stack depth.

