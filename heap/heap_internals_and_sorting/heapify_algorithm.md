# The Heapify Algorithm (Down-Heapify & Up-Heapify)

## Overview
The **Heapify** operation is the fundamental building block of all heap operations. It restores the heap invariant when a single element violates the order property.

---

## 1. Down-Heapify (Sink / Percolate Down)
Used during `extractMin()`, `extractMax()`, and `buildHeap()`.
**Precondition:** The subtrees rooted at `leftChild(i)` and `rightChild(i)` are already valid heaps, but `arr[i]` might violate the property.
1. Inspect children $2i + 1$ and $2i + 2$.
2. Identify the smallest (for Min-Heap) or largest (for Max-Heap) among `{arr[i], arr[left], arr[right]}`.
3. If `arr[i]` is not the extreme:
   - Swap `arr[i]` with the extreme child.
   - Recurse down on the child index.
4. Stop when `arr[i]` is smaller/larger than both children, or when reaching a leaf.
- **Time Complexity:** $O(\log N)$ (proportional to tree height $h$).
- **Space Complexity:** $O(1)$ iterative.

---

## 2. Up-Heapify (Swim / Percolate Up)
Used during `insert()` and `decreaseKey()`.
**Precondition:** The entire heap is valid, except for a newly inserted/updated element at index `i` that may be smaller/larger than its parent.
1. Compare `arr[i]` with its parent `arr[(i - 1) / 2]`.
2. If the heap invariant is violated:
   - Swap `arr[i]` with its parent.
   - Update $i \leftarrow (i - 1) / 2$.
3. Stop when the parent satisfies the invariant or when reaching the root ($i = 0$).
- **Time Complexity:** $O(\log N)$.
- **Space Complexity:** $O(1)$ iterative.

