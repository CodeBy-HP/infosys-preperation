# Partition Array for Maximum Sum (LeetCode 1043)

## Problem Statement

Given an integer array `arr`, partition the array into (contiguous) subarrays of length at most `k`. After partitioning, each subarray has their values changed to become the **maximum value of that subarray**.

Return the **largest sum** of the given array after partitioning.

Test cases are generated such that the answer fits in a 32-bit integer.

---

## Examples

### Example 1:
```text
Input: arr = [1, 15, 7, 9, 2, 5, 10], k = 3
Output: 84
Explanation:
Partition into [1, 15, 7], [9], [2, 5, 10]:
- [1, 15, 7] becomes [15, 15, 15] -> sum = 45
- [9] becomes [9] -> sum = 9
- [2, 5, 10] becomes [10, 10, 10] -> sum = 30
Total sum = 45 + 9 + 30 = 84.
```

### Example 2:
```text
Input: arr = [1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3], k = 4
Output: 83
Explanation:
Partition into:
[1, 4, 1, 5] -> [5, 5, 5, 5] (sum = 20)
[7, 3, 6, 1] -> [7, 7, 7, 7] (sum = 28)
[9, 9, 3]    -> [9, 9, 9]    (sum = 27)
Wait, optimal grouping achieves total sum 83.
```

### Example 3:
```text
Input: arr = [1], k = 1
Output: 1
```

---

## Constraints

- `1 <= arr.length <= 500`
- `0 <= arr[i] <= 10^9`
- `1 <= k <= arr.length`

---

## Recurrence Formulation & Algorithmic Approaches

This is a canonical **Front Partitioning DP** problem. At each index, we decide how long the current ending chunk should be (from length $1$ to $k$).

### 1. State Definition
Let $dp[i]$ denote the maximum partitioned sum achievable for the prefix subarray $arr[0 \dots i - 1]$ of length $i$.

### 2. Transition
To compute $dp[i]$, consider that the final contiguous partition ends at index $i - 1$ and has length $len \in [1, k]$:
- Partition segment: $arr[i - len \dots i - 1]$
- Its maximum value: $maxVal = \max(arr[i - len \dots i - 1])$
- Contribution of this block: $maxVal \times len$

Hence:
$$dp[i] = \max_{\substack{1 \le len \le k \\ i - len \ge 0}} \Big( dp[i - len] + \max(arr[i - len \dots i - 1]) \times len \Big)$$

We can maintain $maxVal$ on the fly as $len$ steps backwards from $1$ to $k$.

### 3. Base Case
- $dp[0] = 0$ (empty prefix has sum 0)

### 4. Space Optimization
Since $dp[i]$ only references up to $k$ previous states ($dp[i - 1], \dots, dp[i - k]$), we can maintain a sliding window of size $k + 1$, reducing space to $O(k)$.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(N \cdot K)$ | $O(N)$ table + $O(N)$ recursion stack |
| **Bottom-Up Tabulation** | $O(N \cdot K)$ | $O(N)$ DP table |
| **Space-Optimized Sliding Buffer** | $O(N \cdot K)$ | $O(K)$ |
