# Problem 10: Shortest Palindrome (LeetCode 214)

## Problem Statement

You are given a string `s`. You can convert `s` to a **palindrome** by adding characters **in front of it**.

Return the shortest palindrome you can find by performing this transformation.

---

## Examples

### Example 1
- **Input:** `s = "aacecaaa"`
- **Output:** `"aaacecaaa"`

### Example 2
- **Input:** `s = "abcd"`
- **Output:** `"dcbabcd"`

---

## Constraints

- $0 \le \text{s.length} \le 5 \times 10^4$
- `s` consists of lowercase English letters only.

---

## Pattern: Longest Palindromic Prefix via KMP LPS

To add minimum characters in front of `s`, we must find the **longest palindromic prefix** of `s`.
Everything after this prefix must be reversed and prepended.
- Create combined string:
  $$T = s + \text{'#'} + \text{reverse}(s)$$
- Compute KMP `lps` array on $T$.
- `lps.back()` gives the exact length $L$ of the longest prefix of $s$ that matches a suffix of $\text{reverse}(s)$ (which is by definition a palindrome!).
- Result: $\text{reverse}(s[L \dots N - 1]) + s$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **KMP on $s + \# + \text{rev}(s)$** | $O(N)$ | $O(N)$ | Optimal linear time |
