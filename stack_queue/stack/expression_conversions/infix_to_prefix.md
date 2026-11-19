# Infix to Prefix Conversion

## Problem Statement

Given an infix mathematical expression `s`, convert it into its **Prefix (Polish Notation)** representation.

Infix: Operators between operands (e.g., `(A + B) * C`).
Prefix: Operators placed before their operands (e.g., `* + A B C`).

---

## Examples

### Example 1
- **Input:** `s = "(A+B)*C-D+F"`
- **Output:** `"+-*+ABCDF"`

### Example 2
- **Input:** `s = "x+y*z/w+u"`
- **Output:** `"++x/*yzwu"`

---

## Algorithm (Reverse Infix $\to$ Modified Postfix $\to$ Reverse)

1. **Reverse** the infix expression.
2. **Invert Parentheses:** Replace every `(` with `)` and every `)` with `(`.
3. **Convert to Postfix:** Run modified Shunting-Yard where:
   - For left-associative operators (`+`, `-`, `*`, `/`), pop only when `precedence(top) > precedence(curr)`.
   - For right-associative operators (`^`), pop when `precedence(top) >= precedence(curr)`.
4. **Reverse the Result:** Reversing the generated postfix expression yields the exact Prefix expression!

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Reversals & Shunting-Yard** | $O(N)$ | $O(N)$ |

