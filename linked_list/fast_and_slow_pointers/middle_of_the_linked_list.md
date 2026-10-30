# Problem 1: Middle of the Linked List (LeetCode 876)

## Problem Statement

Given the `head` of a singly linked list, return the **middle node** of the linked list.

If there are two middle nodes (i.e. the list has an even number of nodes), return the **second middle** node.

---

## Examples

### Example 1
- **Input:** `head = [1, 2, 3, 4, 5]`
- **Output:** `[3, 4, 5]`
- **Explanation:** The middle node of the list is node 3 with value 3.

### Example 2
- **Input:** `head = [1, 2, 3, 4, 5, 6]`
- **Output:** `[4, 5, 6]`
- **Explanation:** Since the list has two middle nodes with values 3 and 4, we return the second one (node 4).

---

## Constraints

- The number of nodes in the list is in the range $[1, 100]$.
- $1 \le \text{Node.val} \le 100$

---

## Pattern & Intuition: Fast & Slow Pointers

The **Fast & Slow Pointer** (Tortoise and Hare) pattern uses two pointers moving at different speeds:
- `slow` moves **1 step** per iteration: `slow = slow->next`
- `fast` moves **2 steps** per iteration: `fast = fast->next->next`

### Why it works:
When `fast` traverses $2k$ steps, `slow` traverses $k$ steps. Therefore, when `fast` reaches the end of the list of length $N$:
- **Odd Length ($N = 2k + 1$):** `fast` lands on the last node (`fast->next == nullptr`). `slow` is on the exact middle $(k + 1)$-th node.
- **Even Length ($N = 2k$):** `fast` advances past the last node (`fast == nullptr`). `slow` lands on the second middle $(k + 1)$-th node.

```
Odd Length (5 nodes):
1 -> 2 -> 3 -> 4 -> 5 -> NULL
          ^              ^
        slow            fast (fast->next == NULL)

Even Length (6 nodes):
1 -> 2 -> 3 -> 4 -> 5 -> 6 -> NULL
               ^              ^
             slow            fast (fast == NULL)
```

Condition to keep advancing: `while (fast != nullptr && fast->next != nullptr)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Fast & Slow Pointers** | $O(N)$ | $O(1)$ | Single pass, stops at $N/2$ iterations |
| **Two-Pass (Length Count)** | $O(N)$ | $O(1)$ | First pass counts $N$, second pass walks $N/2$ |
| **Vector Storage** | $O(N)$ | $O(N)$ | Stores pointers in vector, returns `vec[N/2]` |
