# Implement Stack using Array

## Problem Statement

Implement a **Last-In, First-Out (LIFO)** Stack data structure using a fixed-size or dynamic array.

The stack must support the following standard operations:
- `push(x)`: Inserts element `x` onto the top of the stack.
- `pop()`: Removes and returns the top element of the stack. If the stack is empty, return `-1`.
- `top()`: Returns the top element of the stack without removing it. If the stack is empty, return `-1`.
- `isEmpty()`: Returns `true` if the stack contains no elements, otherwise `false`.
- `size()`: Returns the current number of elements in the stack.

---

## Examples

### Example 1
```cpp
ArrayStack st(5);
st.push(10);
st.push(20);
st.top();    // Returns 20
st.pop();    // Returns 20
st.isEmpty();// Returns false
st.pop();    // Returns 10
st.isEmpty();// Returns true
st.pop();    // Returns -1 (underflow)
```

---

## Constraints

- $1 \le \text{Capacity} \le 10^5$
- $-10^9 \le x \le 10^9$
- All operations should execute in $O(1)$ time.

---

## Mechanics & Invariants

A pointer/index `topIndex` is maintained:
- Initially, `topIndex = -1`.
- **Push:** If `topIndex == capacity - 1`, stack overflow occurs. Otherwise, `arr[++topIndex] = x`.
- **Pop:** If `topIndex == -1`, stack underflow occurs. Otherwise, return `arr[topIndex--]`.
- **Top:** If `topIndex == -1`, return `-1`. Otherwise, return `arr[topIndex]`.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **`push(x)`** | $O(1)$ amortized / worst-case | $O(1)$ |
| **`pop()`** | $O(1)$ | $O(1)$ |
| **`top()`** | $O(1)$ | $O(1)$ |
| **`isEmpty()`** | $O(1)$ | $O(1)$ |
| **Total Space** | — | $O(N)$ for array storage |

