# Problem 13: Palindrome Partitioning II (Front Partitioning Optimization)

## Problem Statement

Given a string `s`, partition `s` such that every substring of the partition is a **palindrome**.

Return the **minimum cuts** needed for a palindrome partitioning of `s`.
*(Note: If the problem asks for the minimum number of palindromic substrings, it is simply $\text{cuts} + 1$).*

---

## Examples

### Example 1
- **Input:** `s = "aab"`
- **Output:** `1` (or `2` substrings)
- **Explanation:** The partition `["aa", "b"]` requires $1$ cut, producing $2$ palindromic substrings.

### Example 2
- **Input:** `s = "a"`
- **Output:** `0` (or `1` substring)
- **Explanation:** The entire string is already a palindrome.

### Example 3
- **Input:** `s = "ababbbabbababa"`
- **Output:** `2` (or `3` substrings)
- **Explanation:** An optimal partition is `["aba", "babbabb", "ababa"]` using $2$ cuts.

---

## Constraints

- $1 \le \text{s.length} \le 2000$
- `s` consists of lowercase English letters only.

---

## The Paradigm: Front Partitioning Optimization

Standard MCM partitions an interval $[i, j]$ using a pivot $k$, running in $O(N^3)$.
For string partitioning, we only need to fix the left cut point $i$ and search for the next cut point $k$.

1. **State:**
   - $\text{dp}[i]$ represents the minimum cuts needed for the suffix $s[i \dots n - 1]$.
2. **Transition:**
   - For every $k \in [i, n - 1]$:
   - If substring $s[i \dots k]$ is a palindrome:
     $$\text{dp}[i] = \min_{k} (1 + \text{dp}[k + 1])$$
3. **The Phantom Cut:**
   - When $s[i \dots n - 1]$ reaches the end of the string, our formula adds 1 cut after the last character. Thus, the actual cut count is $\text{dp}[0] - 1$.
4. **$O(1)$ Palindrome Precomputation:**
   - We precompute a 2D table `isPalin[i][j]` in $O(N^2)$ time:
     `isPalin[i][j] = (s[i] == s[j]) && (j - i < 2 || isPalin[i + 1][j - 1])`
   - This eliminates repetitive palindrome loops, achieving true $O(N^2)$ overall runtime.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(N^2)$ | $O(N^2)$ |
| **Bottom-Up Tabulation with Precomputed Palindromes** | $O(N^2)$ | $O(N^2)$ |
| **Space-Optimized Palindrome Expansion** | $O(N^2)$ | $O(N)$ |

