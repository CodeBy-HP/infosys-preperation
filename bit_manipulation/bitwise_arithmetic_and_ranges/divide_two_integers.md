# Divide Two Integers (LeetCode 29)

## Problem Statement
Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, `8.345` would be truncated to `8`, and `-2.7335` would be truncated to `-2`.

Return the quotient after dividing `dividend` by `divisor`.

**Note:** Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: `[-2^31, 2^31 - 1]`. For this problem, if the quotient is strictly greater than `2^31 - 1`, then return `2^31 - 1`, and if the quotient is strictly less than `-2^31`, then return `-2^31`.

### Example 1:
```
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = 3.33333.. which is truncated to 3.
```

### Constraints:
- `-2^31 <= dividend, divisor <= 2^31 - 1`
- `divisor != 0`

---

## Pattern Insight: Exponential Bit Shifting Subtraction
- Linear subtraction (`while (dividend >= divisor) { dividend -= divisor; ++quotient; }`) runs in $O(\text{dividend})$ time, which TLEs when `dividend = 2^31 - 1, divisor = 1`.
- **Bit Doubling:**
  - Notice that any integer quotient can be expressed as a sum of powers of 2 (binary representation):
    $$\text{quotient} = \sum_{i=0}^{31} c_i \cdot 2^i, \quad c_i \in \{0, 1\}$$
  - Starting from $i = 31$ down to 0:
    - If `dividend >= (divisor << i)`:
      - Subtract `(divisor << i)` from `dividend`.
      - Add `(1 << i)` to `quotient`.
- Use `long long` for intermediate calculations to avoid overflow when handling `INT_MIN` ($-2^{31}$).

---

## Complexity
- **Time Complexity:** $O(32) = O(1)$ operations.
- **Space Complexity:** $O(1)$.
