# Problem 2: Linked List Cycle II (LeetCode 142)

## Problem Statement

Given the `head` of a linked list, return the **node where the cycle begins**. If there is no cycle, return `null`.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the `next` pointer. Internally, `pos` is used to denote the index of the node that tail's `next` pointer is connected to (**0-indexed**). It is `-1` if there is no cycle. **Note that `pos` is not passed as a parameter.**

**Do not modify the linked list.**

---

## Examples

### Example 1
- **Input:** `head = [3, 2, 0, -4], pos = 1` (tail links back to node index 1, value 2)
- **Output:** `tail connects to node index 1`
- **Explanation:** There is a cycle in the linked list, where tail connects to the second node.

### Example 2
- **Input:** `head = [1, 2], pos = 0`
- **Output:** `tail connects to node index 0`

### Example 3
- **Input:** `head = [1], pos = -1`
- **Output:** `no cycle`

---

## Constraints

- The number of the nodes in the list is in the range $[0, 10^4]$.
- $-10^5 \le \text{Node.val} \le 10^5$
- `pos` is `-1` or a valid index in the linked-list.

---

## Mathematical Proof: Floyd's Cycle Finding Algorithm

Let:
- $L$ = distance from `head` to the **cycle entry node**.
- $C$ = length of the cycle.
- $x$ = distance from cycle entry node to the **meeting point** of slow and fast pointers.

```
       L                 x
head ------> [Entry] ---------> [Meeting Point]
                ^                     |
                |                     | (C - x)
                +---------------------+
```

1. **Distance Traveled:**
   - $\text{Distance}_{\text{slow}} = L + x$
   - $\text{Distance}_{\text{fast}} = L + x + nC$, where $n \ge 1$ is the number of full cycles fast looped.

2. **Speed Relationship:**
   - Since fast travels at twice the speed of slow:
   $$\text{Distance}_{\text{fast}} = 2 \times \text{Distance}_{\text{slow}}$$
   $$L + x + nC = 2(L + x)$$
   $$nC = L + x$$
   $$L = nC - x = (n - 1)C + (C - x)$$

3. **Key Deduction:**
   - $L$ (distance from `head` to `Entry`) is identically equal to $(C - x)$ plus some integer number of full loops $(n - 1)C$.
   - Therefore, if we reset a pointer `p1 = head` and keep `p2 = Meeting Point`, and advance both at **1 step per second**, they are mathematically guaranteed to collide exactly at the **cycle entry node**!

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Floyd's Algorithm** | $O(N)$ | $O(1)$ | Optimal mathematical two-pointer collision |
| **Hash Set** | $O(N)$ | $O(N)$ | Stores visited node pointers |
