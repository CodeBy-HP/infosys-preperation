# Preorder, Inorder, and Postorder Traversal in One Pass

## Problem Statement
Given the `root` of a binary tree, compute the **Preorder**, **Inorder**, and **Postorder** traversals simultaneously in a **single pass** using a single stack.

---

## 1. Algorithmic Approach (Single Stack with State Machine)

### Core Intuition
In recursive traversal, every node is visited 3 times:
1. **First visit (State 1):** Coming down from parent before visiting left subtree $\longrightarrow$ **Preorder**.
2. **Second visit (State 2):** Returning from left subtree before going right $\longrightarrow$ **Inorder**.
3. **Third visit (State 3):** Returning from right subtree before returning to parent $\longrightarrow$ **Postorder**.

We can simulate this exactly using a single stack storing pairs: `std::pair<TreeNode*, int> (node, state)`:

```
Initialize: stack.push({root, 1})

While stack is not empty:
  Pop {node, state}
  
  If state == 1:
      preorder.push_back(node->val)
      stack.push({node, 2})
      if (node->left) stack.push({node->left, 1})
      
  Else if state == 2:
      inorder.push_back(node->val)
      stack.push({node, 3})
      if (node->right) stack.push({node->right, 1})
      
  Else if state == 3:
      postorder.push_back(node->val)
      // Do not re-push; node is fully processed!
```

---

## 2. Complexity Analysis
- **Time Complexity:** $O(3N) = O(N)$ — Every node transitions through states 1, 2, and 3.
- **Space Complexity:** $O(H)$ — Auxiliary stack depth matches tree height $H$ ($O(\log N)$ balanced, $O(N)$ skewed).

