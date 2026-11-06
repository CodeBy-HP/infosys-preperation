# Pascal's Triangle III (Element at Row R, Column C)

## Problem Statement

Given two integers $r$ (row number) and $c$ (column number), where both are **1-indexed**, find and return the element at position $(r, c)$ in Pascal's triangle.

```text
Row 1:        1
Row 2:       1 1
Row 3:      1 2 1
Row 4:     1 3 3 1
Row 5:    1 4 6 4 1
```

For instance, at row $5$, column $3$, the value is $6$.

---

## Examples

### Example 1
- **Input:** `r = 5`, `c = 3`
- **Output:** `6`

### Example 2
- **Input:** `r = 1`, `c = 1`
- **Output:** `1`

### Example 3
- **Input:** `r = 6`, `c = 2`
- **Output:** `5`

---

## Constraints

- $1 \le c \le r \le 50$

---

## Mathematical Formulation

The element at row $r$ and column $c$ (1-indexed) in Pascal's Triangle is given by the binomial coefficient:
$$\text{Value}(r, c) = \binom{r - 1}{c - 1} = \frac{(r - 1)!}{(c - 1)! \times (r - c)!}$$

Expanding the formula:
$$\binom{n}{k} = \frac{n \times (n - 1) \times (n - 2) \times \dots \times (n - k + 1)}{1 \times 2 \times 3 \times \dots \times k}$$
where $n = r - 1$ and $k = c - 1$.

### Optimal Iterative Calculation in $\mathcal{O}(c)$:
We can compute this product iteratively in $O(c)$ steps:
```cpp
long long res = 1;
for (int i = 0; i < c - 1; ++i) {
    res = res * (r - 1 - i);
    res = res / (i + 1);
}
```
*Note:* Dividing by $(i + 1)$ immediately after multiplication is mathematically guaranteed to leave no remainder because the product of any $(i + 1)$ consecutive integers is always divisible by $(i + 1)!$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Generate Triangle** | $\mathcal{O}(r^2)$ | $\mathcal{O}(r^2)$ |
| **Iterative Combination** | $\mathcal{O}(c)$ | $\mathcal{O}(1)$ |

