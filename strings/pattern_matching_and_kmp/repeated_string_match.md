# Problem 9: Repeated String Match (LeetCode 686 / Rabin-Karp)

## Problem Statement

Given two strings `a` and `b`, return the minimum number of times you should repeat string `a` so that string `b` is a substring of it. If it is impossible for `b` to be a substring of `a` after repeating it, return `-1`.

---

## Examples

### Example 1
- **Input:** `a = "abcd", b = "cdabcdab"`
- **Output:** `3`
- **Explanation:** Repeating `a` 3 times produces `"abcdabcdabcd"`. `b` is a substring starting at index 2.

### Example 2
- **Input:** `a = "a", b = "aa"`
- **Output:** `2`

---

## Constraints

- $1 \le \text{a.length}, \text{b.length} \le 10^4$
- `a` and `b` consist of lowercase English letters.

---

## Theoretical Upper Bound: Repeating Count

Let $L_a = |a|$ and $L_b = |b|$.
- The minimum number of repeats needed just to match length is $q = \lceil L_b / L_a \rceil$.
- Since $b$ might start near the end of one copy and extend across, it can span at most $q + 2$ repeats of $a$.
- If $b$ is not a substring within $q + 2$ repeats, it is mathematically impossible.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **KMP / Rabin-Karp on Repeated String** | $O(L_a \times q + L_b)$ | $O(L_a \times q)$ |
