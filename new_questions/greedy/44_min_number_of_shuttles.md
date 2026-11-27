# 44. Minimum Number of Shuttles / Boats to Save People (LeetCode 881)

## Problem Statement

You are given an array `people` where `people[i]` is the weight of the $i$-th person, and an infinite number of shuttles/boats where each shuttle can carry a maximum weight of `limit`.

Each shuttle carries **at most two people** at the same time, provided the sum of the weight of those people is at most `limit`.

Return the **minimum number of shuttles** to carry every given person.

---

## Examples

### Example 1
- **Input:** `people = [1, 2]`, `limit = 3`
- **Output:** `1`

### Example 2
- **Input:** `people = [3, 2, 2, 1]`, `limit = 3`
- **Output:** `3`
- **Explanation:** Shuttles: `(1, 2)`, `(2)`, `(3)`.

### Example 3
- **Input:** `people = [3, 5, 3, 4]`, `limit = 5`
- **Output:** `4`
- **Explanation:** Shuttles: `(3)`, `(3)`, `(4)`, `(5)`.

---

## Constraints

- $1 \le \text{people.length} \le 5 \times 10^4$
- $1 \le \text{people}[i] \le \text{limit} \le 3 \times 10^4$

---

## Pattern Insight: Sort + Greedy Lightest-Heaviest Pairing

1. Sort `people` ascending.
2. Maintain `left = 0` (lightest) and `right = n - 1` (heaviest).
3. Always board the heaviest person `people[right]`. If `people[left] + people[right] <= limit`, pair the lightest person into the same shuttle (`left++`).
4. Decrement `right--` and increment `shuttles++`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sorting + Two Pointers** | $O(N \log N)$ | $O(1)$ auxiliary |
