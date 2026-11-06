# Number of Longest Increasing Subsequences

## Problem Overview
Given an integer array `nums`, return the **number of longest increasing subsequences**.
Notice that the sequence has to be **strictly increasing**.

---

## Dual DP Formulation (Length and Count)
We track two parallel arrays:
- `len[i]`: Length of the longest increasing subsequence ending at index $i$ (initialized to `1`).
- `cnt[i]`: Number of longest increasing subsequences of length `len[i]` ending at index $i$ (initialized to `1`).

For every pair $(j, i)$ with $0 \le j < i$ and $nums[j] < nums[i]$:
1. **Longer LIS found:** If $len[j] + 1 > len[i]$:
   $$len[i] = len[j] + 1, \quad cnt[i] = cnt[j]$$
2. **Alternative LIS with same length found:** If $len[j] + 1 == len[i]$:
   $$cnt[i] += cnt[j]$$

Finally, find the maximum length $\text{maxLen} = \max_{i} len[i]$.
The total number of LIS is:
$$\text{Total Count} = \sum_{i, \; len[i] == \text{maxLen}} cnt[i]$$

---

## Complexity Analysis
- **Time Complexity:** $O(N^2)$
- **Auxiliary Space:** $O(N)$

