# Problem 14: Lucas' Theorem for Huge N Modulo Small Prime

## Problem Statement

Compute the binomial coefficient $\binom{n}{r} \pmod p$ where:
$$0 \le r \le n \le 10^{18}$$
and $p$ is a **small prime** ($p \le 10^5$).

---

## Why Standard Factorials Fail

When $n \ge p$, the factorial $n!$ contains $p$ as a factor, so:
$$n! \equiv 0 \pmod p$$

Similarly, if $r \ge p$ or $(n - r) \ge p$, their factorials are also multiples of $p$.
Dividing $0$ by $0$ modulo $p$ is undefined! Standard modular inverse precomputation completely breaks down.

---

## Lucas' Theorem Statement

> **Lucas' Theorem:**
> Write $n$ and $r$ in their **base-$p$ representations**:
> $$n = n_k p^k + n_{k-1} p^{k-1} + \dots + n_1 p + n_0$$
> $$r = r_k p^k + r_{k-1} p^{k-1} + \dots + r_1 p + r_0$$
> where $0 \le n_i, r_i < p$.
>
> Then:
> $$\binom{n}{r} \equiv \prod_{i=0}^{k} \binom{n_i}{r_i} \pmod p$$
> with the convention that $\binom{n_i}{r_i} = 0$ whenever $n_i < r_i$.

---

## Recursive Implementation

Notice that the lowest base-$p$ digits are $n_0 = n \pmod p$ and $r_0 = r \pmod p$.
The remaining higher digits correspond to $\lfloor n / p \rfloor$ and $\lfloor r / p \rfloor$.

Therefore, Lucas' Theorem can be written as a clean recurrence:
$$\text{lucas}(n, r, p) = \left( \text{lucas}\Big(\lfloor n / p \rfloor, \lfloor r / p \rfloor, p\Big) \times \binom{n \pmod p}{r \pmod p} \right) \pmod p$$

### Base Case:
When $r == 0$, $\binom{n}{0} = 1$.
The term $\binom{n \pmod p}{r \pmod p}$ has inputs strictly $< p$, so it can be evaluated in $O(1)$ time using standard precomputed factorials up to $p - 1$!

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Factorial Precomputation** | $\mathcal{O}(p)$ up to $p - 1$ | $\mathcal{O}(p)$ |
| **Lucas Evaluation** | $\mathcal{O}(\log_p n)$ base-$p$ divisions | $\mathcal{O}(\log_p n)$ recursion depth |
| **Total** | $\mathcal{O}(p + \log_p n)$ | $\mathcal{O}(p)$ |

