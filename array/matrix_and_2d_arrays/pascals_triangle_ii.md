# Pascal's Triangle II (LeetCode 119)

## Problem Statement

Given an integer `rowIndex`, return the **`rowIndex`-th** (0-indexed) row of **Pascal's triangle**.

---

## Examples

### Example 1
- **Input:** `rowIndex = 3`
- **Output:** `[1, 3, 3, 1]`

### Example 2
- **Input:** `rowIndex = 0`
- **Output:** `[1]`

### Example 3
- **Input:** `rowIndex = 1`
- **Output:** `[1, 1]`

---

## Constraints

- $0 \le \text{rowIndex} \le 33$

---

## Approaches

### Approach 1: Full Triangle Generation (Brute Force)
Generate all rows from $0$ up to `rowIndex` using a 2D vector, and return the last row.
- **Time Complexity:** $\mathcal{O}(K^2)$
- **Space Complexity:** $\mathcal{O}(K^2)$

### Approach 2: 1D Array In-Place Backward Sweep (Better)
Maintain a single 1D vector `row` of size `rowIndex + 1` initialized with `1`.
For each row $i$ from $1$ to `rowIndex`:
Update backwards from $j = i - 1$ down to $1$:
$$\text{row}[j] = \text{row}[j] + \text{row}[j - 1]$$
- **Time Complexity:** $\mathcal{O}(K^2)$
- **Space Complexity:** $\mathcal{O}(K)$

### Approach 3: Multiplicative Combinatorial Progression (Optimal)
In row $K$, the element at column $c$ (0-indexed) is:
$$\text{elem}[c] = \binom{K}{c} = \frac{K \times (K - 1) \times \dots \times (K - c + 1)}{1 \times 2 \times \dots \times c}$$

Notice the ratio between consecutive elements:
$$\frac{\binom{K}{c}}{\binom{K}{c - 1}} = \frac{K - c + 1}{c}$$

Therefore, each subsequent element is computed directly in $\mathcal{O}(1)$ from the previous element:
$$\text{elem}[c] = \text{elem}[c - 1] \times \frac{K - c + 1}{c}$$
- **Time Complexity:** $\mathcal{O}(K)$ strictly linear
- **Space Complexity:** $\mathcal{O}(1)$ auxiliary space

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Full Triangle** | $\mathcal{O}(K^2)$ | $\mathcal{O}(K^2)$ |
| **1D Backward DP** | $\mathcal{O}(K^2)$ | $\mathcal{O}(K)$ |
| **Combinatorial Ratio** | $\mathcal{O}(K)$ | $\mathcal{O}(1)$ auxiliary |

