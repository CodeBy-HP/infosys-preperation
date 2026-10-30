# Design Circular Queue (LeetCode 622)

## Problem Statement
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the `MyCircularQueue` class:
- `MyCircularQueue(k)`: Initializes the object with the size of the queue to be `k`.
- `boolean enQueue(int value)`: Inserts an element into the circular queue. Return true if the operation is successful.
- `boolean deQueue()`: Deletes an element from the circular queue. Return true if the operation is successful.
- `int Front()`: Gets the front item from the queue. If the queue is empty, return -1.
- `int Rear()`: Gets the last item from the queue. If the queue is empty, return -1.
- `boolean isEmpty()`: Checks whether the circular queue is empty or not.
- `boolean isFull()`: Checks whether the circular queue is full or not.

### Example 1:
```
MyCircularQueue myCircularQueue = new MyCircularQueue(3);
myCircularQueue.enQueue(1); // return True
myCircularQueue.enQueue(2); // return True
myCircularQueue.enQueue(3); // return True
myCircularQueue.enQueue(4); // return False
myCircularQueue.Rear();     // return 3
myCircularQueue.isFull();   // return True
myCircularQueue.deQueue();  // return True
myCircularQueue.enQueue(4); // return True
myCircularQueue.Rear();     // return 4
```

### Constraints:
- `1 <= k <= 1000`
- `0 <= value <= 1000`
- At most `3000` calls will be made to `enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, and `isFull`.

---

## Pattern Insight: Fixed Array Ring Buffer with Head and Count
- Maintain a fixed-size vector `buffer` of capacity $k$.
- Use `head` pointer and `count` variable:
  - `tail = (head + count - 1) % capacity`
  - `isEmpty()`: `count == 0`
  - `isFull()`: `count == capacity`
  - `enQueue(val)`: Place at `(head + count) % capacity`, increment `count`.
  - `deQueue()`: Advance `head = (head + 1) % capacity`, decrement `count`.
- All operations run in strict $O(1)$ time with $O(k)$ bounded memory.

---

## Complexity
- **Time Complexity:** $O(1)$ for all operations (`enQueue`, `deQueue`, `Front`, `Rear`, `isEmpty`, `isFull`).
- **Space Complexity:** $O(k)$ fixed memory.
