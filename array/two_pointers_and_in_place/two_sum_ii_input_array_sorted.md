# Problem 1: Two Sum II - Input Array Is Sorted (LeetCode 167)

## Problem Statement

Given a **1-indexed** array of integers `numbers` that is already **sorted in non-decreasing order**, find two numbers such that they add up to a specific `target` number.

Return the indices of the two numbers, `index1` and `index2`, added by one as an integer array `[index1, index2]` of length 2.

You may not use the same element twice. Your solution must use only **$O(1)$ extra space**.

---

## Examples

### Example 1
- **Input:** `numbers = [2, 7, 11, 15], target = 9`
- **Output:** `[1, 2]`
- **Explanation:** The sum of 2 and 7 is 9. Therefore, `index1 = 1`, `index2 = 2`. We return `[1, 2]`.

### Example 2
- **Input:** `numbers = [2, 3, 4], target = 6`
- **Output:** `[1, 3]`

---

## Constraints

- $2 \le \text{numbers.length} \le 3 \times 10^4$
- $-1000 \le \text{numbers}[i] \le 1000$
- `numbers` is sorted in non-decreasing order.
- $-1000 \le \text{target} \le 1000$
- The tests are generated such that there is **exactly one solution**.

---

## Pattern: Two-Pointer Convergent Scan

Since the array is sorted monotonically:
- Initialize `left = 0`, `right = n - 1`.
- Compute `sum = numbers[left] + numbers[right]`.
- If `sum == target`: found! Return `{left + 1, right + 1}`.
- If `sum < target`: any element paired with `numbers[left]` will be $\le sum < target$, so `left` cannot be part of the solution: advance `left++`.
- If `sum > target`: symmetrically, `right` cannot be part of the solution: decrement `right--`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Two-Pointer Convergent Scan** | $O(N)$ | $O(1)$ |
