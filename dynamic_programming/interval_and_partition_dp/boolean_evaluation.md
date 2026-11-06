# Different Ways to Evaluate a Boolean Expression (Boolean Parenthesization)

## Problem Overview
Given a boolean expression with following symbols:
- Symbols: `'T'` (true), `'F'` (false)
- Operators: `'&'` (AND), `'|'` (OR), `'^'` (XOR)

Count the number of ways we can parenthesize the expression so that the value of expression evaluates to **True**.
Return the result modulo $10^9 + 7$ (or $1003$ depending on specific platform constraints).

---

## 3D / Dual Matrix Interval DP Formulation
We maintain two states for every sub-expression interval $[i, j]$ (where $i$ and $j$ represent indices of operands):
- $dp_T[i][j]$: Total ways to evaluate interval $[i, j]$ to **True**.
- $dp_F[i][j]$: Total ways to evaluate interval $[i, j]$ to **False**.

### Operator Truth Tables
For each operator at position $k$ ($i < k \le j$):
Let $LT = dp_T[i][k - 1]$, $LF = dp_F[i][k - 1]$, $RT = dp_T[k][j]$, $RF = dp_F[k][j]$.
- **AND (`&`):**
  - $\text{True} = LT \times RT$
  - $\text{False} = (LT \times RF) + (LF \times RT) + (LF \times RF)$
- **OR (`|`):**
  - $\text{True} = (LT \times RT) + (LT \times RF) + (LF \times RT)$
  - $\text{False} = LF \times RF$
- **XOR (`^`):**
  - $\text{True} = (LT \times RF) + (LF \times RT)$
  - $\text{False} = (LT \times RT) + (LF \times RF)$

---

## Complexity Analysis
- **Time Complexity:** $O(N^3)$ where $N$ is the number of operands.
- **Auxiliary Space:** $O(N^2)$

