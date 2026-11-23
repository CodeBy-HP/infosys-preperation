# Remove Duplicates from Sorted Doubly Linked List

## Problem Statement

Given the `head` of a **sorted** doubly linked list, remove all duplicate nodes such that each element appears only once.

Return the pointer to the head of the modified doubly linked list.

---

## Examples

### Example 1
- **Input:** `head = [1, 1, 1, 2, 3, 3, 4]`
- **Output:** `[1, 2, 3, 4]`

### Example 2
- **Input:** `head = [1, 2, 2]`
- **Output:** `[1, 2]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $-10^9 \le \text{Node.val} \le 10^9$
- The list is sorted in non-decreasing order.

---

## Lookahead Duplicate Skipping

Because the list is sorted, all duplicate values form contiguous clusters:
1. Iterate while `curr != nullptr && curr->next != nullptr`.
2. Look ahead using inner loop: `nextNode = curr->next; while (nextNode != nullptr && nextNode->val == curr->val)`.
3. Free intermediate duplicate nodes.
4. Rewire: `curr->next = nextNode; if (nextNode) nextNode->prev = curr;`.
5. Advance `curr = curr->next;`.

---

## Complexity Analysis

| Metric | Complexity |
| :--- | :--- |
| **Time Complexity** | $O(N)$ |
| **Space Complexity** | $O(1)$ |

