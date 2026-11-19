# Postfix to Infix Conversion

## Problem Statement

Given an arithmetic expression in **Postfix (Reverse Polish)** notation, convert it into an equivalent fully parenthesized **Infix** expression.

Postfix: `A B + C *`
Infix: `((A + B) * C)`

---

## Examples

### Example 1
- **Input:** `s = "ab+c*"`
- **Output:** `"((a+b)*c)"`

### Example 2
- **Input:** `s = "ab+cd-*"`
- **Output:** `"((a+b)*(c-d))"`

---

## Algorithm (Left-to-Right Stack Scan)

1. Initialize an empty stack of strings `st`.
2. Iterate through the postfix string **from left to right** (index $0$ to $n - 1$):
   - If character is an operand (alphanumeric):
     - Push it as a string onto `st`.
   - If character is an operator (`+`, `-`, `*`, `/`, `^`):
     - Pop `op2 = st.top()`, `st.pop()`.
     - Pop `op1 = st.top()`, `st.pop()`.
     - Form compound expression: `string exp = "(" + op1 + op + op2 + ")"`.
     - Push `exp` back onto `st`.
3. The final element on the stack is the converted Infix expression.

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Left-to-Right Stack Scan** | $O(N)$ | $O(N)$ |

