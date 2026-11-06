# Insert a Node into a Binary Search Tree (BST)

## Problem Statement
Given the `root` node of a binary search tree (BST) and a `val` to insert into the tree, return the root of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.

Notice that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. You can return any of them.

```
        4
       / \
      2   7
     / \
    1   3

val = 5
Inserted:
        4
       / \
      2   7
     / \  /
    1  3 5
```

---

## 1. Algorithmic Approaches

### Approach A: Iterative Insertion ($O(H)$ time, $O(1)$ space)
1. If `root == nullptr`, return `new TreeNode(val)`.
2. Maintain `curr = root`.
3. Loop infinitely:
   - If `val < curr->val`:
     - If `curr->left != nullptr`, move `curr = curr->left`.
     - Else, attach `curr->left = new TreeNode(val)` and break.
   - If `val > curr->val`:
     - If `curr->right != nullptr`, move `curr = curr->right`.
     - Else, attach `curr->right = new TreeNode(val)` and break.
4. Return `root`.

### Approach B: Recursive Insertion ($O(H)$ time, $O(H)$ stack)
```cpp
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) {
        root->left = insertIntoBST(root->left, val);
    } else {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}
```

---

## 2. Complexity Analysis
- **Time Complexity:** $O(H)$ — Traverses down from the root to an empty leaf position ($O(\log N)$ balanced, $O(N)$ worst-case).
- **Space Complexity:**
  - Iterative: $O(1)$ auxiliary memory.
  - Recursive: $O(H)$ recursion stack frames.

