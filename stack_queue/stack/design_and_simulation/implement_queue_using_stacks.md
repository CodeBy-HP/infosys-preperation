# Problem 11: Implement Queue using Stacks (LeetCode 232)

## Problem Statement

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (`push`, `peek`, `pop`, and `empty`).

Implement the `MyQueue` class:
- `void push(int x)` Pushes element x to the back of the queue.
- `int pop()` Removes the element from the front of the queue and returns it.
- `int peek()` Returns the element at the front of the queue.
- `boolean empty()` Returns true if the queue is empty, false otherwise.

**Follow-up:** Can you implement the queue such that each operation is **amortized $O(1)$** time complexity?

---

## Dual Stack Transfer Mechanism

1. `inStack`: dedicated to `push` operations.
2. `outStack`: dedicated to `pop` and `peek` operations.
3. Whenever `outStack` becomes empty, dump all elements from `inStack` into `outStack` in one batch.
   - This inverts LIFO order into FIFO order!
   - Every element is pushed and popped at most twice $\implies$ **Amortized $O(1)$** cost per operation.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **`push`** | $O(1)$ | $O(N)$ |
| **`pop`** | Amortized $O(1)$ | $O(N)$ |
| **`peek`** | Amortized $O(1)$ | $O(N)$ |
| **`empty`** | $O(1)$ | $O(1)$ |
