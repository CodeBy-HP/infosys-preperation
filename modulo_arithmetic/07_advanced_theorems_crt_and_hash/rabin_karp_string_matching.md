# Problem 20: Rabin-Karp String Matching (Double Polynomial Rolling Hash)

## Problem Statement

Given two strings: a `text` of length $N$ and a `pattern` of length $M$ ($M \le N$), find the first (or all) starting index where `pattern` occurs as a substring in `text`.

Achieve $\mathcal{O}(N + M)$ average time complexity using **Modular Polynomial Rolling Hash**.

---

## Mathematical Principle: Polynomial Rolling Hash Modulo $P$

Encode any string $S = s_0 s_1 \dots s_{m-1}$ as an integer polynomial evaluated at base $B$:
$$H(S) = \left( \sum_{i=0}^{m-1} s_i \cdot B^{m - 1 - i} \right) \pmod M$$
where $B = 31$ (or $131$) and $M$ is a large prime like $10^9 + 7$.

### $\mathcal{O}(1)$ Rolling Transition
When shifting the window from $[L, L + m - 1]$ to $[L + 1, L + m]$:
1. **Remove outgoing character $s_L$:**
   $$H' = (H - s_L \cdot B^{m - 1}) \pmod M$$
2. **Shift existing window left (multiply by base):**
   $$H'' = (H' \cdot B) \pmod M$$
3. **Add incoming character $s_{L + m}$:**
   $$H_{\text{new}} = (H'' + s_{L + m}) \pmod M$$

Combining and applying negative modulo normalization:
$$H_{\text{new}} = \Big( (H - s_L \cdot B^{m - 1}) \cdot B + s_{L + m} \Big) \pmod M$$

### Double Hashing to Eliminate Hash Collisions
To prevent malicious test cases that trigger hash collisions, compute **two independent hashes simultaneously** with different moduli:
- Hash 1: $B_1 = 31, \quad M_1 = 10^9 + 7$
- Hash 2: $B_2 = 37, \quad M_2 = 10^9 + 9$

The probability of collision across two $10^9$ primes is $\frac{1}{M_1 M_2} \approx 10^{-18}$, which is virtually zero.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Preprocessing Pattern Hash** | $\mathcal{O}(M)$ |
| **Text Sliding Window** | $\mathcal{O}(N)$ ($O(1)$ per character) |
| **Total Average Time** | $\mathcal{O}(N + M)$ |
| **Space Complexity** | $\mathcal{O}(1)$ |

