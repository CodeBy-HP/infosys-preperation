# Minimum Insertions or Deletions to Convert String A to B

## Problem Overview
Given two strings `word1` and `word2`, return the minimum number of steps required to make `word1` and `word2` the same.
In each step, you can **delete** a character in either string (or equivalently, convert $A$ to $B$ using character deletions and insertions).

---

## LCS Invariant Formulation
To minimize operations, maximize the preserved content between the two strings:
The preserved content is their **Longest Common Subsequence (LCS)**!
1. Deletions from `word1`: $N - \text{LCS}(\text{word1}, \text{word2})$
2. Insertions into `word1` (or deletions from `word2`): $M - \text{LCS}(\text{word1}, \text{word2})$

$$\text{Total Operations} = (N - \text{LCS}) + (M - \text{LCS}) = N + M - 2 \cdot \text{LCS}$$

---

## Complexity Analysis
- **Time Complexity:** $O(N \times M)$
- **Auxiliary Space:** $O(M)$

