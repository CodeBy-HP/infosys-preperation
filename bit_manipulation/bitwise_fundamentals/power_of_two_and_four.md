# Power of Two and Power of Four (LeetCode 231 & 342)

## Problem Statement
1. **Power of Two:** Given an integer `n`, return `true` if it is a power of two. Otherwise, return `false`.
2. **Power of Four:** Given an integer `n`, return `true` if it is a power of four. Otherwise, return `false`.

### Example 1:
```
Input: n = 16 -> Power of Two: true, Power of Four: true
Input: n = 8  -> Power of Two: true, Power of Four: false
Input: n = 0  -> Power of Two: false, Power of Four: false
```

### Constraints:
- `-2^31 <= n <= 2^31 - 1`

---

## Pattern Insight: Single-Bit Invariants & Odd-Position Masks
1. **Power of Two:**
   - Any power of two has **exactly one bit set** in binary (e.g., $1=2^0, 2=2^1, 4=2^2, 8=2^3$).
   - A positive number $n > 0$ with exactly one bit set will have that bit cleared to zero by `n & (n - 1)`.
   - Condition: `n > 0 && (n & (n - 1)) == 0`.
2. **Power of Four:**
   - Must first be a power of two: `n > 0 && (n & (n - 1)) == 0`.
   - The single set bit must be at an **even bit position** (0, 2, 4, 6, ..., 30).
     - $1 = 4^0 \to \text{bit 0}$
     - $4 = 4^1 \to \text{bit 2}$
     - $16 = 4^2 \to \text{bit 4}$
   - Mask with `0x55555555` (binary `01010101010101010101010101010101`), which has 1s at all even positions:
     - Condition: `(n & 0x55555555) != 0`.
   - Alternatively, $4^k \equiv (3 + 1)^k \equiv 1 \pmod 3$, so `n % 3 == 1`.

---

## Complexity
- **Time Complexity:** $O(1)$ strictly constant time.
- **Space Complexity:** $O(1)$.
