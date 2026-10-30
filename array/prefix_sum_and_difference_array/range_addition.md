# Problem 8: Range Addition / Difference Array (LeetCode 370)

## Problem Statement

You are given an integer `length` and an array `updates` where $\text{updates}[i] = [\text{startId}_i, \text{endId}_i, \text{inc}_i]$.

You have an array `arr` of length `length` with all zeros, and you have some operations to apply. Each operation increments all elements from index $\text{startId}_i$ to $\text{endId}_i$ (inclusive) by $\text{inc}_i$.

Return `arr` after applying all the updates.

---

## Examples

### Example 1
- **Input:** `length = 5, updates = [[1, 3, 2], [2, 4, 3], [0, 2, -2]]`
- **Output:** `[-2, 0, 3, 5, 3]`

---

## Constraints

- $1 \le \text{length} \le 10^5$
- $0 \le \text{updates.length} \le 10^4$
- $0 \le \text{startId}_i \le \text{endId}_i < \text{length}$
- $-1000 \le \text{inc}_i \le 1000$

---

## Paradigm: The Difference Array ($\Delta$)

Instead of updating every index in the range $[L, R]$ in $O(R - L + 1)$ time:
- Mark range start: $\text{diff}[L] += \text{inc}$.
- Mark range end cutoff: $\text{diff}[R + 1] -= \text{inc}$ (if $R + 1 < N$).
- After recording all updates in $O(1)$ each, compute the **prefix sum** of $\text{diff}$ in a single linear pass to recover the final array values!

$$\text{Total Time} = O(N + K)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Difference Array** | $O(N + K)$ | $O(N)$ | $O(1)$ per range update |
| **Naive Range Loop** | $O(N \times K)$ | $O(1)$ | Times out for large $K$ |
