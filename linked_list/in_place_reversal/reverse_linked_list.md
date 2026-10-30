# Problem 4: Reverse Linked List (LeetCode 206)

## Problem Statement

Given the `head` of a singly linked list, reverse the list, and return the **reversed list**.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `[5, 4, 3, 2, 1]`

### Example 2
- **Input:** `head = [1, 2]`
- **Output:** `[2, 1]`

### Example 3
- **Input:** `head = []`
- **Output:** `[]`

---

## Constraints

- The number of nodes in the list is the range $[0, 5000]$.
- $-5000 \le \text{Node.val} \le 5000$

---

## Pattern & Intuition: 3-Pointer Iteration & Recursion

### 1. Iterative 3-Pointer Invariant
Maintain three pointer references:
- `prev`: points to the already reversed prefix (initially `nullptr`).
- `curr`: points to the node being processed.
- `nextNode`: stores `curr->next` before breaking the forward pointer.

```
Initial:
NULL     1 -> 2 -> 3 -> NULL
 ^       ^
prev    curr

Step:
nextNode = curr->next;  // Save 2
curr->next = prev;      // Reverse link: 1 -> NULL
prev = curr;            // Advance prev to 1
curr = nextNode;        // Advance curr to 2
```

### 2. Recursive Formulation
Assume `reverseList(head->next)` correctly reverses the sublist from the second node onward:
```
head -> [head->next <- ... <- newHead]
```
To connect the current `head`:
```cpp
head->next->next = head;
head->next = nullptr;
return newHead;
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Iterative 3-Pointer** | $O(N)$ | $O(1)$ | Strictly optimal space |
| **Recursive**          | $O(N)$ | $O(N)$ | $O(N)$ stack frames |
