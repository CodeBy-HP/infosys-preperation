# Partition Array for Maximum Sum

## Problem Overview
Given an integer array `arr`, partition the array into (contiguous) subarrays of length at most `k`. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning.

---

## Front Partitioning Formulation
Let $dp[i]$ be the maximum sum obtainable for the prefix of length $i$ ($arr[0 \dots i-1]$):
- **Base Case:** $dp[0] = 0$.
- **Transition:**
  Consider making the last partition of length $len \in [1, k]$ ending at index $i - 1$:
  $$\text{subarray} = arr[i - len \dots i - 1]$$
  Let $maxVal = \max(arr[i - len \dots i - 1])$.
  All $len$ elements in this subarray are replaced with $maxVal$, contributing $maxVal \times len$.
  $$dp[i] = \max_{1 \le len \le k, \; i - len \ge 0} \big(dp[i - len] + \maxVal \times len\big)$$

---

## Complexity Analysis
- **Time Complexity:** $O(N \cdot K)$ since each state looks back at most $K$ steps while tracking running max in $O(1)$.
- **Auxiliary Space:** $O(N)$ (or $O(K)$ sliding buffer).

