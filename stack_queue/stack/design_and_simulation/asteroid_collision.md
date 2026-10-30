# Problem 12: Asteroid Collision (LeetCode 735)

## Problem Statement

We are given an array `asteroids` of integers representing asteroids in a row.

For each asteroid:
- The absolute value represents its size.
- The sign represents its direction (`+` means right, `-` means left).
- Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet:
- The smaller one explodes.
- If both are the same size, both explode.
- Two asteroids moving in the same direction never meet.

---

## Examples

### Example 1
- **Input:** `asteroids = [5, 10, -5]`
- **Output:** `[5, 10]` (`10` and `-5` collide; `10` survives)

### Example 2
- **Input:** `asteroids = [8, -8]`
- **Output:** `[]` (Both explode)

### Example 3
- **Input:** `asteroids = [10, 2, -5]`
- **Output:** `[10]`

---

## Constraints

- $2 \le \text{asteroids.length} \le 10^4$
- $-1000 \le \text{asteroids}[i] \le 1000$
- `asteroids[i] != 0`

---

## Collision Invariant

Collision occurs **if and only if** stack top moves right (`st.top() > 0`) and incoming asteroid moves left (`curr < 0`).
- While `st.top() > 0 && curr < 0`:
  - If `st.top() < abs(curr)`: top explodes (`st.pop()`), incoming continues fighting!
  - If `st.top() == abs(curr)`: both explode (`st.pop()`), break.
  - If `st.top() > abs(curr)`: incoming explodes, break.
- If incoming asteroid survives all battles, push it onto the stack.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Stack Collision Battle** | $O(N)$ | $O(N)$ |
