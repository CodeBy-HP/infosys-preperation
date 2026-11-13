# Convert Min-Heap to Max-Heap

## Problem Overview
Given an array `arr` representing a valid **Min-Heap**, convert it into a valid **Max-Heap** in-place with optimal time and space complexity.

---

## Linear Time Bottom-Up Heapify
Although the array already satisfies the Min-Heap property, its ordering has no direct correlation with Max-Heap requirements (the minimum is at root `0`, whereas Max-Heap requires the maximum at root `0`).
However, because the array already represents a **complete binary tree**, we can apply **Bottom-Up Max-Heapify**:
1. Leaves at indices $[\lfloor N / 2 \rfloor, \; N - 1]$ are already valid max-heaps of size 1.
2. Iterate backwards from the last internal node:
   $$\text{start} = \frac{N - 2}{2}$$
   down to index `0`, calling `maxHeapify(arr, N, i)`.
3. This transforms the min-heap into a max-heap in strictly **$O(N)$ time**!

---

## Complexity Analysis
- **Time Complexity:** $O(N)$ (via the standard bottom-up linear heap build proof).
- **Space Complexity:** $O(1)$ auxiliary space in-place.

