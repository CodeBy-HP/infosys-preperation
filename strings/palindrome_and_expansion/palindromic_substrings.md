# Problem 6: Palindromic Substrings (LeetCode 647)

## Problem Statement

Given a string `s`, return the number of **palindromic substrings** in it.

A string is a **palindrome** when it reads the same backward as forward.

A **substring** is a contiguous sequence of characters within the string.

---

## Examples

### Example 1
- **Input:** `s = "abc"`
- **Output:** `3` (`"a"`, `"b"`, `"c"`)

### Example 2
- **Input:** `s = "aaa"`
- **Output:** `6` (`"a"`, `"a"`, `"a"`, `"aa"`, `"aa"`, `"aaa"`)

---

## Constraints

- $1 \le \text{s.length} \le 1000$
- `s` consists of lowercase English letters.

---

## Pattern: Two-Pointer Expansion Counting

For each of the $2N - 1$ centers:
- Expand outward while `s[l] == s[r]`.
- Every successful expansion step identifies one unique palindromic substring: increment `count++`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Expand Around Center** | $O(N^2)$ | $O(1)$ |
