# Problem 20: Delete Node in a BST (LeetCode 450)

## Problem Statement

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the **root node reference** (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:
1. Search for a node to remove.
2. If the node is found, delete the node.

---

## Examples

### Example 1
```text
        5
       / \
      3   6
     / \   \
    2   4   7
Delete key = 3:
        5
       / \
      4   6
     /     \
    2       7
```
- **Input:** `root = [5,3,6,2,4,null,7], key = 3`
- **Output:** `[5,4,6,2,null,null,7]`

---

## Constraints

- The number of nodes in the tree is in the range $[0, 10^4]$.
- $-10^5 \le \text{Node.val} \le 10^5$
- Each node has a **unique** value.
- `key` is found in the BST.

---

## The 3 Deletion Cases

1. **Leaf Node (`!left && !right`):** Safely delete node and return `nullptr`.
2. **One Child:** Return the non-null child to take the deleted node's place:
   `return left ? left : right`.
3. **Two Children:**
   - Find the **In-Order Successor** (the smallest node in the right subtree).
   - Overwrite current node's value with successor's value: `root->val = successor->val`.
   - Recursively delete the successor from the right subtree:
     `root->right = deleteNode(root->right, successor->val)`.

---

## Complexity Analysis

| Approach | Time Complexity | Space Complexity |
| :--- | :--- | :--- |
| **Recursive BST Deletion** | $O(H)$ | $O(H)$ recursion stack |
