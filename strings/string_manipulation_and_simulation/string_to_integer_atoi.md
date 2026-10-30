# Problem 11: String to Integer (atoi) (LeetCode 8)

## Problem Statement

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer (similar to C/C++'s `atoi` function).

The algorithm for `myAtoi(string s)` is as follows:
1. **Whitespace:** Ignore any leading whitespace (`" "`).
2. **Signedness:** Determine the sign by checking if the next character is `'-'` or `'+'`. Assume positive if neither is present.
3. **Conversion:** Read the integer by ignoring leading zeros until the next non-digit character or end of the input. If no digits were read, the integer is 0.
4. **Rounding:** If the integer is out of the 32-bit signed integer range $[-2^{31}, 2^{31} - 1]$, clamp the integer so that it remains in the range.

---

## Examples

### Example 1
- **Input:** `s = "42"`
- **Output:** `42`

### Example 2
- **Input:** `s = " -042"`
- **Output:** `-42`

### Example 3
- **Input:** `s = "1337c0d3"`
- **Output:** `1337`

### Example 4
- **Input:** `s = "0-1"`
- **Output:** `0`

### Example 5
- **Input:** `s = "words and 987"`
- **Output:** `0`

---

## Constraints

- $0 \le \text{s.length} \le 200$
- `s` consists of English letters (lower-case and upper-case), digits (`0-9`), `' '`, `'+'`, `'-'`, and `'.'`.

---

## Pattern: Finite State Machine & Overflow Clamping

To prevent undefined behavior without 64-bit integer overflow:
$$\text{INT\_MAX} = 2147483647, \quad \text{INT\_MIN} = -2147483648$$
Before multiplying `total * 10 + digit`:
- If `total > INT_MAX / 10`: overflow is guaranteed! Return `sign == 1 ? INT_MAX : INT_MIN`.
- If `total == INT_MAX / 10 && digit > 7`: overflow! Clamp and return.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Deterministic Scan** | $O(N)$ | $O(1)$ |
