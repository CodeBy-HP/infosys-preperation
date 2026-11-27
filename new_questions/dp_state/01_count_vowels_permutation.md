# 01. Count Vowels Permutation (Infosys OA Variant)

## Problem Statement

Given an integer `n`, return how many strings of length `n` can be formed under the following rules:
- Each character is a lowercase vowel (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`).
- Each vowel `'a'` may only be followed by an `'e'`.
- Each vowel `'e'` may only be followed by an `'a'` or an `'i'`.
- Each vowel `'i'` **may not** be followed by another `'i'`.
- Each vowel `'o'` may only be followed by an `'i'` or a `'u'`.
- Each vowel `'u'` may only be followed by an `'a'`.

Since the answer may be too large, return it modulo $10^9 + 7$.

---

## Examples

### Example 1
- **Input:** `n = 1`
- **Output:** `5`
- **Explanation:** All possible strings are: `"a"`, `"e"`, `"i"`, `"o"`, `"u"`.

### Example 2
- **Input:** `n = 2`
- **Output:** `10`
- **Explanation:** `"ae"`, `"ea"`, `"ei"`, `"ia"`, `"ie"`, `"io"`, `"iu"`, `"oi"`, `"ou"`, `"ua"`.

### Example 3
- **Input:** `n = 5`
- **Output:** `68`

---

## Constraints

- $1 \le n \le 2 \times 10^4$ (for $O(N)$ DP; up to $10^9$ via Matrix Exponentiation)

---

## Pattern Insight: State-Transition DP & Matrix Exponentiation

Tracking counts ending at each of the 5 vowels gives a constant-size finite state machine:
- `next_a = (e + i + u) % MOD`
- `next_e = (a + i) % MOD`
- `next_i = (e + o) % MOD`
- `next_o = i % MOD`
- `next_u = (i + o) % MOD`

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Space-Optimized State DP** | $O(N)$ | $O(1)$ |
| **Matrix Exponentiation** | $O(5^3 \log N)$ | $O(1)$ |
