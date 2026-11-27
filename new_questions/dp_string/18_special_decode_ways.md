# 18. Special Decode Ways (Decode Ways I & II — LeetCode 91 & 639)

## Problem Statement

A message containing letters from `A-Z` can be **encoded** into numbers using the mapping `'A' -> "1"`, `'B' -> "2"`, ..., `'Z' -> "26"`.

In addition to digits `'0'-'9'`, the encoded string `s` may also contain the wildcard character `'*'`, which can represent **any digit from `'1'` to `'9'`** (it does not represent `'0'`).

Given a string `s` containing digits and the `'*'` character, return the **number of ways** to decode it modulo $10^9 + 7$.

---

## Examples

### Example 1 (Standard Digits)
- **Input:** `s = "226"`
- **Output:** `3`
- **Explanation:** `"BZ"` (2 26), `"VF"` (22 6), or `"BBF"` (2 2 6).

### Example 2 (Wildcard `'*'`)
- **Input:** `s = "1*"`
- **Output:** `18`
- **Explanation:** `'*'` can be `'1'-'9'` (9 ways decoded separately as `"1" + *`, plus `"11"` through `"19"` decoded as two digits = 9 ways) $\implies 9 + 9 = 18$.

### Example 3
- **Input:** `s = "*"`
- **Output:** `9`

---

## Constraints

- $1 \le \text{s.length} \le 10^5$
- `s[i]` is a digit `'0'-'9'` or `'*'`.

---

## Pattern Insight: Weighted 1-Step & 2-Step Transitions

At index `i` (looking at `c1 = s[i-1]` and `c0 = s[i-2]`):
1. **Single-character ways (`ways1(c1)`):**
   - `'*'`: `9`
   - `'0'`: `0`
   - `'1'-'9'`: `1`
2. **Two-character ways (`ways2(c0, c1)`):**
   - `**`: `15` (`11-19` + `21-26`)
   - `*d`: `2` if `d <= '6'`, else `1`
   - `1*`: `9`, `2*`: `6`, `(other)*`: `0`
   - `dd`: `1` if `10 <= stoi(c0c1) <= 26`, else `0`

$$dp[i] = \big(ways1 \times dp[i-1] + ways2 \times dp[i-2]\big) \pmod{10^9 + 7}$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Rolling 2-Variable DP** | $O(N)$ | $O(1)$ |
| **1D Tabulation** | $O(N)$ | $O(N)$ |
