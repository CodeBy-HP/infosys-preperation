# Problem 5: Reverse Linked List II (LeetCode 92)

## Problem Statement

Given the `head` of a singly linked list and two integers `left` and `right` where `left <= right`, reverse the nodes of the list from position `left` to position `right`, and return the **reversed list**.

Positions are **1-indexed**.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5], left = 2, right = 4`
- **Output:** `[1, 4, 3, 2, 5]`

### Example 2
- **Input:** `head = [5], left = 1, right = 1`
- **Output:** `[5]`

---

## Constraints

- The number of nodes in the list is $n$.
- $1 \le n \le 500$
- $-500 \le \text{Node.val} \le 500$
- $1 \le \text{left} \le \text{right} \le n$

---

## Invariant: One-Pass Head Insertion

Instead of disconnecting the sublist and reconnecting it with multiple passes, we can reverse the sublist in **one pass** using a sentinel `dummy` node:

1. Traverse `prev` to node `left - 1`.
2. Let `curr = prev->next` (this node will end up at the tail of the reversed sublist).
3. Repeat $(right - left)$ times:
   - Extract `nextNode = curr->next`.
   - Point `curr->next = nextNode->next`.
   - Splice `nextNode` right after `prev`:
     ```cpp
     nextNode->next = prev->next;
     prev->next = nextNode;
     ```

```
Initial (left=2, right=4):
dummy -> 1 -> 2 -> 3 -> 4 -> 5
prev    curr  nextNode

Step 1: Move 3 in front of 2:
dummy -> 1 -> 3 -> 2 -> 4 -> 5
prev          curr  nextNode

Step 2: Move 4 in front of 3:
dummy -> 1 -> 4 -> 3 -> 2 -> 5
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **One-Pass Head Insertion** | $O(N)$ | $O(1)$ | Elegant, no multi-pass overhead |
| **Extract & Reverse Sublist** | $O(N)$ | $O(1)$ | Disconnects sublist, reverses, stitches back |
