# Problem 17: Rotate Image (LeetCode 48)

## Problem Statement

You are given an $n \times n$ 2D `matrix` representing an image, rotate the image by **90 degrees (clockwise)**.

You have to rotate the image **in-place**, which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

---

## Examples

### Example 1
```text
[1, 2, 3]        [7, 4, 1]
[4, 5, 6]  ===>  [8, 5, 2]
[7, 8, 9]        [9, 6, 3]
```
- **Input:** `matrix = [[1,2,3],[4,5,6],[7,8,9]]`
- **Output:** `[[7,4,1],[8,5,2],[9,6,3]]`

---

## Constraints

- $n == \text{matrix.length} == \text{matrix}[i]\text{.length}$
- $1 \le n \le 20$
- $-1000 \le \text{matrix}[i][j] \le 1000$

---

## Geometric Invariant: Transpose + Horizontal Reflection

$$\text{Rotate } 90^\circ \text{ Clockwise} \equiv \text{Transpose} + \text{Reverse each row}$$
1. **Transpose Matrix:** Swap `matrix[i][j]` with `matrix[j][i]` for all $j > i$.
2. **Reverse Rows:** Reverse each row horizontally (`reverse(row.begin(), row.end())`).

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Transpose + Reverse** | $O(N^2)$ | $O(1)$ in-place |
