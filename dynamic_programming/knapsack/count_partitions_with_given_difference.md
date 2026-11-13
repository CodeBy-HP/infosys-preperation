# Count Partitions with Given Difference (GFG)

## Problem Statement

Given an array `arr` of $N$ non-negative integers and a difference $D$, count the number of partitions of the array into two subsets $S_1$ and $S_2$ such that:
$$sum(S_1) \ge sum(S_2) \quad \text{and} \quad sum(S_1) - sum(S_2) = D$$

Since the count may be very large, return the result modulo $10^9 + 7$.

---

## Examples

### Example 1:
```text
Input: arr = [5, 2, 6, 4], D = 3
Output: 1
Explanation:
Total sum = 5 + 2 + 6 + 4 = 17.
Target subset sum S1 = (17 + 3) / 2 = 10.
Subset with sum 10: {6, 4}.
S2 will have sum 17 - 10 = 7 ({5, 2}).
Difference: 10 - 7 = 3.
Only 1 such valid partition exists.
```

### Example 2:
```text
Input: arr = [1, 1, 1, 1], D = 0
Output: 6
Explanation:
Total sum = 4.
Target sum S1 = (4 + 0) / 2 = 2.
Number of ways to choose 2 items out of 4: C(4, 2) = 6.
```

### Example 3:
```text
Input: arr = [1, 2, 1], D = 3
Output: 0
Explanation:
Total sum = 4.
Target sum S1 = (4 + 3) / 2 = 7 / 2 = 3.5 (not an integer!).
No integer subset partition can have difference 3. Output is 0.
```

---

## Constraints

- $1 \le N \le 500$
- $0 \le D \le 2500$
- $0 \le arr[i] \le 50$

---

## Recurrence Formulation & Mathematical Reduction

### 1. Mathematical Derivation
Let $S_{tot} = \sum_{i=0}^{N-1} arr[i]$.
If the array is partitioned into $S_1$ and $S_2$:
1. $sum(S_1) + sum(S_2) = S_{tot}$
2. $sum(S_1) - sum(S_2) = D$

Adding (1) and (2):
$$2 \times sum(S_1) = S_{tot} + D \implies sum(S_1) = \frac{S_{tot} + D}{2}$$

Thus, the problem **strictly reduces** to finding the number of subsets in `arr` that sum to $target = \frac{S_{tot} + D}{2}$.

### 2. Edge Case Invariants (Early Exits)
A valid partition is mathematically impossible if:
1. $S_{tot} < D$: Difference cannot exceed the array's entire sum.
2. $(S_{tot} + D) \pmod 2 \ne 0$: Sum must be an even integer.

### 3. Handling Zeros
Because $arr[i] \ge 0$, zeros can either be included or excluded without affecting the sum.
At base case:
- If element is `0`, it can be included or excluded, yielding $2$ ways.
- $dp[0] = 1$ (for empty subset of positive elements).

### 4. 1D Space-Optimized DP
Iterate backwards from $target$ down to $num$:
$$dp[s] = (dp[s] + dp[s - num]) \pmod{10^9 + 7}$$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (2D DP)** | $O(N \times \text{target})$ | $O(N \times \text{target})$ |
| **Space-Optimized (1D DP)** | $O(N \times \text{target})$ | $O(\text{target})$ where $\text{target} \le \frac{S_{tot} + D}{2}$ |
