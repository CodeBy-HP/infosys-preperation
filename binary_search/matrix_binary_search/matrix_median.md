# Matrix Median (Row-Wise Sorted Matrix)

## Problem Statement

Given a row-wise sorted matrix `mat` of dimensions $R \times C$ where both $R$ and $C$ are **odd integers**, find the **median** of the matrix.

The median of an array of $N = R \times C$ elements (where $N$ is odd) is the element located at index $\lfloor N / 2 \rfloor$ in the sorted version of all elements.

---

## Examples

### Example 1
- **Input:**
  ```text
  mat = [
    [1, 3, 5],
    [2, 6, 9],
    [3, 6, 9]
  ]
  ```
- **Output:** `5`
- **Explanation:**
  - Flattened and sorted elements: `[1, 2, 3, 3, 5, 6, 6, 9, 9]`.
  - The middle element (index 4 of 9) is `5`.

### Example 2
- **Input:**
  ```text
  mat = [
    [1, 3, 4],
    [2, 5, 6],
    [7, 8, 9]
  ]
  ```
- **Output:** `5`
- **Explanation:** Sorted elements: `[1, 2, 3, 4, 5, 6, 7, 8, 9]`. The median is `5`.

---

## Constraints

- $1 \le R, C \le 1000$
- $R$ and $C$ are odd numbers ($R \times C$ is odd).
- $1 \le \text{mat}[i][j] \le 10^9$
- Each row of `mat` is sorted in non-decreasing order.

---

## Predicate Monotonicity on Value Space

Let $N = R \times C$. Since $N$ is odd, the median has at least $\lfloor N / 2 \rfloor + 1$ elements $\le$ itself.
For any value $X \in [\min(\text{mat}), \max(\text{mat})]$:
$$\text{countLessEqual}(X) = \sum_{r=0}^{R-1} (\text{upper\_bound}(row_r, X) - row_r\text{.begin()})$$

Since each row is sorted, `countLessEqual(X)` can be evaluated in $O(R \log C)$ time.
Furthermore, as $X$ increases, $\text{countLessEqual}(X)$ is **monotonically non-decreasing**.

### Binary Search Transition
- **Search Range:**
  - $left = \min_{r=0}^{R-1} \text{mat}[r][0]$
  - $right = \max_{r=0}^{R-1} \text{mat}[r][C-1]$
- Compute $\text{mid} = left + \frac{right - left}{2}$.
- If $\text{countLessEqual}(mid) \le \frac{R \times C}{2}$:
  - $mid$ cannot be the median; there are not enough elements $\le mid$.
  - Search higher: `left = mid + 1`.
- Else:
  - $mid$ could be the median or greater than the median.
  - Narrow down the upper bound: `right = mid - 1`.
- Upon loop termination, `left` holds the median.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Binary Search on Value Range** | $O(R \log C \cdot \log(\max - \min))$ | $O(1)$ |
| **Flatten and Sort** | $O(R \cdot C \log(R \cdot C))$ | $O(R \cdot C)$ |
| **Min-Heap $K$-way Merge** | $O(\frac{R \cdot C}{2} \log R)$ | $O(R)$ |

