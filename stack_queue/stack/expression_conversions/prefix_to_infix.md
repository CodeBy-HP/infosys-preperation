# Prefix to Infix Conversion

## Problem Statement

Given a string `s` representing an arithmetic expression in **Prefix (Polish)** notation, convert it to an equivalent fully parenthesized **Infix** expression.

Prefix: `* + A B - C D`
Infix: `((A + B) * (C - D))`

---

## Examples

### Example 1
- **Input:** `s = "*+AB-CD"`
- **Output:** `"((A+B)*(C-D))"`

### Example 2
- **Input:** `s = "*-A/BC-/AKL"`
- **Output:** `"((A-(B/C))*((A/K)-L))"`

---

## Algorithm (Right-to-Left Stack Scan)

1. Initialize a stack of strings `st`.
2. Iterate through the prefix string **from right to left** (index $n - 1$ down to $0$):
   - If character is an operand (alphanumeric):
     - Push it as a string onto `st`.
   - If character is an operator (`+`, `-`, `*`, `/`, `^`):
     - Pop `op1 = st.top()`, `st.pop()`.
     - Pop `op2 = st.top()`, `st.pop()`.
     - Form compound expression string: `string exp = "(" + op1 + op + op2 + ")"`.
     - Push `exp` back onto `st`.
3. The final element remaining on `st.top()` is the completed Infix expression.

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Right-to-Left Stack Traversal** | $O(N)$ | $O(N)$ string stack |

