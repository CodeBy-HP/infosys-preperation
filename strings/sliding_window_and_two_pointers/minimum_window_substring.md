# Problem 2: Minimum Window Substring (LeetCode 76)

## Problem Statement

Given two strings `s` and `t` of lengths `m` and `n` respectively, return the **minimum window substring** of `s` such that every character in `t` (**including duplicates**) is included in the window. If there is no such substring, return the empty string `""`.

The testcases will be generated such that the answer is **unique**.

---

## Examples

### Example 1
- **Input:** `s = "ADOBECODEBANC", t = "ABC"`
- **Output:** `"BANC"`
- **Explanation:** The minimum window substring `"BANC"` includes 'A', 'B', and 'C' from string t.

### Example 2
- **Input:** `s = "a", t = "a"`
- **Output:** `"a"`

### Example 3
- **Input:** `s = "a", t = "aa"`
- **Output:** `""`

---

## Constraints

- $m == \text{s.length}$
- $n == \text{t.length}$
- $1 \le m, n \le 10^5$
- `s` and `t` consist of uppercase and lowercase English letters.

---

## Pattern: Expand to Qualify, Contract to Optimize

1. **Frequency Target:** Build `targetCount` of all characters in `t`. Count unique characters needed: `required = targetCount.size()`.
2. **Expand Right (`r++`):**
   - Add `s[r]` to `windowCount`.
   - If `windowCount[s[r]] == targetCount[s[r]]`, increment `formed++`.
3. **Contract Left (`l++`):**
   - While `formed == required` (all characters from `t` are present):
     - Record minimum window: `if (r - l + 1 < minLen)`.
     - Decrement `windowCount[s[l]]`.
     - If `windowCount[s[l]] < targetCount[s[l]]`, decrement `formed--`.
     - Advance `l++`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Sliding Window + Formed Counter** | $O(M + N)$ | $O(\Sigma) = O(128)$ | Each character visited at most twice |
