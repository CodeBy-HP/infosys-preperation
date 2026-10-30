# Moving Average from Data Stream (LeetCode 346)

## Problem Statement
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the `MovingAverage` class:
- `MovingAverage(int size)`: Initializes the object with the size of the window `size`.
- `double next(int val)`: Returns the moving average of the last `size` values of the stream.

### Example 1:
```
Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
```

### Constraints:
- `1 <= size <= 1000`
- `-10^5 <= val <= 10^5`
- At most `10^4` calls will be made to `next`.

---

## Pattern Insight: Sliding Buffer with Running Sum
- Maintain a FIFO queue of elements currently in the window, along with a `runningSum` variable.
- For each `next(val)`:
  - If the queue has reached capacity `size`:
    - Subtract `q.front()` from `runningSum`.
    - Pop `q.front()`.
  - Add `val` to `runningSum` and push `val` into `q`.
  - Return `runningSum / q.size()`.
- Every operation is guaranteed $O(1)$ time with $O(size)$ memory.

---

## Complexity
- **Time Complexity:** $O(1)$ per `next()` call.
- **Space Complexity:** $O(size)$ to store the window.
