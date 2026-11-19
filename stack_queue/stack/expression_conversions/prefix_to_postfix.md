# Prefix to Postfix Conversion

## Problem Statement

Given an arithmetic expression in **Prefix (Polish)** notation, convert it directly to **Postfix (Reverse Polish)** notation without building intermediate parse trees.

Prefix: `* + A B C`
Postfix: `A B + C *`

---

## Examples

### Example 1
- **Input:** `s = "*+AB-CD"`
- **Output:** `"AB+CD-*"`

### Example 2
- **Input:** `s = "*-A/BC-/AKL"`
- **Output:** `"ABC/-AK/L-*"`

---

## Algorithm (Right-to-Left Stack Scan)

1. Initialize an empty stack of strings `st`.
2. Iterate through the prefix string **from right to left**:
   - If the character is an operand (alphanumeric):
     - Push it as a string onto `st`.
   - If the character is an operator (`+`, `-`, `*`, `/`, `^`):
     - Pop `op1 = st.top()`, `st.pop()`.
     - Pop `op2 = st.top()`, `st.pop()`.
     - Form postfix token: `string exp = op1 + op2 + op`.
     - Push `exp` back onto `st`.
3. The remaining string on top of the stack is the final Postfix expression.

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Right-to-Left Stack Traversal** | $O(N)$ | $O(N)$ |

