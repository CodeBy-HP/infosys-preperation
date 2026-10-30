# Problem 22: Majority Element II (LeetCode 229)

## Problem Statement

Given an integer array of size $n$, find all elements that appear **more than $\lfloor n / 3 \rfloor$ times**.

---

## Examples

### Example 1
- **Input:** `nums = [3, 2, 3]`
- **Output:** `[3]`

### Example 2
- **Input:** `nums = [1]`
- **Output:** `[1]`

### Example 3
- **Input:** `nums = [1, 2]`
- **Output:** `[1, 2]`

---

## Constraints

- $1 \le \text{nums.length} \le 5 \times 10^4$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Pattern: Generalized Boyer-Moore with $\le 2$ Candidates

Mathematically, at most **two** distinct elements can have a frequency strictly greater than $\lfloor n / 3 \rfloor$:
1. Maintain two candidate variables `cand1`, `cand2` and their battle counts `count1`, `count2`.
2. First pass: elect the two strongest survivors.
3. Second pass: count exact occurrences of `cand1` and `cand2` to verify they strictly exceed $\lfloor n / 3 \rfloor$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Extended Boyer-Moore** | $O(N)$ | $O(1)$ |
