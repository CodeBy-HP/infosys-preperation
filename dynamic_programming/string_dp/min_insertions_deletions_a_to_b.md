# Minimum Insertions and Deletions to Convert String A to B (LeetCode 583)

## Problem Statement

Given two strings `word1` and `word2`, return the **minimum number of steps** required to make `word1` and `word2` the same.

In each step, you can delete exactly one character in either string.
(This is mathematically equivalent to converting string $A$ to string $B$ using character deletions and insertions).

---

## Examples

### Example 1:
```text
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation:
You need one step to make "sea" to "ea" (delete 's'), and one step to make "eat" to "ea" (delete 't').
Total steps = 2.
```

### Example 2:
```text
Input: word1 = "leetcode", word2 = "etco"
Output: 4
Explanation:
In "leetcode", delete 'l', 'e' (the second 'e'), 'd', 'e' -> 4 deletions to match "etco".
```

### Example 3:
```text
Input: word1 = "heap", word2 = "pea"
Output: 3
Explanation:
LCS is "ea" (length 2).
Deletions from "heap": 'h', 'p' (2 operations).
Insertions from "pea": 'p' (1 operation).
Total = 2 + 1 = 3 operations.
```

---

## Constraints

- `1 <= word1.length, word2.length <= 500`
- `word1` and `word2` consist of only lowercase English letters.

---

## Recurrence Formulation & Algorithmic Approaches

### 1. Invariant & LCS Connection
To minimize total insertions and deletions, we should preserve as many common characters in order as possible between `word1` and `word2`.
The maximum sequence of characters that can remain untouched without violating their relative order is their **Longest Common Subsequence (LCS)**:
- Characters to delete from `word1`: $|word1| - \text{LCS}(word1, word2)$
- Characters to insert into `word1` (or delete from `word2`): $|word2| - \text{LCS}(word1, word2)$

Therefore:
$$\text{Min Steps} = (|word1| - \text{LCS}) + (|word2| - \text{LCS}) = |word1| + |word2| - 2 \cdot \text{LCS}(word1, word2)$$

### 2. Space-Optimized LCS
We compute LCS length using two rolling 1D arrays:
```cpp
int n = word1.size(), m = word2.size();
vector<int> prev(m + 1, 0), curr(m + 1, 0);

for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
        if (word1[i - 1] == word2[j - 1]) curr[j] = 1 + prev[j - 1];
        else curr[j] = max(prev[j], curr[j - 1]);
    }
    prev = curr;
}
int lcs = prev[m];
return n + m - 2 * lcs;
```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Tabulation (2D DP)** | $O(N \times M)$ | $O(N \times M)$ |
| **Space-Optimized (Rolling Rows)** | $O(N \times M)$ | $O(M)$ where $M = |word2|$ |
