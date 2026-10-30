# Problem 14: Maximum Product Subarray (LeetCode 152)

## Problem Statement

Given an integer array `nums`, find a subarray that has the largest product, and return the product.

---

## Examples

### Example 1
- **Input:** `nums = [2, 3, -2, 4]`
- **Output:** `6` (`[2, 3]`)

### Example 2
- **Input:** `nums = [-2, 0, -1]`
- **Output:** `0`

---

## Constraints

- $1 \le \text{nums.length} \le 2 \times 10^4$
- $-10 \le \text{nums}[i] \le 10$

---

## Dual Min/Max Tracking for Sign Flips

Unlike addition, multiplying two negative numbers creates a positive number! A large negative product can instantly flip into a large positive product:
- Maintain both `currMax` and `currMin`.
- When `nums[i] < 0`, swap `currMax` and `currMin`.
- Transitions:
  $$\text{currMax} = \max(\text{nums}[i], \text{currMax} \times \text{nums}[i])$$
  $$\text{currMin} = \min(\text{nums}[i], \text{currMin} \times \text{nums}[i])$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Dual Min/Max Dynamic Programming** | $O(N)$ | $O(1)$ |
