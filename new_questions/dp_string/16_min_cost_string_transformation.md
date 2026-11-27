# 16. Minimum Cost String Transformation (Edit Distance & Custom Cost Variant)

## Problem Statement

Given two strings `word1` and `word2`, return the **minimum cost** (or minimum number of operations) required to convert `word1` to `word2`.

You have the following three operations permitted on a word:
1. **Insert** a character (cost = `insCost`, default `1`)
2. **Delete** a character (cost = `delCost`, default `1`)
3. **Replace** a character (cost = `repCost`, default `1`)

*(LeetCode 72 uses uniform cost `1`. Infosys OA variants assign custom costs `insCost`, `delCost`, `repCost`.)*

---

## Examples

### Example 1 (Uniform Cost = 1)
- **Input:** `word1 = "horse"`, `word2 = "ros"`
- **Output:** `3`
- **Explanation:** `horse -> rorse -> rose -> ros` (1 replace, 2 deletes).

### Example 2 (Custom Costs)
- **Input:** `word1 = "abc"`, `word2 = "adc"`, `insCost = 5`, `delCost = 5`, `repCost = 2`
- **Output:** `2`
- **Explanation:** Replace `'b'` with `'d'` for cost `2` instead of deleting `'b'` and inserting `'d'` (`5 + 5 = 10`).

---

## Constraints

- $0 \le \text{word1.length}, \text{word2.length} \le 500$
- `word1` and `word2` consist of lowercase English letters.

---

## Pattern Insight: Weighted 2D String DP

Let `dp[i][j]` be the minimum cost to transform `word1[0..i-1]` into `word2[0..j-1]`:
- If `word1[i-1] == word2[j-1]`: `dp[i][j] = dp[i-1][j-1]`.
- Else:
  $$\text{dp}[i][j] = \min\big(dp[i-1][j] + \text{delCost}, \ dp[i][j-1] + \text{insCost}, \ dp[i-1][j-1] + \text{repCost}\big)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Space-Optimized 1D DP** | $O(M \cdot N)$ | $O(\min(M, N))$ |
| **2D Tabular DP** | $O(M \cdot N)$ | $O(M \cdot N)$ |
