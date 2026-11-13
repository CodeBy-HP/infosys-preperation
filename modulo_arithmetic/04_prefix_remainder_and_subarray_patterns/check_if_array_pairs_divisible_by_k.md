# Problem 12: Check If Array Pairs Are Divisible by K (LeetCode 1497)

## Problem Statement

Given an array of integers `arr` of even length $n$ and an integer $k$.

We want to divide the array into exactly $n / 2$ pairs such that the sum of each pair is divisible by $k$.

Return `true` If you can find a way to do that or `false` otherwise.

---

## Examples

### Example 1
- **Input:** `arr = [1, 2, 3, 4, 5, 10, 6, 7, 8, 9]`, `k = 5`
- **Output:** `true`
- **Explanation:** Pairs are `(1, 9)`, `(2, 8)`, `(3, 7)`, `(4, 6)`, `(5, 10)`. Sums are 10, 10, 10, 10, 15, all divisible by 5.

### Example 2
- **Input:** `arr = [1, 2, 3, 4, 5, 6]`, `k = 7`
- **Output:** `true`
- **Explanation:** Pairs are `(1, 6)`, `(2, 5)`, `(3, 4)`.

### Example 3
- **Input:** `arr = [1, 2, 3, 4, 5, 6]`, `k = 10`
- **Output:** `false`

---

## Mathematical Principle: Modulo Pairing Constraints

Two numbers $a$ and $b$ sum to a multiple of $k$ if and only if:
$$(a + b) \equiv 0 \pmod k \iff ((a \pmod k) + (b \pmod k)) \equiv 0 \pmod k$$

Let each element be mapped to its canonical remainder in $[0, k - 1]$:
$$r = ((x \pmod k) + k) \pmod k$$

### Pairing Invariants:
1. **Remainder $0$:**
   An element with remainder $0$ can **only** be paired with another element with remainder $0$ ($0 + 0 = 0$).
   $$\text{count}[0] \pmod 2 == 0 \quad (\text{must be even})$$

2. **Symmetric Remainder (when $k$ is even, $r = k / 2$):**
   An element with remainder $k / 2$ can only pair with another element with remainder $k / 2$ ($k/2 + k/2 = k \equiv 0$).
   $$\text{count}[k / 2] \pmod 2 == 0 \quad (\text{must be even})$$

3. **Complementary Remainders ($1 \le r \le k - 1$):**
   An element with remainder $r$ must pair with an element having remainder $k - r$:
   $$\text{count}[r] == \text{count}[k - r]$$

If all three invariants hold, a valid pairing exists; otherwise, it is mathematically impossible.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N + K)$ single frequency pass + check up to $K/2$ |
| **Space Complexity** | $\mathcal{O}(K)$ for the remainder bucket array |

