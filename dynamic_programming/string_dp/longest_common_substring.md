# Longest Common Substring (GFG)

## Problem Statement

Given two strings `s1` and `s2`, find the length of the **longest common substring** between them.

A substring is a contiguous sequence of characters within a string. Unlike a subsequence, characters of a substring must appear consecutively in both strings.

---

## Examples

### Example 1:
```text
Input: s1 = "ABCDGH", s2 = "ACDGHR"
Output: 4
Explanation:
The longest common substring is "CDGH" with length 4.
```

### Example 2:
```text
Input: s1 = "ABC", s2 = "ACB"
Output: 1
Explanation:
The longest common substrings are "A", "B", "C", all of length 1.
```

### Example 3:
```text
Input: s1 = "YZ", s2 = "AB"
Output: 0
Explanation:
There is no common character between the two strings, so length is 0.
```

---

## Constraints

- $1 \le |s1|, |s2| \le 1000$
- Both strings consist of lowercase and uppercase English letters.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Invariant Contrast: Substring vs. Subsequence
In Longest Common Subsequence (LCS), if two characters do not match, the running chain is maintained by taking $\max(dp[i-1][j], dp[i][j-1])$.
In **Longest Common Substring**, because contiguity is mandatory, an unmatched character immediately **breaks the chain**!

### 2. State Definition
Let $dp[i][j]$ denote the length of the longest common substring **strictly ending** at index $i - 1$ of $s1$ and index $j - 1$ of $s2$.

### 3. State Transition
- If $s1[i - 1] == s2[j - 1]$:
  $$dp[i][j] = 1 + dp[i - 1][j - 1]$$
- If $s1[i - 1] \ne s2[j - 1]$:
  $$dp[i][j] = 0$$

### 4. Result Tracking
Since the longest common substring may end at any pair of positions $(i, j)$:
$$\text{Max Substring Length} = \max_{1 \le i \le N, \; 1 \le j \le M} dp[i][j]$$

### 5. Space Optimization ($O(M)$)
Because row $i$ relies only on diagonal entries $dp[i-1][j-1]$ from the previous row, by iterating $j$ **backwards** from $M$ down to $1$:
```cpp
int maxLen = 0;
vector<int> dp(M + 1, 0);
for (int i = 1; i <= N; ++i) {
    for (int j = M; j >= 1; --j) {
        if (s1[i - 1] == s2[j - 1]) {
            dp[j] = 1 + dp[j - 1];
            maxLen = max(maxLen, dp[j]);
        } else {
            dp[j] = 0; // Chain reset!
        }
    }
}
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (2D DP)** | $O(N \times M)$ | $O(N \times M)$ |
| **Space-Optimized (1D DP)** | $O(N \times M)$ | $O(M)$ where $M = |s2|$ |
