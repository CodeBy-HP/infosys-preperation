# Sort a K-Sorted Array (Nearly Sorted Array)

## Problem Overview
Given an array of $N$ elements where each element is at most $K$ positions away from its target sorted position.
Sort the array in ascending order with the most optimal time complexity.

---

## Min-Heap Window of Size $K + 1$ Invariant
Because every element is at most $K$ positions away from its correct sorted index:
- The element that belongs at sorted index $0$ must be located within the window $[0, K]$ (the first $K + 1$ elements).
- More generally, the element that belongs at index $i$ must be the minimum among the currently available candidates in $[i, i + K]$.

### Algorithm:
1. Build a **Min-Heap** with the first $K + 1$ elements ($O(K)$).
2. For each index $i \in [0, N - 1]$:
   - Pop the minimum element from the min-heap and place it at `arr[i]`.
   - If there are remaining elements in the input array ($i + K + 1 < N$), push `arr[i + K + 1]` into the min-heap.
3. When the input array is exhausted, drain the remaining elements from the min-heap into the array.

---

## Complexity Analysis
- **Time Complexity:** $O(N \log K)$ — substantially faster than $O(N \log N)$ when $K \ll N$.
- **Space Complexity:** $O(K)$ auxiliary space for the heap of size $K + 1$.

