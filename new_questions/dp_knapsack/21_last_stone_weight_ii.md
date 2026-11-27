# 21. Last Stone Weight II (LeetCode 1049)

## Problem Statement

You are given an array of integers `stones` where `stones[i]` is the weight of the $i$-th stone.

We are playing a game with the stones. On each turn, we choose any two stones and smash them together. Suppose the stones have weights `x` and `y` with $x \le y$. The result of this smash is:
- If $x == y$, both stones are destroyed, and
- If $x \ne y$, the stone of weight $x$ is destroyed, and the stone of weight $y$ has new weight $y - x$.

At the end of the game, there is **at most one** stone left.
Return the **smallest possible weight** of the left stone. If there are no stones left, return `0`.

---

## Examples

### Example 1
- **Input:** `stones = [2, 7, 4, 1, 8, 1]`
- **Output:** `1`
- **Explanation:** We can partition stones into `{2, 4, 1, 1}` (sum = 8) and `{7, 8}` (sum = 15)? Wait: `{2, 7, 1}` (10) vs `{4, 8, 1}` (13) $\to 3$; `{1, 8, 2}` (11) vs `{7, 4, 1}` (12) $\implies |11 - 12| = 1$.

### Example 2
- **Input:** `stones = [31, 26, 33, 21, 40]`
- **Output:** `5`

---

## Constraints

- $1 \le \text{stones.length} \le 30$
- $1 \le \text{stones}[i] \le 100$

---

## Pattern Insight: 0/1 Knapsack Subset Partition Min-Difference

Every stone ends up contributing either `+stones[i]` or `-stones[i]` to the final remaining stone!
Partitioning into two groups $S_1$ and $S_2$:
$$\text{Remaining Weight} = |S_1 - S_2| = |\text{TotalSum} - 2 S_1|$$
Find the largest subset sum $S_1 \le \lfloor \text{TotalSum} / 2 \rfloor$ using boolean 0/1 Knapsack DP (`dp[s]`).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **1D Boolean 0/1 Knapsack DP** | $O(N \cdot \text{TotalSum})$ | $O(\text{TotalSum})$ |
| **Bitset Optimization** | $O(N \cdot \text{TotalSum} / 64)$ | $O(\text{TotalSum})$ |
