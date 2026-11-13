# Morris Preorder Traversal ($O(1)$ Space)

## Problem Statement
Given the `root` of a binary tree, return the **preorder traversal** of its nodes' values using **$O(1)$ auxiliary memory** (without recursion and without an explicit stack).

---

## 1. Algorithmic Approach (Threaded Preorder)

### Comparison with Morris Inorder
Notice the timing of when `curr->val` is visited:
- **Inorder ($\text{Left} \to \text{Root} \to \text{Right}$):** Visit `curr->val` when **returning** from the left subtree (at the moment of **severing** the thread: `prev->right == curr`).
- **Preorder ($\text{Root} \to \text{Left} \to \text{Right}$):** Visit `curr->val` immediately upon **first encounter**, before exploring the left subtree (at the moment of **creating** the thread: `prev->right == nullptr`).

```
Algorithm State Machine:
Initialize curr = root

While curr != nullptr:
    If curr->left == nullptr:
        Add curr->val to preorder
        curr = curr->right
    Else:
        Find in-order predecessor prev (rightmost node in curr->left)
        
        If prev->right == nullptr:
            Add curr->val to preorder   <--- VISIT ROOT BEFORE ENTERING LEFT
            prev->right = curr          <--- CREATE THREAD
            curr = curr->left
        Else: (prev->right == curr)
            prev->right = nullptr       <--- CUT THREAD (Do not re-visit curr)
            curr = curr->right
```

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Every edge is traversed at most 3 times.
- **Space Complexity:** $O(1)$ — Strictly constant auxiliary memory; input tree structure is fully restored upon termination.

