# Floor and Ceil in a Sorted Array

## Problem Statement

Given a sorted array `arr` of $N$ integers and an integer `x`, find the **floor** and **ceil** of `x` in the array.

- **Floor:** The largest element in the array that is less than or equal to `x` ($\text{arr}[i] \le x$). If no such element exists, floor is `-1`.
- **Ceil:** The smallest element in the array that is greater than or equal to `x` ($\text{arr}[i] \ge x$). If no such element exists, ceil is `-1`.

Return a pair `[floor, ceil]`.

---

## Examples

### Example 1
- **Input:** `arr = [3, 4, 4, 7, 8, 10]`, `x = 5`
- **Output:** `[4, 7]`
- **Explanation:**
  - Largest element $\le 5$ is `4`.
  - Smallest element $\ge 5$ is `7`.

### Example 2
- **Input:** `arr = [3, 4, 4, 7, 8, 10]`, `x = 2`
- **Output:** `[-1, 3]`
- **Explanation:**
  - No element $\le 2$, so floor is `-1`.
  - Smallest element $\ge 2$ is `3`.

### Example 3
- **Input:** `arr = [3, 4, 4, 7, 8, 10]`, `x = 11`
- **Output:** `[10, -1]`
- **Explanation:**
  - Largest element $\le 11$ is `10`.
  - No element $\ge 11$, so ceil is `-1`.

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le \text{arr}[i], x \le 10^9$
- `arr` is sorted in non-decreasing order.

---

## Binary Search Invariants

### 1. Finding Floor ($\le x$)
- If `arr[mid] <= x`: `arr[mid]` is a valid candidate for floor. Save `floor = arr[mid]`, and search right (`left = mid + 1`) to find an even larger value $\le x$.
- If `arr[mid] > x`: Search left (`right = mid - 1`).

### 2. Finding Ceil ($\ge x$)
- This is mathematically equivalent to the **Lower Bound**:
  - If `arr[mid] >= x`: `arr[mid]` is a candidate for ceil. Save `ceil = arr[mid]`, and search left (`right = mid - 1`) to find a smaller value $\ge x$.
  - If `arr[mid] < x`: Search right (`left = mid + 1`).

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Dual Binary Search (Independent Floor & Ceil)** | $O(\log N)$ | $O(1)$ |
| **Combined Single-Pass Binary Search** | $O(\log N)$ | $O(1)$ |
| **Linear Search** | $O(N)$ | $O(1)$ |

