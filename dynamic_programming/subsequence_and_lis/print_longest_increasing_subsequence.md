# Print Longest Increasing Subsequence

## Problem Overview
Given an array `arr` of $N$ integers, not only find the length of the Longest Increasing Subsequence (LIS), but **reconstruct and return the actual elements** of the LIS in increasing order.
If multiple valid subsequences exist, returning any of them is acceptable.

---

## Reconstruction Formulation
In standard $O(N^2)$ LIS tabulation:
$$dp[i] = 1 + \max_{0 \le j < i, \; arr[j] < arr[i]} dp[j]$$
To reconstruct the path, maintain a `parent[i]` (back-pointer) array:
- When a strictly better predecessor $j$ is found ($dp[j] + 1 > dp[i]$), set `parent[i] = j`.
- Find the index `lastIndex` with the maximum $dp$ value.
- Backtrack from `lastIndex` using `parent` until the starting element (`parent[curr] == curr`), then reverse the collected sequence!

---

## Complexity Analysis
- **Time Complexity:** $O(N^2)$
- **Auxiliary Space:** $O(N)$ for $dp$ and $parent$ arrays.

