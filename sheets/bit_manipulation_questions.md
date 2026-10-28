# Bit Manipulation: Questions & Problem Patterns Sheet

> A structured collection of classic and tricky bit manipulation questions, categorized by core patterns with intuition, mathematical formulations, edge cases, and clean implementations.

---

## Table of Contents
1. [Pattern 1: Bitwise Contribution (Column-by-Column)](#pattern-1-bitwise-contribution)
   - [Problem 1.1: Sum of XOR of All Pairs](#problem-11-sum-of-xor-of-all-pairs)
2. [Problem Template for Future Additions](#problem-template-for-future-additions)

---

## Pattern 1: Bitwise Contribution

> **Core Philosophy:**  
> When asked to compute sums involving bitwise operations (`XOR`, `AND`, `OR`) over all pairs or subarrays, **never evaluate pairs horizontally in $O(N^2)$**.  
> Instead, isolate each bit position independently and count set bits vertically in $O(N \times 31)$.

---

### Problem 1.1: Sum of XOR of All Pairs

#### 1. Problem Statement
Given an array `arr` of $n$ non-negative integers, calculate the sum of $(arr[i] \oplus arr[j])$ for all pairs $(i, j)$ such that $0 \le i < j < n$:

$$
\text{Total Sum} = \sum_{i=0}^{n-2} \sum_{j=i+1}^{n-1} (arr[i] \oplus arr[j])
$$

---

#### 2. Core Intuition & Logic
- **Horizontal approach ($O(N^2)$):** Checking all $\frac{n(n-1)}{2}$ pairs times out for $N > 10^4$.
- **Vertical approach ($O(31 \cdot N)$):** 
  - Look at each bit position $b$ from $0$ to $30$ independently.
  - A pair $(arr[i], arr[j])$ produces a **set bit ($1$) at position $b$ in $(arr[i] \oplus arr[j])$** if and only if **one number has $1$ and the other has $0$** at bit $b$.
  - If both numbers have $1$, $1 \oplus 1 = 0$.
  - If both numbers have $0$, $0 \oplus 0 = 0$.

---

#### 3. Mathematical Formula
For a fixed bit position $b$:
1. Let `set_count` = number of elements having the $b$-th bit set ($= 1$).
2. Let `unset_count` = $n - \text{set\_count}$ = number of elements having the $b$-th bit unset ($= 0$).
3. The number of valid pairs contributing $1$ at bit position $b$ is:

$$
\boxed{\text{Valid Pairs}_b = \text{set count} \times \text{unset count}}
$$

4. Positional weight of bit $b$ is $2^b$. Therefore, the contribution of bit $b$ to the overall sum is:

$$
\boxed{\text{Contribution}_b = (\text{set count} \times \text{unset count}) \times 2^b}
$$

5. Total answer across all 31 bits:

$$
\boxed{\text{Total Sum} = \sum_{b=0}^{30} \Big((\text{set count}_b \times \text{unset count}_b) \times 2^b\Big)}
$$

---

#### 4. Concrete Walkthrough Example
Let `arr = [1, 2, 3]` ($n = 3$):
- $1 = 001_2$
- $2 = 010_2$
- $3 = 011_2$

**Direct Pairwise XORs:**
- $(1 \oplus 2) = 3$
- $(1 \oplus 3) = 2$
- $(2 \oplus 3) = 1$
- **Total Sum** = $3 + 2 + 1 = 6$

**Using Bit Contribution:**
- **Bit 0 ($2^0 = 1$):**
  - Numbers with Bit 0 set: $1, 3 \implies \text{set count} = 2$
  - Numbers with Bit 0 unset: $2 \implies \text{unset count} = 1$
  - Contribution = $(2 \times 1) \times 2^0 = 2 \times 1 = 2$
- **Bit 1 ($2^1 = 2$):**
  - Numbers with Bit 1 set: $2, 3 \implies \text{set count} = 2$
  - Numbers with Bit 1 unset: $1 \implies \text{unset count} = 1$
  - Contribution = $(2 \times 1) \times 2^1 = 2 \times 2 = 4$
- **Bit 2 ($2^2 = 4$):**
  - Numbers with Bit 2 set: None $\implies \text{set count} = 0$
  - Contribution = $0$

$$
\text{Total Sum} = 2 + 4 + 0 = 6
$$

*(Both methods give the exact same result: 6)*

---

#### 5. C++ Implementation
```cpp
#include <bits/stdc++.h>
using namespace std;

long long sumXOROfAllPairs(const vector<int>& arr) {
    int n = arr.size();
    long long total_sum = 0;

    // Check each bit position from 0 to 30
    for (int b = 0; b < 31; ++b) {
        long long set_count = 0;
        
        for (int i = 0; i < n; ++i) {
            if ((arr[i] >> b) & 1) {
                set_count++;
            }
        }
        
        long long unset_count = n - set_count;
        long long pairs = set_count * unset_count;
        
        // Use 1LL to prevent 32-bit overflow on bit shift
        total_sum += pairs * (1LL << b);
    }

    return total_sum;
}
```

---

#### 6. Complexity Analysis
- **Time Complexity:** $O(31 \times N) = O(N)$ -- linear scan over the array for each of the 31 bits.
- **Space Complexity:** $O(1)$ -- auxiliary variables only.

---

#### 7. Critical Gotchas & Edge Cases
- **Integer Overflow:** `set_count * unset_count` can reach $\approx (5 \times 10^4)^2 = 2.5 \times 10^9$, which overflows a standard 32-bit signed `int`. Always use `long long`.
- **Bit Shift Overflow:** Always write `(1LL << b)` instead of `(1 << b)` when shifting by $\ge 31$ or accumulating into 64-bit integers.
- **Bit Precedence:** In `(arr[i] >> b) & 1`, the outer parentheses are mandatory because `>>` and `&` have lower precedence than arithmetic/comparison operators.

---

## Problem Template for Future Additions

```markdown
### Problem X.Y: [Problem Name]

#### 1. Problem Statement
- Brief description, input/output, and constraints.

#### 2. Core Intuition & Logic
- Brute force vs. optimized observation.
- Why bitwise properties apply here.

#### 3. Mathematical Formula / Trick
- Formulas, state transitions, or counting rules.

#### 4. C++ Implementation
- Clean, commented snippet.

#### 5. Complexity
- Time: $O(...)$
- Space: $O(...)$

#### 6. Critical Gotchas
- Overflows, edge cases, bit bounds.
```
