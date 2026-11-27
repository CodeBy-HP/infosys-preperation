# 32. Longest Alternating Sign / Turbulent Subarray (LeetCode 978 + Sign Variant)

## Problem Statement

### Variant A (LeetCode 978 — Longest Turbulent Subarray)
Given an integer array `arr`, return the **length of a maximum size turbulent subarray** of `arr`.
A subarray is **turbulent** if the comparison sign flips between each adjacent pair of elements (`>` then `<` then `>`..., or `<` then `>` then `<`...).

### Variant B (Infosys — Longest Alternating Sign Subarray)
Given an integer array `arr` containing positive and negative integers (and possibly `0`s), return the **longest contiguous subarray** where adjacent elements strictly alternate in sign (`+`, `-`, `+`, ... or `-`, `+`, `-`, ...). Note: `0` has neither sign and breaks the alternation.

---

## Examples

### Example 1 (Variant A — Turbulent Subarray)
- **Input:** `arr = [9, 4, 2, 10, 7, 8, 8, 1, 9]`
- **Output:** `5`
- **Explanation:** `arr[1] > arr[2] < arr[3] > arr[4] < arr[5]` (`[4, 2, 10, 7, 8]`).

### Example 2 (Variant B — Alternating Sign)
- **Input:** `arr = [1, -2, 3, 4, -5, 6, -7]`
- **Output:** `4`
- **Explanation:** `[4, -5, 6, -7]` has strictly alternating signs.

---

## Constraints

- $1 \le \text{arr.length} \le 4 \times 10^4$
- $-10^9 \le \text{arr}[i] \le 10^9$

---

## Pattern Insight: Up/Down State DP (`O(N)` time, `O(1)` space)

Track `inc` (longest turbulent subarray ending with an upward move `arr[i-1] < arr[i]`) and `dec` (ending with downward move `arr[i-1] > arr[i]`):
- If `arr[i] > arr[i-1]`: `inc = dec + 1; dec = 1;`
- Else if `arr[i] < arr[i-1]`: `dec = inc + 1; inc = 1;`
- Else: `inc = dec = 1;`

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **O(1)-Space State DP** | $O(N)$ | $O(1)$ |
