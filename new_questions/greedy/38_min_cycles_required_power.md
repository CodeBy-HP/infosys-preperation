# 38. Minimum Cycles to Generate Required Power (Infosys SP OA Exact PYQ)

## Problem Statement

You have `n` processing cores with power capacities given in an integer array `arr` of size `n`, and a required total power threshold `T`.

In each **cycle**, you must pick **exactly two unused cores** `(a, b)` to generate combined power:
- **Sum Power Mode:** `power(a, b) = a + b`
- **Difference / Product Pair Mode:** `power(a, b) = |a - b|` (or `a * b`).

Once a core is used in a cycle, it cannot be reused in any future cycle.

Return the **minimum number of cycles** needed to generate total power **at least `T`**. If it is impossible even after pairing as many cores as possible, return `-1`.

---

## Examples

### Example 1 (Sum Power Mode: `a + b`)
- **Input:** `arr = [3, 8, 2, 5, 10]`, `T = 20`
- **Output:** `2`
- **Explanation:** Sort descending: `[10, 8, 5, 3, 2]`.
  - Cycle 1: Pair `(10, 8)` $\implies 18$.
  - Cycle 2: Pair `(5, 3)` $\implies +8 = 26 \ge 20$.
  Minimum cycles = `2`.

### Example 2 (Impossible)
- **Input:** `arr = [1, 2, 3]`, `T = 10`
- **Output:** `-1`
- **Explanation:** At most 1 pair can be formed (3 cores total); max power = $3 + 2 = 5 < 10$.

### Example 3 (Absolute Difference Power Mode: `|a - b|`)
- **Input:** `arr = [1, 10, 2, 9]`, `T = 15`
- **Output:** `2`
- **Explanation:** Pair largest with smallest: `(10, 1)` $\to 9$, `(9, 2)` $\to 7$, sum = $16 \ge 15$ in `2` cycles.

---

## Constraints

- $1 \le n \le 10^5$
- $1 \le \text{arr}[i] \le 10^9$
- $1 \le T \le 10^{18}$

---

## Pattern Insight: Greedy Maximal Pair Extraction

To hit `T` in the minimum number of cycles:
1. **Sum / Product Mode (`a + b` or `a * b` with positive `arr[i]`):** Sort ascending and greedily pair the two largest remaining elements from the right (`arr[n-1], arr[n-2]`, then `arr[n-3], arr[n-4]`, ...).
2. **Absolute Difference Mode (`|a - b|`):** Sort ascending and greedily pair extremes via Two Pointers (`arr[r] - arr[l]`, `l++`, `r--`).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sorting + Greedy Pairing** | $O(N \log N)$ | $O(1)$ auxiliary |
