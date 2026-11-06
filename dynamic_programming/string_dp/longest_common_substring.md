# Longest Common Substring

## Problem Overview
Given two strings `s1` and `s2`, find the length of the **longest common substring** between them.
A substring is a contiguous sequence of characters within a string (unlike a subsequence, characters must appear consecutively).

---

## Substring vs Subsequence Invariant
In Longest Common Subsequence (LCS), if characters do not match, we carry forward previous maximums: $\max(dp[i-1][j], dp[i][j-1])$.
In **Longest Common Substring**, if characters do not match, the contiguous chain is **broken immediately**:
- If $s_1[i - 1] == s_2[j - 1]$:
  $$dp[i][j] = 1 + dp[i - 1][j - 1]$$
- If $s_1[i - 1] \ne s_2[j - 1]$:
  $$dp[i][j] = 0$$

The result is the global maximum across all cells:
$$\text{Max Substring Length} = \max_{i, j} dp[i][j]$$

---

## Complexity Analysis
- **Tabulation (2D DP):** $O(N \times M)$ Time, $O(N \times M)$ Space.
- **Space-Optimized (1D Row):** By updating backwards from $M$ down to $1$, space reduces to $O(M)$.
  - **Time Complexity:** $O(N \times M)$
  - **Auxiliary Space:** $O(M)$

