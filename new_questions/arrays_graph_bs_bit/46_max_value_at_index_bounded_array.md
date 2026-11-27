# 46. Maximum Value at a Given Index in a Bounded Array (LeetCode 1802)

## Problem Statement

You are given three positive integers: `n`, `index`, and `maxSum`. You want to construct an array `nums` (**0-indexed**) that satisfies the following conditions:
- `nums.length == n`
- `nums[i]` is a **positive integer** ($nums[i] \ge 1$) where $0 \le i < n$.
- `abs(nums[i] - nums[i+1]) <= 1` where $0 \le i < n - 1$.
- The sum of all elements of `nums` does not exceed `maxSum`.
- `nums[index]` is **maximized**.

Return `nums[index]` of the constructed array.

---

## Examples

### Example 1
- **Input:** `n = 4`, `index = 2`, `maxSum = 6`
- **Output:** `2`
- **Explanation:** `nums = [1, 1, 2, 1]` has sum $5 \le 6$ and `nums[2] = 2`.

### Example 2
- **Input:** `n = 6`, `index = 1`, `maxSum = 10`
- **Output:** `3`

---

## Constraints

- $1 \le n \le \text{maxSum} \le 10^9$
- $0 \le \text{index} < n$

---

## Pattern Insight: Binary Search on Answer + Arithmetic Series Geometry

If we set `nums[index] = x`, the **minimum possible sum** of a valid array slopes down by `1` on both left and right sides until hitting the floor value `1`:
- Left side has `leftLen = index` elements, decreasing from `x - 1`.
- Right side has `rightLen = n - index - 1` elements, decreasing from `x - 1`.
Using arithmetic progression sum helper `sideSum(peakMinus1, len)`, check feasibility `x + leftSum + rightSum <= maxSum` in **$O(1)$** per probe, achieving **$O(\log(\text{maxSum}))$ total time**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Binary Search on Peak Value** | $O(\log(\text{maxSum}))$ | $O(1)$ |
