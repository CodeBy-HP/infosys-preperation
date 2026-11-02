# Gray Code and Circular Permutation (LeetCode 89 & 1238)

## Problem Statement
An **$n$-bit gray code sequence** is a sequence of $2^n$ integers where:
- Every integer is in the inclusive range $[0, 2^n - 1]$,
- The first integer is `0`,
- An integer appears **no more than once** in the sequence,
- The binary representation of every pair of adjacent integers differs by **exactly one bit**, and
- The binary representation of the first and last integers differs by **exactly one bit**.

Given an integer `n`, return any valid $n$-bit gray code sequence.

### Example 1:
```
Input: n = 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2
Adjacent pairs differ by exactly 1 bit.
```

### Constraints:
- `1 <= n <= 16`

---

## Pattern Insight: Direct Bitwise Formula & Mathematical Inversion
1. **Binary to Gray Code Formula:**
   The $i$-th element in a standard Gray code sequence is directly given by:
   $$G(i) = i \oplus (i \gg 1)$$
   - Proof: In standard binary, incrementing $i$ flips the lowest set bit and all trailing ones. Right-shifting $i$ by 1 and XORing eliminates all flips except the most significant flipped bit, ensuring strictly a 1-bit difference!
2. **Gray Code to Binary (Inversion):**
   Given a Gray code integer $g$, its binary value $b$ is recovered by cumulative prefix XOR:
   $$b = g \oplus (g \gg 1) \oplus (g \gg 2) \dots$$
3. **Circular Permutation Starting from Target (LC 1238):**
   - Generating standard Gray code starting with $0$, then XORing every element with `start` shifts the start element to `start` while preserving the 1-bit difference between all consecutive elements!

---

## Complexity
- **Time Complexity:** $O(2^n)$ optimal.
- **Space Complexity:** $O(1)$ auxiliary space.
