# Problem 18: Spiral Matrix (LeetCode 54)

## Problem Statement

Given an $m \times n$ `matrix`, return all elements of the `matrix` in **spiral order**.

---

## Examples

### Example 1
```text
[ 1, 2, 3 ]
[ 4, 5, 6 ]
[ 7, 8, 9 ]
```
- **Input:** `matrix = [[1,2,3],[4,5,6],[7,8,9]]`
- **Output:** `[1, 2, 3, 6, 9, 8, 7, 4, 5]`

---

## Constraints

- $m == \text{matrix.length}$
- $n == \text{matrix}[i]\text{.length}$
- $1 \le m, n \le 10$

---

## Pattern: 4-Boundary Shrinking Loop

Maintain four bounding variables: `top = 0`, `bottom = m - 1`, `left = 0`, `right = n - 1`:
1. Traverse right: `top++`.
2. Traverse down: `right--`.
3. If `top <= bottom`: traverse left, `bottom--`.
4. If `left <= right`: traverse up, `left++`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Boundary Shrink** | $O(M \times N)$ | $O(1)$ auxiliary (excluding output) |
