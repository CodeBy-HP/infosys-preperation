# Longest Palindromic Subsequence (LeetCode 516)

## Problem Statement

Given a string `s`, find the **length of the longest palindromic subsequence** in `s`.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

---

## Examples

### Example 1:
```text
Input: s = "bbbab"
Output: 4
Explanation:
One possible longest palindromic subsequence is "bbbb".
```

### Example 2:
```text
Input: s = "cbbd"
Output: 2
Explanation:
One possible longest palindromic subsequence is "bb".
```

### Example 3:
```text
Input: s = "a"
Output: 1
```

---

## Constraints

- `1 <= s.length <= 1000`
- `s` consists only of lowercase English letters.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Canonical Reduction to LCS
A palindrome reads identical forwards and backwards.
Therefore, any subsequence of string $s$ that forms a palindrome must simultaneously appear in the identical order in the **reversed string** $\text{rev}(s)$.
Hence, the problem is **strictly equivalent** to computing the Longest Common Subsequence of $s$ and its reverse:
$$\text{LPS}(s) = \text{LCS}(s, \; \text{reverse}(s))$$

### 2. Direct Interval DP Formulation
Alternatively, consider substring $s[i \dots j]$ ($i \le j$):
- If $s[i] == s[j]$:
  $$dp[i][j] = (i == j \; ? \; 1 : 2 + dp[i + 1][j - 1])$$
- If $s[i] \ne s[j]$:
  $$dp[i][j] = \max(dp[i + 1][j], \; dp[i][j - 1])$$

- **Base Cases:**
  - $dp[i][i] = 1$ (single characters)
  - $dp[i][j] = 0$ for $i > j$.

### 3. Space-Optimized LCS Approach
Using two rolling 1D rows for $\text{LCS}(s, \text{rev}(s))$:
```cpp
string rev = s;
reverse(rev.begin(), rev.end());
int n = s.length();
vector<int> prev(n + 1, 0), curr(n + 1, 0);

for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
        if (s[i - 1] == rev[j - 1]) curr[j] = 1 + prev[j - 1];
        else curr[j] = max(prev[j], curr[j - 1]);
    }
    prev = curr;
}
return prev[n];
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Top-Down Memoization** | $O(N^2)$ | $O(N^2)$ table + $O(N)$ recursion depth |
| **Tabulation (2D DP)** | $O(N^2)$ | $O(N^2)$ |
| **Space-Optimized (Rolling Rows)** | $O(N^2)$ | $O(N)$ |
