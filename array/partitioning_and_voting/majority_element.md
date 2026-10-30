# Problem 21: Majority Element (LeetCode 169)

## Problem Statement

Given an array `nums` of size $n$, return the **majority element**.

The majority element is the element that appears **more than $\lfloor n / 2 \rfloor$ times**. You may assume that the majority element always exists in the array.

**Follow-up:** Could you solve the problem in linear time and in $O(1)$ space?

---

## Examples

### Example 1
- **Input:** `nums = [3, 2, 3]`
- **Output:** `3`

### Example 2
- **Input:** `nums = [2, 2, 1, 1, 1, 2, 2]`
- **Output:** `2`

---

## Constraints

- $n == \text{nums.length}$
- $1 \le n \le 5 \times 10^4$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Boyer-Moore Voting Algorithm

Imagine each number is an army battling other numbers:
- If a candidate army encounters an identical ally, its strength increases: `count++`.
- If it encounters a different enemy number, both cancel out: `count--`.
- Since the majority element appears strictly more than $\lfloor n / 2 \rfloor$ times, even if all other numbers unite to eliminate it, the majority element will always be the last survivor!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Boyer-Moore Voting** | $O(N)$ | $O(1)$ |
