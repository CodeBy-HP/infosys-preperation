# Count Partitions with Given Difference

## Problem Overview
Given an array `arr` of $N$ non-negative integers and a difference $D$, count the number of partitions of the array into two subsets $S_1$ and $S_2$ such that:
$$sum(S_1) \ge sum(S_2) \quad \text{and} \quad sum(S_1) - sum(S_2) = D$$
Return the count modulo $10^9 + 7$.

---

## Mathematical Reduction
Let $S_{tot} = \sum arr[i]$.
We know:
$$S_1 + S_2 = S_{tot}$$
$$S_1 - S_2 = D$$
Adding both equations:
$$2 S_1 = S_{tot} + D \implies S_1 = \frac{S_{tot} + D}{2}$$

Thus, the problem **strictly reduces** to counting subsets with target sum $T = \frac{S_{tot} + D}{2}$.

### Feasibility Conditions
If any of these fail, return `0`:
1. $S_{tot} - D < 0$ (impossible for difference to exceed total sum)
2. $(S_{tot} + D) \pmod 2 \ne 0$ (must be an integer)

---

## Complexity Analysis
- **Time Complexity:** $O(N \times \frac{S_{tot} + D}{2})$
- **Auxiliary Space:** $O(\frac{S_{tot} + D}{2})$

