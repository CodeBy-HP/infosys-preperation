# 05. Number Construction (`a[i+1]` Divisibility & `2*a[i]` Variant — Unique Birthday Gift)

## Problem Statement

You are given two integers `n` and `k`. Count the number of arrays `a` of length `k` such that:
1. $1 \le a[i] \le n$ for every $0 \le i < k$.
2. For every adjacent pair, $a[i + 1]$ is divisible by $a[i]$ ($a[i + 1] \pmod{a[i]} == 0$).

*(Special Restricted Variant: If adjacent elements must strictly satisfy $a[i + 1] = 2 \cdot a[i]$ OR $a[i + 1] = a[i]$, return the count modulo $10^9 + 7$.)*

Return the number of valid arrays modulo $10000$ (or $10^9 + 7$).

---

## Examples

### Example 1 (General Divisibility — Infosys / HackWithInfy PYQ)
- **Input:** `n = 2`, `k = 1`
- **Output:** `2`
- **Explanation:** Valid arrays of length 1: `[1]`, `[2]`.

### Example 2 (General Divisibility)
- **Input:** `n = 2`, `k = 2`
- **Output:** `3`
- **Explanation:** Valid arrays of length 2: `[1, 1]`, `[1, 2]`, `[2, 2]`. (`[2, 1]` is invalid because $1$ is not divisible by $2$).

### Example 3 (Doubling Rule `a[i+1] in {a[i], 2*a[i]}`)
- **Input:** `n = 4`, `k = 2`
- **Output:** `6`
- **Explanation:** Valid arrays: `[1,1]`, `[1,2]`, `[2,2]`, `[2,4]`, `[3,3]`, `[4,4]`.

---

## Constraints

- $1 \le n \le 2000$
- $1 \le k \le 2000$

---

## Pattern Insight: Harmonic Sieve Push-DP

Instead of checking all $O(n^2)$ pairs per length step, iterate forward by multiples:
For each length `len` from `1` to `k - 1`, and each ending value `val` from `1` to `n`:
Push `dp[val]` forward to all multiples `m = val, 2*val, 3*val, ... <= n`:
$$\text{next\_dp}[m] += \text{dp}[val]$$
By the harmonic series, $\sum_{val=1}^n \lfloor n / val \rfloor = O(n \log n)$ per length step!

---

## Complexity Analysis

| Variant | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **General Divisibility (`a[i+1] % a[i] == 0`)** | $O(k \cdot n \log n)$ | $O(n)$ |
| **Strict Doubling/Self (`a[i+1] in {a[i], 2*a[i]}`)** | $O(k \cdot n)$ | $O(n)$ |
