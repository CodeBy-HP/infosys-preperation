# Lower Bound in a Sorted Array

## Problem Statement

Given a sorted array `arr` of $N$ integers and an integer `target`, find the **lower bound** of `target`.

The **lower bound** of a target is defined as the smallest index `idx` such that:
$$\text{arr}[idx] \ge target$$

If all elements in the array are strictly smaller than `target`, the lower bound is considered to be the size of the array, $N$.

---

## Examples

### Example 1
- **Input:** `arr = [1, 2, 8, 10, 11, 12, 19]`, `target = 5`
- **Output:** `2`
- **Explanation:** The smallest element $\ge 5$ is `8`, which is located at index `2`.

### Example 2
- **Input:** `arr = [3, 5, 8, 15, 19]`, `target = 9`
- **Output:** `3`
- **Explanation:** The smallest element $\ge 9$ is `15`, which is at index `3`.

### Example 3
- **Input:** `arr = [2, 3, 7, 10, 11]`, `target = 12`
- **Output:** `5`
- **Explanation:** No element is $\ge 12$. The lower bound is the length of array $N = 5$.

---

## Constraints

- $1 \le N \le 10^5$
- $1 \le \text{arr}[i], target \le 10^9$
- `arr` is sorted in non-decreasing order.

---

## The Lower Bound Invariant

In binary search on a closed interval $[left, right]$:
1. Initialize `ans = N`.
2. Compute $\text{mid} = left + \frac{right - left}{2}$.
3. Check condition $\text{arr}[mid] \ge target$:
   - If **True**: `arr[mid]` is a valid candidate. Save `ans = mid`. Since we want the *smallest* such index, search leftward: `right = mid - 1`.
   - If **False**: `arr[mid] < target`. Therefore, no index $\le mid$ can satisfy the condition. Search rightward: `left = mid + 1`.
4. Upon loop termination ($left > right$), `ans` (or equivalently `left`) holds the exact lower bound index.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space | Notes |
| :--- | :--- | :--- | :--- |
| **Binary Search (Custom Implementation)** | $O(\log N)$ | $O(1)$ | Optimal halving |
| **C++ Standard Library (`std::lower_bound`)** | $O(\log N)$ | $O(1)$ | Pointer/iterator arithmetic |
| **Linear Search** | $O(N)$ | $O(1)$ | Brute-force scanning |

