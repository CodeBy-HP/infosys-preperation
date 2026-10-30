# Problem 2: Next Greater Element II (LeetCode 503)

## Problem Statement

Given a **circular integer array** `nums` (i.e., the next element of `nums[nums.length - 1]` is `nums[0]`), return the **next greater number** for every element in `nums`.

The next greater number of a number `x` is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return `-1` for this number.

---

## Examples

### Example 1
- **Input:** `nums = [1, 2, 1]`
- **Output:** `[2, -1, 2]`
- **Explanation:**
  - First 1's next greater is 2.
  - 2 has no next greater element (-1).
  - Second 1 wraps around circularly to find 2.

### Example 2
- **Input:** `nums = [1, 2, 3, 4, 3]`
- **Output:** `[2, 3, 4, -1, 4]`

---

## Constraints

- $1 \le \text{nums.length} \le 10^4$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Pattern: Double-Length Circular Pass ($2N - 1$)

Simulate circular traversal by looping $i$ from $2N - 1$ down to $0$ using modulo index $i \pmod N$:
- While `!st.empty() && st.top() <= nums[i % n]`: pop elements.
- If $i < n$: result is `st.empty() ? -1 : st.top()`.
- Push `nums[i % n]` to stack.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Monotonic Stack (2N Scan)** | $O(N)$ | $O(N)$ stack space |
