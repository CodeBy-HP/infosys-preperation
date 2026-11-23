# Delete the Middle Node of a Linked List (LeetCode 2095)

## Problem Statement

You are given the `head` of a linked list. Delete the **middle node**, and return the `head` of the modified linked list.

The **middle node** of a linked list of size $n$ is the $\lfloor n / 2 \rfloor$-th node from the start using 0-based indexing:
- For $n = 1$: Middle index is 0.
- For $n = 2$: Middle index is 1.
- For $n = 3$: Middle index is 1.
- For $n = 4$: Middle index is 2.
- For $n = 7$: Middle index is 3.

---

## Examples

### Example 1
- **Input:** `head = [1, 3, 4, 7, 1, 2, 6]`
- **Output:** `[1, 3, 4, 1, 2, 6]`
- **Explanation:** $n = 7$, middle index is $\lfloor 7/2 \rfloor = 3$ (value 7), which is deleted.

### Example 2
- **Input:** `head = [1, 2, 3, 4]`
- **Output:** `[1, 2, 4]`
- **Explanation:** $n = 4$, middle index is $\lfloor 4/2 \rfloor = 2$ (value 3), which is deleted.

### Example 3
- **Input:** `head = [2, 1]`
- **Output:** `[2]`
- **Explanation:** Middle is index 1 (value 1), leaving `[2]`.

---

## Constraints

- The number of nodes in the list is in the range $[1, 10^5]$.
- $1 \le \text{Node.val} \le 10^5$

---

## Floyd's Tortoise and Hare with Gap Skip

To delete the middle node in a **single pass** without pre-counting length:
1. If `!head || !head->next`: delete `head` and return `nullptr`.
2. Advance `fast` two steps ahead: `fast = head->next->next; slow = head;`.
3. Loop while `fast != nullptr && fast->next != nullptr`:
   - `slow = slow->next;`
   - `fast = fast->next->next;`
4. Because `fast` was offset by two steps from the start, when `fast` reaches the end, `slow` lands on the node **immediately preceding the middle node**.
5. Delete target:
   ```cpp
   ListNode* middle = slow->next;
   slow->next = middle->next;
   delete middle;
   ```

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Floyd's Fast & Slow with Offset** | $O(N)$ single pass | $O(1)$ |
| **Two-Pass Count & Advance** | $O(N)$ two passes | $O(1)$ |

