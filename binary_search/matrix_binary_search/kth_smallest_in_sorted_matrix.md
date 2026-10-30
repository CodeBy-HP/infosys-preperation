# Kth Smallest Element in a Sorted Matrix (LeetCode 378)

## Problem Statement
Given an `n x n` matrix where each of the rows and columns is sorted in ascending order, return the $k$-th smallest element in the matrix.

Note that it is the $k$-th smallest element **in the sorted order**, not the $k$-th distinct element.

You must find a solution with a memory complexity better than $O(n^2)$.

### Example 1:
```
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13.
```

### Constraints:
- `n == matrix.length == matrix[i].length`
- `1 <= n <= 300`
- `-10^9 <= matrix[i][j] <= 10^9`
- `1 <= k <= n^2`

---

## Pattern Insight: Binary Search on Matrix Value Range
- Rather than binary searching on indices, binary search on the **value range**:
  $$left = matrix[0][0], \quad right = matrix[n-1][n-1]$$
- For a candidate value `mid`:
  - Count how many elements in the matrix are $\le mid$.
  - Using the staircase scan from bottom-left $(n - 1, 0)$:
    - If `matrix[r][c] <= mid`, all elements from row $0$ to $r$ in column $c$ are $\le mid$ (add $r + 1$ to count), and move right `c++`.
    - Else move up `r--`.
  - Counting takes only $O(n)$ time!
- If `count < k`: $k$-th smallest must be strictly greater $\to$ `left = mid + 1`.
- Else: `right = mid`.

---

## Complexity
- **Time Complexity:** $O(n \log(\max - \min))$.
- **Space Complexity:** $O(1)$ auxiliary space.
