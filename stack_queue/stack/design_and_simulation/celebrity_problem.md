# The Celebrity Problem

## Problem Statement

A **celebrity** is a person who is known to everyone else at a party, but does not know anyone in return.

Given a square matrix $M$ of size $N \times N$, where $M[i][j] = 1$ denotes that person $i$ knows person $j$, and $M[i][j] = 0$ denotes that person $i$ does not know person $j$, determine whether a celebrity is present. If yes, return their 0-based index. If no celebrity exists, return `-1`.

Note: A person cannot know themselves (the diagonal $M[i][i]$ is typically $0$).

---

## Examples

### Example 1
- **Input:**
  ```text
  M = [
    [0, 1, 0],
    [0, 0, 0],
    [0, 1, 0]
  ]
  ```
- **Output:** `1`
- **Explanation:**
  - Person 0 knows Person 1.
  - Person 2 knows Person 1.
  - Person 1 knows nobody ($M[1][0]=0, M[1][1]=0, M[1][2]=0$).
  - Everyone knows Person 1, and Person 1 knows no one. Thus, Person 1 is the celebrity.

### Example 2
- **Input:**
  ```text
  M = [
    [0, 1],
    [1, 0]
  ]
  ```
- **Output:** `-1`
- **Explanation:** Person 0 knows Person 1 and Person 1 knows Person 0. Neither satisfies the condition.

---

## Constraints

- $2 \le N \le 3000$
- $M[i][j] \in \{0, 1\}$
- $M[i][i] = 0$

---

## Elimination Principles

### 1. The Stack Elimination Invariant
Consider two candidates $A$ and $B$:
- If $A$ knows $B$, $A$ **cannot** be a celebrity (celebrities know nobody). Discard $A$.
- If $A$ does not know $B$, $B$ **cannot** be a celebrity (everyone must know the celebrity). Discard $B$.
In each comparison, exactly one candidate is eliminated. After $N - 1$ comparisons using a LIFO stack, only one potential candidate remains.

### 2. Verification Pass
Elimination only guarantees that if a celebrity exists, it must be the surviving candidate $C$. A final $O(N)$ pass checks:
1. Row $C$: $\sum_{j=0}^{N-1} M[C][j] = 0$ (celebrity knows nobody).
2. Column $C$: $\sum_{i=0, i \ne C}^{N-1} M[i][C] = N - 1$ (everyone knows the celebrity).

---

## Complexity Analysis

| Approach | Comparisons | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- | :--- |
| **Stack Elimination** | $3(N - 1)$ | $O(N)$ | $O(N)$ |
| **Two Pointers Elimination** | $3(N - 1)$ | $O(N)$ | $O(1)$ |
| **Degree Counting Matrix** | $N^2$ | $O(N^2)$ | $O(N)$ |

