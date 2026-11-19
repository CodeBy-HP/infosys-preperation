# Implement Queue using Linked List

## Problem Statement

Implement a **First-In, First-Out (FIFO)** Queue data structure using a singly linked list.

The queue must support the following standard operations in **$O(1)$ time**:
- `enqueue(x)`: Inserts element `x` at the back of the queue.
- `dequeue()`: Removes and returns the front element. If the queue is empty, return `-1`.
- `front()`: Returns the front element without removing it. If the queue is empty, return `-1`.
- `isEmpty()`: Returns `true` if the queue is empty, otherwise `false`.
- `size()`: Returns the current number of elements.

---

## Mechanics & Invariants

To achieve $O(1)$ operations at both ends, maintain two pointers:
- `head`: Points to the front of the queue (where elements are dequeued).
- `tail`: Points to the rear of the queue (where elements are enqueued).
- **Enqueue(x):**
  - Allocate `newNode = new Node(x)`.
  - If `tail == nullptr`, queue was empty: `head = tail = newNode`.
  - Else, `tail->next = newNode; tail = newNode;`.
- **Dequeue():**
  - If `head == nullptr`, return `-1`.
  - Extract `val = head->data`.
  - Advance `head = head->next`. If `head == nullptr`, set `tail = nullptr`.
  - Return `val`.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **`enqueue(x)`** | $O(1)$ | $O(1)$ per node |
| **`dequeue()`** | $O(1)$ | $O(1)$ |
| **`front()`** | $O(1)$ | $O(1)$ |
| **`isEmpty()`** | $O(1)$ | $O(1)$ |
| **Total Memory** | — | $O(N)$ with pointer nodes |

