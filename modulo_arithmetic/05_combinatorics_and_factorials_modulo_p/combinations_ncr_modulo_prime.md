# Problem 13: Combinations nCr Modulo Prime

## Problem Statement

Precompute binomial coefficients $\binom{n}{r} \pmod P$ where $P = 10^9 + 7$ (or any prime) such that multiple queries $(n, r)$ with $0 \le r \le n \le N$ ($N \le 10^6$) can be answered in **$\mathcal{O}(1)$ time per query**.

---

## Mathematical Formulation

The binomial coefficient $\binom{n}{r}$ (or $nCr$) represents the number of ways to choose $r$ unordered elements from $n$ distinct elements:
$$\binom{n}{r} = \frac{n!}{r! \times (n - r)!}$$

Under a prime modulus $P$, division is replaced by modular multiplicative inverse:
$$\binom{n}{r} \equiv n! \times (r!)^{-1} \times ((n - r)!)^{-1} \pmod P$$

---

## $\mathcal{O}(N)$ Precomputation Strategy

1. **Factorial Array:**
   $$fact[i] = (fact[i - 1] \times i) \pmod P \quad (fact[0] = 1)$$

2. **Inverse Factorial Array (The Backward Sweep Trick):**
   Instead of computing $(i!)^{-1}$ for every $i$ using $N \log P$ invocations of Fermat's Little Theorem:
   - Compute the inverse of the **largest** factorial $(N!)^{-1}$ once using FLT:
     $$invFact[N] = (fact[N])^{P - 2} \pmod P$$
   - Now sweep **backwards** from $N - 1$ down to $0$ using the identity:
     $$( (i - 1)! )^{-1} \equiv (i!)^{-1} \times i \pmod P$$
     $$invFact[i - 1] = (invFact[i] \times i) \pmod P$$

This computes all factorials and inverse factorials up to $N$ in strictly **$\mathcal{O}(N + \log P)$** time!

3. **$\mathcal{O}(1)$ Query:**
   ```cpp
   long long nCr(int n, int r) {
       if (r < 0 || r > n) return 0;
       return fact[n] * invFact[r] % P * invFact[n - r] % P;
   }
   ```

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Precomputation** | $\mathcal{O}(N + \log P)$ | $\mathcal{O}(N)$ for arrays |
| **Per Query** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |

