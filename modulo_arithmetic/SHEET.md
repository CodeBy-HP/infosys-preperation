# Modulo Arithmetic Master Roadmap, Theory & Problem Sheet

Welcome to the definitive guide on **Modulo Arithmetic in Competitive Programming and Technical Interviews**. Modulo arithmetic is the mathematical backbone of combinatorics, dynamic programming, number theory, hashing, and cryptography.

---

## 📐 1. Mathematical Foundations & Formulations

### 1.1 The Definition of Congruence
Two integers $a$ and $b$ are said to be **congruent modulo $m$** (written as $a \equiv b \pmod m$) if their difference $(a - b)$ is an integer multiple of $m$:
$$a \equiv b \pmod m \iff m \mid (a - b) \iff a = k \cdot m + b \quad (k \in \mathbb{Z})$$

Equivalently, under the Division Theorem:
$$a = q \cdot m + r \quad \text{where } 0 \le r < m$$
Here, $r$ is the canonical remainder ($a \pmod m$).

---

### 1.2 The Negative Modulo Trap in C++ / Java
In mathematics, the remainder $r$ is **strictly non-negative**: $0 \le r < m$.
However, in C, C++, and Java, the `%` operator calculates the **truncated remainder** (retaining the sign of the dividend):
$$-7 \% 5 = -2 \quad (\text{in C++ and Java})$$
In mathematics:
$$-7 = (-2) \times 5 + 3 \implies -7 \equiv 3 \pmod 5$$

#### ⚠️ The Universal Negative Modulo Fix
To always guarantee a valid non-negative remainder in $[0, m - 1]$:
```cpp
int rem = ((a % m) + m) % m;
```
*Why this works:* If `a % m` is negative (in $[-m + 1, -1]$), adding $m$ shifts it into $[1, m - 1]$, and the second `% m` leaves positive remainders unchanged.

---

### 1.3 Fundamental Algebraic Properties

1. **Addition:**
   $$(a + b) \pmod m = ((a \pmod m) + (b \pmod m)) \pmod m$$
2. **Subtraction:**
   $$(a - b) \pmod m = ((a \pmod m) - (b \pmod m) + m) \pmod m$$
   *(Adding $m$ prevents negative intermediary results).*
3. **Multiplication:**
   $$(a \times b) \pmod m = ((a \pmod m) \times (b \pmod m)) \pmod m$$
   *Overflow rule:* In C++, if $a, b \approx 10^9$, their product is $10^{18}$, which overflows a 32-bit signed `int` ($2 \times 10^9$). Always cast to `long long`:
   ```cpp
   long long prod = (1LL * (a % m) * (b % m)) % m;
   ```
4. **Exponentiation:**
   $$(a^b) \pmod m = (a \pmod m)^b \pmod m$$

---

## ⚡ 2. The Division Problem & Modular Multiplicative Inverse

### 2.1 Why Division Cannot Be Performed Directly
Unlike addition and multiplication, division **does not distribute** over modulo:
$$\frac{a}{b} \pmod m \ne \frac{a \pmod m}{b \pmod m} \pmod m$$
*Counterexample:* $\frac{12}{3} \pmod 4 = 4 \pmod 4 = 0$.
However, $\frac{12 \pmod 4}{3 \pmod 4} = \frac{0}{3} = 0$, but $\frac{14}{2} \pmod 4 = 7 \pmod 4 = 3$, whereas $\frac{14 \pmod 4}{2 \pmod 4} = \frac{2}{2} = 1 \ne 3$.

To divide $a$ by $b$ modulo $m$, we multiply $a$ by the **Modular Multiplicative Inverse** of $b$, denoted $b^{-1}$:
$$\frac{a}{b} \equiv a \cdot b^{-1} \pmod m$$
where $b^{-1}$ is the unique integer in $[1, m - 1]$ such that:
$$b \cdot b^{-1} \equiv 1 \pmod m$$

