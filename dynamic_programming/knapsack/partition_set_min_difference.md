# Partition Set Into 2 Subsets With Min Absolute Sum Difference

## Problem Overview
Given an array `arr` of $N$ non-negative integers, partition the array into two non-empty subsets $S_1$ and $S_2$ such that the absolute difference between their sums $|sum(S_1) - sum(S_2)|$ is minimized.
Return the minimum possible absolute difference.

---

## Invariant Formulation
Let total sum of the array be $S_{tot}$. If subset $S_1$ has sum $s_1$, then subset $S_2$ has sum $S_{tot} - s_1$.
The absolute difference is:
$$|s_1 - (S_{tot} - s_1)| = |2 s_1 - S_{tot}|$$
We only need to find all possible achievable subset sums $s_1 \in [0, \lfloor S_{tot} / 2 \rfloor]$.
The minimum difference is:
$$\min_{s_1 \in [0, \lfloor S_{tot} / 2 \rfloor], \; dp[N-1][s_1] == \text{true}} (S_{tot} - 2 s_1)$$

---

## Complexity Analysis
- **Space-Optimized Tabulation:**
  - **Time Complexity:** $O(N \times S_{tot})$
  - **Auxiliary Space:** $O(S_{tot})$

