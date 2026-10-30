# Problem 15: Next Permutation (LeetCode 31)

## Problem Statement

A **permutation** of an array of integers is an arrangement of its members into a sequence or linear order.

The **next permutation** of an array of integers is the next lexicographically greater permutation of its integer. More formally, if all the permutations of the array are sorted in one container according to their lexicographical order, then the next permutation of that array is the permutation that follows it in the sorted container.

If such arrangement is not possible, the array must be rearranged as the lowest possible order (i.e., sorted in ascending order).

The replacement must be **in place** and use only constant extra memory.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3]`
- **Output:** `[1, 3, 2]`

### Example 2
- **Input:** `nums = [3, 2, 1]`
- **Output:** `[1, 2, 3]`

---

## 3-Step Pivot & Suffix Reversal Algorithm

1. **Find Pivot:** Find the first index $i$ from the right such that `nums[i] < nums[i + 1]`.
   - If no such $i$ exists, array is in reverse sorted order: simply reverse entire array.
2. **Find Successor:** Find the smallest element in suffix `nums[i + 1 ... n - 1]` strictly greater than `nums[i]`. (From the right, the first element with `nums[j] > nums[i]`).
3. **Swap & Reverse Suffix:**
   - Swap `nums[i]` and `nums[j]`.
   - Reverse the suffix from index $i + 1$ to $n - 1$ (which is in descending order, turning it into ascending order!).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Pivot Scan + Reverse** | $O(N)$ | $O(1)$ |
