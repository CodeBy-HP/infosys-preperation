# 43. Minimum Number of Operations to Make Array Empty (LeetCode 2870)

## Problem Statement

You are given a **0-indexed** array `nums` consisting of positive integers.

There are two types of operations that you can apply on the array any number of times:
1. Choose **two** elements with **equal** values and delete them from the array.
2. Choose **three** elements with **equal** values and delete them from the array.

Return the **minimum number of operations** required to make the array empty, or `-1` if it is not possible.

---

## Examples

### Example 1
- **Input:** `nums = [2, 3, 3, 2, 2, 4, 2, 3, 4]`
- **Output:** `4`
- **Explanation:**
  - `2` appears 4 times $\to$ `2 + 2` (2 ops)
  - `3` appears 3 times $\to$ `3` (1 op)
  - `4` appears 2 times $\to$ `2` (1 op)
  - Total = `4` operations.

### Example 2
- **Input:** `nums = [2, 1, 2, 2, 3, 3]`
- **Output:** `-1`
- **Explanation:** `1` appears once, which cannot be removed by groups of 2 or 3.

---

## Constraints

- $2 \le \text{nums.length} \le 10^5$
- $1 \le \text{nums}[i] \le 10^6$

---

## Mathematical Insight

Every integer count $c \ge 2$ can be expressed as $3x + 2y$!
- If $c == 1$: impossible $\implies$ return `-1`.
- Otherwise, we maximize triples (groups of 3) to minimize operations:
  $$\text{ops}(c) = \left\lceil \frac{c}{3} \right\rceil = \frac{c + 2}{3}$$
  Verify mod 3:
  - $c = 3k \implies k$ ops (`3` $\times k$)
  - $c = 3k + 1 \implies (k - 1)$ triples + two pairs = $k + 1$ ops (`(c + 2)/3`)
  - $c = 3k + 2 \implies k$ triples + one pair = $k + 1$ ops (`(c + 2)/3`)

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Frequency Map + Ceiling Math** | $O(N)$ | $O(N)$ |
