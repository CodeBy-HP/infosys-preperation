# 04. Count Strings `{0, 1, 2}` with Structural Constraints (Infosys SP Exact PYQ)

## Problem Statement

Given an integer `n`, count the number of valid strings of length `n` consisting strictly of characters `'0'`, `'1'`, and `'2'` satisfying **all** of the following conditions:
1. No two consecutive `'0'`s appear (`"00"` is forbidden).
2. No three consecutive `'1'`s appear (`"111"` is forbidden).
3. Every `'2'` must be strictly **surrounded by `'1'`s** on both sides (i.e., `'2'` can only appear inside the pattern `"121"`, meaning `'2'` cannot be at index `0`, cannot be at index `n - 1`, must follow `'1'`, and must be followed by `'1'`).

Return the total number of valid strings modulo $10^9 + 7$.

---

## Examples

### Example 1
- **Input:** `n = 1`
- **Output:** `2`
- **Explanation:** Valid strings: `"0"`, `"1"`. (`"2"` cannot exist without surrounding `'1'`s).

### Example 2
- **Input:** `n = 2`
- **Output:** `3`
- **Explanation:** Valid strings: `"01"`, `"10"`, `"11"`. (`"00"` invalid; `'2'` cannot be placed in length 2).

### Example 3
- **Input:** `n = 3`
- **Output:** `6`
- **Explanation:** Valid strings: `"010"`, `"011"`, `"101"`, `"110"`, `"121"`. Wait: `"121"` (1), `"010"` (2), `"011"` (3), `"101"` (4), `"110"` (5) -> total = `5` (`"111"` is forbidden!).

---

## Constraints

- $1 \le n \le 10^5$
- Output modulo $10^9 + 7$.

---

## Pattern Insight: Exact Finite-State DP

Track the last two characters `(prev2, prev1)` where values are `{0, 1, 2, 3 (NONE)}`:
- Transition rules placing `curr` at index `i`:
  1. If `prev1 == 2`: `curr` **must** be `1`.
  2. If `curr == 0`: forbidden if `prev1 == 0`.
  3. If `curr == 1`: forbidden if `prev1 == 1 && prev2 == 1`.
  4. If `curr == 2`: forbidden if `prev1 != 1` **or** `i == n - 1` (since nothing follows the last position to sandwich `'2'`).

Notice at the end (`i == n`), `prev1` cannot be `2` (enforced by rejecting `curr == 2` at `i == n - 1`).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Bottom-Up Rolling State DP** | $O(N)$ | $O(1)$ |
| **Top-Down Memoization** | $O(N)$ | $O(N)$ |
