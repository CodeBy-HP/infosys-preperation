# Minimum Cost to Make Array Zero (Divide & Conquer / Cartesian Tree DP)

## Problem Statement

You are given an array of $N$ positive integers. Your task is to transform all elements in the array to exactly $0$ by repeatedly applying either of the following two operations to minimize the total cost:

- **Operation 1:** Choose a contiguous subarray $[L, R]$ and subtract exactly $1$ from every element in that subarray. The cost of applying this operation once is $X$.
- **Operation 2:** Choose a specific single index $i$ where the element is strictly positive, and instantly set that element to $0$. The cost of applying this operation once is $Y$.

Return the **absolute minimum total cost** required to make every element in the array equal to $0$.

---

## Examples

### Example 1
- **Input:** `A = [1, 2, 3, 2, 1]`, `X = 2`, `Y = 3`
- **Output:** `6`
- **Explanation:**
  - If we only used Operation 2 on all 5 elements: $5 \times 3 = 15$.
  - Using Operation 1:
    - Decrement $[0, 4]$ by 1 (cost $2$). Remaining: `[0, 1, 2, 1, 0]`.
    - Decrement $[1, 3]$ by 1 (cost $2$). Remaining: `[0, 0, 1, 0, 0]`.
    - Decrement index 2 by 1 (cost $2$). Remaining: all zeros.
    - Total cost = $2 + 2 + 2 = 6$.
  - The minimum cost is $6$.

### Example 2
- **Input:** `A = [10, 10, 10]`, `X = 5`, `Y = 2`
- **Output:** `6`
- **Explanation:**
  - Using Operation 1 would cost $10 \times 5 = 50$.
  - Using Operation 2 on all 3 elements costs $3 \times 2 = 6$.
  - The minimum cost is $6$.

---

## Constraints

- $1 \le N \le 5000$ (or up to $10^5$ with Segment Tree RMQ)
- $1 \le A[i] \le 10^9$
- $1 \le X, Y \le 10^9$

---

## Algorithmic Paradigm: Divide & Conquer on Segment Minimums

For any contiguous segment $[L, R]$ that currently has a baseline subtracted value $\text{base}$:

### Two Competing Strategies:
1. **Option A (Point Resets):**
   Clear every element in the range individually using Operation 2:
   $$\text{Cost}_A = (R - L + 1) \times Y$$

2. **Option B (Subarray Decrement + Divide & Conquer):**
   Find the minimum element in the range: $m = \min_{i=L}^R A[i]$.
   - Apply Operation 1 to the entire range $(m - \text{base})$ times, which costs:
     $$\text{cost\_op1} = (m - \text{base}) \times X$$
   - This reduces all instances of $m$ to zero relative to the baseline.
   - The zeroed-out elements act as barriers that divide $[L, R]$ into independent subsegments where $A[i] > m$.
   - For each maximal contiguous subsegment $[l_k, r_k]$ where elements exceed $m$, recursively solve with the new baseline set to $m$:
     $$\text{Cost}_B = \text{cost\_op1} + \sum_{k} \text{solve}(l_k, r_k, m)$$

3. **Optimal Cost for Range $[L, R]$:**
   $$\text{Cost}(L, R, \text{base}) = \min(\text{Cost}_A, \text{Cost}_B)$$

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Average Time Complexity** | $\mathcal{O}(N \log N)$ (balanced splits) |
| **Worst-case Time Complexity** | $\mathcal{O}(N^2)$ without RMQ, $\mathcal{O}(N \log N)$ with Segment Tree RMQ |
| **Space Complexity** | $\mathcal{O}(N)$ recursion stack depth |

