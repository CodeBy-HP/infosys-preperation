# 50. Perfect Combinations (`AND = 0` and `OR % 3 == 0`) (Infosys SP OA Exact PYQ)

## Problem Statement

Given an integer array `A` of size `N`:

- **Variant A (Pair Counting — Infosys SP PYQ):** Count the number of index pairs `(i, j)` with $0 \le i < j < N$ such that:
  1. $(A[i] \mathbin{\&} A[j]) == 0$ (no shared set bits)
  2. $(A[i] \mid A[j]) \pmod 3 == 0$ (bitwise OR is divisible by 3)

- **Variant B (Subset Counting):** Count the number of non-empty subsets of `A` where elements are pairwise bit-disjoint and the bitwise OR of the subset is divisible by 3.

Return the count modulo $10^9 + 7$.

---

## Examples

### Example 1 (Variant A — Pair Counting)
- **Input:** `A = [1, 2, 4, 5]`
- **Output:** `2`
- **Explanation:**
  - `(1, 2)` (`01 & 10 = 0`, `01 | 10 = 3`, `3 % 3 == 0`) $\checkmark$
  - `(2, 4)` (`010 & 100 = 0`, `010 | 100 = 6`, `6 % 3 == 0`) $\checkmark$
  - `(1, 4)` (`1 | 4 = 5`, `5 % 3 != 0`) $\times$
  - `(2, 5)` (`2 & 5 = 0`, `2 | 5 = 7`, `7 % 3 != 0`) $\times$
  - Total = `2`.

---

## Constraints

- $1 \le N \le 10^5$
- $0 \le A[i] < 2^{18}$ (up to $10^5$)

---

## Pattern Insight: `A[i] & A[j] == 0` $\implies$ `A[i] | A[j] = A[i] + A[j]` + SOS DP!

Notice the crucial algebraic identity:
Whenever two non-negative integers share **no common set bits** (`(x & y) == 0`), bitwise OR equals ordinary addition:
$$x \mid y = x + y$$
Therefore, $(x \mid y) \pmod 3 == 0 \iff (x + y) \pmod 3 == 0 \iff y \pmod 3 == (3 - (x \pmod 3)) \pmod 3$!

We can solve Variant A in **$O(B \cdot 2^B + N)$** using **Sum Over Subsets (SOS) DP** stratified into 3 buckets by modulo 3:
1. Build `sos[rem][mask]` = number of array elements `y` with `y % 3 == rem` whose bits are a subset of `mask`.
2. For each `x = A[i]`, compute `comp = fullMask ^ x` and `needRem = (3 - x % 3) % 3`.
3. `sos[needRem][comp]` directly gives the exact count of valid partners `y`!
4. Subtract self-matches (`x == 0`, since `0 & 0 == 0` and `(0 | 0) % 3 == 0`) and divide ordered pairs by `2`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Stratified SOS DP (Pairs)** | $O(B \cdot 2^B + N)$ | $O(2^B)$ |
| **Submask Bitmask DP (Subsets)** | $O(N \cdot 3^{B})$ or $O(3^B)$ | $O(2^B)$ |
