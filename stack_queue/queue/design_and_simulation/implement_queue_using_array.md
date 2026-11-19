# Implement Queue using Array

## Problem Statement

Implement a **First-In, First-Out (FIFO)** Queue data structure using an array.

The queue must support the following standard operations:
- `push(x)` / `enqueue(x)`: Inserts element `x` at the back of the queue.
- `pop()` / `dequeue()`: Removes and returns the front element. If empty, return `-1`.
- `peek()` / `front()`: Returns the front element without removing it. If empty, return `-1`.
- `isEmpty()`: Returns `true` if empty, otherwise `false`.
- `isFull()`: Returns `true` if fixed capacity is reached, otherwise `false`.
- `size()`: Returns current element count.

---

## Why Ring Buffer (Circular Array)?

If you use a naive linear array with `front` and `rear` pointers, every `pop()` shifts elements left in $O(N)$ time, or moves `front` forward, causing unused dead space at the beginning of the array.

A **Circular Array (Ring Buffer)** solves this by wrapping indices around using modulo arithmetic:
$$\text{rear} = (\text{front} + \text{count}) \pmod{\text{capacity}}$$

---

## Constraints

- $1 \le \text{Capacity} \le 10^5$
- $-10^9 \le x \le 10^9$
- All operations execute in **$O(1)$ time**.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **`enqueue(x)`** | $O(1)$ | $O(1)$ |
| **`dequeue()`** | $O(1)$ | $O(1)$ |
| **`front()`** | $O(1)$ | $O(1)$ |
| **`isEmpty()` / `isFull()`** | $O(1)$ | $O(1)$ |
| **Total Memory** | — | $O(N)$ bounded array |