**Existence Condition:** $b^{-1} \pmod m$ exists **if and only if** $\gcd(b, m) = 1$ ($b$ and $m$ are coprime).

---

### 2.2 Derivation 1: Fermat's Little Theorem (FLT)
When the modulus $m = p$ is a **prime number**:

> **Fermat's Little Theorem:**
> If $p$ is prime and $\gcd(b, p) = 1$, then:
> $$b^{p - 1} \equiv 1 \pmod p$$

Multiplying both sides by $b^{-1}$:
$$b^{p - 2} \cdot b \cdot b^{-1} \equiv 1 \cdot b^{-1} \pmod p$$
$$b^{-1} \equiv b^{p - 2} \pmod p$$

Thus, modular inverse under a prime modulus $p$ is calculated via **Binary Exponentiation** in $O(\log p)$ time:
```cpp
long long modInverse(long long b, long long p) {
    return power(b, p - 2, p); // power computes (b^(p-2)) % p
}
```

---

### 2.3 Derivation 2: Extended Euclidean Algorithm (When Modulus is Not Prime)
If $m$ is composite but $\gcd(b, m) = 1$, FLT fails. We invoke **Bézout's Identity**:
$$b \cdot x + m \cdot y = \gcd(b, m) = 1$$
Taking both sides modulo $m$:
$$b \cdot x + m \cdot y \equiv 1 \pmod m \implies b \cdot x \equiv 1 \pmod m$$
Therefore, the Bézout coefficient $x$ is the modular inverse $b^{-1} \pmod m$!

The Extended Euclidean Algorithm computes $x$ in $O(\log(\min(b, m)))$ steps.

---

### 2.4 Derivation 3: Linear Time Inverses for $1 \dots N$ in $O(N)$
To compute inverses of all numbers from $1$ to $N$ modulo a prime $p$ without doing $N \log p$ computations:

Let $p = k \cdot i + r$, where $k = \lfloor p / i \rfloor$ and $r = p \pmod i$.
$$k \cdot i + r \equiv 0 \pmod p$$
$$r \equiv -k \cdot i \pmod p$$
Multiply both sides by $i^{-1} \cdot r^{-1}$:
$$i^{-1} \equiv -k \cdot r^{-1} \pmod p$$
Substitute $k = \lfloor p / i \rfloor$ and $r = p \pmod i$:
$$i^{-1} \equiv -\lfloor p / i \rfloor \cdot (p \pmod i)^{-1} \pmod p$$
Adding $p$ to prevent negative results:
$$inv[i] = \Big(p - \lfloor p / i \rfloor \Big) \times inv[p \pmod i] \pmod p$$
With base case $inv[1] = 1$, this enables $O(N)$ total precomputation!

---

## 🚀 3. Modulo Invariant Patterns in DSA

```
                         MODULO ARITHMETIC IN DSA
                                     │
         ┌───────────────────────────┼───────────────────────────┐
         ▼                           ▼                           ▼
Prefix Remainder Hashing     Binary & Matrix Power      Combinatorics & Inverses
- Subarray Sum % K == 0      - O(log N) Fast Power      - nCr % P via Factorial Inv
- Check Divisible Pairs      - Matrix DP Recurrence     - Lucas' Theorem (Huge N)
- Rolling Hash (Rabin-Karp)  - Euler's Totient Power    - Catalan Numbers % P
```

---

## 📚 Master Problem Roadmap

### 1. Basics & Overflow Handling
*Focus: Negative modulo, large product prevention without overflow, and safe modular arithmetic.*
* **[Problem 1: Safe Modular Arithmetic & Overflow Avoidance](01_basics_and_overflow_handling/safe_modular_arithmetic.md)** ([C++ Code](01_basics_and_overflow_handling/safe_modular_arithmetic.cpp)): Complete framework for modular addition, subtraction with $+M$, and multiplication.
* **[Problem 2: Large Modular Multiplication (Binary Multiplication)](01_basics_and_overflow_handling/large_modular_multiplication.md)** ([C++ Code](01_basics_and_overflow_handling/large_modular_multiplication.cpp)): Multiplying two $10^{18}$ numbers modulo $10^{18}$ without 64-bit overflow using Russian Peasant bit-doubling and `__int128`.

