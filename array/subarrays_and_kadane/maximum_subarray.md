# Problem 13: Maximum Subarray (LeetCode 53 / Kadane's Algorithm)

## Problem Statement

Given an integer array `nums`, find the subarray with the largest sum, and return its sum.

---

## Examples

### Example 1
- **Input:** `nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4]`
- **Output:** `6`
- **Explanation:** The subarray `[4, -1, 2, 1]` has the largest sum 6.

### Example 2
- **Input:** `nums = [1]`
- **Output:** `1`

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-10^4 \le \text{nums}[i] \le 10^4$

---

## Kadane's Dynamic Programming Invariant

Let $\text{currentSum}$ be the maximum subarray sum ending at the current index:
$$\text{currentSum} = \max(\text{num}, \text{currentSum} + \text{num})$$
- If $\text{currentSum} < 0$, it is a net drag on any future subarray. Greedily restart fresh from the next element: `currentSum = max(0, currentSum)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Kadane's Algorithm** | $O(N)$ | $O(1)$ |
