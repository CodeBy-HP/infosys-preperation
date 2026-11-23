# Deletion of the K-th Element of a Linked List

## Problem Statement

Given the `head` of a singly linked list and an integer `k` ($1$-based index), delete the **$k$-th node** of the linked list and return the head of the modified list.

If $k$ is greater than the total number of nodes, no node should be deleted.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5]`, `k = 3`
- **Output:** `[1, 2, 4, 5]`
- **Explanation:** The 3rd element has value 3 and is removed.

### Example 2
- **Input:** `head = [1, 2, 3]`, `k = 1`
- **Output:** `[2, 3]`
- **Explanation:** Deleting the 1st element updates head to node 2.

### Example 3
- **Input:** `head = [1, 2]`, `k = 5`
- **Output:** `[1, 2]`
- **Explanation:** $k$ exceeds list length; list remains unchanged.

---

## Constraints

- The number of nodes in the list is in the range $[0, 10^5]$.
- $1 \le k \le 10^5$
- $-10^9 \le \text{Node.val} \le 10^9$

---

## The Sentinel Dummy & Lookahead Invariant

1. **When $k = 1$:** The head itself is deleted.
2. **For $k > 1$:** Maintain `curr` and step $k - 2$ times to land on the $(k - 1)$-th node (the predecessor).
3. **Using a Sentinel Node:** `dummy(0); dummy.next = head;` allows treating $k = 1$ and $k > 1$ uniformly by advancing $k - 1$ steps from `dummy`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Sentinel Dummy Node** | $O(N)$ | $O(1)$ |
| **Predecessor Pointer** | $O(N)$ | $O(1)$ |

