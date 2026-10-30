# Problem 7: Minimum Remove to Make Valid Parentheses (LeetCode 1249)

## Problem Statement

Given a string `s` of `'('`, `')'` and lowercase English characters.

Your task is to remove the minimum number of parentheses ( `'('` or `')'`, in any positions ) so that the resulting parentheses string is valid and return **any** valid string.

---

## Examples

### Example 1
- **Input:** `s = "lee(t(c)o)de)"`
- **Output:** `"lee(t(c)o)de"`

### Example 2
- **Input:** `s = "a)b(c)d"`
- **Output:** `"ab(c)d"`

---

## Constraints

- $1 \le \text{s.length} \le 10^5$
- `s[i]` is either `'('`, `')'`, or lowercase English letter.

---

## Pattern: Two-Pass Invalidation Marking

1. **Pass 1:** Track unmatched indices:
   - For `'('`: push index to stack.
   - For `')'`: if stack is non-empty, pop. Else, mark invalid: `s[i] = '*'`.
2. Any leftover `'('` indices in the stack after Pass 1 are also invalid: mark `s[st.top()] = '*'`.
3. **Pass 2:** Filter out all marked `'*'` characters.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **In-Place Marker + Filter** | $O(N)$ | $O(N)$ |
