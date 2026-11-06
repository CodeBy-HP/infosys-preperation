# Print Longest Increasing Subsequence (GFG)

## Problem Statement

Given an array `arr` of $N$ integers, find the length of the Longest Increasing Subsequence (LIS) and **reconstruct and return the actual elements** of the LIS in increasing order.

If there are multiple valid subsequences with the maximum length, returning **any of them** is acceptable.

---

## Examples

### Example 1:
```text
Input: arr = [10, 22, 9, 33, 21, 50, 41, 60, 80]
Output: [10, 22, 33, 50, 60, 80]
Explanation:
The longest increasing subsequence has length 6.
One valid subsequence is [10, 22, 33, 50, 60, 80].
Another valid answer could be [10, 22, 33, 41, 60, 80].
```

### Example 2:
```text
Input: arr = [0, 8, 4, 12, 2, 10, 6, 14]
Output: [0, 4, 10, 14]
Explanation:
Length of LIS is 4. One valid reconstruction is [0, 4, 10, 14] (or [0, 2, 6, 14]).
```

### Example 3:
```text
Input: arr = [5, 4, 3, 2, 1]
Output: [5]
Explanation:
Any single element constitutes a valid LIS of length 1.
```

---

## Constraints

- $1 \le N \le 1000$
- $1 \le arr[i] \le 10^5$

---

## Recurrence Formulation & Path Reconstruction

### 1. State Definition
Let $dp[i]$ represent the length of the longest strictly increasing subsequence ending at index $i$.
$$dp[i] = 1 + \max_{\substack{0 \le j < i \\ arr[j] < arr[i]}} dp[j]$$

### 2. Predecessor Back-Pointers
To reconstruct the exact subsequence without storing full arrays inside DP states:
- Initialize `parent[i] = i` for all $i \in [0, N - 1]$.
- Whenever an index $j < i$ improves $dp[i]$:
  $$\text{If } dp[j] + 1 > dp[i] \implies dp[i] = dp[j] + 1, \quad parent[i] = j$$

### 3. Reconstruction Algorithm
1. Locate the index `lastIndex` where $dp$ is maximized across the entire array.
2. Backtrack from `lastIndex` using the `parent` pointers:
   ```cpp
   vector<int> lis;
   int curr = lastIndex;
   while (parent[curr] != curr) {
       lis.push_back(arr[curr]);
       curr = parent[curr];
   }
   lis.push_back(arr[curr]); // Push the root element
   reverse(lis.begin(), lis.end());
   return lis;
   ```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation + Parent Pointers** | $O(N^2)$ DP + $O(\text{LIS})$ backtrack | $O(N)$ for $dp$ and $parent$ arrays |
