# Problem 4: Super Pow (LeetCode 372 / Euler's Totient Power)

## Problem Statement

Your task is to calculate $a^b \pmod{1337}$ where $a$ is a positive integer and $b$ is an extremely large positive integer represented as an array of decimal digits:
$$b = [d_0, d_1, d_2, \dots, d_{k-1}]$$

---

## Examples

### Example 1
- **Input:** `a = 2`, `b = [3]`
- **Output:** `8` ($2^3 = 8$)

### Example 2
- **Input:** `a = 2`, `b = [1, 0]`
- **Output:** `1024` ($2^{10} = 1024$)

### Example 3
- **Input:** `a = 1`, `b = [4, 3, 3, 8, 5, 2]`
- **Output:** `1`

---

## Constraints

- $1 \le a \le 2^{31} - 1$
- $1 \le b.\text{length} \le 2000$
- $0 \le b[i] \le 9$
- $b$ does not contain leading zeros.

---

## Mathematical Principle: Horner's Modulo Recurrence

Notice that a decimal number with last digit $d$ can be decomposed into:
$$b = 10 \cdot b' + d$$

By exponent laws:
$$a^b = a^{10 \cdot b' + d} = (a^{b'})^{10} \times a^d$$

Applying modulo arithmetic at each step:
$$a^b \pmod M = \Big( (a^{b'} \pmod M)^{10} \times (a^d \pmod M) \Big) \pmod M$$

### Recursive Strategy:
- Pop the last digit $d = b.\text{back()}$.
- Compute part 1: `powMod(superPow(a, b'), 10, 1337)`
- Compute part 2: `powMod(a, d, 1337)`
- Return `(part1 * part2) % 1337`.

---

## Alternative: Euler's Totient Theorem $\phi(M)$

For $M = 1337 = 7 \times 191$ (both prime):
$$\phi(1337) = (7 - 1) \times (191 - 1) = 6 \times 190 = 1140$$

For any exponent $B \ge \phi(M)$:
$$a^B \equiv a^{(B \bmod 1140) + 1140} \pmod{1337}$$
This allows compressing the entire array $b$ of length $2000$ into a single integer $B \pmod{1140}$ in $O(N)$ time!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Horner's Rule (Recursive)** | $\mathcal{O}(N)$ where $N = b.\text{length}$ | $\mathcal{O}(N)$ call stack |
| **Euler's Totient Reduction** | $\mathcal{O}(N)$ single pass | $\mathcal{O}(1)$ space |

