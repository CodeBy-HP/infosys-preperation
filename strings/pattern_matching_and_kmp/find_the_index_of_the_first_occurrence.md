# Problem 8: Find the Index of the First Occurrence in a String (LeetCode 28 / KMP)

## Problem Statement

Given two strings `needle` and `haystack`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if `needle` is not part of `haystack`.

---

## Examples

### Example 1
- **Input:** `haystack = "sadbutsad", needle = "sad"`
- **Output:** `0`

### Example 2
- **Input:** `haystack = "leetcode", needle = "leeto"`
- **Output:** `-1`

---

## Constraints

- $1 \le \text{haystack.length}, \text{needle.length} \le 10^4$
- `haystack` and `needle` consist of only lowercase English characters.

---

## The Knuth-Morris-Pratt (KMP) Algorithm & LPS Array

When a mismatch occurs at `needle[j]`, naive string matching resets `j = 0` and rewinds `i`.
KMP exploits precomputed **Longest Proper Prefix which is also a Suffix (LPS)**:
- `lps[i]` stores the length of the longest proper prefix of `needle[0...i]` that matches a suffix of `needle[0...i]`.
- On mismatch after $j$ matches: `j = lps[j - 1]`. The search pointer `i` **never backtracks**!

$$\text{Time Complexity: } O(N + M)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **KMP Algorithm** | $O(N + M)$ | $O(M)$ | Optimal linear matching |
| **Naive Brute Force** | $O(N \times M)$ | $O(1)$ | Backtracks $i$ on mismatch |
