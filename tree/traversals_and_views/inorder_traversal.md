# Binary Tree Inorder Traversal

## Problem Statement
Given the `root` of a binary tree, return the **inorder traversal** of its nodes' values.

**Inorder Rule:** Traverse the **Left subtree**, then visit the **Root (Current node)**, then traverse the **Right subtree**.
$$\text{Order: } \text{Left} \longrightarrow \text{Root} \longrightarrow \text{Right}$$

---

## 1. Recursive Approach

### Algorithm
1. If the current node is `nullptr`, return.
2. Recursively call `inorder(node->left)`.
3. Process `node->val`.
4. Recursively call `inorder(node->right)`.

### Complexity
- **Time Complexity:** $O(N)$ — Every node is visited exactly once.
- **Space Complexity:** $O(H)$ — Auxiliary stack frames proportional to the height $H$ of the tree ($O(\log N)$ best/balanced, $O(N)$ skewed).

---

## 2. Iterative Approach (Using Explicit Stack)

### Intuition
To simulate the call stack iteratively:
1. Drill down as far left as possible, pushing every ancestor node onto `std::stack<TreeNode*>`.
2. When hitting `nullptr` (left boundary reached), the top of the stack is the leftmost unvisited node (the "root" of the local subtree).
3. Pop the node, process its value, and transition to its right child (`curr = curr->right`).
4. Repeat while `curr != nullptr` or the stack is non-empty.

```
       1
      / \
     2   3
    / \
   4   5

Stack progression:
Push: [1] -> [1, 2] -> [1, 2, 4]
Pop 4: Output [4]. curr = 4->right (nullptr)
Pop 2: Output [4, 2]. curr = 2->right (5)
Push 5: [1, 5]
Pop 5: Output [4, 2, 5]. curr = 5->right (nullptr)
Pop 1: Output [4, 2, 5, 1]. curr = 1->right (3)
Push 3: [3]
Pop 3: Output [4, 2, 5, 1, 3].
Final Inorder: [4, 2, 5, 1, 3]
```

### Complexity
- **Time Complexity:** $O(N)$ — Each node is pushed and popped exactly once.
- **Space Complexity:** $O(H)$ — Stack holds at most $H$ nodes along the current branch.

