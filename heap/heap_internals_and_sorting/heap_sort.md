# Heap Sort Algorithm

## Problem Overview
Given an array of integers `arr`, sort the array in **ascending order** using the **Heap Sort** algorithm.
Heap Sort is an in-place, comparison-based sorting algorithm with a guaranteed $O(N \log N)$ worst-case time complexity.

---

## In-Place Sorting Architecture
Heap Sort leverages the Max-Heap property: the root `arr[0]` is always the **largest element** in the heap:
1. **Phase 1: Build Max-Heap ($O(N)$)**
   Convert the input array into a Max-Heap in-place by calling `maxHeapify` from $\lfloor N / 2 \rfloor - 1$ down to `0`.
2. **Phase 2: Extract Maximum & Shrink Frontier ($O(N \log N)$)**
   For $i = N - 1$ down to $1$:
   - Swap `arr[0]` with `arr[i]`. (The current maximum is now permanently placed at the sorted tail of the array!).
   - The active heap size shrinks to $i$.
   - Call `maxHeapify(arr, i, 0)` on the root to restore the Max-Heap property for the remaining $i$ elements.
3. Upon loop completion, the entire array is sorted in ascending order!

---

## Complexity & Stability Analysis
- **Time Complexity:**
  - Best Case: $O(N \log N)$
  - Average Case: $O(N \log N)$
  - Worst Case: $O(N \log N)$
- **Auxiliary Space:** strictly **$O(1)$** in-place (no auxiliary buffer needed).
- **Stability:** Not stable (long-distance parent-child swaps can invert the relative order of duplicate keys).

