# Problem 2: Large Modular Multiplication (Binary Multiplication)

## Problem Statement

Given three 64-bit integers $a, b,$ and $m$ where:
$$0 \le a, b < m \le 10^{18}$$

Compute $(a \times b) \pmod m$ without causing 64-bit unsigned integer overflow.

---

## Why Standard `(a * b) % m` Fails

In standard 64-bit architectures, the maximum value of an `unsigned long long` is:
$$2^{64} - 1 \approx 1.84 \times 10^{19}$$

If $a = 10^{18}$ and $b = 10^{18}$, their true product is $a \times b = 10^{36}$.
Evaluating `a * b` wraps around silently due to modulo $2^{64}$, yielding a completely wrong result before `% m` is applied!

---

## Approach 1: GCC/Clang 128-bit Integer (`__int128`)

In modern competitive programming (GCC/Clang on 64-bit platforms), `__int128` can store values up to $\approx 3.4 \times 10^{38}$, which easily holds $10^{36}$:

```cpp
long long mulMod128(long long a, long long b, long long m) {
    return static_cast<long long>((static_cast<__int128>(a) * b) % m);
}
```
**Complexity:** $O(1)$ time, $O(1)$ space.

---

## Approach 2: Binary Multiplication (Russian Peasant / Double-and-Add)

Analogous to Binary Exponentiation (which converts multiplication to repeated squaring), **Binary Multiplication** decomposes multiplication into repeated additions and doubling:

$$a \times b = a \times \sum_{i} b_i 2^i$$

At each step:
- If $b$ is odd ($b \& 1$), add $a$ to `result`: `result = (result + a) % m`.
- Double $a$: `a = (a + a) % m`.
- Halve $b$: `b >>= 1`.

Because addition $(x + y) \pmod m$ never exceeds $2m \le 2 \times 10^{18} < 2^{63}-1$, no 64-bit overflow ever occurs!

**Complexity:** $O(\log b)$ time, $O(1)$ space.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Overflow Free? |
| :--- | :--- | :--- | :--- |
| **`__int128` Cast** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ | Yes (up to $10^{18}$) |
| **Binary Multiplication** | $\mathcal{O}(\log b)$ | $\mathcal{O}(1)$ | Yes (Universal) |

