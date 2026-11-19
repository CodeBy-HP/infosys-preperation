# Postfix to Prefix Conversion

## Problem Statement

Given an arithmetic expression in **Postfix (Reverse Polish)** notation, convert it into an equivalent **Prefix (Polish)** notation.

Postfix: `A B + C *`
Prefix: `* + A B C`

---

## Examples

### Example 1
- **Input:** `s = "AB+CD-*"`
- **Output:** `"*+AB-CD"`

### Example 2
- **Input:** `s = "ABC/-AK/L-*"`
- **Output:** `"*-A/BC-/AKL"`

---

## Algorithm (Left-to-Right Stack Scan)

1. Initialize an empty stack of strings `st`.
2. Iterate through the postfix string **from left to right**:
   - If the character is an operand (alphanumeric):
     - Push it as a string onto `st`.
   - If the character is an operator (`+`, `-`, `*`, `/`, `^`):
     - Pop `op2 = st.top()`, `st.pop()`.
     - Pop `op1 = st.top()`, `st.pop()`.
     - Form prefix token: `string exp = op + op1 + op2`.
     - Push `exp` back onto `st`.
3. The remaining string on the stack is the final Prefix expression.

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Left-to-Right Stack Scan** | $O(N)$ | $O(N)$ |

