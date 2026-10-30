# Problem 8: Evaluate Reverse Polish Notation (LeetCode 150)

## Problem Statement

You are given an array of strings `tokens` that represents an arithmetic expression in a **Reverse Polish Notation (RPN)**.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:
- The valid operators are `'+'`, `'-'`, `'*'`, and `'/'`.
- Each operand may be an integer or another expression.
- The division between two integers always **truncates toward zero**.

---

## Examples

### Example 1
- **Input:** `tokens = ["2","1","+","3","*"]`
- **Output:** `9` (`((2 + 1) * 3) = 9`)

### Example 2
- **Input:** `tokens = ["4","13","5","/","+"]`
- **Output:** `6` (`(4 + (13 / 5)) = 6`)

---

## Constraints

- $1 \le \text{tokens.length} \le 10^4$
- `tokens[i]` is either an operator: `"+"`, `"-"`, `"*"`, or `"/"`, or an integer in the range `[-200, 200]`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **RPN Operand Stack** | $O(N)$ | $O(N)$ |
