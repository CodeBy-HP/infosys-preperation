# Sum of Two Integers (LeetCode 371)

## Problem Statement
Given two integers `a` and `b`, return the sum of the two integers without using the operators `+` and `-`.

### Example 1:
```
Input: a = 1, b = 2
Output: 3
```

### Example 2:
```
Input: a = 2, b = 3
Output: 5
```

### Constraints:
- `-1000 <= a, b <= 1000`

---

## Pattern Insight: Digital Half-Adder Circuit Simulation
- An adder circuit decomposes integer addition into two components:
  1. **Sum without carry:** Bitwise XOR ($a \oplus b$) produces the sum bits where $1 + 0 = 1$ and $1 + 1 = 0$.
  2. **Carry generation:** Bitwise AND ($a \ \& \ b$) identifies bit positions where both inputs are 1. The carry must be shifted left by 1 position: $(a \ \& \ b) \ll 1$.
- Iterative loop:
  - `sum = a ^ b`
  - `carry = (uint32_t)(a & b) << 1`
  - Update `a = sum`, `b = carry`.
  - Repeat until `carry == 0`.
- In C++, casting `(a & b)` to `uint32_t` before left shifting avoids undefined behavior with negative signed integers.

---

## Complexity
- **Time Complexity:** $O(1)$ — At most 32 carry propagation cycles.
- **Space Complexity:** $O(1)$.
