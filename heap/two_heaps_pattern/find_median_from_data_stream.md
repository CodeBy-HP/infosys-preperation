
# Find Median from Data Stream (LeetCode 295)

## Problem Overview

The **median** is the middle value in an ordered integer list.

- If the list contains an odd number of elements, the median is the middle element.
- If the list contains an even number of elements, the median is the average of the two middle elements.

**Examples:**

For `arr = [2, 3, 4]`, the median is `3`.

For `arr = [2, 3]`, the median is `(2 + 3) / 2 = 2.5`.

Implement the `MedianFinder` class with the following operations:

- `MedianFinder()`: Initializes the `MedianFinder` object.
- `void addNum(int num)`: Adds the integer `num` from the data stream to the data structure.
- `double findMedian()`: Returns the median of all elements added so far.

Answers within `10^-5` of the actual answer will be accepted.

---

## Example 1

**Input:**

```python
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
```

**Output:**

```python
[null, null, null, 1.5, null, 2.0]
```

**Explanation:**

```python
MedianFinder medianFinder = new MedianFinder();

medianFinder.addNum(1)      # arr = [1]
medianFinder.addNum(2)      # arr = [1, 2]
medianFinder.findMedian()   # returns 1.5 (i.e., (1 + 2) / 2)

medianFinder.addNum(3)      # arr = [1, 2, 3]
medianFinder.findMedian()   # returns 2.0
```

---

## Constraints

- `-10^5 <= num <= 10^5`
- There will be at least one element in the data structure before calling `findMedian`.
- At most `5 * 10^4` calls will be made to `addNum` and `findMedian`.

---

## Follow-up Questions

1. If all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?

2. If 99% of all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?


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

