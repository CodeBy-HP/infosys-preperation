# Problem 16: Product of Array Except Self (LeetCode 238)

## Problem Statement

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in **$O(n)$ time** and without using the **division operator**.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 3, 4]`
- **Output:** `[24, 12, 8, 6]`

---

## Constraints

- $2 \le \text{nums.length} \le 10^5$
- $-30 \le \text{nums}[i] \le 30$

---

## Prefix & Suffix Sweep in $O(1)$ Extra Space

$$\text{answer}[i] = \text{prefixProduct}(0 \dots i - 1) \times \text{suffixProduct}(i + 1 \dots n - 1)$$
1. **Pass 1 (Left to Right):** Populate `answer[i]` with the prefix product up to $i - 1$.
2. **Pass 2 (Right to Left):** Maintain running `suffixProduct = 1`. Multiply `answer[i] *= suffixProduct` and update `suffixProduct *= nums[i]`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Two-Pass Prefix/Suffix** | $O(N)$ | $O(1)$ extra (ignoring return array) |
