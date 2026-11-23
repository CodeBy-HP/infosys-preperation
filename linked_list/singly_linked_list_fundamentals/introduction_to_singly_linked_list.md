# Introduction to Singly Linked List

## Problem Statement

A **Singly Linked List** is a fundamental linear data structure in which elements (called **nodes**) are stored non-contiguously in memory. Each node consists of two parts:
1. **Data (`val`):** The value stored in the node.
2. **Next Pointer (`next`):** A reference/pointer to the subsequent node in the sequence (or `nullptr` if it is the terminal node).

Given an array of integers `arr`, construct a singly linked list representing the elements in the exact order of the array and return the pointer to the **head** node of the linked list.

If `arr` is empty, return `nullptr`.

---

## Examples

### Example 1
- **Input:** `arr = [1, 2, 3, 4, 5]`
- **Output:** `1 -> 2 -> 3 -> 4 -> 5 -> nullptr`
- **Explanation:** Node 1 points to 2, 2 points to 3, 3 points to 4, 4 points to 5, and 5 points to null.

### Example 2
- **Input:** `arr = [42]`
- **Output:** `42 -> nullptr`
- **Explanation:** A single-element array produces a single-node linked list where `next` is null.

### Example 3
- **Input:** `arr = []`
- **Output:** `nullptr`

---

## Constraints

- $0 \le \text{arr.length} \le 10^5$
- $-10^9 \le \text{arr}[i] \le 10^9$

---

## Node Representation in C++

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
```

### Construction Paradigms
1. **Iterative with Tail Pointer:**
   - Instantiate head node with `arr[0]`.
   - Maintain a `mover` or `tail` pointer. For every subsequent element, allocate a new node, link `mover->next = newNode`, and advance `mover = newNode`.
2. **Sentinel (Dummy) Node Technique:**
   - Initialize `dummy(0)`.
   - Link incoming nodes to `curr->next`.
   - Returns `dummy.next`, eliminating special head checks.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Iterative with Tail Pointer** | $O(N)$ | $O(1)$ |
| **Dummy Head Construction** | $O(N)$ | $O(1)$ |
| **Recursive Construction** | $O(N)$ | $O(N)$ call stack |

