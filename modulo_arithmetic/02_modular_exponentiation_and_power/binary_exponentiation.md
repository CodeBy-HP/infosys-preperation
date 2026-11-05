# Problem 3: Binary Exponentiation (Pow(x, n) % mod)

## Problem Statement

Given integers $a, b,$ and $m$, calculate $(a^b) \pmod m$ efficiently, where:
- $0 \le a \le 10^9$
- $0 \le b \le 10^{18}$
- $1 \le m \le 10^9 + 7$

---

## Mathematical Principle: Divide and Conquer / Binary Representation

A naive linear multiplication takes $O(b)$ operations, which completely times out for $b = 10^{18}$ ($10^{18}$ operations take over 30 years).

Notice that any exponent $b$ can be expressed uniquely as a sum of powers of 2 in binary:
$$b = b_0 2^0 + b_1 2^1 + b_2 2^2 + \dots + b_k 2^k \quad (b_i \in \{0, 1\})$$

Therefore:
$$a^b = a^{b_0 2^0} \times a^{b_1 2^1} \times a^{b_2 2^2} \times \dots \times a^{b_k 2^k}$$

Notice the sequence of powers:
$$a^{2^0} = a, \quad a^{2^1} = (a^{2^0})^2, \quad a^{2^2} = (a^{2^1})^2, \quad \dots, \quad a^{2^{i+1}} = (a^{2^i})^2$$

Each power is simply the **square of the previous power**!

---

## Iterative Algorithm (Bitwise Fast Power)

1. Initialize `result = 1` and `base = a % m`.
2. While $b > 0$:
   - If the lowest bit of $b$ is 1 (`b & 1`):
     $$\text{result} = (\text{result} \times \text{base}) \pmod m$$
   - Square the base for the next bit position:
     $$\text{base} = (\text{base} \times \text{base}) \pmod m$$
   - Shift $b$ right by 1 bit: `b >>= 1`.
3. Return `result`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(\log b)$ (at most 64 iterations for $b \le 10^{18}$) |
| **Space Complexity** | $\mathcal{O}(1)$ auxiliary space |

