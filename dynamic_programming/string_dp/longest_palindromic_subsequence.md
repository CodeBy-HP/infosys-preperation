# Longest Palindromic Subsequence

## Problem Overview
Given a string `s`, find the length of the **longest palindromic subsequence** in `s`.
A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

---

## Canonical Reduction to LCS
A palindrome reads identical forwards and backwards.
Therefore, any subsequence of $s$ that is palindromic must also appear identically in the reverse of $s$, `rev(s)`!
The longest palindromic subsequence is **strictly equivalent** to:
$$LPS(s) = LCS(s, \; \text{reverse}(s))$$

---

## Complexity Analysis
- **Tabulation (LCS on $s$ and $rev(s)$):**
  - **Time Complexity:** $O(N^2)$
  - **Auxiliary Space:** $O(N)$ with two rolling rows.

