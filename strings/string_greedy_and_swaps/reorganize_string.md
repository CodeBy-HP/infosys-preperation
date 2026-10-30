# Problem 16: Reorganize String (LeetCode 767)

## Problem Statement

Given a string `s`, rearrange the characters of `s` so that any two adjacent characters are not the same.

Return any possible rearrangement of `s` or return `""` if not possible.

---

## Examples

### Example 1
- **Input:** `s = "aab"`
- **Output:** `"aba"`

### Example 2
- **Input:** `s = "aaab"`
- **Output:** `""`

---

## Constraints

- $1 \le \text{s.length} \le 500$
- `s` consists of lowercase English letters.

---

## Pigeonhole Principle & Even/Odd Stride Placement

1. **Pigeonhole Bottleneck:** If $\text{maxFrequency} > \lfloor (N + 1) / 2 \rfloor$, it is physically impossible. Return `""`.
2. **Stride Placement:**
   - First place the most frequent character into even indices: $0, 2, 4 \dots$
   - Once even indices are filled, place remaining characters in continuing even then odd indices ($1, 3, 5 \dots$).
   - This ensures identical characters are separated by at least 1 position.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Even/Odd Stride Array** | $O(N)$ | $O(26)$ |
