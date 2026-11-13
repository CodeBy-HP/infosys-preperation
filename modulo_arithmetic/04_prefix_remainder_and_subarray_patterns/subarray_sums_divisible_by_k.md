# Problem 9: Subarray Sums Divisible by K (LeetCode 974)

## Problem Statement

Given an integer array `nums` and an integer `k`, return the number of non-empty continuous subarrays whose sum is strictly divisible by `k`.

A subarray is a contiguous part of an array.

---

## Examples

### Example 1
- **Input:** `nums = [4, 5, 0, -2, -3, 1]`, `k = 5`
- **Output:** `7`
- **Explanation:**
  There are 7 subarrays with sum divisible by $k = 5$:
  - `[4, 5, 0, -2, -3, 1]` (sum = 5)
  - `[5]` (sum = 5)
  - `[5, 0]` (sum = 5)
  - `[5, 0, -2, -3]` (sum = 0)
  - `[0]` (sum = 0)
  - `[0, -2, -3]` (sum = -5)
  - `[-2, -3]` (sum = -5)

### Example 2
- **Input:** `nums = [5]`, `k = 9`
- **Output:** `0`

---

## Mathematical Principle: Prefix Congruence

Let $P[i] = \sum_{j=0}^{i-1} \text{nums}[j]$ be the prefix sum.
The sum of subarray $\text{nums}[L \dots R]$ is:
$$\text{sum}(L, R) = P[R + 1] - P[L]$$

The subarray sum is divisible by $k$ if and only if:
$$(P[R + 1] - P[L]) \equiv 0 \pmod k \iff P[R + 1] \equiv P[L] \pmod k$$

Therefore, two prefix sums with the **same remainder modulo $k$** delineate a subarray whose sum is a multiple of $k$.

### Crucial Invariant: Negative Remainder Normalization
In C/C++, `-7 % 5 = -2`. Mathematically, this belongs to residue class $-2 + 5 = 3 \pmod 5$.
Always normalize remainders:
$$\text{rem} = ((\text{sum} \pmod k) + k) \pmod k$$

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ single pass |
| **Space Complexity** | $\mathcal{O}(K)$ for remainder frequency array |

