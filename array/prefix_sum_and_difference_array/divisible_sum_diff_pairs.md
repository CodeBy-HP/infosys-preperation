# Problem 9: Divisible Sum and Difference Pairs

## Problem Statement

You are given an integer array `a` of size $n$ and two integers $D$ and $M$.

Your task is to count the number of **unordered pairs** `(i, j)` such that:
- $0 \le i < j < n$
- $(a[i] + a[j]) \pmod D == 0$
- $|a[i] - a[j]| \pmod M == 0$

Return the total number of pairs satisfying both conditions.

---

## Examples

### Example 1
- **Input:** `a = [2, 4, 6, 8], D = 2, M = 2`
- **Output:** `6` (all pairs satisfy both modulo 2 conditions)

---

## Constraints

- $1 \le n \le 10^5$
- $1 \le D, M \le 10^9$
- $0 \le a[i] \le 10^9$

---

## Mathematical Reduction: Dual Remainder Key

Two numbers satisfy $|a[i] - a[j]| \pmod M == 0$ if and only if:
$$a[i] \equiv a[j] \pmod M$$
Two numbers satisfy $(a[i] + a[j]) \pmod D == 0$ if and only if:
$$a[j] \equiv (-a[i]) \pmod D \equiv (D - (a[i] \pmod D)) \pmod D$$

Therefore, for each incoming number $x$:
1. Current remainder state: `remD = x % D`, `remM = x % M`.
2. Complement remainder state needed:
   `targetRemD = (D - remD) % D`, `targetRemM = remM`.
3. Lookup count of pairs with key `(targetRemD, targetRemM)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Dual Remainder Hash Map** | $O(N)$ | $O(N)$ |
