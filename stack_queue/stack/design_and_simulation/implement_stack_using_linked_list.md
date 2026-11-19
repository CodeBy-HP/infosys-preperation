# Implement Stack using Linked List

## Problem Statement

Implement a **Last-In, First-Out (LIFO)** Stack data structure using a singly linked list.

The stack must dynamically allocate and deallocate nodes to support an unbounded number of elements without fixed capacity limitations:
- `push(x)`: Inserts element `x` onto the top of the stack.
- `pop()`: Removes and returns the top element of the stack. If the stack is empty, return `-1`.
- `top()`: Returns the top element of the stack without removing it. If the stack is empty, return `-1`.
- `isEmpty()`: Returns `true` if the stack is empty, otherwise `false`.
- `size()`: Returns the current number of elements.

---

## Examples

### Example 1
```cpp
LinkedListStack st;
st.push(5);
st.push(10);
st.top();    // Returns 10
st.pop();    // Returns 10
st.pop();    // Returns 5
st.isEmpty();// Returns true
st.pop();    // Returns -1 (underflow)
```

---

## Constraints

- Memory is dynamically allocated per node.
- All operations must run in strict **$O(1)$ worst-case time**.

---

## Mechanics & Invariants

In a singly linked list, inserting and deleting at the **head** (the front) takes $O(1)$ time:
- The head of the linked list acts as the **top** of the stack.
- **Push(x):** Create a new node `newNode = new Node(x)`. Point `newNode->next = head`. Update `head = newNode`. Increment `count`.
- **Pop():** If `head == nullptr`, return `-1`. Save `temp = head`, `val = head->data`. Advance `head = head->next`. Delete `temp`. Decrement `count`. Return `val`.
- **Top():** Return `head ? head->data : -1`.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **`push(x)`** | $O(1)$ | $O(1)$ per node |
| **`pop()`** | $O(1)$ | $O(1)$ |
| **`top()`** | $O(1)$ | $O(1)$ |
| **`isEmpty()`** | $O(1)$ | $O(1)$ |
| **Total Memory** | — | $O(N)$ with pointer overhead |

