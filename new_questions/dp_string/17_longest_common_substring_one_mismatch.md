# 17. Longest Common Substring with At Most One Mismatch (Infosys String DP)

## Problem Statement

Given two strings `s1` and `s2` (or two integer arrays `nums1` and `nums2`), find the **maximum length** of a contiguous substring that appears in both `s1` and `s2` with **at most one mismatch** (i.e., Hamming distance between the two chosen substrings of equal length is $\le 1$).

*(Closest LeetCode base: LeetCode 718 — Maximum Length of Repeated Subarray, extended with 1-mismatch tolerance.)*

---

## Examples

### Example 1
- **Input:** `s1 = "abca"`, `s2 = "rama"`
- **Output:** `2`
- **Explanation:** `"ca"` vs `"ma"` have length 2 with 1 mismatch (`'c' != 'm'`, `'a' == 'a'`).

### Example 2
- **Input:** `s1 = "abcde"`, `s2 = "abfde"`
- **Output:** `5`
- **Explanation:** Entire strings match except index 2 (`'c'` vs `'f'`). Length = 5.

### Example 3
- **Input:** `s1 = "xyz"`, `s2 = "abc"`
- **Output:** `1`
- **Explanation:** Any single-character substring has 1 mismatch $\le 1$.

---

## Constraints

- $1 \le |s_1|, |s_2| \le 1000$
- Strings consist of lowercase English letters.

---

## Pattern Insight: Dual-Streak Diagonal DP

Maintain two quantities ending at `(i, j)` (1-indexed):
1. `exact[i][j]`: longest matching suffix ending at `s1[i-1]` and `s2[j-1]` with **0 mismatches**.
2. `oneMis[i][j]`: longest common suffix ending at `s1[i-1]` and `s2[j-1]` with **at most 1 mismatch**.

Transitions:
- If `s1[i-1] == s2[j-1]`:
  - `exact[i][j] = exact[i-1][j-1] + 1`
  - `oneMis[i][j] = oneMis[i-1][j-1] + 1`
- Else (current pair consumes our single mismatch allowance):
  - `exact[i][j] = 0`
  - `oneMis[i][j] = exact[i-1][j-1] + 1`

Track global `max(oneMis[i][j])`. Runs in **$O(N \cdot M)$ time** and **$O(M)$ space**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Space-Optimized Dual-Streak DP** | $O(N \cdot M)$ | $O(M)$ |
| **3D $k$-Mismatch DP** | $O(N \cdot M \cdot K)$ | $O(M \cdot K)$ |
