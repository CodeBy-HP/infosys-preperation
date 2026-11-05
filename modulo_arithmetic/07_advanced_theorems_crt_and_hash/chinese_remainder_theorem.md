# Problem 19: Chinese Remainder Theorem (CRT)

## Problem Statement

Given a system of linear congruences:
$$\begin{aligned}
x &\equiv a_1 \pmod{m_1} \\
x &\equiv a_2 \pmod{m_2} \\
&\;\;\vdots \\
x &\equiv a_k \pmod{m_k}
\end{aligned}$$
where the moduli $m_1, m_2, \dots, m_k$ are **pairwise coprime** ($\gcd(m_i, m_j) = 1$ for all $i \ne j$).

Find the unique integer $x$ in the range $[0, M - 1]$ satisfying all $k$ congruences simultaneously, where $M = \prod_{i=1}^k m_i$.

---

## Examples

### Example 1
- **Congruences:**
  - $x \equiv 2 \pmod 3$
  - $x \equiv 3 \pmod 5$
  - $x \equiv 2 \pmod 7$
- **Output:** `23`
- **Explanation:**
  - $23 \pmod 3 = 2$
  - $23 \pmod 5 = 3$
  - $23 \pmod 7 = 2$
  - $23$ is the unique solution modulo $3 \times 5 \times 7 = 105$.

---

## Mathematical Derivation (Gauss's Construction)

1. Compute the total product of all moduli:
   $$M = m_1 \times m_2 \times \dots \times m_k$$

2. For each congruence $i$:
   - Let $M_i = \frac{M}{m_i}$ (the product of all other moduli except $m_i$).
   - Since $m_i$ is coprime to all other moduli, $\gcd(M_i, m_i) = 1$.
   - Compute the modular multiplicative inverse of $M_i$ modulo $m_i$:
     $$y_i = (M_i)^{-1} \pmod{m_i} \iff M_i \cdot y_i \equiv 1 \pmod{m_i}$$

3. Notice the orthogonal behavior of the term $T_i = a_i \cdot M_i \cdot y_i$:
   - Modulo $m_i$:
     $$T_i = a_i \cdot (M_i \cdot y_i) \equiv a_i \cdot 1 \equiv a_i \pmod{m_i}$$
   - Modulo $m_j$ ($j \ne i$):
     Since $M_i$ contains $m_j$ as a factor, $M_i \equiv 0 \pmod{m_j}$:
     $$T_i \equiv 0 \pmod{m_j}$$

4. Summing all terms $T_i$ yields the simultaneous solution:
   $$x = \left( \sum_{i=1}^{k} a_i \cdot M_i \cdot y_i \right) \pmod M$$

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(k \log(\max m_i))$ via Extended Euclidean inverses |
| **Space Complexity** | $\mathcal{O}(k)$ |

