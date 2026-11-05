# Problem 8: Fraction to Recurring Decimal (LeetCode 166)

## Problem Statement

Given two integers representing the `numerator` and `denominator` of a fraction, return the fraction in string format.

If the fractional part is repeating, enclose the repeating part in parentheses.

If multiple answers exist, return any of them.

---

## Examples

### Example 1
- **Input:** `numerator = 1`, `denominator = 2`
- **Output:** `"0.5"`

### Example 2
- **Input:** `numerator = 2`, `denominator = 1`
- **Output:** `"2"`

### Example 3
- **Input:** `numerator = 4`, `denominator = 333`
- **Output:** `"0.(012)"`

---

## Mathematical Principle: Pigeonhole Principle on Remainder Sequences

In long division of $\frac{a}{b}$:
1. Integer quotient: $\lfloor a / b \rfloor$
2. Remainder: $r = a \pmod b$

To generate subsequent decimal places:
- Multiply remainder by 10: $r' = 10 \times r$.
- Next decimal digit: $d = \lfloor r' / b \rfloor$.
- New remainder: $r_{\text{next}} = r' \pmod b$.

### Why Decimals Either Terminate or Repeat:
The possible non-zero values of the remainder modulo $b$ are strictly bounded within:
$$\{1, 2, 3, \dots, |b| - 1\}$$

By the **Pigeonhole Principle**:
- If a remainder reaches $0$, the decimal terminates.
- If $0$ is never reached, within at most $|b|$ steps, a remainder **must repeat**.
- Once a remainder repeats, all subsequent digits and remainders will replicate the exact same sequence forever (a recurring cycle).

### Hash Map Cycle Detection:
We store `remainder -> position in result string`. When the current remainder is already in the map, insert `'('` at the recorded position and append `')'` at the end.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $\mathcal{O}(|denominator|)$ at most $|denominator|$ unique remainders |
| **Space Complexity** | $\mathcal{O}(|denominator|)$ to store seen remainder positions |

