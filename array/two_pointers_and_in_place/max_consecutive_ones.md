# Problem 5: Max Consecutive Ones (LeetCode 485)

## Problem Statement

Given a binary array `nums`, return the maximum number of consecutive `1`'s in the array.

---

## Examples

### Example 1
- **Input:** `nums = [1, 1, 0, 1, 1, 1]`
- **Output:** `3`

### Example 2
- **Input:** `nums = [1, 0, 1, 1, 0, 1]`
- **Output:** `2`

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- `nums[i]` is either `0` or `1`.

---

## Fundamental Linear State Machine

Maintain running count:
- If `num == 1`: `currentCount++`, `maxCount = max(maxCount, currentCount)`.
- Else: reset `currentCount = 0`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Linear Scan** | $O(N)$ | $O(1)$ |
