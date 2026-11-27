# 42. Equalize Temperature Regulators (Infosys OA PYQ)

## Problem Statement

You are given an integer array `temps` representing the current temperatures of `n` sequential temperature regulators.

You want to equalize all regulators to the exact same temperature using the **minimum number of operations**:
- **Variant A (Individual Increment Only):** In one operation, increase any single regulator's temperature by `+1` (decreasing is forbidden). Minimum operations = $\sum_{i=0}^{n-1} (\max(temps) - temps[i])$.
- **Variant B (Suffix/Prefix Range Increment — "Make Array Equal"):** In one operation, increase **all elements in a suffix/prefix or contiguous subarray** by `+1` so every regulator reaches the same final temperature!

Return the **minimum total operations** needed to equalize all regulators.

---

## Examples

### Example 1 (Variant A — Individual Increment Only)
- **Input:** `temps = [3, 2, 5, 2, 3]`
- **Output:** `10`
- **Explanation:** Target = $\max(temps) = 5$. Operations = $(5-3)+(5-2)+(5-5)+(5-2)+(5-3) = 2+3+0+3+2 = 10$.

### Example 2 (Variant B — Contiguous Subarray `+1` Increment to Match `max(temps)`)
- **Input:** `temps = [1, 3, 2]`
- **Output:** `3`
- **Explanation:** Target = `3`, deficits = `[2, 0, 1]`. Using subarray increments (`+1` on a range): `2` ops on `[0..0]` + `1` op on `[2..2]` = `3`.

---

## Constraints

- $1 \le n \le 10^5$
- $0 \le \text{temps}[i] \le 10^9$

---

## Pattern Insight

1. **Individual Increments:** Every regulator must reach at least `M = max(temps)`. Summing `(M - temps[i])` is optimal in **$O(N)$ time**.
2. **Contiguous Subarray `+1` Increments:** Convert `temps` to deficit array `d[i] = max(temps) - temps[i]`. By **LeetCode 1526 (Minimum Number of Increments on Subarrays to Form a Target Array)**, minimum range operations equals:
   $$d[0] + \sum_{i=1}^{n-1} \max(0, \ d[i] - d[i - 1])$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Single-Pass Max Deficit / Subarray Difference** | $O(N)$ | $O(1)$ |
