# Introduction to Doubly Linked List

## Problem Statement

A **Doubly Linked List (DLL)** is a bidirectional linked data structure where each node contains:
1. `val`: The integer value of the node.
2. `next`: A pointer referencing the subsequent node (or `nullptr`).
3. `prev`: A pointer referencing the preceding node (or `nullptr`).

Given an array of integers `arr`, construct a doubly linked list representing the array elements in sequence, correctly wiring both `next` and `prev` pointers. Return the pointer to the **head** node.

If `arr` is empty, return `nullptr`.

---

## Examples

### Example 1
- **Input:** `arr = [1, 2, 3, 4]`
- **Output:** `nullptr <- 1 <-> 2 <-> 3 <-> 4 -> nullptr`

### Example 2
- **Input:** `arr = [42]`
- **Output:** `nullptr <- 42 -> nullptr`

---

## Constraints

- $0 \le \text{arr.length} \le 10^5$
- $-10^9 \le \text{arr}[i] \le 10^9$

---

## DLL Node Structure in C++

```cpp
struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int x) : val(x), prev(nullptr), next(nullptr) {}
    Node(int x, Node* p, Node* n) : val(x), prev(p), next(n) {}
};
```

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(N)$ |
| **Space Complexity** | $O(1)$ auxiliary |

