# Sort a Linked List of 0s, 1s, and 2s

## Problem Statement

Given the `head` of a singly linked list containing only numbers `0`, `1`, and `2`, sort the linked list so that all `0`s appear first, followed by all `1`s, and finally all `2`s.

You must rearrange the list in-place by updating links rather than just overwriting values.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 2, 1, 2, 0, 2, 2]`
- **Output:** `[0, 1, 1, 2, 2, 2, 2, 2]`

### Example 2
- **Input:** `head = [2, 1, 0, 2]`
- **Output:** `[0, 1, 2, 2]`

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $\text{Node.val} \in \{0, 1, 2\}$

---

## Three-Dummy Partition Invariant

Maintain three dummy nodes (`zeroDummy`, `oneDummy`, `twoDummy`) with their respective tail pointers:
1. Traverse list and link each node to the tail of `0`, `1`, or `2`.
2. Connect tails:
   - `zeroTail->next = (oneDummy.next) ? oneDummy.next : twoDummy.next;`
   - `oneTail->next = twoDummy.next;`
   - `twoTail->next = nullptr;` (essential to sever cycle).
3. Return `zeroDummy.next ? zeroDummy.next : (oneDummy.next ? oneDummy.next : twoDummy.next)`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Three-Pointer Splicing (Pointer Rewiring)** | $O(N)$ | $O(1)$ |
| **Frequency Counting (Value Replacement)** | $O(N)$ | $O(1)$ |

