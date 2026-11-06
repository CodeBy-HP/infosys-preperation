# Minimum Insertions to Make String Palindrome

## Problem Overview
Given a string `s`, find the **minimum number of characters you need to insert** anywhere in `s` to make it a palindrome.

---

## Invariant Formulation
To minimize the number of insertions, we should keep the largest possible palindromic structure that already exists in `s` completely intact.
The largest existing palindromic structure is the **Longest Palindromic Subsequence (LPS)**.
All characters that are **not** part of this LPS must have a symmetrical counterpart inserted to balance them:
$$\text{Min Insertions} = N - \text{Length of LPS}(s) = N - \text{LCS}(s, \; \text{reverse}(s))$$

---

## Complexity Analysis
- **Time Complexity:** $O(N^2)$ via LCS.
- **Auxiliary Space:** $O(N)$ with rolling arrays.

