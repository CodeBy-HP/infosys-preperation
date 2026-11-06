# Shortest Common Supersequence

## Problem Overview
Given two strings `str1` and `str2`, return the **shortest string** that has both `str1` and `str2` as subsequences. If there are multiple valid strings, return any of them.
A string $S$ is a supersequence of string $T$ if $T$ is a subsequence of $S$.

---

## Reconstruction from LCS Table
Length of SCS is $N + M - \text{LCS}(\text{str1}, \text{str2})$.
To **construct the actual supersequence string**:
1. Build the full $(N + 1) \times (M + 1)$ LCS DP table.
2. Backtrack two pointers $(i, j)$ from $(N, M)$ to $(0, 0)$:
   - If `str1[i-1] == str2[j-1]`: The character is part of LCS! Add it **once** and move diagonally: $i \leftarrow i - 1, j \leftarrow j - 1$.
   - Else if $dp[i-1][j] > dp[i][j-1]$: Character `str1[i-1]` must be included; move up: $i \leftarrow i - 1$.
   - Else: Character `str2[j-1]` must be included; move left: $j \leftarrow j - 1$.
3. When one pointer hits 0, append all remaining characters of the other string.
4. Reverse the accumulated string.

---

## Complexity Analysis
- **Time Complexity:** $O(N \times M)$
- **Auxiliary Space:** $O(N \times M)$ to retain the 2D DP matrix for backtracking.

