# Infix to Postfix Conversion

## Problem Statement

Given an infix mathematical expression `s` containing operands (alphanumeric characters), binary operators (`+`, `-`, `*`, `/`, `^`), and parentheses `(` and `)`, convert the expression to its **Postfix (Reverse Polish Notation)** representation.

Infix: Operators placed between operands (e.g., `A + B`).
Postfix: Operators placed after their operands (e.g., `A B +`).

---

## Examples

### Example 1
- **Input:** `s = "a+b*(c^d-e)^(f+g*h)-i"`
- **Output:** `"abcd^e-fgh*+^*+i-"`

### Example 2
- **Input:** `s = "(p+q)*(m-n)"`
- **Output:** `"pq+mn-*"`

---

## Operator Precedence & Associativity

| Operator | Precedence | Associativity |
| :--- | :--- | :--- |
| `^` | 3 (Highest) | Right-to-Left |
| `*`, `/` | 2 | Left-to-Right |
| `+`, `-` | 1 (Lowest) | Left-to-Right |

---

## Algorithm (Shunting-Yard)

1. Initialize an empty stack of operators and an output string `result`.
2. Iterate through each character `c` of the infix expression:
   - If `c` is an operand, append it to `result`.
   - If `c == '('`: Push onto stack.
   - If `c == ')'`: Pop and append operators to `result` until `'('` is encountered, then discard `'('`.
   - If `c` is an operator:
     - While stack is not empty and top is an operator with:
       - Greater precedence than `c`, OR
       - Equal precedence and left-associative:
       pop from stack and append to `result`.
     - Push `c` onto the stack.
3. Pop all remaining operators from the stack and append to `result`.

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Shunting-Yard Conversion** | $O(N)$ | $O(N)$ stack space |

