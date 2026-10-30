# Implement Stack using Queues (LeetCode 225)

## Problem Statement
Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (`push`, `top`, `pop`, and `empty`).

Implement the `MyStack` class:
- `void push(int x)`: Pushes element x to the top of the stack.
- `int pop()`: Removes the element on the top of the stack and returns it.
- `int top()`: Returns the element on the top of the stack.
- `boolean empty()`: Returns `true` if the stack is empty, `false` otherwise.

**Notes:**
- You must use only standard operations of a queue — which means only `push to back`, `peek/pop from front`, `size`, and `is empty` operations are valid.
- **Follow-up:** Can you implement the stack using only **one queue**?

### Example 1:
```
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False
```

### Constraints:
- `1 <= x <= 9`
- At most `100` calls will be made to `push`, `pop`, `top`, and `empty`.

---

## Pattern Insight: Single Queue Rotation Trick
- We can implement a stack with **only 1 single queue**:
  - In `push(x)`:
    1. First push $x$ to the queue.
    2. Then, rotate the previous $(sz - 1)$ elements by dequeuing each from the front and enqueuing it back to the end!
    3. Now, the newly added element $x$ is placed at the front of the queue.
  - Result:
    - `pop()` is simply `q.pop()` (O(1)).
    - `top()` is simply `q.front()` (O(1)).
    - `empty()` is `q.empty()` (O(1)).

---

## Complexity
- **Time Complexity:**
  - `push(x)`: $O(N)$ rotation.
  - `pop()`, `top()`, `empty()`: $O(1)$.
- **Space Complexity:** $O(N)$ for queue storage.
