# Find Median from Data Stream (LeetCode 295)

## Problem Overview
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the median is the mean of the two middle values.
Design a data structure that supports the following two operations:
- `void addNum(int num)`: Adds an integer `num` from the data stream to the data structure.
- `double findMedian()`: Returns the median of all elements so far.

---

## The Dual-Heap Balanced Partition Invariant
To support $O(\log N)$ insertion and strictly $O(1)$ median retrieval, partition the continuous stream into two halves:
1. **Left Half (Smaller Numbers):** Maintained in a **Max-Heap** `leftMaxHeap`.
2. **Right Half (Larger Numbers):** Maintained in a **Min-Heap** `rightMinHeap`.

### Balancing Rules:
- **Order Property:** Every element in `leftMaxHeap` must be $\le$ every element in `rightMinHeap`:
  $$\max(\text{leftMaxHeap}) \le \min(\text{rightMinHeap})$$
- **Size Invariant:** `leftMaxHeap` is allowed to hold at most **1 more element** than `rightMinHeap`:
  $$|leftMaxHeap| - |rightMinHeap| \in \{0, 1\}$$

### `addNum(num)` Procedure ($O(\log N)$):
1. Push `num` into `leftMaxHeap`.
2. Balance values: Move top of `leftMaxHeap` to `rightMinHeap`.
3. Balance sizes: If $|rightMinHeap| > |leftMaxHeap|$, move top of `rightMinHeap` back to `leftMaxHeap`.

### `findMedian()` Procedure ($O(1)$):
- If total size is odd:
  $$\text{Median} = \text{leftMaxHeap.top()}$$
- If total size is even:
  $$\text{Median} = \frac{\text{leftMaxHeap.top()} + \text{rightMinHeap.top()}}{2.0}$$

---

## Complexity Analysis
- **`addNum()` Time:** $O(\log N)$
- **`findMedian()` Time:** strictly **$O(1)$**
- **Space Complexity:** $O(N)$

