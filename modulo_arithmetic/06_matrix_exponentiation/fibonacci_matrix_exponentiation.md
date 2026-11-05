# Problem 16: N-th Fibonacci Number via Matrix Exponentiation

## Problem Statement

Given an integer $N$ ($0 \le N \le 10^{18}$), calculate the $N$-th Fibonacci number:
$$F_0 = 0, \quad F_1 = 1, \quad F_N = F_{N - 1} + F_{N - 2} \quad (N \ge 2)$$
modulo $10^9 + 7$.

---

## Why Dynamic Programming Fails

A standard linear DP array takes $\mathcal{O}(N)$ time.
For $N = 10^{18}$, $10^{18}$ operations will Time Limit Exceeded (taking billions of seconds).
We need an $\mathcal{O}(\log N)$ approach.

---

## Matrix State Representation

Write the Fibonacci recurrence in linear algebra vector form:
$$\begin{pmatrix} F_{N} \\ F_{N-1} \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix} \begin{pmatrix} F_{N-1} \\ F_{N-2} \end{pmatrix}$$

By applying this transition matrix $M = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}$ repeatedly:
$$\begin{pmatrix} F_{N} \\ F_{N-1} \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^{N - 1} \begin{pmatrix} F_1 \\ F_0 \end{pmatrix} = \begin{pmatrix} 1 & 1 \\ 1 & 0 \end{pmatrix}^{N - 1} \begin{pmatrix} 1 \\ 0 \end{pmatrix}$$

### Binary Matrix Exponentiation
Just as we compute $a^k \pmod m$ in $O(\log k)$ via repeated squaring, we can compute $M^{N - 1} \pmod m$ using **Matrix Binary Exponentiation**!
- Matrix multiplication of two $2 \times 2$ matrices takes $2^3 = 8$ scalar multiplications.
- Computing $M^{N - 1}$ requires at most $64$ matrix multiplications.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(2^3 \log N) = \mathcal{O}(\log N)$ ($\approx 64$ operations) |
| **Space Complexity** | $\mathcal{O}(1)$ for $2 \times 2$ matrices |

