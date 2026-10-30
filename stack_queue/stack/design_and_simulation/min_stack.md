# Problem 10: Min Stack (LeetCode 155)

## Problem Statement

Design a stack that supports push, pop, top, and retrieving the minimum element in **constant time**.

Implement the `MinStack` class:
- `MinStack()` initializes the stack object.
- `void push(int val)` pushes the element `val` onto the stack.
- `void pop()` removes the element on the top of the stack.
- `int top()` gets the top element of the stack.
- `int getMin()` retrieves the minimum element in the stack.

You must implement a solution with **$O(1)$ time complexity** for each function.

---

## Examples

```cpp
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
```

---

## Constraints

- $-2^{31} \le \text{val} \le 2^{31} - 1$
- Methods `pop`, `top` and `getMin` operations will always be called on **non-empty** stacks.
- At most $3 \times 10^4$ calls will be made to `push`, `pop`, `top`, and `getMin`.

---

## Two Methods

### 1. Paired Value and Rolling Minimum (`pair<int, int>`)
Push `{val, min(val, currentMin)}` onto a single stack.

### 2. Difference Tracking ($O(1)$ Extra Space)
Store the difference `diff = val - currentMin` using 64-bit integer.

---

## Complexity Analysis

| Operation | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **All Methods** | $O(1)$ | $O(N)$ |
