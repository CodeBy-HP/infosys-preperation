# Problem 5: Trapping Rain Water (LeetCode 42)

## Problem Statement

Given $n$ non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

---

## Examples

### Example 1
- **Input:** `height = [0,1,0,2,1,0,1,3,2,1,2,1]`
- **Output:** `6`

---

## Constraints

- $n == \text{height.length}$
- $1 \le n \le 2 \times 10^4$
- $0 \le \text{height}[i] \le 10^5$

---

## Two Solutions: Two Pointers vs Monotonic Stack

### 1. Two Pointers ($O(1)$ Space)
Maintain `leftMax` and `rightMax`:
- If `height[left] < height[right]`: water trapped at `left` is bounded by `leftMax`: $\max(0, \text{leftMax} - \text{height}[left])$. Advance `left++`.
- Else: water trapped at `right` is bounded by `rightMax`. Advance `right--`.

### 2. Monotonic Stack (Horizontal Slices)
Stack stores decreasing heights. When a taller bar is seen:
- Pop `bottom = st.top()`.
- Bounded water height: $\min(\text{height}[left], \text{height}[i]) - \text{height}[bottom]$.
- Bounded width: $i - left - 1$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Two Pointers** | $O(N)$ | $O(1)$ strictly constant |
| **Monotonic Stack** | $O(N)$ | $O(N)$ stack space |
