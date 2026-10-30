# Problem 18: Flatten a Multilevel Doubly Linked List (LeetCode 430)

## Problem Statement

You are given a doubly linked list, which contains nodes that have a **next** pointer, a **previous** pointer, and an additional **child** pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure.

Given the `head` of the first level of the list, **flatten** the list so that all the nodes appear in a single-level, doubly linked list. Let $curr$ be a node with a child list. The nodes in the child list should appear after $curr$ and before $curr.next$ in the flattened list.

Return the `head` of the flattened list. The nodes in the list must have all of their child pointers set to `null`.

---

## Examples

```
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

Flattened:
 1-2-3-7-8-11-12-9-10-4-5-6-NULL
```

---

## Constraints

- The number of Nodes will not exceed $1000$.
- $1 \le \text{Node.val} \le 10^5$

---

## Pattern: Preorder DFS / Pointer Splicing

Whenever node `curr` has a `child`:
1. Save `nextNode = curr->next`.
2. Recursively (or iteratively) flatten the child branch.
3. Stitch child list:
   - `curr->next = curr->child;`
   - `curr->child->prev = curr;`
4. Traverse to the tail of the child branch (`childTail`).
5. Connect `childTail` to `nextNode`:
   - `childTail->next = nextNode;`
   - If `nextNode`: `nextNode->prev = childTail;`
6. Sever `curr->child = nullptr`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Iterative In-Place Splicing** | $O(N)$ | $O(1)$ | Strictly constant auxiliary space |
| **DFS with Stack**             | $O(N)$ | $O(N)$ | Explicit stack for `next` pointers |
