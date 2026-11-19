# Number of Greater Elements to the Right

## Problem Statement

Given an array `arr` of $N$ integers and $Q$ queries, where each query gives an index `indices[i]`, find the count of elements strictly greater than `arr[indices[i]]` that appear to the right of `indices[i]` in the array (i.e., at indices $j > \text{indices}[i]$).

---

## Examples

### Example 1
- **Input:**
  - `arr = [3, 4, 2, 7, 5, 8, 10, 6]`
  - `queries = [0, 5]`
- **Output:** `[6, 1]`
- **Explanation:**
  - For index 0 (`arr[0] = 3`), elements to the right greater than 3 are: `4, 7, 5, 8, 10, 6` (count = 6).
  - For index 5 (`arr[5] = 8`), elements to the right greater than 8 is: `10` (count = 1).

### Example 2
- **Input:**
  - `arr = [1, 2, 3, 4, 5]`
  - `queries = [4, 1]`
- **Output:** `[0, 3]`
- **Explanation:**
  - For index 4 (`arr[4] = 5`), there are no elements to the right (count = 0).
  - For index 1 (`arr[1] = 2`), elements to the right greater than 2 are: `3, 4, 5` (count = 3).

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le Q \le 10^5$
- $1 \le \text{arr}[i] \le 10^9$
- $0 \le \text{indices}[i] < N$

---

## Pattern Insight: Next Greater vs. All Greater

A critical conceptual distinction in stack/queue paradigms:
1. **Next Greater Element (NGE):** Finds the *first* element to the right that is strictly greater. Solved in **$O(N)$** using a **Monotonic Stack**.
2. **Number of Greater Elements (Count):** Finds the *total count* of all elements to the right that are strictly greater.
   - A single monotonic stack only tracks dominating bounds, not the full frequency distribution of non-dominating larger elements.
   - Hence, counting requires order-statistic techniques:
     - **Fenwick Tree (BIT) / Coordinate Compression:** Traverse from right to left, insert values, query prefix sum of frequencies for values $> arr[i]$. $O((N + Q) \log N)$.
     - **Modified Merge Sort / Divide & Conquer:** Inversion count adaptation in $O(N \log N)$.
     - **Brute Force:** Linear scan to the right per query in $O(Q \cdot N)$.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space | Optimal For |
| :--- | :--- | :--- | :--- |
| **Fenwick Tree (BIT) + Coordinate Compression** | $O((N + Q) \log N)$ | $O(N)$ | Large $N, Q \le 10^5$ |
| **Merge Sort Divide-and-Conquer** | $O(N \log N + Q)$ | $O(N)$ | Batch counting all indices |
| **Brute Force Rightward Scan** | $O(Q \cdot N)$ | $O(1)$ | Small inputs / single queries |

