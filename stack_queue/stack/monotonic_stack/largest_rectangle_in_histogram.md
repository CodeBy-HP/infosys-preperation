# Problem 4: Largest Rectangle in Histogram (LeetCode 84)

## Problem Statement

Given an array of integers `heights` representing the histogram's bar height where the width of each bar is 1, return the **area of the largest rectangle** in the histogram.

---

## Examples

### Example 1
```text
      6
    5 #
    # #   3
  2 # # 2 #
# # # # # #
2 1 5 6 2 3
```
- **Input:** `heights = [2, 1, 5, 6, 2, 3]`
- **Output:** `10` (The rectangle formed by heights 5 and 6: $5 \times 2 = 10$)

---

## Constraints

- $1 \le \text{heights.length} \le 10^5$
- $0 \le \text{heights}[i] \le 10^4$

---

## Algorithmic Invariant: Nearest Smaller Boundaries

For each bar $i$ of height $H$:
- How far left can it extend? Until the first bar smaller than $H$: `leftSmaller`.
- How far right can it extend? Until the first bar smaller than $H$: `rightSmaller`.
$$\text{Width} = \text{rightSmaller} - \text{leftSmaller} - 1$$
$$\text{Area} = H \times \text{Width}$$

### One-Pass Stack Optimization:
Maintain a strictly increasing stack of indices:
- When a smaller bar is encountered, pop `mid = st.top()`.
- Its height is `heights[mid]`.
- Its right boundary is the current index $i$.
- Its left boundary is the new `st.top()` (or $-1$ if stack is empty).
$$\text{width} = i - \text{st.top}() - 1$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Single-Pass Monotonic Stack** | $O(N)$ | $O(N)$ |
