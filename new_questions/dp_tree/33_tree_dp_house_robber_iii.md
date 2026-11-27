# 33. Tree DP (OA Version) — House Robber III & General Tree Independent Set

## Problem Statement

### Binary Tree Version (LeetCode 337 — House Robber III)
The thief has found himself a new place for his thievery again. There is only one entrance to this area, called `root`. Besides the `root`, each house has one and only one parent house. Two directly-linked houses cannot be robbed on the same night.

Return the **maximum amount of money** the thief can rob without alerting the police.

### General N-ary Tree OA Version (Infosys Tree DP)
Given an undirected tree of `n` nodes (numbered `0..n-1`) with positive/integer weights `val[0..n-1]`, select a subset of nodes (an **independent set**) such that no two adjacent nodes connected by an edge are both selected, maximizing the total weight.

---

## Examples

### Example 1
- **Input:** `root = [3, 2, 3, null, 3, null, 1]`
- **Output:** `7`
- **Explanation:** Maximum amount = `3 + 3 + 1 = 7` (root + leaf children).

### Example 2 (N-ary Tree)
- **Input:** `n = 4`, edges `[(0, 1), (0, 2), (0, 3)]`, `val = [5, 3, 4, 2]`
- **Output:** `9`
- **Explanation:** Picking leaves `1, 2, 3` gives $3 + 4 + 2 = 9 > 5$.

---

## Constraints

- $1 \le n \le 10^4$
- $0 \le \text{Node.val} \le 10^4$

---

## Pattern Insight: Bottom-Up Post-Order `{rob, skip}` Pair DP

For every node `u`, return a pair `{take_u, skip_u}`:
- `take_u = val[u] + sum(skip_v for all children v)`
- `skip_u = sum(max(take_v, skip_v) for all children v)`

Runs in a single **$O(N)$** DFS pass!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Post-Order Tree DP (`{take, skip}`)** | $O(N)$ | $O(H)$ recursion stack |
