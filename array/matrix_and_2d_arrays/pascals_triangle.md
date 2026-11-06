# Pascal's Triangle (LeetCode 118 / Pascal's Triangle I)

## Problem Statement

Given an integer `numRows`, return the first `numRows` of **Pascal's triangle**.

In Pascal's triangle, each number is the sum of the two numbers directly above it:
```text
        1
       1 1
      1 2 1
     1 3 3 1
    1 4 6 4 1
```

---

## Examples

### Example 1
- **Input:** `numRows = 5`
- **Output:** `[[1], [1, 1], [1, 2, 1], [1, 3, 3, 1], [1, 4, 6, 4, 1]]`

### Example 2
- **Input:** `numRows = 1`
- **Output:** `[[1]]`

---

## Constraints

- $1 \le \text{numRows} \le 30$

---

## Mathematical Formulation & Approaches

### Approach 1: Cell-by-cell Combination Formula $\binom{n}{r}$ (Brute Force)
Each element at row $r$ (0-indexed) and column $c$ (0-indexed) is given by:
$$\text{val} = \binom{r}{c} = \frac{r!}{c! (r - c)!}$$
Computing this independently for every single cell takes $\mathcal{O}(N^3)$ time and can cause intermediate 64-bit integer overflows.

### Approach 2: Dynamic Programming In-Place Row Generation (Optimal)
Notice that each row $i$ has $(i + 1)$ elements:
1. The first and last elements of every row are always `1`:
   $$\text{triangle}[i][0] = 1, \quad \text{triangle}[i][i] = 1$$
2. Any interior element is the sum of the two elements directly above it in row $i - 1$:
   $$\text{triangle}[i][j] = \text{triangle}[i - 1][j - 1] + \text{triangle}[i - 1][j] \quad (1 \le j < i)$$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Combination per cell** | $\mathcal{O}(N^3)$ | $\mathcal{O}(1)$ auxiliary |
| **Row-by-Row DP** | $\mathcal{O}(N^2)$ | $\mathcal{O}(1)$ auxiliary (excluding result) |

