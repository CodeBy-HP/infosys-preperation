# Problem: Maximum Dominance Partition

## Problem Statement

You are given an array $A$ consisting of $N$ integers and an integer $K$.

Your task is to divide the array into **exactly $K$ non-empty contiguous subarrays**.

The **dominance score** of a subarray is defined as the **maximum frequency of any element** in that subarray.
- For example, if a subarray is $[2, 3, 2, 4, 2]$:
  - Frequency of $2 = 3$
  - Frequency of $3 = 1$
  - Frequency of $4 = 1$
  - Dominance score = $\max(3, 1, 1) = 3$.

The total score of a partition is the **sum of the dominance scores** across all $K$ subarrays.

Find and return the **maximum possible total score**.

---

## Examples

### Example 1
- **Input:**
  ```text
  5 2
  1 2 2 1 2
  ```
- **Output:** `4`
- **Explanation:**
  - One optimal partition into 2 subarrays is $[1]$ and $[2, 2, 1, 2]$:
    - Dominance of $[1]$ is $1$ (element $1$ appears once).
    - Dominance of $[2, 2, 1, 2]$ is $3$ (element $2$ appears three times).
    - Total score = $1 + 3 = 4$.

---

## Input & Output Format

### Input Format
- The first line contains two space-separated integers: $N$ and $K$.
- The second line contains $N$ space-separated integers representing the array $A$.

### Output Format
- Print a single integer: the maximum possible total dominance score.

---

## Constraints

- $1 \le K \le N \le 300$
- $1 \le A[i] \le 10^9$

---

## Dynamic Programming Formulation

1. **Precomputing Subarray Dominance Scores:**
   - In $O(N^2)$ time, precalculate $\text{cost}[i][j]$ = max frequency in $A[i \dots j]$ using a frequency table.
2. **State:**
   - $\text{dp}[i][g]$: maximum dominance score from partitioning prefix $A[0 \dots i - 1]$ into exactly $g$ subarrays.
3. **Recurrence Relation:**
   $$\text{dp}[i][g] = \max_{g - 1 \le j < i} \Big( \text{dp}[j][g - 1] + \text{cost}[j][i - 1] \Big)$$
4. **Base Cases:**
   - $\text{dp}[0][0] = 0$.
   - $\text{dp}[i][0] = -\infty$ for $i > 0$.

---

## Complexity Analysis

| Phase | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Cost Precomputation** | $O(N^2)$ | $O(N^2)$ |
| **Top-Down (Recursion + Memoization)** | $O(K \cdot N^2)$ | $O(N^2 + K \cdot N)$ |
| **Bottom-Up Tabulation** | $O(K \cdot N^2)$ | $O(N^2 + K \cdot N)$ |
| **Space-Optimized Iterative** | $O(K \cdot N^2)$ | $O(N^2 + N)$ |

