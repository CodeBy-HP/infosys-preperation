# Implement Max Heap

## Problem Overview
Implement a **Max Heap** data structure from scratch using a dynamic array with the following operations:
- `insert(val)`: Inserts a new value into the heap in $O(\log N)$.
- `getMax()`: Returns the maximum element without removing it in $O(1)$.
- `extractMax()`: Removes and returns the maximum element in $O(\log N)$.
- `increaseKey(i, newVal)`: Increases the key at index `i` to `newVal` ($newVal > arr[i]$) in $O(\log N)$.
- `deleteKey(i)`: Deletes the element at index `i` in $O(\log N)$.

---

## Invariant Mechanics
- **Max-Heap Property:** For every non-root node $i$, $\text{heap}[(i - 1) / 2] \ge \text{heap}[i]$.
- In `extractMax()`, the maximum element is at index `0`. Replace `heap[0]` with `heap.back()`, pop the back, and call `downHeapify(0)` sinking with the **largest child**.
- In `deleteKey(i)`, call `increaseKey(i, INT_MAX)` bubbling it to the root, followed by `extractMax()`.

---

## Complexity Analysis
- `getMax()`: $O(1)$ Time.
- `insert()`, `extractMax()`, `increaseKey()`, `deleteKey()`: $O(\log N)$ Time.
- Auxiliary Space: $O(N)$.

