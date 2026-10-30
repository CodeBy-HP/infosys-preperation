# Design Circular Deque (LeetCode 641)

## Problem Statement
Design your implementation of the circular double-ended queue (deque).

Implement the `MyCircularDeque` class:
- `MyCircularDeque(int k)`: Initializes the deque with a maximum size of `k`.
- `boolean insertFront()`: Adds an item at the front of Deque. Indicates if the operation was successful.
- `boolean insertLast()`: Adds an item at the rear of Deque. Indicates if the operation was successful.
- `boolean deleteFront()`: Deletes an item from the front of Deque. Indicates if the operation was successful.
- `boolean deleteLast()`: Deletes an item from the rear of Deque. Indicates if the operation was successful.
- `int getFront()`: Gets the front item from the Deque. If the deque is empty, return -1.
- `int getRear()`: Gets the last item from Deque. If the deque is empty, return -1.
- `boolean isEmpty()`: Checks whether Deque is empty or not.
- `boolean isFull()`: Checks whether Deque is full or not.

### Example 1:
```
MyCircularDeque myCircularDeque = new MyCircularDeque(3);
myCircularDeque.insertLast(1);  // return True
myCircularDeque.insertLast(2);  // return True
myCircularDeque.insertFront(3); // return True
myCircularDeque.insertFront(4); // return False, the queue is full.
myCircularDeque.getRear();      // return 2
myCircularDeque.isFull();       // return True
myCircularDeque.deleteLast();   // return True
myCircularDeque.insertFront(4); // return True
myCircularDeque.getFront();     // return 4
```

### Constraints:
- `1 <= k <= 1000`
- `0 <= value <= 1000`
- At most `2000` calls will be made to the deque operations.

---

## Pattern Insight: Bidirectional Ring Buffer Pointer Arithmetic
- Maintaining `head` (index of front element) and `count` allows symmetric manipulation of both ends:
  - `insertFront(val)`: Decrement head circularly: `head = (head - 1 + capacity) % capacity`, insert value, increment `count`.
  - `insertLast(val)`: Place at `(head + count) % capacity`, increment `count`.
  - `deleteFront()`: `head = (head + 1) % capacity`, decrement `count`.
  - `deleteLast()`: Simply decrement `count`.
  - `getFront()`: `buffer[head]`.
  - `getRear()`: `buffer[(head + count - 1) % capacity]`.

---

## Complexity
- **Time Complexity:** $O(1)$ for all 8 operations.
- **Space Complexity:** $O(k)$ auxiliary space.
