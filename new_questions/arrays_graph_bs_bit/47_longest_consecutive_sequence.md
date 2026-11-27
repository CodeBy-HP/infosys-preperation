# 47. Longest Consecutive Sequence (LeetCode 128)

## Problem Statement

Given an unsorted array of integers `nums`, return the **length of the longest consecutive elements sequence**.

You must write an algorithm that runs in **$O(n)$ time**.

---

## Examples

### Example 1
- **Input:** `nums = [100, 4, 200, 1, 3, 2]`
- **Output:** `4`
- **Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Its length is `4`.

### Example 2
- **Input:** `nums = [0, 3, 7, 2, 5, 8, 4, 6, 0, 1]`
- **Output:** `9`

---

## Constraints

- $0 \le \text{nums.length} \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Pattern Insight: Sequence-Start Hash Set Filtering

Insert all numbers into an `unordered_set<int> s`.
Iterate through every distinct `num` in `s`:
- Only begin counting a streak if **`!s.count(num - 1)`** (meaning `num` is the true left boundary of its consecutive sequence!).
- Expand `num + 1, num + 2, ...` while present in `s`.
Because each element is scanned inside the `while` loop at most once, total work is strictly **$O(N)$**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Hash Set Sequence-Start Check** | $O(N)$ average | $O(N)$ |
| **Sorting + Linear Scan** | $O(N \log N)$ | $O(1)$ |
