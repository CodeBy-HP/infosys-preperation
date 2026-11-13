# Problem 6: Modular Multiplicative Inverse (FLT & Extended GCD)

## Problem Statement

Given an integer $a$ and a modulus $m$, compute the **Modular Multiplicative Inverse** $a^{-1} \pmod m$ such that:
$$a \cdot a^{-1} \equiv 1 \pmod m$$
where $a^{-1} \in [1, m - 1]$. If no such inverse exists, return $-1$.

---

## Existence Condition

The inverse $a^{-1} \pmod m$ exists **if and only if** $a$ and $m$ are coprime:
$$\gcd(a, m) = 1$$

If $\gcd(a, m) = d > 1$, then for any integer $x$:
$$a \cdot x - m \cdot y = d \cdot (a' x - m' y) \ne 1$$
Hence, no modular inverse can possibly exist.

---

## Method 1: Fermat's Little Theorem (Prime Modulus $m = p$)

When the modulus is a **prime number $p$**:
$$a^{p - 1} \equiv 1 \pmod p \implies a \cdot a^{p - 2} \equiv 1 \pmod p$$
Therefore:
$$a^{-1} \equiv a^{p - 2} \pmod p$$

Calculated in $O(\log p)$ time via binary exponentiation.

---

## Method 2: Extended Euclidean Algorithm (Composite Modulus)

When $m$ is **composite** (or prime), we use the Extended Euclidean Algorithm to solve **Bézout's Identity**:
$$a \cdot x + m \cdot y = \gcd(a, m)$$

If $\gcd(a, m) = 1$:
$$a \cdot x + m \cdot y = 1 \implies a \cdot x \equiv 1 \pmod m$$
The coefficient $x$ is the modular inverse!
Normalizing to $[0, m - 1]$:
$$a^{-1} = (x \pmod m + m) \pmod m$$

---

## Complexity Analysis

| Algorithm | Precondition | Time Complexity | Space Complexity |
| :--- | :--- | :--- | :--- |
| **Fermat's Little Theorem** | $m$ must be prime | $\mathcal{O}(\log m)$ | $\mathcal{O}(1)$ |
| **Extended Euclidean (EEA)**| $\gcd(a, m) = 1$ | $\mathcal{O}(\log(\min(a, m)))$ | $\mathcal{O}(1)$ iterative |

