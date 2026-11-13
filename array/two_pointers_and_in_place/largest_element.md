# Largest Element in an Array

## Problem Statement

Given an array of integers `nums`, find and return the **largest element** in the array.

---

## Examples

### Example 1
- **Input:** `nums = [2, 5, 1, 3, 0]`
- **Output:** `5`

### Example 2
- **Input:** `nums = [8, 10, 5, 7, 9]`
- **Output:** `10`

---

## Constraints

- $1 \le \text{nums.length} \le 10^5$
- $-10^9 \le \text{nums}[i] \le 10^9$

---

## Approaches

### Approach 1: Brute Force (Sorting)
Sort the array in ascending order. The largest element will reside at index $N - 1$.
- **Time Complexity:** $\mathcal{O}(N \log N)$
- **Space Complexity:** $\mathcal{O}(1)$ or $\mathcal{O}(N)$ depending on sorting algorithm.

### Approach 2: Optimal (Single-Pass Linear Scan)
Maintain a running maximum variable `max_elem` initialized to `nums[0]`. Iterate through the array; if the current element is strictly greater than `max_elem`, update `max_elem`.
- **Time Complexity:** $\mathcal{O}(N)$
- **Space Complexity:** $\mathcal{O}(1)$

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Brute Force (Sorting)** | $\mathcal{O}(N \log N)$ | $\mathcal{O}(1)$ auxiliary |
| **Optimal (Linear Scan)** | $\mathcal{O}(N)$ | $\mathcal{O}(1)$ |

