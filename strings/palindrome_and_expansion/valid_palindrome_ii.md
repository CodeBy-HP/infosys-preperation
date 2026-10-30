# Problem 7: Valid Palindrome II (LeetCode 680)

## Problem Statement

Given a string `s`, return `true` if the `s` can be palindrome after deleting **at most one** character from it.

---

## Examples

### Example 1
- **Input:** `s = "aba"`
- **Output:** `true`

### Example 2
- **Input:** `s = "abca"`
- **Output:** `true` (Delete 'c')

### Example 3
- **Input:** `s = "abc"`
- **Output:** `false`

---

## Constraints

- $1 \le \text{s.length} \le 10^5$
- `s` consists of lowercase English letters.

---

## Pattern: Two-Pointer Branching on First Mismatch

1. Two pointers: `left = 0`, `right = s.size() - 1`.
2. While `s[left] == s[right]`: `left++`, `right--`.
3. On first mismatch `s[left] != s[right]`:
   - Either delete `s[left]` and check if `isPalindrome(s, left + 1, right)`.
   - Or delete `s[right]` and check if `isPalindrome(s, left, right - 1)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Two-Pointer Branching** | $O(N)$ | $O(1)$ |
