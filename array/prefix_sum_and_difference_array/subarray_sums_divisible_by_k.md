# Problem 10: Subarray Sums Divisible by K (LeetCode 974)

## Problem Statement

Given an integer array `nums` and an integer `k`, return the number of non-empty continuous subarrays whose sum is strictly divisible by `k`.

A subarray is a contiguous part of an array.

---

## Examples

### Example 1
- **Input:** `nums = [4, 5, 0, -2, -3, 1]`, `k = 5`
- **Output:** `7`
- **Explanation:**
  There are 7 subarrays with a sum divisible by $k = 5$:
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

## Constraints

- $1 \le \text{nums.length} \le 3 \times 10^4$
- $-10^4 \le \text{nums}[i] \le 10^4$
- $2 \le k \le 10^4$

---

## Mathematical Principle: Modulo Congruence

Let $P[i] = \sum_{j=0}^{i-1} \text{nums}[j]$ be the prefix sum.
The sum of subarray $\text{nums}[L \dots R]$ is:
$$\text{sum}(L, R) = P[R + 1] - P[L]$$

The subarray sum is divisible by $k$ if and only if:
$$(P[R + 1] - P[L]) \equiv 0 \pmod k \iff P[R + 1] \equiv P[L] \pmod k$$

Therefore, two prefix sums with the **same remainder modulo $k$** delineate a subarray whose sum is a multiple of $k$.

### Crucial Edge Case: Negative Modulo in C++
In C/C++, `-7 % 5 = -2`, but mathematically the congruence class is $-2 + 5 = 3$.
To ensure all remainders map to the non-negative interval $[0, k - 1]$:
$$\text{rem} = ((\text{sum} \pmod k) + k) \pmod k$$

---

## Step-by-Step Algorithm

1. Initialize `count[k] = {0}` with `count[0] = 1` (representing the empty prefix at index 0).
2. Maintain running `prefix_sum = 0` and `total_subarrays = 0`.
3. For each number in `nums`:
   - `prefix_sum += num`
   - Calculate normalized remainder: `rem = ((prefix_sum % k) + k) % k`.
   - Add `count[rem]` to `total_subarrays` (each previous occurrence forms a valid divisible subarray).
   - Increment `count[rem]++`.
4. Return `total_subarrays`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ single linear pass |
| **Space Complexity** | $\mathcal{O}(K)$ for the remainder frequency array |

