# Binary Tree Preorder Traversal

## Problem Statement
Given the `root` of a binary tree, return the **preorder traversal** of its nodes' values.

**Preorder Rule:** Visit the **Root (Current node)** first, then traverse the **Left subtree**, then traverse the **Right subtree**.
$$\text{Order: } \text{Root} \longrightarrow \text{Left} \longrightarrow \text{Right}$$

---

## 1. Recursive Approach

### Algorithm
1. If current node is `nullptr`, return.
2. Process `node->val`.
3. Recursively call `preorder(node->left)`.
4. Recursively call `preorder(node->right)`.

### Complexity
- **Time Complexity:** $O(N)$ — Every node is visited once.
- **Space Complexity:** $O(H)$ — Call stack depth bounded by tree height $H$.

---

## 2. Iterative Approach (Using Explicit Stack)

### Intuition
Since a stack is LIFO (Last-In, First-Out), to visit `Left` before `Right`:
1. Push `root` to stack.
2. While stack is not empty:
   - Pop `curr = st.top()`.
   - Process `curr->val`.
   - **Push `curr->right` first** (if non-null), so it sits underneath.
   - **Push `curr->left` second** (if non-null), so it will be popped and processed first.

```
       1
      / \
     2   3
    / \
   4   5

Stack progression:
Push root: [1]
Pop 1: Output [1]. Push 3, then 2 -> [3, 2]
Pop 2: Output [1, 2]. Push 5, then 4 -> [3, 5, 4]
Pop 4: Output [1, 2, 4]. (No children)
Pop 5: Output [1, 2, 4, 5]. (No children)
Pop 3: Output [1, 2, 4, 5, 3]. (No children)
Final Preorder: [1, 2, 4, 5, 3]
```

### Complexity
- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(H)$ auxiliary stack frames.

