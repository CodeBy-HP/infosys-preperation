# Number of 1 Bits / Hamming Weight (LeetCode 191)

## Problem Statement
Given a positive integer `n`, write a function that returns the number of set bits (1s) it has (also known as the Hamming weight).

### Example 1:
```
Input: n = 11 (binary 1011)
Output: 3
Explanation: The input binary string 1011 has a total of three set bits.
```

### Example 2:
```
Input: n = 128 (binary 10000000)
Output: 1
```

### Constraints:
- `1 <= n <= 2^31 - 1`

---

## Pattern Insight: Brian Kernighan’s Algorithm ($O(K)$ Optimal)
1. **Naive Loop ($O(32)$):**
   - Check the lowest bit with `n & 1`, then right shift `n >>= 1`. Takes 32 iterations regardless of how sparse the bits are.
2. **Brian Kernighan's Algorithm ($O(\text{set bits})$):**
   - The expression `n - 1` flips the lowest set bit of `n` to `0` and sets all trailing zeroes after it to `1`.
   - Therefore, `n & (n - 1)` clears **strictly the lowest set bit** of `n` while leaving all higher bits unchanged!
   - Each iteration eliminates one set bit. If $n$ has $K$ ones, the loop executes exactly $K$ times.

---

## Complexity
- **Time Complexity:** $O(K)$ where $K$ is the number of set bits ($K \le 32$).
- **Space Complexity:** $O(1)$.
