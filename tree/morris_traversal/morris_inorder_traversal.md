# Morris Inorder Traversal ($O(1)$ Space)

## Problem Statement
Given the `root` of a binary tree, return the **inorder traversal** of its nodes' values using **$O(1)$ auxiliary memory** (without recursion and without an explicit stack).

---

## 1. Algorithmic Approach (Threaded Binary Tree)

### The Core Obstacle
Standard DFS or stack-based traversal uses $O(H)$ space to remember the path back to the parent once the left subtree is exhausted. 

### The Threading Solution
In an Inorder traversal ($\text{Left} \to \text{Root} \to \text{Right}$), the node visited immediately before `curr` is its **in-order predecessor** (the rightmost node of `curr`'s left subtree).
Instead of keeping a stack, we temporarily modify the tree by pointing the predecessor's `right` pointer back to `curr`:
$$\text{predecessor}\to\text{right} = \text{curr}$$

```
Step 1: Create Thread                 Step 2: Traverse & Cut Thread
         curr                                  curr (revisited!)
        /                                     /
     pred                                  pred
        \                                     \
         (points back to curr)                 nullptr (restored!)
```

### Algorithm State Machine
1. Initialize `curr = root`.
2. While `curr != nullptr`:
   - **Case 1: `curr->left == nullptr`**
     - No left subtree to explore.
     - Add `curr->val` to result.
     - Move right: `curr = curr->right`.
   - **Case 2: `curr->left != nullptr`**
     - Find the in-order predecessor `prev`:
       ```cpp
       TreeNode* prev = curr->left;
       while (prev->right != nullptr && prev->right != curr) {
           prev = prev->right;
       }
       ```
     - **Subcase 2A: `prev->right == nullptr` (Thread Creation):**
       - Establish temporary back-link: `prev->right = curr`.
       - Move left: `curr = curr->left`.
     - **Subcase 2B: `prev->right == curr` (Thread Cut / Return Trip):**
       - The left subtree has already been fully visited!
       - Sever the temporary thread: `prev->right = nullptr` (restoring tree).
       - Add `curr->val` to result.
       - Move right: `curr = curr->right`.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Although it looks like nested loops, each edge in the tree is traversed at most 3 times (finding predecessor, threading, and cutting). Amortized time is strictly $O(N)$.
- **Space Complexity:** $O(1)$ — Zero recursion stack, zero data structure allocations.

