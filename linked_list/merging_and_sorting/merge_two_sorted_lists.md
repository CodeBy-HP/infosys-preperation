# Problem 11: Merge Two Sorted Lists (LeetCode 21)

## Problem Statement

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one **sorted** list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

---

## Examples

### Example 1
- **Input:** `list1 = [1, 2, 4], list2 = [1, 3, 4]`
- **Output:** `[1, 1, 2, 3, 4, 4]`

### Example 2
- **Input:** `list1 = [], list2 = []`
- **Output:** `[]`

### Example 3
- **Input:** `list1 = [], list2 = [0]`
- **Output:** `[0]`

---

## Constraints

- The number of nodes in both lists is in the range $[0, 50]$.
- $-100 \le \text{Node.val} \le 100$
- Both `list1` and `list2` are sorted in non-decreasing order.

---

## Two Core Formulations: Iterative with Sentinel vs Recursive

### 1. Iterative with Dummy Node
Maintain `tail` pointer starting at `dummy`:
- Compare `list1->val` and `list2->val`.
- Append smaller node to `tail->next` and advance the corresponding list pointer.
- Once one list is exhausted, directly link the remainder: `tail->next = list1 ? list1 : list2`.

### 2. Recursive Formulation
The smaller head becomes the root of the merged result:
```cpp
if (list1->val <= list2->val) {
    list1->next = mergeTwoLists(list1->next, list2);
    return list1;
} else {
    list2->next = mergeTwoLists(list1, list2->next);
    return list2;
}
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Iterative with Dummy** | $O(N + M)$ | $O(1)$ | Optimal space, no recursion overhead |
| **Recursive**           | $O(N + M)$ | $O(N + M)$ | Call stack depth |
