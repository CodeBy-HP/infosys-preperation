# Insertion Before Value X in a Linked List

## Problem Statement

Given the `head` of a singly linked list, an integer `val`, and an integer `X`, insert a new node containing value `val` immediately **before the first occurrence of node with value `X`**.

If no node with value `X` exists, do not insert any node and return the original list.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 4, 5]`, `val = 3`, `X = 4`
- **Output:** `[1, 2, 3, 4, 5]`

### Example 2
- **Input:** `head = [2, 3]`, `val = 1`, `X = 2`
- **Output:** `[1, 2, 3]`
- **Explanation:** $X$ is at the head, so `val` becomes the new head.

### Example 3
- **Input:** `head = [1, 2, 3]`, `val = 10`, `X = 99`
- **Output:** `[1, 2, 3]`
- **Explanation:** Value 99 is not present; list remains untouched.

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val}, val, X \le 10^9$

---

## Sentinel Predecessor Invariant

Using dummy sentinel node `dummy(0); dummy.next = head;`:
1. Traverse with pointer `curr = &dummy`.
2. Look ahead: check if `curr->next != nullptr && curr->next->val == X`.
3. When found:
   ```cpp
   ListNode* newNode = new ListNode(val);
   newNode->next = curr->next;
   curr->next = newNode;
   ```
4. Return `dummy.next`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(N)$ |
| **Space Complexity** | $O(1)$ |

