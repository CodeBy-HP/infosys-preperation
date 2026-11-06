# Longest Bitonic Subsequence

## Problem Overview
Given an array of positive integers `arr`, find the length of the **Longest Bitonic Subsequence**.
A sequence is called **bitonic** if it is first strictly increasing, and then strictly decreasing.
(Formally, there exists an index $k$ such that $x_0 < x_1 < \dots < x_k > x_{k+1} > \dots > x_m$).

---

## Dual LIS Formulation
1. **Forward LIS ($dp_1$):**
   $dp_1[i]$ = length of longest increasing subsequence ending at index $i$:
   $$dp_1[i] = 1 + \max_{0 \le j < i, \; arr[j] < arr[i]} dp_1[j]$$
2. **Backward LIS ($dp_2$):**
   $dp_2[i]$ = length of longest increasing subsequence starting at index $i$ (or decreasing subsequence starting at $i$):
   $$dp_2[i] = 1 + \max_{i < j < n, \; arr[j] < arr[i]} dp_2[j]$$
3. **Peak Combination:**
   Treating index $i$ as the bitonic peak:
   $$\text{Length}(i) = dp_1[i] + dp_2[i] - 1$$
   (The peak element $arr[i]$ is counted in both $dp_1[i]$ and $dp_2[i]$, so we subtract $1$).

The answer is $\max_{0 \le i < n} (dp_1[i] + dp_2[i] - 1)$.

---

## Complexity Analysis
- **Time Complexity:** $O(N^2)$ (or $O(N \log N)$ with binary search patience sort for both directions).
- **Auxiliary Space:** $O(N)$

