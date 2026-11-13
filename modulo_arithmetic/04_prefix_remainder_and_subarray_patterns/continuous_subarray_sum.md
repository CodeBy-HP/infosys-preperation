# Problem 10: Continuous Subarray Sum (LeetCode 523)

## Problem Statement

Given an integer array `nums` and an integer `k`, return `true` if `nums` has a **good subarray**, or `false` otherwise.

A **good subarray** is defined as:
1. Its length is **at least two** ($R - L + 1 \ge 2$).
2. The sum of the elements of the subarray is a **multiple of $k$** (i.e., $\sum_{i=L}^R \text{nums}[i] \equiv 0 \pmod k$).

---

## Examples

### Example 1
- **Input:** `nums = [23, 2, 4, 6, 7]`, `k = 6`
- **Output:** `true`
- **Explanation:** `[2, 4]` is a continuous subarray of size 2 whose sum is 6, which is a multiple of 6.

### Example 2
- **Input:** `nums = [23, 2, 6, 4, 7]`, `k = 6`
- **Output:** `true`
- **Explanation:** `[23, 2, 6, 4, 7]` has sum 42, which is a multiple of 6.

### Example 3
- **Input:** `nums = [23, 2, 6, 4, 7]`, `k = 13`
- **Output:** `false`

---

## Mathematical Principle: Earliest Index Remainder Hashing

Let $P[i]$ be the prefix sum up to index $i$ ($0$-indexed).
The sum of subarray $\text{nums}[j + 1 \dots i]$ is:
$$\text{sum} = P[i] - P[j]$$

This sum is divisible by $k$ if and only if:
$$P[i] \equiv P[j] \pmod k$$

To satisfy the length constraint $(i - j \ge 2)$:
- Store the **earliest index** at which each remainder $r = P[i] \pmod k$ was observed.
- Base initialization: `rem_to_index[0] = -1` (an imaginary empty prefix before index 0, allowing subarrays starting from index 0 of length $\ge 2$ to be detected).
- If the remainder was previously seen at index $j$, check if $(i - j \ge 2)$. If yes, return `true`.
- If not seen, insert `rem_to_index[rem] = i` (never overwrite existing indices to maximize distance $i - j$).

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(N)$ single pass |
| **Space Complexity** | $\mathcal{O}(\min(N, K))$ hash map size |

