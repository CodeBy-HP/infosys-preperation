# Problem 3: Daily Temperatures (LeetCode 739)

## Problem Statement

Given an array of integers `temperatures` represents the daily temperatures, return an array `answer` such that `answer[i]` is the **number of days you have to wait** after the $i^{\text{th}}$ day to get a warmer temperature. If there is no future day for which this is possible, keep `answer[i] == 0` instead.

---

## Examples

### Example 1
- **Input:** `temperatures = [73, 74, 75, 71, 69, 72, 76, 73]`
- **Output:** `[1, 1, 4, 2, 1, 1, 0, 0]`

### Example 2
- **Input:** `temperatures = [30, 40, 50, 60]`
- **Output:** `[1, 1, 1, 0]`

---

## Constraints

- $1 \le \text{temperatures.length} \le 10^5$
- $30 \le \text{temperatures}[i] \le 100$

---

## Pattern: Monotonic Stack of Indices

Store **indices** in the stack:
- When a warmer day `temperatures[i] > temperatures[st.top()]` is reached:
  - Pop `prevDay = st.top()`.
  - The wait time is $i - prevDay$.
  - Record `result[prevDay] = i - prevDay`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Monotonic Index Stack** | $O(N)$ | $O(N)$ |
