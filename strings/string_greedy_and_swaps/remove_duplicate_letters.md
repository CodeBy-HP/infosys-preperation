# Problem 17: Remove Duplicate Letters (LeetCode 316)

## Problem Statement

Given a string `s`, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the **smallest in lexicographical order** among all possible results.

---

## Examples

### Example 1
- **Input:** `s = "bcabc"`
- **Output:** `"abc"`

### Example 2
- **Input:** `s = "cbacdcbc"`
- **Output:** `"acdb"`

---

## Constraints

- $1 \le \text{s.length} \le 10^4$
- `s` consists of lowercase English letters.

---

## Monotonic Stack with Frequency Tracking

1. Precompute `lastOccurrence` index for each character.
2. Maintain `seen` boolean array to guarantee uniqueness.
3. While building result string (as a stack):
   - If `c` is already in stack, skip it!
   - While stack is non-empty, `stack.back() > c`, and `lastOccurrence[stack.back()] > i`:
     - The top character can appear later, so we pop it to achieve a smaller lexicographical prefix!
     - `seen[stack.back()] = false; stack.pop_back();`
   - Push `c` and mark `seen[c] = true`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Monotonic Stack** | $O(N)$ | $O(26)$ |
