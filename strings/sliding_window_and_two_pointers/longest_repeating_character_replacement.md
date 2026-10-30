# Problem 3: Longest Repeating Character Replacement (LeetCode 424)

## Problem Statement

You are given a string `s` and an integer `k`. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most `k` times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

---

## Examples

### Example 1
- **Input:** `s = "ABAB", k = 2`
- **Output:** `4`
- **Explanation:** Replace the two 'A's with two 'B's or vice versa.

### Example 2
- **Input:** `s = "AABABBA", k = 1`
- **Output:** `4`
- **Explanation:** Replace the middle 'A' with 'B' to form `"AABBBBA"`. The substring `"BBBB"` has length 4.

---

## Constraints

- $1 \le \text{s.length} \le 10^5$
- `s` consists of only uppercase English letters.
- $0 \le k \le \text{s.length}$

---

## Core Invariant: Window Size vs Max Frequency

In any window of length $W = \text{right} - \text{left} + 1$:
$$\text{Number of replacements needed} = W - \text{maxFrequency}$$
A window is valid if and only if:
$$W - \text{maxFrequency} \le k$$

### Key Optimization:
We do not need to recompute `maxFrequency` downwards when shrinking `left`! A smaller `maxFrequency` can never produce a larger valid window than the maximum we have already found.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Monotonic Non-Shrinking Window** | $O(N)$ | $O(26)$ | Strictly single pass |
