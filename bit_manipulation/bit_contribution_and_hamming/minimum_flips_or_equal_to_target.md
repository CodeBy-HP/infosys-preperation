# Minimum Flips to Make a OR b Equal to c (LeetCode 1318)

## Problem Statement
Given 3 positives numbers `a`, `b` and `c`. Return the minimum flips required in some bits of `a` and `b` to make `(a OR b == c)`. (bitwise OR operation).

Flip operation consists of changing any single bit 1 to 0 or changing the bit 0 to 1 in their binary representation.

### Example 1:
```
Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1, b = 4, c = 5 such that (a OR b == 5)
a: 0010 -> 0001
b: 0110 -> 0100
c: 0101
Total flips = 3.
```

### Constraints:
- `1 <= a <= 10^9`
- `1 <= b <= 10^9`
- `1 <= c <= 10^9`

---

## Pattern Insight: Independent Bitwise Truth Table Evaluation
- For each bit position $0 \le i < 32$:
  - Let $bit_a = (a >> i) \& 1$, $bit_b = (b >> i) \& 1$, and $bit_c = (c >> i) \& 1$.
  - Case 1: $bit_c == 1$:
    - We need $bit_a \mid bit_b == 1$.
    - If both $bit_a == 0$ and $bit_b == 0$, we must flip at least one of them to 1 $\to$ **1 flip**.
    - If either is 1, no flips needed $\to$ **0 flips**.
  - Case 2: $bit_c == 0$:
    - We need $bit_a \mid bit_b == 0$, meaning both must be 0!
    - Every 1 bit in $bit_a$ or $bit_b$ must be flipped to 0 $\to$ **$(bit_a + bit_b)$ flips** (can be 0, 1, or 2 flips).

---

## Complexity
- **Time Complexity:** $O(32) = O(1)$ constant operations.
- **Space Complexity:** $O(1)$.
