# Fenwick Tree / Binary Indexed Tree (BIT)

## Problem Statement

Given an array of $n$ elements, efficiently support:
1. **Point Update:** Add a value $\Delta$ to element at index $i$.
2. **Prefix Sum Query:** Return the sum of elements from index $1$ to index $i$ ($\sum_{j=1}^i \text{nums}[j]$).
3. **Range Sum Query:** Return the sum of elements between indices $L$ and $R$ ($\sum_{j=L}^R \text{nums}[j] = \text{prefix}(R) - \text{prefix}(L - 1)$).

All update and query operations must run in **$O(\log N)$ time** using only **$O(N)$ extra space** and lightweight, non-recursive, bitwise operations.

---

## The Core Bitwise Engine: Lowest Set Bit (LSB)

A Fenwick Tree organizes interval sums using the binary representation of indices.
Each index $i$ is responsible for storing the sum of the previous $2^k$ elements, where $2^k$ is the **Lowest Set Bit (LSB)** of $i$.

In two's complement arithmetic, the LSB is computed in $O(1)$ CPU cycles as:
$$\text{LSB}(i) = i \ \& \ (-i)$$

### Examples of LSB:
- $i = 10$ (binary `1010`): $10 \ \& \ (-10) = 2$ (binary `0010`). Responsible for $2$ elements ($[9, 10]$).
- $i = 12$ (binary `1100`): $12 \ \& \ (-12) = 4$ (binary `0100`). Responsible for $4$ elements ($[9, 12]$).
- $i = 8$ (binary `1000`): $8 \ \& \ (-8) = 8$ (binary `1000`). Responsible for $8$ elements ($[1, 8]$).

---

## Operations & Mechanics

### 1. Prefix Query (`query(i)`):
To compute the sum from $1$ to $i$, add `bit[i]` and **subtract the LSB** to jump backward to the preceding disjoint interval:
```cpp
int sum = 0;
while (i > 0) {
    sum += bit[i];
    i -= (i & -i); // Strip lowest set bit
}
```
*Example (`query(7)`):*
- Add `bit[7]` (binary `111`), subtract LSB $1 \implies i = 6$ (binary `110`).
- Add `bit[6]`, subtract LSB $2 \implies i = 4$ (binary `100`).
- Add `bit[4]`, subtract LSB $4 \implies i = 0$. Done in 3 jumps ($O(\log N)$)!

### 2. Point Update (`add(i, delta)`):
To update index $i$, add `delta` to `bit[i]` and **add the LSB** to cascade the update to every ancestor bucket responsible for $i$:
```cpp
while (i <= n) {
    bit[i] += delta;
    i += (i & -i); // Cascade forward
}
```

---

## Fenwick Tree vs. Segment Tree

| Feature | Fenwick Tree (BIT) | Segment Tree |
| :--- | :--- | :--- |
| **Code Length** | ~15 lines | ~60+ lines |
| **Memory** | $N + 1$ elements | $4N$ elements |
| **Recursion** | None (iterative while loop) | Deep recursion tree |
| **Constant Factor** | Extremely fast CPU cache | Slower due to branch misses |
| **Range Updates** | Requires difference array | Handled natively via Lazy tags |
| **Non-invertible Operations** | Hard for `min`/`max` | Natively supports `min`, `max`, GCD |

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Build Tree** | $O(N)$ linear build / $O(N \log N)$ | $N + 1$ array |
| **Point Update** | $O(\log N)$ | $O(1)$ |
| **Prefix Sum Query** | $O(\log N)$ | $O(1)$ |
| **Range Sum Query** | $O(\log N)$ | $O(1)$ |

