# Target Sum

## Problem Overview
You are given an integer array `nums` and an integer `target`.
You want to build an expression out of `nums` by adding one of the symbols `'+'` and `'-'` before each integer in `nums` and then concatenate all the integers.
Return the number of different expressions that evaluate to `target`.

---

## Reduction to Subset Difference
Suppose we assign `+` to elements in subset $P$ and `-` to elements in subset $N$:
$$sum(P) - sum(N) = \text{target}$$
$$sum(P) + sum(N) = \text{totalSum}$$
Adding both equations:
$$2 \times sum(P) = \text{totalSum} + \text{target} \implies sum(P) = \frac{\text{totalSum} + \text{target}}{2}$$

The problem reduces to counting subsets with target sum $S = \frac{\text{totalSum} + \text{target}}{2}$.

### Invariants & Guard Checks
1. $|\text{target}| > \text{totalSum} \implies$ impossible (return `0`).
2. $(\text{totalSum} + \text{target}) \pmod 2 \ne 0 \implies$ impossible (return `0`).

---

## Complexity Analysis
- **Space-Optimized Tabulation:**
  - **Time Complexity:** $O(N \times \frac{\text{totalSum} + \text{target}}{2})$
  - **Auxiliary Space:** $O(\frac{\text{totalSum} + \text{target}}{2})$

