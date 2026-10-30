# Problem 19: Set Matrix Zeroes (LeetCode 73)

## Problem Statement

Given an $m \times n$ integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`'s.

You must do it **in place**.

**Follow up:** Could you devise a constant space solution?

---

## Examples

### Example 1
```text
[1, 1, 1]        [1, 0, 1]
[1, 0, 1]  ===>  [0, 0, 0]
[1, 1, 1]        [1, 0, 1]
```
- **Input:** `matrix = [[1,1,1],[1,0,1],[1,1,1]]`
- **Output:** `[[1,0,1],[0,0,0],[1,0,1]]`

---

## Constraints

- $m == \text{matrix.length}$
- $n == \text{matrix}[0]\text{.length}$
- $1 \le m, n \le 200$

---

## Pattern: Using 1st Row and 1st Column as Marker Storage ($O(1)$ Space)

Instead of allocating $O(M + N)$ marker arrays, use `matrix[0][col]` and `matrix[row][0]` as the zero flags:
1. Use separate variable `firstColZero` to track whether the original first column has a zero.
2. For all other cells $(r, c)$: if `matrix[r][c] == 0`, mark `matrix[r][0] = 0` and `matrix[0][c] = 0`.
3. In a second bottom-up/right-to-left pass, zero cells based on the markers.
4. Finally zero first row and first column if flagged.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **In-Place Boundary Flags** | $O(M \times N)$ | $O(1)$ strictly constant space |
