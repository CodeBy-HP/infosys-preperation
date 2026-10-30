# Problem 17: Copy List with Random Pointer (LeetCode 138)

## Problem Statement

A linked list of length $n$ is given such that each node contains an additional random pointer, which could point to any node in the list, or `null`.

Construct a **deep copy** of the list. The deep copy should consist of exactly $n$ brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the `next` and `random` pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

Return the `head` of the copied linked list.

---

## Examples

### Example 1
- **Input:** `head = [[7,null],[13,0],[11,4],[10,2],[1,0]]`
- **Output:** `[[7,null],[13,0],[11,4],[10,2],[1,0]]`

---

## Constraints

- $0 \le n \le 1000$
- $-10^4 \le \text{Node.val} \le 10^4$
- `Node.random` is `null` or is pointing to some node in the linked list.

---

## Algorithmic Masterclass: The 3-Pass Node Weaving Technique

While a hash map solution takes $O(N)$ extra memory, the **Weaving Technique** achieves deep copying in $O(1)$ auxiliary space:

### Pass 1: Interleave cloned nodes
For every node $A$, create clone $A'$ and insert it directly after $A$:
$$A \to A' \to B \to B' \to C \to C'$$

### Pass 2: Assign cloned `random` pointers
For each original node `curr`:
$$\text{curr}\to\text{next}\to\text{random} = \text{curr}\to\text{random} \ ? \ \text{curr}\to\text{random}\to\text{next} : \text{nullptr}$$

### Pass 3: Unweave the two lists
Separate original nodes from cloned nodes restoring the original list links and building the cloned list:
```cpp
curr->next = clone->next;
clone->next = clone->next ? clone->next->next : nullptr;
```

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity | Notes |
| :--- | :--- | :--- | :--- |
| **Node Interleaving (Weaving)** | $O(N)$ | $O(1)$ | Strictly $O(1)$ auxiliary space |
| **Hash Map (`orig -> clone`)**  | $O(N)$ | $O(N)$ | Map lookups take extra heap memory |
