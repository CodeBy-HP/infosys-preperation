# Count Palindromic Subsequences (GFG)

## Problem Statement

Given a string `s`, return the **total number of palindromic subsequences** (need not be distinct in value if formed from characters at different index positions) modulo $10^9 + 7$.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters. A palindromic subsequence reads the same forwards and backwards.

---

## Examples

### Example 1:
```text
Input: s = "abcd"
Output: 4
Explanation:
Palindromic subsequences of "abcd" are:
"a", "b", "c", "d" (each individual character is a palindrome).
Total count = 4.
```

### Example 2:
```text
Input: s = "aab"
Output: 4
Explanation:
Palindromic subsequences are:
"a" (at index 0), "a" (at index 1), "b" (at index 2), and "aa" (indices 0 and 1).
Total count = 4.
```

### Example 3:
```text
Input: s = "b"
Output: 1
```

---

## Constraints

- $1 \le |s| \le 1000$
- String `s` consists of lowercase English letters.

---

## Recurrence Formulation & Algorithmic Approaches

This is a classical **Interval Dynamic Programming** problem evaluated via the **Principle of Inclusion-Exclusion**.

### 1. State Definition
Let $dp[i][j]$ denote the total number of palindromic subsequences contained in the substring $s[i \dots j]$.

### 2. State Transitions
Consider the subsegment $s[i \dots j]$ ($i < j$):
1. Number of palindromes in prefix $s[i \dots j - 1]$: $dp[i][j - 1]$.
2. Number of palindromes in suffix $s[i + 1 \dots j]$: $dp[i + 1][j]$.
3. Intersection (palindromes purely inside $s[i + 1 \dots j - 1]$): $dp[i + 1][j - 1]$.

#### Case 1: $s[i] == s[j]$
The outer pair $s[i]$ and $s[j]$ can wrap around **every** palindromic subsequence existing in $s[i + 1 \dots j - 1]$, plus the two boundary characters together form the palindrome $s[i]s[j]$ (an extra $+1$):
$$dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) + (dp[i + 1][j - 1] + 1)$$
Canceling the identical terms:
$$dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] + 1) \pmod{10^9 + 7}$$

#### Case 2: $s[i] \ne s[j]$
The outer characters cannot form a pair:
$$dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) \pmod{10^9 + 7}$$

### 3. Base Cases
- Single characters: $dp[i][i] = 1$ for all $0 \le i < N$.
- Empty segments: $dp[i][j] = 0$ for $i > j$.

---

## Complexity Analysis

| Metric | Interval DP (By substring length) |
| :--- | :--- |
| **Time Complexity** | $O(N^2)$ evaluating $N(N+1)/2$ intervals |
| **Auxiliary Space** | $O(N^2)$ for 2D DP matrix |
