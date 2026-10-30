# Reverse Bits (LeetCode 190)

## Problem Statement
Reverse bits of a given 32-bit unsigned integer.

### Example 1:
```
Input: n = 00000010100101000001111010011100
Output:    00111001011110000010100101000000 (964176192)
```

### Constraints:
- The input is a 32-bit unsigned integer.

**Follow up:** If this function is called many times, how would you optimize it?

---

## Pattern Insight: Bit-by-Bit Shift vs. Divide-and-Conquer Mask Swapping
1. **Loop Approach ($O(32)$):**
   - In each of 32 steps, shift `result` left by 1, append `n & 1`, and shift `n` right by 1.
2. **Divide-and-Conquer Bit Permutation ($O(1)$ fast):**
   - Swap adjacent 16-bit blocks: `n = (n >> 16) | (n << 16)`.
   - Swap adjacent 8-bit bytes: `n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8)`.
   - Swap adjacent 4-bit nibbles: `n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4)`.
   - Swap adjacent 2-bit pairs: `n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2)`.
   - Swap adjacent bits: `n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1)`.
   - Requires zero branching and only 5 parallel mask operations!

---

## Complexity
- **Time Complexity:** $O(1)$ (5 bitwise operations).
- **Space Complexity:** $O(1)$.
