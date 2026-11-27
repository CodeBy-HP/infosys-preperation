# 07. Count Strings `{a, b, c}` with First Character `'a'` Condition (Infosys OA)

## Problem Statement

Given an integer `n`, count the number of strings of length `n` that can be formed using the characters `'a'`, `'b'`, and `'c'` under the following rules:
1. The **first character** of the string must be `'a'`.
2. **At most one `'b'`** and **at most two `'c'`s** are allowed in the entire string (classic restricted-count variant) **OR** no two `'c'`s are adjacent and `'b'` cannot immediately precede `'c'` (`"bc"` forbidden).

*(This problem file provides solutions for both the **Combinatorial Count-Restricted Variant** and the **Adjacency-Constrained First-Char-'a' DP Variant** seen in Infosys coding pools.)*

Return the count modulo $10^9 + 7$.

---

## Examples

### Example 1 (Count-Restricted Variant: first char `'a'`, at most 1 `'b'`, at most 2 `'c'`)
- **Input:** `n = 1`
- **Output:** `1` (`"a"`)

### Example 2 (Count-Restricted Variant)
- **Input:** `n = 3`
- **Output:** `9`
- **Explanation:** First char is fixed as `'a'`. For the remaining $n - 1 = 2$ positions, all combinations of `{a, b, c}` of length 2 are $3^2 = 9$, all of which have $\le 1$ `'b'` and $\le 2$ `'c'`s except `"bb"` (invalid, since at most 1 `'b'`), leaving `8` valid strings!
  - Valid remaining 2 chars: `"aa"`, `"ab"`, `"ac"`, `"ba"`, `"bc"`, `"ca"`, `"cb"`, `"cc"` $\implies 8$ ways.

### Example 3 (Adjacency Variant: starts with `'a'`, no `"cc"`, no `"bc"`)
- **Input:** `n = 3`
- **Output:** `7`
- **Explanation:** Length-3 strings starting with `'a'` avoiding `"cc"` and `"bc"`: `"aaa"`, `"aab"`, `"aac"`, `"aba"`, `"abb"`, `"aca"`, `"acb"`.

---

## Constraints

- $1 \le n \le 10^5$ (up to $10^9$ via closed-form formula for the count-restricted variant)
- Output modulo $10^9 + 7$.

---

## Pattern Insight

1. **Count-Restricted Variant (Fixed first char `'a'`):**
   Remaining $m = n - 1$ characters can use at most one `'b'` and at most two `'c'`s:
   - 0 `b`, 0 `c`: $1$
   - 0 `b`, 1 `c`: $m$
   - 0 `b`, 2 `c`: $\frac{m(m-1)}{2}$
   - 1 `b`, 0 `c`: $m$
   - 1 `b`, 1 `c`: $m(m-1)$
   - 1 `b`, 2 `c`: $\frac{m(m-1)(m-2)}{2}$
   Closed form: $O(1)$ time!
2. **Adjacency-Restricted Variant:**
   State DP `dp[last_char]` initialized at length 1 with `dp['a'] = 1, dp['b'] = 0, dp['c'] = 0`.

---

## Complexity Analysis

| Variant | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Count-Restricted Variant (Closed Form)** | $O(1)$ | $O(1)$ |
| **Count-Restricted Variant (DP)** | $O(N)$ | $O(1)$ |
| **Adjacency-Restricted Variant (DP)** | $O(N)$ | $O(1)$ |
