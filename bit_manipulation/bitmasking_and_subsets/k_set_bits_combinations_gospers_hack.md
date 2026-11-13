# Combinations of K Set Bits in an N-Bit Mask (Gosper's Hack)

## Problem Statement
Given two integers `N` and `K` ($0 \le K \le N$), generate all non-negative integers strictly less than $2^N$ that have **exactly $K$ set bits** (1s) in their binary representation, ordered in ascending lexicographical order.

This problem is fundamental in:
- Generating all subsets of size $K$ from an $N$-element set ($k$-combinations).
- Traveling Salesperson Problem (TSP) with state-layering by subset size.
- Feature selection, combinatorial search, and sub-graph isomorphism.

### Example 1:
```
Input: N = 4, K = 2
Output: [3, 5, 6, 9, 10, 12]
Explanation:
3  -> 0011 (2 bits set)
5  -> 0101 (2 bits set)
6  -> 0110 (2 bits set)
9  -> 1001 (2 bits set)
10 -> 1010 (2 bits set)
12 -> 1100 (2 bits set)
Total combinations: 4! / (2! * 2!) = 6.
```

### Constraints:
- `1 <= N <= 31`
- `0 <= K <= N`

---

## 1. Brute Force Approach: Full Power Set Filtering ($O(2^N)$)
- Loop through all $2^N$ numbers from $0$ to $(1 \ll N) - 1$.
- Check if `__builtin_popcount(mask) == K`.
- **Limitation:** Inefficient when $\binom{N}{K} \ll 2^N$.
  - For $N = 30, K = 3$: $\binom{30}{3} = 4,060$, but brute force checks $2^{30} \approx 1.07 \times 10^9$ numbers ($\approx 2$ seconds or TLE).

---

## 2. Recursive Backtracking ($O(\binom{N}{K})$)
- Recursively place $K$ ones into $N$ slots:
  - If remaining bits to place equals remaining positions, fill them all.
  - If $K = 0$, record mask.
  - Branch on placing bit at position $pos$ or skipping it.
- **Limitation:** Incurs recursion overhead, function call stacks, and does not yield an in-place $O(1)$ bit-level transition.

---

## 3. Optimal Approach: Gosper's Hack ($O(\binom{N}{K})$ Time, $O(1)$ Space)

**Gosper's Hack** is a famous bit manipulation algorithm (from HAKMEM Item 175) that computes the **next lexicographical integer with the same number of set bits** in strictly $O(1)$ bitwise operations!

### Step-by-Step Derivation:
Suppose the current mask is `mask`:
1. **Isolate the lowest set bit (`c`):**
   $$c = \text{mask} \ \& \ (-\text{mask})$$
2. **Ripple carry addition (`r`):**
   $$r = \text{mask} + c$$
   - Adding $c$ to `mask` flips the rightmost contiguous block of ones to zeros, and sets the bit immediately to its left to 1.
   - For example: `...0011100 + 0000100 = ...0100000`.
3. **Count and reposition shifted ones:**
   - The expression `(r ^ mask)` isolates the bits that changed. It contains $(m + 2)$ ones, where $m$ is the length of the flipped run of ones.
   - We divide by `c` (or right-shift by $\text{ctz}(c)$) to bring this block down to the least significant bit (LSB):
     $$\frac{r \oplus \text{mask}}{c}$$
   - Since $r$ already carries one of the ones to a higher position, we need to shift right by an additional 2 bits (`>> 2`) to discard the extra bits:
     $$\left(\frac{r \oplus \text{mask}}{c}\right) \gg 2$$
4. **Combine with carry result (`r`):**
   $$\text{next\_mask} = \left(\left(\frac{r \oplus \text{mask}}{c}\right) \gg 2\right) \mid r$$

### Initialization & Termination:
- **Smallest integer with $K$ set bits:**
  $$\text{start} = (1 \ll K) - 1$$
- **Termination bound:**
  $$\text{mask} < (1 \ll N)$$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space | Total Visited States |
| :--- | :--- | :--- | :--- |
| **Brute Force** | $O(2^N)$ | $O(1)$ | $2^N$ (wasteful) |
| **Recursive Backtracking** | $O(\binom{N}{K})$ | $O(N)$ recursion | $\binom{N}{K}$ |
| **Gosper's Hack (Optimal)** | $O(\binom{N}{K})$ | $O(1)$ constant | $\binom{N}{K}$ strictly |

