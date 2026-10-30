# Problem 9: Basic Calculator II (LeetCode 227)

## Problem Statement

Given a string `s` which represents an expression, evaluate this expression and return its value. 

The integer division should **truncate toward zero**.

You may assume that the given expression is always valid. All intermediate results will fit in a 32-bit signed integer.

**Note:** You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as `eval()`.

---

## Examples

### Example 1
- **Input:** `s = "3+2*2"`
- **Output:** `7`

### Example 2
- **Input:** `s = " 3/2 "`
- **Output:** `1`

---

## Constraints

- $1 \le \text{s.length} \le 3 \times 10^5$
- `s` consists of integers and operators (`'+'`, `'-'`, `'*'`, `'/'`) separated by spaces.

---

## Pattern: Operator Precedence Delayed Execution

Accumulate current number `currentNum`:
- When an operator or end of string is encountered:
  - If previous sign was `'+'`: push `+currentNum`.
  - If previous sign was `'-'`: push `-currentNum`.
  - If previous sign was `'*'`: pop top, multiply by `currentNum`, and push back.
  - If previous sign was `'/'`: pop top, divide by `currentNum`, and push back.
- Sum all elements remaining in stack at the end.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Stack Precedence Delay** | $O(N)$ | $O(N)$ or $O(1)$ with rolling sum |
