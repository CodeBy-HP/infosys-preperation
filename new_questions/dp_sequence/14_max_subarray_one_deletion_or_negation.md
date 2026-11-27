# 14. Maximum Subarray Sum with One Deletion / Negation (LeetCode 1186 + Infosys Twist)

## Problem Statement

Given an array of integers `arr`, return the **maximum sum** for a **non-empty** subarray (contiguous elements) with at most **one deletion** (Variant A) or at most **one element negation** ($-arr[i]$) (Variant B).

Note that the subarray must remain **non-empty** after performing at most one deletion.

---

## Examples

### Example 1 (One Deletion — LeetCode 1186)
- **Input:** `arr = [1, -2, 0, 3]`
- **Output:** `4`
- **Explanation:** Choose `[1, -2, 0, 3]` and delete `-2` $\implies$ `[1, 0, 3]`, sum = `4`.

### Example 2 (One Deletion)
- **Input:** `arr = [1, -2, -2, 3]`
- **Output:** `3`
- **Explanation:** Just pick `[3]` (0 deletions).

### Example 3 (One Negation — Infosys Variant)
- **Input:** `arr = [1, -5, 4]`
- **Output:** `10`
- **Explanation:** Negate `-5` to `+5`, total sum = $1 + 5 + 4 = 10$.

---

## Constraints

- $1 \le \text{arr.length} \le 10^5$
- $-10^4 \le \text{arr}[i] \le 10^4$

---

## Pattern Insight: Two-State Kadane DP

Maintain two states ending at index `i`:
1. `noOp`: Max subarray sum ending at `i` with **0 operations** used (`max(arr[i], noOp + arr[i])`).
2. `oneOp`: Max subarray sum ending at `i` with **at most 1 operation** used:
   - **Deletion Variant:** Either delete `arr[i]` (`noOp` from `i-1`), or extend previous deleted subarray (`oneOp + arr[i]`):
     `oneOp = max(prevNoOp, oneOp + arr[i])`
   - **Negation Variant:** Either start/continue by negating `arr[i]` (`max(-arr[i], prevNoOp - arr[i])`), or extend earlier negated subarray (`oneOp + arr[i]`).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **O(1)-Space State Kadane** | $O(N)$ | $O(1)$ |
| **Prefix + Suffix Kadane Arrays** | $O(N)$ | $O(N)$ |
