# Maximum Sum Combinations

## Problem Overview
Given two integer arrays $A$ and $B$ of size $N$ each, and an integer $C$.
A **sum combination** is formed by choosing one element $A[i]$ from $A$ and one element $B[j]$ from $B$.
Return the **$C$ largest sum combinations** formed from $A$ and $B$ in non-increasing order.

---

## Max-Heap BFS Frontier Invariant
Generating all $N^2$ sums takes $O(N^2 \log(N^2))$ which TLEs for $N = 10^5$.
Instead:
1. Sort both arrays $A$ and $B$ in **descending order**:
   - The absolute maximum possible sum is $A[0] + B[0]$.
2. Initialize a **Max-Heap** storing `{sum, i, j}` and an `unordered_set` (or `set`) of visited index pairs `(i, j)`.
3. Push `{A[0] + B[0], 0, 0}` into the max-heap.
4. Repeat $C$ times:
   - Pop the current largest sum combination `{sum, i, j}`.
   - Append `sum` to the output array.
   - The next potential largest candidates must be adjacent in the 2D sorted grid:
     1. Down neighbor: `(i + 1, j)` $\implies A[i + 1] + B[j]$
     2. Right neighbor: `(i, j + 1)` $\implies A[i] + B[j + 1]$
   - If not previously visited, push into the max-heap and mark visited.

---

## Complexity Analysis
- **Time Complexity:** $O(N \log N + C \log C)$
- **Space Complexity:** $O(C)$ for the max-heap and visited set.

