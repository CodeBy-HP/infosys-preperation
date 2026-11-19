# Kth Missing Positive Number (LeetCode 1539)

## Problem Statement

Given an array `arr` of positive integers sorted in a strictly increasing order, and an integer `k`, return the **$k$-th positive integer** that is missing from this array.

---

## Examples

### Example 1
- **Input:** `arr = [2, 3, 4, 7, 11]`, `k = 5`
- **Output:** `9`
- **Explanation:**
  - The missing positive integers are `[1, 5, 6, 8, 9, 10, 12, ...]`.
  - The 5th missing positive integer is `9`.

### Example 2
- **Input:** `arr = [1, 2, 3, 4]`, `k = 2`
- **Output:** `6`
- **Explanation:**
  - The missing positive integers are `[5, 6, 7, ...]`.
  - The 2nd missing positive integer is `6`.

---

## Constraints

- $1 \le \text{arr.length} \le 1000$
- $1 \le \text{arr}[i] \le 1000$
- $1 \le k \le 1000$
- `arr[i] < arr[j]` for $1 \le i < j \le \text{arr.length}$.

---

## Monotonic Missing Formula & Invariant

If no numbers were missing, the element at index $i$ (0-indexed) would simply be $i + 1$.
Therefore, the total count of positive integers missing up to index $i$ is:
$$\text{missing}(i) = \text{arr}[i] - (i + 1)$$

Since `arr` is strictly ascending, $\text{missing}(i)$ is **monotonically non-decreasing**:

| Index $i$ | 0 | 1 | 2 | 3 | 4 |
| :--- | :--- | :--- | :--- | :--- | :--- |
| $\text{arr}[i]$ | 2 | 3 | 4 | 7 | 11 |
| Expected ($i+1$) | 1 | 2 | 3 | 4 | 5 |
| Missing Count | 1 | 1 | 1 | 3 | 6 |

### Binary Search:
We binary search for the transition boundary where the missing count is less than $k$:
- If $\text{missing}(mid) < k$: Not enough missing numbers yet $\to left = mid + 1$.
- Else: $\text{missing}(mid) \ge k \to right = mid - 1$.

At loop termination, `right` is the largest index with $\text{missing}(right) < k$, and `left = right + 1`.
The $k$-th missing number is:
$$\text{ans} = \text{arr}[right] + (k - \text{missing}(right)) = \text{arr}[right] + k - (\text{arr}[right] - (right + 1)) = right + 1 + k = left + k$$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Optimal Binary Search** | $O(\log N)$ | $O(1)$ |
| **Linear Missing Scan** | $O(N + k)$ | $O(1)$ |
| **Hash Set Lookup** | $O(N + k)$ | $O(N)$ |

