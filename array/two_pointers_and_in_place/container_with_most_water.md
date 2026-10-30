# Problem 3: Container With Most Water (LeetCode 11)

## Problem Statement

You are given an integer array `height` of length $n$. There are $n$ vertical lines drawn such that the two endpoints of the $i^{\text{th}}$ line are $(i, 0)$ and $(i, \text{height}[i])$.

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the **maximum amount of water** a container can store.

Notice that you may not slant the container.

---

## Examples

### Example 1
- **Input:** `height = [1, 8, 6, 2, 5, 4, 8, 3, 7]`
- **Output:** `49`
- **Explanation:** The max area is between index 1 (height 8) and index 8 (height 7): $\text{width} = 8 - 1 = 7$, $\text{height} = \min(8, 7) = 7 \implies 7 \times 7 = 49$.

---

## Constraints

- $n == \text{height.length}$
- $2 \le n \le 10^5$
- $0 \le \text{height}[i] \le 10^4$

---

## Mathematical Proof: Shrinking the Shorter Line

$$\text{Area} = (R - L) \times \min(\text{height}[L], \text{height}[R])$$
Suppose $\text{height}[L] \le \text{height}[R]$:
- If we move $R$ inward ($R - 1$), the width $(R - L)$ strictly decreases, and the height can never exceed $\text{height}[L]$. Therefore, keeping $L$ while moving $R$ inward can **never** produce a strictly larger area!
- The only hope of achieving a larger area is by discarding the bottleneck line $L$ and advancing `left++`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Two-Pointer Bottleneck Elimination** | $O(N)$ | $O(1)$ |
