# Flattening a Linked List (GFG Classic)

## Problem Statement

Given a Linked List of size $N$, where every node represents a sub-linked-list and contains two pointers:
1. `next`: Points to the next main node in the horizontal chain.
2. `bottom`: Points to a sub-linked-list where all nodes are sorted in ascending order.

Each horizontal list is linked via `next`, and each vertical sub-linked list is sorted via `bottom`.
Flatten the entire multi-level list into a single linked list sorted in ascending order using the `bottom` pointer (`next` pointer of every node in the result should point to `nullptr`).

---

## Examples

### Example 1
- **Input:**
  ```text
  5 -> 10 -> 19 -> 28
  |    |     |     |
  7    20    22    35
  |          |     |
  8          50    40
  |                |
  30               45
  ```
- **Output:**
  `5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 30 -> 35 -> 40 -> 45 -> 50`

---

## Constraints

- $0 \le N \le 500$ (number of head nodes)
- $1 \le \text{total nodes} \le 10^5$
- $1 \le \text{Node.data} \le 10^5$

---

## Divide and Conquer / Recursive Merge Invariant

This problem is structurally equivalent to **Merge K Sorted Lists**:
1. Base case: If `root == nullptr || root->next == nullptr`, return `root`.
2. Recursively flatten the remaining horizontal chain:
   ```cpp
   root->next = flatten(root->next);
   ```
3. Merge the current vertical chain `root` with the flattened horizontal chain `root->next` using standard two-way sorted merge on `bottom` pointers:
   ```cpp
   root = mergeTwoSortedLists(root, root->next);
   ```
4. Return `root`.

---

## Complexity Analysis

| Approach | Time Complexity | Auxiliary Space |
| :--- | :--- | :--- |
| **Recursive Merge (Two at a time from right)** | $O(N \cdot M)$ where $M$ is total nodes | $O(N)$ recursion stack |
| **Min-Heap (Priority Queue)** | $O(M \log K)$ where $K$ is horizontal lists | $O(K)$ heap |

