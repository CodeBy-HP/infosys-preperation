# Problem: Paint House with Budget Constraint

## Problem Statement

There are $N$ houses arranged in a straight line, numbered from $0$ to $N - 1$. Each house must be painted using one of $C$ available colors (indexed $0$ to $C - 1$).

The cost of painting the $i$-th house with color $j$ is given by a cost matrix $\text{cost}[i][j]$.

You must satisfy the following conditions:
1. Every house must be painted in exactly one color.
2. **No two adjacent houses may share the same color** (i.e., $\text{color}[i] \ne \text{color}[i + 1]$).
3. The **total painting cost must not exceed** the given budget $B$.

Find the **minimum total painting cost**. If it is impossible to paint all houses within budget $B$, return/print **-1**.

---

## Examples

### Example 1
- **Input:**
  ```text
  3 3 20
  1 2 3
  1 4 6
  3 2 1
  ```
- **Output:** `4`
- **Explanation:**
  - House 0 painted color 0 (cost = 1)
  - House 1 painted color 1 (cost = 2) -> wait, cost[1][1] is 4, cost[1][0] is 1, but adjacent color rule means color 0 is forbidden.
  - Painting sequence:
    - House 0: color 0 (cost = 1)
    - House 1: color 1 (cost = 4) or color 2 (cost = 6) -> 1 + 4 = 5.
    - House 0: color 1 (cost = 2), House 1: color 0 (cost = 1), House 2: color 1 (cost = 2) -> Total = 2 + 1 + 2 = 5.
    - If House 0: color 2 (cost = 3), House 1: color 0 (cost = 1), House 2: color 2 (cost = 1) -> Total = 3 + 1 + 1 = 5.
    - Minimum total cost is within budget 20, returns minimum cost.

---

## Input & Output Format

### Input Format
```text
N C B
<N lines, each with C integers representing cost[i][0...C-1]>
```

### Output Format
Print a single integer: the minimum total cost if $\le B$, otherwise `-1`.

---

## Constraints

- $1 \le N \le 10^5$
- $2 \le C \le 100$
- $1 \le B \le 10^9$
- $1 \le \text{cost}[i][j] \le 10^4$

---

## Dynamic Programming Formulation

1. **State:**
   - $\text{dp}[i][c]$: minimum cost to paint houses $0 \dots i$ such that house $i$ is painted with color $c$.
2. **Recurrence Relation:**
   $$\text{dp}[i][c] = \text{cost}[i][c] + \min_{k \ne c} \text{dp}[i - 1][k]$$
3. **Base Case:**
   - $\text{dp}[0][c] = \text{cost}[0][c]$ for all $0 \le c < C$.
4. **Final Answer:**
   - $\text{result} = \min_{c} \text{dp}[N - 1][c]$.
   - If $\text{result} \le B$, return $\text{result}$; otherwise return $-1$.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Top-Down (Recursion + Memoization)** | $O(N \cdot C^2)$ | $O(N \cdot C)$ |
| **Bottom-Up Tabulation** | $O(N \cdot C^2)$ | $O(N \cdot C)$ |
| **Space-Optimized Iterative** | $O(N \cdot C^2)$ | $O(C)$ |
| **Optimal Prefix/Suffix Min Optimization** | $O(N \cdot C)$ | $O(C)$ |

