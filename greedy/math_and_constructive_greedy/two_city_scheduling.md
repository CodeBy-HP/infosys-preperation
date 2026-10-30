# Two City Scheduling with Transit Cost

## Problem Statement

A company is organizing a conference in two cities, **City A** and **City B**. There are $2N$ employees, and **exactly $N$ employees must be assigned to each city**.

For each employee $i \in [0, 2N - 1]$:
- The cost of traveling directly to **City A** is $A[i]$.
- To travel to **City B**, the employee must first stop at a transit hub. The total cost to travel to City B is:
  $$\text{cost\_B}[i] = \min(A[i],\, B[i]) + B[i]$$
  where $A[i]$ is the direct flight cost to City A and $B[i]$ is the transit flight cost to City B.

Determine the **minimum total travel cost** to send exactly $N$ employees to City A and $N$ employees to City B.

---

## Examples

### Example 1
- **Input:**
  ```text
  N = 2 (Total employees = 4)
  A = [10, 20, 30, 40]
  B = [30, 20, 10, 20]
  ```
- **Explanation:**
  - Costs to City B:
    - Employee 0: $\min(10, 30) + 30 = 10 + 30 = 40$ (Diff vs A: $40 - 10 = +30$)
    - Employee 1: $\min(20, 20) + 20 = 20 + 20 = 40$ (Diff vs A: $40 - 20 = +20$)
    - Employee 2: $\min(30, 10) + 10 = 10 + 10 = 20$ (Diff vs A: $20 - 30 = -10$)
    - Employee 3: $\min(40, 20) + 20 = 20 + 20 = 40$ (Diff vs A: $40 - 40 = 0$)
  - Greedily pick the 2 smallest differences to send to City B:
    - Employee 2 (diff = -10) $\rightarrow$ City B (cost 20)
    - Employee 3 (diff = 0) $\rightarrow$ City B (cost 40)
    - Employee 0 $\rightarrow$ City A (cost 10)
    - Employee 1 $\rightarrow$ City A (cost 20)
  - Total minimum cost = $20 + 40 + 10 + 20 = 90$.

---

## Constraints

- $1 \le N \le 10^5$ (total employees $2N \le 2 \times 10^5$)
- $1 \le A[i], B[i] \le 10^5$

---

## The Greedy Opportunity Cost Formulation

Suppose we initially send **all $2N$ employees to City A**.
The total base cost is:
$$\text{Base Cost} = \sum_{i=0}^{2N - 1} A[i]$$

Now we must choose exactly $N$ employees to divert to City B instead.
The change in cost (opportunity cost / delta) for diverting employee $i$ is:
$$\Delta[i] = \text{cost\_B}[i] - A[i] = (\min(A[i], B[i]) + B[i]) - A[i]$$

To minimize the final total cost, we greedily select the **$N$ employees with the smallest $\Delta[i]$**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Greedy Sorting** | $O(N \log N)$ | $O(N)$ | Sorts differences array |
| **Quickselect (`std::nth_element`)** | $O(N)$ average | $O(N)$ | Finds top $N$ without full sort |

