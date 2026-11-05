# Problem 7: Linear Sieve Modular Inverses in O(N)

## Problem Statement

Given an integer $N$ and a prime modulus $P$, compute the modular multiplicative inverses for **all integers from $1$ to $N$ modulo $P$**:
$$inv[1], inv[2], \dots, inv[N]$$
in strictly $\mathcal{O}(N)$ total time.

---

## Why Computing Individually is Inefficient

Using Fermat's Little Theorem or Extended Euclidean Algorithm for each of the $N$ numbers requires:
$$\mathcal{O}(N \log P) \text{ time}$$

For $N = 10^7$ or $10^6$ in strict competitive programming time limits ($1.0$ s), $10^7 \log(10^9) \approx 3 \times 10^8$ operations will Time Limit Exceeded (TLE). A linear $\mathcal{O}(N)$ recurrence is required.

---

## Mathematical Derivation of the Linear Recurrence

For any integer $i \in [2, P - 1]$, divide $P$ by $i$ using the Division Algorithm:
$$P = k \cdot i + r$$
where:
$$k = \lfloor P / i \rfloor, \quad r = P \pmod i \quad (0 < r < i)$$

Taking this equation modulo $P$:
$$k \cdot i + r \equiv 0 \pmod P$$
$$r \equiv -k \cdot i \pmod P$$

Multiply both sides by $i^{-1} \cdot r^{-1}$:
$$r \cdot (i^{-1} \cdot r^{-1}) \equiv (-k \cdot i) \cdot (i^{-1} \cdot r^{-1}) \pmod P$$
$$i^{-1} \equiv -k \cdot r^{-1} \pmod P$$

Substitute back $k = \lfloor P / i \rfloor$ and $r = P \pmod i$:
$$i^{-1} \equiv -\lfloor P / i \rfloor \cdot (P \pmod i)^{-1} \pmod P$$

Since $r = P \pmod i < i$, the inverse $(P \pmod i)^{-1}$ **has already been computed in a previous step**!

To eliminate the negative sign and keep the result in $[0, P - 1]$:
$$inv[i] = \Big( P - \lfloor P / i \rfloor \Big) \times inv[P \pmod i] \pmod P$$

### Base Case:
$$inv[1] = 1$$

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ single pass of constant-time transitions |
| **Space Complexity** | $\mathcal{O}(N)$ array storage |

