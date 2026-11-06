# Largest Divisible Subset (LeetCode 368)

## Problem Statement

Given a set of **distinct** positive integers `nums`, return the largest subset `answer` such that every pair of elements `(answer[i], answer[j])` in this subset satisfies:
- `answer[i] % answer[j] == 0`, OR
- `answer[j] % answer[i] == 0`

If there are multiple solutions, return **any of them**.

---

## Examples

### Example 1:
```text
Input: nums = [1, 2, 3]
Output: [1, 2]
Explanation:
[1, 3] is also accepted since 3 % 1 == 0.
```

### Example 2:
```text
Input: nums = [1, 2, 4, 8]
Output: [1, 2, 4, 8]
Explanation:
Every pair satisfies the divisibility condition:
2 % 1 == 0, 4 % 2 == 0, 8 % 4 == 0, etc.
```

### Example 3:
```text
Input: nums = [3, 4, 16, 8]
Output: [4, 8, 16]
```

---

## Constraints

- `1 <= nums.length <= 1000`
- `1 <= nums[i] <= 2 * 10^9`
- All the integers in `nums` are **unique**.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Transitivity & Sorting Reduction
Divisibility is a transitive relation over sorted positive integers:
$$\text{If } a \mid b \text{ and } b \mid c \implies a \mid c$$
Therefore, if we sort `nums` in ascending order:
For any candidate $nums[i]$, if $nums[i] \pmod{nums[j]} == 0$ (where $j < i$), then $nums[i]$ is guaranteed to be divisible by **every** predecessor element in the subset ending at $nums[j]$!

This reduces the problem strictly to an **LIS variant**.

### 2. State Definition & Transition
- Sort `nums` in ascending order.
- Let $dp[i]$ denote the size of the largest divisible subset whose largest element is $nums[i]$.
- Transition:
  $$dp[i] = 1 + \max_{\substack{0 \le j < i \\ nums[i] \% nums[j] == 0}} dp[j]$$

### 3. Path Reconstruction
Maintain an array `parent[i]` to record which predecessor index $j$ yielded the maximum $dp[i]$:
- Find the index `maxIdx` where $dp[maxIdx]$ is maximized.
- Traverse backwards from `maxIdx` using `parent`, pushing elements into the result vector until `parent[curr] == curr`.
- Reverse the result vector.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Sort + LIS Tabulation** | $O(N \log N + N^2) = O(N^2)$ | $O(N)$ for $dp$ and $parent$ arrays |
