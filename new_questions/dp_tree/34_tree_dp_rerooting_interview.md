# 34. Tree DP (Interview Version) — Subtree Rerooting & Diameter/Distance Sum (LeetCode 834)

## Problem Statement

There is an undirected connected tree with `n` nodes labeled from `0` to `n - 1` and `n - 1` edges.

You are given the integer `n` and the array `edges` where `edges[i] = [a_i, b_i]` indicates an edge between nodes `a_i` and `b_i` in the tree.

Return an array `answer` of length `n` where `answer[i]` is the **sum of the distances** between the $i$-th node in the tree and all other nodes (the canonical Infosys/FAANG **Rerooting Tree DP** interview benchmark!).

*(Also includes **Diameter / Max Path Sum** helper patterns frequently combined in Infosys SP interviews.)*

---

## Examples

### Example 1
- **Input:** `n = 6`, `edges = [[0,1], [0,2], [2,3], [2,4], [2,5]]`
- **Output:** `[8, 12, 6, 10, 10, 10]`
- **Explanation:**
  - Node 0 has distances `1, 1, 2, 2, 2` $\to$ sum = `8`.
  - Node 2 has distances `1, 2, 1, 1, 1` $\to$ sum = `6`.

---

## Constraints

- $1 \le n \le 3 \times 10^4$
- `edges.length == n - 1`

---

## Pattern Insight: Two-Pass In-Out Rerooting DP

1. **DFS 1 (Bottom-Up Subtree Aggregation from Root `0`):**
   - Compute `sz[u]` = number of nodes in subtree of `u`.
   - Compute `ans[0]` = sum of depths from root `0`:
     `ans[u] += ans[v] + sz[v]`.
2. **DFS 2 (Top-Down Rerooting Shift from Parent `u` to Child `v`):**
   When moving the root across edge `(u, v)`:
   - `sz[v]` nodes inside `v`'s subtree become **1 unit closer**.
   - `(n - sz[v])` nodes outside `v`'s subtree become **1 unit farther**.
   $$\text{ans}[v] = \text{ans}[u] - sz[v] + (n - sz[v])$$

Total complexity: **$O(N)$ time**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Two-Pass Rerooting Tree DP** | $O(N)$ | $O(N)$ |
| **All-Pairs BFS from Each Node** | $O(N^2)$ | $O(N)$ |
