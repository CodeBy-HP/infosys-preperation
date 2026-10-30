# Problem 5: Longest Palindromic Substring (LeetCode 5)

## Problem Statement

Given a string `s`, return the **longest palindromic substring** in `s`.

---

## Examples

### Example 1
- **Input:** `s = "babad"`
- **Output:** `"bab"` (or `"aba"`)

### Example 2
- **Input:** `s = "cbbd"`
- **Output:** `"bb"`

---

## Constraints

- $1 \le \text{s.length} \le 1000$
- `s` consist of only digits and English letters.

---

## Pattern: Expand Around Center

A palindrome mirrors around its center:
- There are $N$ odd-length centers: single character `(i, i)`.
- There are $N - 1$ even-length centers: character pairs `(i, i + 1)`.
Total $2N - 1$ centers. Expanding from each center takes $O(N)$ time.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Expand Around Center** | $O(N^2)$ | $O(1)$ | Strictly $O(1)$ auxiliary space |
| **Manacher's Algorithm** | $O(N)$ | $O(N)$ | Advanced linear palindrome algorithm |