---

### 2. Modular Exponentiation & Power
*Focus: Binary exponentiation in $O(\log N)$, large power sequences, and Euler's Totient reduction.*
* **[Problem 3: Binary Exponentiation (Pow(x, n) % mod)](02_modular_exponentiation_and_power/binary_exponentiation.md)** ([C++ Code](02_modular_exponentiation_and_power/binary_exponentiation.cpp)): Iterative bitwise fast power handling negative exponents and large bounds in $O(\log n)$.
* **[Problem 4: Super Pow (Euler's Totient Theorem)](02_modular_exponentiation_and_power/super_pow.md)** ([C++ Code](02_modular_exponentiation_and_power/super_pow.cpp)): Computing $a^b \pmod{1337}$ where $b$ is an array of digits via Totient property $\phi(1337) = 1140$.
* **[Problem 5: Count Good Numbers](02_modular_exponentiation_and_power/count_good_numbers.md)** ([C++ Code](02_modular_exponentiation_and_power/count_good_numbers.cpp)): Permutations of alternating even and prime digit slots up to $N = 10^{15}$ via modular power.

---

### 3. Modular Inverse & Division
*Focus: Fermat's Little Theorem, Extended Euclidean algorithm, and $O(N)$ linear inverses.*
* **[Problem 6: Modular Multiplicative Inverse (FLT & Extended GCD)](03_modular_inverse_and_division/modular_multiplicative_inverse.md)** ([C++ Code](03_modular_inverse_and_division/modular_multiplicative_inverse.cpp)): Implementation of both FLT for primes and Extended Euclidean for composite moduli.
* **[Problem 7: Linear Sieve Modular Inverses in O(N)](03_modular_inverse_and_division/linear_modular_inverses.md)** ([C++ Code](03_modular_inverse_and_division/linear_modular_inverses.cpp)): Precomputing inverses of all numbers from $1$ to $N$ in strictly $O(N)$ linear time.
* **[Problem 8: Fraction to Recurring Decimal](03_modular_inverse_and_division/fraction_to_recurring_decimal.md)** ([C++ Code](03_modular_inverse_and_division/fraction_to_recurring_decimal.cpp)): Modulo division tracking remainder cycles using hash maps to isolate repeating fractional sequences.

---

### 4. Prefix Remainder & Subarray Patterns
*Focus: Remainder frequency hashing, modulo complements, and divisibility guarantees.*
* **[Problem 9: Subarray Sums Divisible by K](04_prefix_remainder_and_subarray_patterns/subarray_sums_divisible_by_k.md)** ([C++ Code](04_prefix_remainder_and_subarray_patterns/subarray_sums_divisible_by_k.cpp)): Remainder congruence $P[R] \equiv P[L-1] \pmod K$ with negative remainder normalization in $O(N)$.
* **[Problem 10: Continuous Subarray Sum](04_prefix_remainder_and_subarray_patterns/continuous_subarray_sum.md)** ([C++ Code](04_prefix_remainder_and_subarray_patterns/continuous_subarray_sum.cpp)): Earliest seen remainder index tracking enforcing subarray length $\ge 2$.
* **[Problem 11: Make Sum Divisible by P](04_prefix_remainder_and_subarray_patterns/make_sum_divisible_by_p.md)** ([C++ Code](04_prefix_remainder_and_subarray_patterns/make_sum_divisible_by_p.cpp)): Finding the minimal subarray removal to satisfy $(S - \text{sub}) \equiv 0 \pmod p$.
* **[Problem 12: Check If Array Pairs Are Divisible by K](04_prefix_remainder_and_subarray_patterns/check_if_array_pairs_divisible_by_k.md)** ([C++ Code](04_prefix_remainder_and_subarray_patterns/check_if_array_pairs_divisible_by_k.cpp)): Remainder pairing condition: `count[r] == count[k - r]` and even pairing for `r == 0`.

---

### 5. Combinatorics & Factorials Modulo $P$
*Focus: Factorial precomputation, $O(1)$ binomial coefficients, and Lucas' Theorem for huge $N$.*
* **[Problem 13: Combinations nCr Modulo Prime](05_combinatorics_and_factorials_modulo_p/combinations_ncr_modulo_prime.md)** ([C++ Code](05_combinatorics_and_factorials_modulo_p/combinations_ncr_modulo_prime.cpp)): $O(N)$ factorial & inverse factorial precomputations yielding $O(1)$ query time for $\binom{n}{r} \pmod{10^9+7}$.
* **[Problem 14: Lucas' Theorem for Huge N](05_combinatorics_and_factorials_modulo_p/lucas_theorem.md)** ([C++ Code](05_combinatorics_and_factorials_modulo_p/lucas_theorem.cpp)): Base-$p$ digit expansion evaluating $\binom{n}{r} \pmod p$ when $N, R \le 10^{18}$ and $p$ is a small prime.
* **[Problem 15: Number of Ways to Reorder Array for Same BST](05_combinatorics_and_factorials_modulo_p/number_of_ways_reorder_same_bst.md)** ([C++ Code](05_combinatorics_and_factorials_modulo_p/number_of_ways_reorder_same_bst.cpp)): Combining subtree interleaving combinations with modular inverse arithmetic.

---

### 6. Matrix Exponentiation
*Focus: Transforming linear recurrences and graph transitions into $O(K^3 \log N)$ matrix powers.*
* **[Problem 16: N-th Fibonacci Number via Matrix Exponentiation](06_matrix_exponentiation/fibonacci_matrix_exponentiation.md)** ([C++ Code](06_matrix_exponentiation/fibonacci_matrix_exponentiation.cpp)): Computing $F_N \pmod{10^9+7}$ for $N \le 10^{18}$ in $O(\log N)$ time.
* **[Problem 17: Climbing Stairs with K Steps (General Linear Recurrence)](06_matrix_exponentiation/climbing_stairs_k_steps_matrix_expo.md)** ([C++ Code](06_matrix_exponentiation/climbing_stairs_k_steps_matrix_expo.cpp)): Constructing companion transition matrices for generalized $K$-step linear recurrences.
* **[Problem 18: Count Paths of Length K in Directed Graph](06_matrix_exponentiation/count_paths_length_k_graph.md)** ([C++ Code](06_matrix_exponentiation/count_paths_length_k_graph.cpp)): Transition adjacency matrix powering to find paths of exact length $K$ modulo $M$.

---

### 7. Advanced Modulo Theorems & Cryptography
*Focus: Chinese Remainder Theorem, polynomial rolling hash, and Baby-Step Giant-Step discrete log.*
* **[Problem 19: Chinese Remainder Theorem (CRT)](07_advanced_theorems_crt_and_hash/chinese_remainder_theorem.md)** ([C++ Code](07_advanced_theorems_crt_and_hash/chinese_remainder_theorem.cpp)): Reconstructing unique $x \pmod{\prod m_i}$ from coprime congruence equations.
* **[Problem 20: Rabin-Karp String Matching (Double Polynomial Rolling Hash)](07_advanced_theorems_crt_and_hash/rabin_karp_string_matching.md)** ([C++ Code](07_advanced_theorems_crt_and_hash/rabin_karp_string_matching.cpp)): Dual modulo rolling hash ($10^9+7$ and $10^9+9$) eliminating hash collisions in $O(N + M)$ string search.
* **[Problem 21: Baby-Step Giant-Step (Discrete Logarithm)](07_advanced_theorems_crt_and_hash/baby_step_giant_step.md)** ([C++ Code](07_advanced_theorems_crt_and_hash/baby_step_giant_step.cpp)): Solving $a^x \equiv b \pmod m$ in $O(\sqrt{m})$ time using meet-in-the-middle hash matching.

