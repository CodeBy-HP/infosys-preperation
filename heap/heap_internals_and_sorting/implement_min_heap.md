# Implement Min Heap

## Problem Overview
Implement a fully functional **Min Heap** data structure from scratch using a dynamic array with the following member functions:
- `insert(val)`: Inserts a new value into the heap.
- `getMin()`: Returns the minimum element without removing it.
- `extractMin()`: Removes and returns the minimum element.
- `decreaseKey(i, newVal)`: Decreases the value at index `i` to `newVal` ($newVal < arr[i]$).
- `deleteKey(i)`: Deletes the element at index `i`.
- `size()`, `empty()`: Returns size and boolean state.

---

## Invariant Mechanics

### 1. `insert(val)`: $O(\log N)$
Push `val` at the end of the array ($N - 1$), and call `upHeapify(N - 1)` (swim) to bubble it up to its valid position.

### 2. `extractMin()`: $O(\log N)$
Swap root `arr[0]` with the last element `arr[N - 1]`. Pop the back. If the heap is not empty, call `downHeapify(0)` (sink) on the new root.

### 3. `decreaseKey(i, newVal)`: $O(\log N)$
Set `arr[i] = newVal`. Since the value decreased, it can only violate the heap invariant with its ancestors $\implies$ call `upHeapify(i)`.

### 4. `deleteKey(i)`: $O(\log N)$
Call `decreaseKey(i, INT_MIN)` to force the node to become the root, then call `extractMin()`!

---

## Complexity Analysis
- `getMin()`: $O(1)$ Time.
- `insert()`, `extractMin()`, `decreaseKey()`, `deleteKey()`: $O(\log N)$ Time.
- Space Complexity: $O(N)$ for contiguous array storage.

