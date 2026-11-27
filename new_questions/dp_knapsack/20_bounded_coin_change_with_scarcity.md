# 20. Bounded Coin Change with Scarcity & Min Denomination Gap (Infosys SP OA PYQ)

## Problem Statement

You are given `n` distinct coin denominations in an array `coins`, an integer array `cnt` where `cnt[i]` denotes the **maximum number of coins** of denomination `coins[i]` available (scarcity limit), a target sum `amount`, and an integer `D`.

Find the **number of distinct combinations** of coins that sum up to `amount` such that:
1. You use at most `cnt[i]` coins of denomination `coins[i]`.
2. **Minimum Denomination Gap `D`:** For any two *distinct* denominations `c1` and `c2` used in the combination, their absolute difference must be at least `D`:
   $$|c_1 - c_2| \ge D$$

Return the total number of valid combinations modulo $10^9 + 7$.

---

## Examples

### Example 1
- **Input:** `coins = [1, 2, 4]`, `cnt = [2, 2, 2]`, `amount = 5`, `D = 2`
- **Output:** `2`
- **Explanation:**
  - `1 + 4 = 5` ($|4 - 1| = 3 \ge 2$) $\checkmark$
  - `1 + 2 + 2 = 5` (INVALID because $|2 - 1| = 1 < D$)
  - `1 + 1 + 2 + ...` invalid
  - Suppose `amount = 4`: `4` (1 way) and `2 + 2` (1 way) $\implies 2$. With `amount = 5`, only `1 + 4` uses distinct coins with gap $\ge 2 \implies 1$ way! Wait: `1` (cnt 2), `2` (cnt 2), `4` (cnt 2): can only form `5` via `1+4` (valid) or `1+2+2` (invalid since $|2-1| < 2$). So output = `1`.

---

## Constraints

- $1 \le n \le 100$
- $1 \le \text{coins}[i], cnt[i] \le 1000$
- $0 \le \text{amount} \le 1000$
- $0 \le D \le 1000$

---

## Pattern Insight: Sorted Prefix-DP with Gap Binary Search

1. Pair `(coins[i], cnt[i])` and **sort ascending by `coins[i]`**.
2. Define `dp[i][s]` = number of valid combinations summing to `s` whose **largest chosen coin denomination** is `coins[i]`.
3. Maintain prefix sums `pref[i][s] = sum_{p <= i} dp[p][s]`.
4. For coin `i`, find the largest earlier index `j < i` such that `coins[j] <= coins[i] - D`.
5. Choose multiplicity $c \in [1, cnt[i]]$ (paying `val = c * coins[i]`):
   $$\text{dp}[i][s] += (s == val ? 1 : \text{pref}[j][s - val])$$
   *(If no valid `j` exists, we can only form `s == c * coins[i]` using coin `i` alone.)*

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sorted Prefix-Sum Bounded DP** | $O(N \cdot \text{amount} \cdot \overline{cnt})$ | $O(N \cdot \text{amount})$ |
| **Sliding Prefix-Sum Optimization per Modulo Class** | $O(N \cdot \text{amount})$ | $O(N \cdot \text{amount})$ |
