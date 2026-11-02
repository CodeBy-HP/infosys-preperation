# Linear Basis: Gaussian Elimination over GF(2)

## Problem Statement
Given an array of $N$ non-negative 64-bit integers, support the following queries in $O(64)$ time:
1. **Insert:** Insert a new number into the vector space.
2. **Maximum Subset XOR:** Find the maximum XOR sum attainable by picking any subset of numbers.
3. **Query Target:** Check if a given number $x$ can be represented as the XOR sum of some subset.
4. **Minimum Non-Zero XOR:** Find the minimum non-zero XOR sum of a subset.

### Constraints:
- $1 \le N \le 10^5$
- $0 \le arr[i] \le 10^{18}$

---

## Pattern Insight: Vector Space Basis over $\mathbb{F}_2$
- Every integer can be viewed as a 64-dimensional vector over the finite field $\mathbb{F}_2$ (where addition is bitwise XOR $\oplus$).
- Any set of numbers can be represented by a **Basis** of at most 64 linearly independent vectors.
- **Basis Structure:**
  - An array `basis[64]`, where `basis[i]` has its highest set bit (MSB) strictly at position $i$.
- **Insertion Algorithm ($O(64)$):**
  - For $i = 63$ down to 0:
    - If the $i$-th bit of $x$ is 0, continue.
    - If `basis[i]` is empty ($0$), set `basis[i] = x` and break!
    - Otherwise, reduce $x = x \oplus basis[i]$.
- **Maximum Subset XOR Query ($O(64)$):**
  - Start with `ans = 0`.
  - For $i = 63$ down to 0:
    - If `(ans ^ basis[i]) > ans`, update `ans ^= basis[i]`.
  - This greedy choice is guaranteed to be optimal because `basis[i]` is the only basis element that can set bit $i$ without disturbing any higher bits!

---

## Complexity
- **Time Complexity:**
  - Insertion: $O(64) = O(1)$ per number $\to O(64 N)$ for array.
  - Max XOR Query: $O(64) = O(1)$.
- **Space Complexity:** $O(64) = O(1)$ fixed memory.
