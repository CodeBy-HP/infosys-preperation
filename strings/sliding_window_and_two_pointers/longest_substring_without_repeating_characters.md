# Problem 1: Longest Substring Without Repeating Characters (LeetCode 3)

## Problem Statement

Given a string `s`, find the length of the **longest substring** without repeating characters.

---

## Examples

### Example 1
- **Input:** `s = "abcabcbb"`
- **Output:** `3`
- **Explanation:** The answer is `"abc"`, with the length of 3.

### Example 2
- **Input:** `s = "bbbbb"`
- **Output:** `1`
- **Explanation:** The answer is `"b"`, with the length of 1.

### Example 3
- **Input:** `s = "pwwkew"`
- **Output:** `3`
- **Explanation:** The answer is `"wke"`, with the length of 3. Note that `"pwke"` is a subsequence and not a substring.

---

## Constraints

- $0 \le \text{s.length} \le 5 \times 10^4$
- `s` consists of English letters, digits, symbols and spaces.

---

## Pattern & Invariant: Dynamic Sliding Window with Last-Seen Index

Instead of contracting the left boundary one step at a time:
1. Maintain an array / hash map `lastSeen` mapping each character to its most recent index in `s`.
2. As the right pointer `r` advances from `0` to `n - 1`:
   - If `s[r]` was previously seen inside the active window (`lastSeen[s[r]] >= left`):
     - Leap `left` forward past that collision: `left = lastSeen[s[r]] + 1`.
   - Update `lastSeen[s[r]] = r`.
   - Window size is `r - left + 1`. Update `maxLen = max(maxLen, r - left + 1)`.

```
s = "a b c a b c b b"
     L     R            window = "abc", len = 3
       L     R          'a' seen at 0 -> L leaps to 0 + 1 = 1, window = "bca", len = 3
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Last-Seen Index Jump** | $O(N)$ | $O(\Sigma)$ where $\Sigma \le 128$ | Strictly single pass ($R$ never backtracks) |
| **Set-Based Window**     | $O(2N) = O(N)$ | $O(\Sigma)$ | $L$ increments one by one |
