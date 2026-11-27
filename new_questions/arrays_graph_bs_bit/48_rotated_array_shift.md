# 48. Rotated Array Shift / Rotate Array (LeetCode 189)

## Problem Statement

Given an integer array `nums`, rotate the array to the **right** by `k` steps, where `k` is non-negative.

Do this **in-place** with $O(1)$ extra space!

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3, 4, 5, 6, 7]`, `k = 3`
- **Output:** `[5, 6, 7, 1, 2, 3, 4]`
- **Explanation:**
  - Rotate 1 step right: `[7, 1, 2, 3, 4, 5, 6]`
  - Rotate 2 steps right: `[6, 7, 1, 2, 3, 4, 5]`
  - Rotate 3 steps right: `[5, 6, 7, 1, 2, 3, 4]`

### Example 2
- **Input:** `nums = [-1, -100, 3, 99]`, `k = 2`
- **Output:** `[3, 99, -1, -100]`

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-2^{31} \le \text{nums}[i] \le 2^{31} - 1$
- $0 \le k \le 10^5$

---

## Pattern Insight: Three-Reversal Trick

Let $k = k \pmod N$:
1. Reverse entire array `[0, N - 1]`.
2. Reverse first `k` elements `[0, k - 1]`.
3. Reverse remaining elements `[k, N - 1]`.

*(For **Left Rotation** by `k`: reverse `[0, k - 1]`, reverse `[k, N - 1]`, then reverse `[0, N - 1]`.)*

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Three-Reversal In-Place** | $O(N)$ | $O(1)$ |
| **Cyclic Replacements** | $O(N)$ | $O(1)$ |
