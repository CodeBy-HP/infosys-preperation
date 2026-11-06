# Boolean Evaluation / Boolean Parenthesization (GFG)

## Problem Statement

Given a boolean expression `s` of length $N$ with following symbols and operators:
- Symbols: `'T'` (true), `'F'` (false)
- Operators: `'&'` (AND), `'|'` (OR), `'^'` (XOR)

Count the total number of ways we can parenthesize the expression such that the value of the entire expression evaluates to **True**.

Since the answer can be very large, return the result modulo $10^9 + 7$ (or $1003$ depending on specific platform configurations).

---

## Examples

### Example 1:
```text
Input: s = "T|T&F^T"
Output: 4
Explanation:
The expression has length 7: symbols are 'T', 'T', 'F', 'T' and operators are '|', '&', '^'.
The 4 valid parenthesizations evaluating to True are:
1. ((T|T)&(F^T)) -> (T & T) = T
2. (T|(T&(F^T))) -> (T | (T & T)) = T | T = T
3. (((T|T)&F)^T) -> ((T & F) ^ T) = F ^ T = T
4. (T|((T&F)^T)) -> (T | (F ^ T)) = T | T = T
```

### Example 2:
```text
Input: s = "T^F|F"
Output: 2
Explanation:
Two possible ways:
1. ((T^F)|F) -> (T | F) = T
2. (T^(F|F)) -> (T ^ F) = T
Both evaluate to True.
```

---

## Constraints

- $1 \le |s| \le 100$
- $s$ is a syntactically valid expression alternating between boolean literals (`'T'`, `'F'`) and operators (`'&'`, `'|'`, `'^'`).

---

## Recurrence Formulation & Algorithmic Approaches

Because operators like XOR (`^`) evaluate to True when one operand is True and the other is False, we cannot merely count the ways to evaluate to True. We must simultaneously compute **both True and False ways**.

### 1. State Definition
Let $i$ and $j$ be indices in the expression ($i \le j$), always pointing to operand characters (even indices: $0, 2, 4, \dots$):
- $dp_T[i][j]$: Number of ways to parenthesize sub-expression $s[i \dots j]$ to evaluate to **True**.
- $dp_F[i][j]$: Number of ways to parenthesize sub-expression $s[i \dots j]$ to evaluate to **False**.

### 2. Base Cases (Single Operand $i == j$)
- If $s[i] == \text{'T'}$: $dp_T[i][i] = 1, \; dp_F[i][i] = 0$
- If $s[i] == \text{'F'}$: $dp_T[i][i] = 0, \; dp_F[i][i] = 1$

### 3. Transition via Splitting Operators
For each operator at position $k$ ($i < k < j$ with step $+2$):
Let:
- $LT = dp_T[i][k - 1], \quad LF = dp_F[i][k - 1]$
- $RT = dp_T[k + 1][j], \quad RF = dp_F[k + 1][j]$

Depending on operator $s[k]$:
- **AND (`&`):**
  - $\text{True Ways} += LT \times RT$
  - $\text{False Ways} += (LT \times RF) + (LF \times RT) + (LF \times RF)$
- **OR (`|`):**
  - $\text{True Ways} += (LT \times RT) + (LT \times RF) + (LF \times RT)$
  - $\text{False Ways} += LF \times RF$
- **XOR (`^`):**
  - $\text{True Ways} += (LT \times RF) + (LF \times RT)$
  - $\text{False Ways} += (LT \times RT) + (LF \times RF)$

Apply modulo $10^9 + 7$ at each addition.

---

## Complexity Analysis

| Metric | Interval DP (Tabulation / Memoization) |
| :--- | :--- |
| **Time Complexity** | $O(N^3)$ where $N$ is the number of operands |
| **Auxiliary Space** | $O(N^2)$ for 3D state cache $dp[N][N][2]$ |
