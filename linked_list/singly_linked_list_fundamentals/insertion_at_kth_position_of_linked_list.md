# Insertion at the K-th Position of a Linked List

## Problem Statement

Given the `head` of a singly linked list, an integer `val`, and an integer `k` ($1$-based position), insert a new node with value `val` such that it becomes the $k$-th node in the list.

- If $k = 1$, the new node becomes the new head.
- If $k = N + 1$, the new node is appended to the tail.
- If $k > N + 1$, the list remains unchanged.

Return the pointer to the head of the modified linked list.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 4, 5]`, `val = 3`, `k = 3`
- **Output:** `[1, 2, 3, 4, 5]`

### Example 2
- **Input:** `head = [2, 3]`, `val = 1`, `k = 1`
- **Output:** `[1, 2, 3]`

### Example 3
- **Input:** `head = [1, 2]`, `val = 3`, `k = 3`
- **Output:** `[1, 2, 3]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $1 \le k \le 10^5 + 1$
- $-10^9 \le \text{Node.val}, val \le 10^9$

---

## Sentinel Insertion Invariant

Using a sentinel dummy node `dummy(0); dummy.next = head;`:
1. Advance `curr = &dummy` for $k - 1$ steps.
2. If `curr != nullptr`, splice the new node:
   ```cpp
   ListNode* newNode = new ListNode(val);
   newNode->next = curr->next;
   curr->next = newNode;
   ```
3. Return `dummy.next`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(\min(k, N))$ |
| **Space Complexity** | $O(1)$ |

