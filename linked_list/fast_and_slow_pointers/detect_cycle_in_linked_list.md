# Detect a Loop in a Linked List (LeetCode 141)

## Problem Statement

Given `head`, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to. Note that `pos` is not passed as a parameter.

Return `true` if there is a cycle in the linked list. Otherwise, return `false`.

---

## Examples

### Example 1
- **Input:** `head = [3, 2, 0, -4]`, `pos = 1`
- **Output:** `true`
- **Explanation:** There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

### Example 2
- **Input:** `head = [1, 2]`, `pos = 0`
- **Output:** `true`
- **Explanation:** Tail connects to node 0.

### Example 3
- **Input:** `head = [1]`, `pos = -1`
- **Output:** `false`
- **Explanation:** No cycle.

---

## Constraints

- The number of the nodes in the list is in the range $[0, 10^4]$.
- $-10^5 \le \text{Node.val} \le 10^5$
- `pos` is `-1` or a valid index in the linked-list.

---

## Floyd’s Cycle-Finding Algorithm (Tortoise & Hare)

1. Initialize `slow = head` and `fast = head`.
2. In each iteration:
   - `slow` advances $1$ step: `slow = slow->next`.
   - `fast` advances $2$ steps: `fast = fast->next->next`.
3. If `fast == nullptr || fast->next == nullptr`, the list terminates linearly $\implies$ return `false`.
4. If a cycle exists, `fast` enters the loop first. With each step, the relative distance between `fast` and `slow` decreases by 1 ($\Delta v = 1$). They are guaranteed to collide in at most $C$ steps, where $C$ is the loop length $\implies$ return `true`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Floyd's Fast & Slow Pointers** | $O(N)$ | $O(1)$ |
| **Hash Set Node Visited Tracking** | $O(N)$ | $O(N)$ |

