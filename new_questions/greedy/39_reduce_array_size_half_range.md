# 39. Reduce Array Size to Half — Contiguous Value Range Variant (Infosys SP OA Exact PYQ)

## Problem Statement

You are given an integer array `arr` of length `N`.

Unlike the standard LeetCode 1338 problem where you remove any arbitrary set of distinct integers, in this variant you must choose a **single contiguous integer range `[X, Y]`** ($X \le Y$) and remove **every element** in `arr` whose value lies inclusively inside `[X, Y]` (i.e., $X \le arr[i] \le Y$).

Find the **minimum possible range length** `Y - X + 1` (number of integers in `[X, Y]`) such that at least half of the array elements ($\ge \lceil N / 2 \rceil$) are removed!

*(Standard LeetCode 1338 version — minimum number of distinct values to remove — is also included for completeness.)*

---

## Examples

### Example 1 (Range Variant — Infosys PYQ)
- **Input:** `arr = [3, 3, 3, 5, 5, 5, 2, 2, 7, 7]` ($N = 10$, need $\ge 5$ removed)
- **Output:** `3`
- **Explanation:**
  - Pick `[2, 3]`: removes `2` (2 times) and `3` (3 times) = $5 \ge 5$ elements! Range length = $3 - 2 + 1 = 2$!
  - Let's double check: `[2, 3]` removes `2, 2, 3, 3, 3` (5 elements) $\implies$ range length is `2` (`3 - 2 + 1 = 2`).
  - No single value has frequency $\ge 5$ (max freq is 3). So minimum range length is `2`.

### Example 2 (Range Variant)
- **Input:** `arr = [1, 1, 1, 1, 2]` ($N = 5$, need $\ge 3$ removed)
- **Output:** `1`
- **Explanation:** Pick `[1, 1]`, removes 4 elements $\ge 3$, range length = `1`.

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le \text{arr}[i] \le 10^9$

---

## Pattern Insight: Sorted Array Sliding Window (`r - l + 1 >= ceil(N / 2)`)

Wait: Look at how simple and beautiful the Range Variant becomes when `arr` is **sorted**!
Any contiguous value range `[X, Y]` that removes at least `K = (N + 1) / 2` elements simply covers a **contiguous subarray of length `K`** in the sorted array!
Wait — verify that!
- Suppose `arr` is sorted ascending: $a_0 \le a_1 \le \dots \le a_{N-1}$.
- To cover at least `K` elements with minimum value span `Y - X + 1`, we should pick `[X, Y] = [a[i], a[i + K - 1]]`!
- Therefore, the optimal answer is literally:
  $$\min_{0 \le i \le N - K} \big(a[i + K - 1] - a[i] + 1\big)$$
*(Note: If two endpoints have duplicates, `[a[i], a[i + K - 1]]` automatically includes all duplicates inside `[X, Y]`, so $\ge K$ elements are always removed!)*

---

## Complexity Analysis

| Variant | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Range Variant (Sort + Fixed-Size Window)** | $O(N \log N)$ | $O(1)$ |
| **Standard LeetCode 1338 (Freq + Bucket/Sort)** | $O(N)$ | $O(N)$ |
