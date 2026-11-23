# Convert Array to Doubly Linked List

## Problem Statement

Given an array of integers `arr`, convert it into a **Doubly Linked List** and return the head pointer.

Ensure that for every adjacent pair of nodes $A$ and $B$, $A\text{->next} == B$ and $B\text{->prev} == A$.
The head node must have $\text{prev} == nullptr$ and the tail node must have $\text{next} == nullptr$.

---

## Examples

### Example 1
- **Input:** `arr = [3, 5, 8, 10]`
- **Output:** `[3, 5, 8, 10]`
- **Explanation:** $3 \leftrightarrow 5 \leftrightarrow 8 \leftrightarrow 10$.

### Example 2
- **Input:** `arr = [1]`
- **Output:** `[1]`

---

## Constraints

- $0 \le \text{arr.length} \le 10^5$
- $-10^9 \le \text{arr}[i] \le 10^9$

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(N)$ |
| **Space Complexity** | $O(1)$ auxiliary |

