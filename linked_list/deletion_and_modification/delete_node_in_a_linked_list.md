# Problem 24: Delete Node in a Linked List (LeetCode 237)

## Problem Statement

There is a singly-linked list `head` and we want to delete a node in it.

You are given the node to be deleted `node`. You will **not be given access to the first node** of `head`.

All the values of the linked list are **unique**, and it is guaranteed that the given node is **not the last node** in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:
- The value of the given node should not exist in the linked list.
- The number of nodes in the linked list should decrease by one.
- All the values before `node` should be in the same order.
- All the values after `node` should be in the same order.

---

## Examples

### Example 1
- **Input:** `head = [4, 5, 1, 9], node = 5`
- **Output:** `[4, 1, 9]`

---

## Constraints

- The number of the nodes in the given list is in the range $[2, 1000]$.
- $-1000 \le \text{Node.val} \le 1000$
- The value of each node in the list is **unique**.
- The `node` to be deleted is in the list and is **not a tail node**.

---

## Insight: Value Overwrite & Splicing Next Node

Because we don't have access to the predecessor node, we cannot rewire `prev->next = curr->next`.
Instead, we:
1. Copy the value from the subsequent node: `node->val = node->next->val`.
2. Delete the subsequent node: `node->next = node->next->next`.

```
Target is 5:
4 -> [5] -> [1] -> 9
Copy 1 to target:
4 -> [1] -> [1] -> 9
Bypass next node:
4 -> [1] --------> 9
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Value Copying** | $O(1)$ | $O(1)$ |
