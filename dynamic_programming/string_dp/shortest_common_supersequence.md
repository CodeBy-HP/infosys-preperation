# Shortest Common Supersequence (LeetCode 1092)

## Problem Statement

Given two strings `str1` and `str2`, return the **shortest string** that has both `str1` and `str2` as subsequences. If there are multiple valid strings, return **any of them**.

A string $S$ is a supersequence of string $T$ if $T$ can be derived from $S$ by deleting some or no characters without altering the order of remaining characters.

---

## Examples

### Example 1:
```text
Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
- str1 = "abac" is a subsequence of "cabac" because we can delete the first "c": [c]abac -> "abac".
- str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac": cab[ac] -> "cab".
The shortest common supersequence has length 5 ("cabac").
```

### Example 2:
```text
Input: str1 = "aaaaaaaa", str2 = "aaaaaaaa"
Output: "aaaaaaaa"
```

---

## Constraints

- `1 <= str1.length, str2.length <= 1000`
- `str1` and `str2` consist of lowercase English letters.

---

## Recurrence Formulation & String Reconstruction

### 1. Invariant & Length of SCS
In any common supersequence, common characters (the Longest Common Subsequence) only need to be written **once**, while distinct characters from `str1` and `str2` must each appear once.
$$\text{Length of SCS} = |str1| + |str2| - \text{LCS}(str1, str2)$$

### 2. Reconstruction via 2D LCS Table Backtracking
1. Construct the complete $(N + 1) \times (M + 1)$ LCS DP table:
   - If `str1[i - 1] == str2[j - 1]`: $dp[i][j] = 1 + dp[i - 1][j - 1]$
   - Else: $dp[i][j] = \max(dp[i - 1][j], dp[i][j - 1])$
2. Backtrack two pointers $(i, j)$ from $(N, M)$ down to $(0, 0)$:
   - **Match (`str1[i - 1] == str2[j - 1]`):** This character is part of LCS. Append it **once** and step diagonally:
     $$res += str1[i - 1], \quad i \leftarrow i - 1, \; j \leftarrow j - 1$$
   - **Mismatch with $dp[i - 1][j] > dp[i][j - 1]$:** Character $str1[i - 1]$ was not part of LCS. Append it and move up:
     $$res += str1[i - 1], \quad i \leftarrow i - 1$$
   - **Mismatch with $dp[i - 1][j] \le dp[i][j - 1]$:** Character $str2[j - 1]$ was not part of LCS. Append it and move left:
     $$res += str2[j - 1], \quad j \leftarrow j - 1$$
3. When one pointer reaches $0$, append all remaining characters of the other string.
4. Reverse `res` to obtain the final supersequence.

---

## Complexity Analysis

| Metric | Full LCS Table + Backtracking |
| :--- | :--- |
| **Time Complexity** | $O(N \times M)$ table computation + $O(N + M)$ backtracking |
| **Auxiliary Space** | $O(N \times M)$ to retain the 2D DP matrix for path tracing |
