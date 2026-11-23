# Delete the Element with Value X in a Linked List

## Problem Statement

Given the `head` of a singly linked list and an integer `X`, delete the **first node** in the linked list that has value equal to `X`.

Return the pointer to the head of the modified linked list. If no node with value `X` exists, return the list unchanged.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4]`, `X = 3`
- **Output:** `[1, 2, 4]`

### Example 2
- **Input:** `head = [5, 1, 2]`, `X = 5`
- **Output:** `[1, 2]`
- **Explanation:** Target is at the head node.

### Example 3
- **Input:** `head = [1, 2, 3]`, `X = 99`
- **Output:** `[1, 2, 3]`
- **Explanation:** `X` is not present; list remains untouched.

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val}, X \le 10^9$

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Sentinel Dummy Node** | $O(N)$ | $O(1)$ |
| **Predecessor Pointer** | $O(N)$ | $O(1)$ |

