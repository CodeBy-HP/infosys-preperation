# Problem 7: Longest Common Subsequence (LCS)

## Problem Statement

Given two strings `text1` and `text2`, return the **length of their longest common subsequence**. If there is no common subsequence, return `0`.

A **subsequence** of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
- For example, `"ace"` is a subsequence of `"abcde"`.

A **common subsequence** of two strings is a subsequence that is common to both strings.

---

## Examples

### Example 1
- **Input:** `text1 = "abcde", text2 = "ace"`
- **Output:** `3`
- **Explanation:** The longest common subsequence is `"ace"` and its length is 3.

### Example 2
- **Input:** `text1 = "abc", text2 = "abc"`
- **Output:** `3`
- **Explanation:** The longest common subsequence is `"abc"` and its length is 3.

### Example 3
- **Input:** `text1 = "abc", text2 = "def"`
- **Output:** `0`
- **Explanation:** There is no such common subsequence, so the result is 0.

---

## Constraints

- $1 \le \text{text1.length}, \text{text2.length} \le 1000$
- `text1` and `text2` consist of only lowercase English characters.

---

## The Two-Pointer DP Recurrence

Let pointer $i$ index `text1` and pointer $j$ index `text2`.

1. **State:**
   - $\text{dp}[i][j]$ is the LCS length of prefixes `text1[0...i-1]` and `text2[0...j-1]`.
2. **Transitions:**
   - **Scenario A (Characters Match):** `text1[i - 1] == text2[j - 1]`
     $$\text{dp}[i][j] = 1 + \text{dp}[i - 1][j - 1]$$
   - **Scenario B (Characters Differ):**
     $$\text{dp}[i][j] = \max(\text{dp}[i - 1][j],\, \text{dp}[i][j - 1])$$
3. **Base Cases:**
   - If either string prefix is empty ($i = 0$ or $j = 0$), $\text{dp}[0][j] = \text{dp}[i][0] = 0$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(M \times N)$ | $O(M \times N)$ |
| **Bottom-Up (2D Tabulation)** | $O(M \times N)$ | $O(M \times N)$ |
| **Space-Optimized Iterative** | $O(M \times N)$ | $O(N)$ (Rolling two rows) |

