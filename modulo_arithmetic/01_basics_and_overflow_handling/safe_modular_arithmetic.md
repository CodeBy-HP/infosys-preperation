# Safe Modular Arithmetic & Overflow Avoidance

## Problem Statement

Implement a robust, production-grade Modular Arithmetic class / struct in C++ that supports:
1. **Modular Addition:** $(a + b) \pmod m$
2. **Modular Subtraction:** $(a - b) \pmod m$ (handling negative results safely)
3. **Modular Multiplication:** $(a \times b) \pmod m$ (avoiding 32-bit signed integer overflow)
4. **Negative Modulo Normalization:** Convert any negative or arbitrary integer into its canonical remainder $r \in [0, m - 1]$.

---

## The Pitfalls of Naive Implementations

### 1. Integer Overflow in Multiplication
If $a = 10^9$ and $b = 10^9$, then $a \times b = 10^{18}$.
In C++, a standard signed 32-bit integer `int` has a maximum value of $2^{31} - 1 \approx 2.14 \times 10^9$.
Executing `(a * b) % m` with `int` causes **undefined behavior / integer overflow** before the `%` operator is even evaluated!
- **Fix:** Cast at least one operand to `long long` before multiplying:
  ```cpp
  long long result = (1LL * a * b) % m;
  ```

### 2. The Negative Subtraction Bug
If $a \pmod m = 2$ and $b \pmod m = 5$, then $(a - b) = -3$.
In C++, `-3 % 5 = -3` (not `2`).
- **Fix:** Add $m$ before taking modulo:
  ```cpp
  int result = ((a - b) % m + m) % m;
  ```

---

## Safe Implementation Template

```cpp
template <long long MOD>
struct Mint {
    long long val;
    Mint(long long v = 0) {
        val = (v % MOD + MOD) % MOD;
    }

    Mint operator+(const Mint& o) const {
        long long res = val + o.val;
        if (res >= MOD) res -= MOD;
        return Mint(res);
    }

    Mint operator-(const Mint& o) const {
        long long res = val - o.val;
        if (res < 0) res += MOD;
        return Mint(res);
    }

    Mint operator*(const Mint& o) const {
        return Mint((val * o.val) % MOD);
    }
};
```

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Add / Subtract / Normalize** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |
| **Multiply** | $\mathcal{O}(1)$ | $\mathcal{O}(1)$ |

