# Reverse Pairs (LeetCode 493)

## Problem Statement

Given an integer array `nums`, return the number of **reverse pairs** in the array.

A **reverse pair** is a pair $(i, j)$ such that:
$$0 \le i < j < \text{nums.length} \quad \text{and} \quad \text{nums}[i] > 2 \cdot \text{nums}[j]$$

---

## Examples

### Example 1
- **Input:** `nums = [1, 3, 2, 3, 1]`
- **Output:** `2`
- **Explanation:**
  - $(i = 1, j = 4) \implies \text{nums}[1] = 3, \text{nums}[4] = 1 \implies 3 > 2 \times 1$
  - $(i = 3, j = 4) \implies \text{nums}[3] = 3, \text{nums}[4] = 1 \implies 3 > 2 \times 1$

### Example 2
- **Input:** `nums = [2, 4, 3, 5, 1]`
- **Output:** `3`
- **Explanation:**
  - $(1, 4) \implies 4 > 2 \times 1$
  - $(2, 4) \implies 3 > 2 \times 1$
  - $(3, 4) \implies 5 > 2 \times 1$

---

## Constraints

- $1 \le \text{nums.length} \le 5 \times 10^4$
- $-2^{31} \le \text{nums}[i] \le 2^{31} - 1$

---

## Approaches

### Approach 1: Nested Loops (Brute Force)
Test all pairs $(i, j)$ with $i < j$.
- **Time Complexity:** $\mathcal{O}(N^2)$
- **Space Complexity:** $\mathcal{O}(1)$

### Approach 2: Divide and Conquer (Modified Merge Sort)
Because the condition is $\text{nums}[i] > 2 \cdot \text{nums}[j]$ rather than simple $\text{nums}[i] > \text{nums}[j]$, we cannot count reverse pairs simultaneously during the merge step. Instead, we insert a **two-pointer counting step immediately before merging**:

When both left half $[l, \text{mid}]$ and right half $[\text{mid} + 1, r]$ are sorted:
1. Initialize a pointer $j = \text{mid} + 1$.
2. For each element $i$ from $l$ to $\text{mid}$:
   - While $j \le r$ and $\text{nums}[i] > 2\text{LL} \times \text{nums}[j]$, advance $j++$.
   - The number of valid right elements for this $i$ is $j - (\text{mid} + 1)$.
   - Add this count to the total reverse pairs.
3. Standard merge the two sorted halves into a temporary buffer.

Because $j$ only advances forward across all $i$, the counting step runs in $\mathcal{O}(N)$, preserving the overall $\mathcal{O}(N \log N)$ complexity!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Brute Force** | $\mathcal{O}(N^2)$ | $\mathcal{O}(1)$ |
| **Modified Merge Sort** | $\mathcal{O}(N \log N)$ | $\mathcal{O}(N)$ |

