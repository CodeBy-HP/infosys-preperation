# Number of Distinct Islands (LeetCode 694)

## Problem Overview
Given a boolean 2D matrix `grid` of size $N \times M$. You have to find the number of **distinct islands** where a group of connected `1`s (4-directionally) forms an island.
Two islands are considered to be distinct if and only if one island is **not equal to another by translation**. (Rotation and reflection are not considered the same).

---

## Canonical Relative Shape Signature
To check if two islands have identical shape under translation:
1. When an unvisited land cell $(r_0, c_0)$ is encountered, designate $(r_0, c_0)$ as the **base anchor**.
2. Run DFS or BFS to visit the entire island.
3. For each visited cell $(r, c)$ in this island, record its **relative offset vector**:
   $$\text{offset} = (r - r_0, \; c - c_0)$$
4. Sort or record offsets in a canonical order (e.g., standard DFS traversal path).
5. Insert the serialized shape vector into a `std::set<vector<pair<int, int>>>`.
6. The size of the set is the exact number of distinct island shapes!

---

## Complexity Analysis
- **Time Complexity:** $O(N \times M \log(N \times M))$
- **Space Complexity:** $O(N \times M)$

