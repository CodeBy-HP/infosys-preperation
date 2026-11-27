# 35. Make Array Strictly Increasing with Index Divisibility (`arr[i] % (i+1) == 0`) (Infosys Greedy PYQ)

## Problem Statement

You are given an integer array `arr` of size `n`. In one operation, you may **increment** any element `arr[i]` by `1` (`arr[i] = arr[i] + 1`).

You want to transform `arr` such that:
1. The array becomes **strictly increasing**: `arr[0] < arr[1] < ... < arr[n - 1]`.
2. Every element satisfies the **1-based index divisibility condition**:
   $$\text{arr}[i] \pmod{(i + 1)} == 0 \quad \text{for all } 0 \le i < n$$

Return the **minimum total number of operations** required.

---

## Examples

### Example 1
- **Input:** `arr = [1, 3, 2]`
- **Output:** `5`
- **Explanation:**
  - `i = 0` (divisor 1): Keep `1` (ops = 0).
  - `i = 1` (divisor 2): Need `val >= 3`, `val > 1`, `val % 2 == 0` $\implies$ smallest is `4` (`+1` op).
  - `i = 2` (divisor 3): Need `val >= 2`, `val > 4`, `val % 3 == 0` $\implies$ smallest is `6` (`6 - 2 = 4` ops).
  - Total operations = $0 + 1 + 4 = 5$, resulting array = `[1, 4, 6]`.

### Example 2
- **Input:** `arr = [2, 4, 6]`
- **Output:** `0`
- **Explanation:** Already strictly increasing and `[2%1, 4%2, 6%3] == [0, 0, 0]`.

---

## Constraints

- $1 \le n \le 10^5$
- $1 \le \text{arr}[i] \le 10^9$

---

## Pattern Insight: Greedy Minimal Valid Multiple

Since we want the **minimum** total increments, making each prefix element as **small as possible** is always globally optimal (leaves maximum room for subsequent elements to avoid extra bumps!).
At index `i` (divisor $d = i + 1$):
1. Minimal lower bound: $L = \max(arr[i], \ prev + 1)$.
2. Smallest multiple of $d$ that is $\ge L$:
   $$\text{target} = \left\lceil \frac{L}{d} \right\rceil \times d = \left(\frac{L + d - 1}{d}\right) \times d$$
   *(When $L \le 0$, handle negative modulo carefully.)*
3. Add `target - arr[i]` to total operations and set `prev = target`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Greedy Minimal Multiple Sweep** | $O(N)$ | $O(1)$ |
