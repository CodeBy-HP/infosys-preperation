# Problem 14: Split a String in Balanced Strings (With At Most 1 Swap)

## Problem Statement

You are given a string `s` of **even length $N$** consisting only of the characters `'L'` and `'R'`. The string is **globally balanced**, meaning it contains an equal number of `'L'` and `'R'` characters.

A **substring** is considered **balanced** if it contains an equal number of `'L'` and `'R'` characters.

Your goal is to split the string into the **maximum possible number** of **contiguous balanced substrings**.

Before making the splits, you may perform **at most one** operation:
- Swap one **pair of adjacent characters** in the string.
- You may also choose **not to perform any swap**.

Determine the maximum number of balanced substrings into which the string can be partitioned.

---

## Examples

### Example 1
- **Input:** `s = "RLRRLLRLRL"`
- **Output:** `4`
- **Explanation:** `"RL"`, `"RRLL"`, `"RL"`, `"RL"` without any swaps.

---

## Pattern: Prefix Difference Balance with Adjacent Perturbation

Let $\text{diff}[i] = \text{count}(L) - \text{count}(R)$ at index $i$:
1. A split occurs wherever $\text{diff}[i] == 0$.
2. Swapping adjacent characters $s[i]$ and $s[i + 1]$:
   - If $s[i] == 'L'$ and $s[i + 1] == 'R'$: the local difference at index $i$ shifts by $-2$ (from $+2$ down to $0$!).
   - If $s[i] == 'R'$ and $s[i + 1] == 'L'$: the local difference shifts by $+2$ (from $-2$ up to $0$!).
3. If such a transition can create an additional zero-crossing at index $i$ without ruining the global balance, we gain $+1$ split!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Single-Pass Prefix Tracking** | $O(N)$ | $O(1)$ | Strictly constant space |
