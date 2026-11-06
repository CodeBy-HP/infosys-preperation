# Construct BST from Preorder Traversal

## Problem Statement
Given an array of integers `preorder`, which represents the **preorder traversal** of a binary search tree (BST), construct and return the binary search tree.

It is guaranteed that for the given test cases, there is always possible to find a binary search tree with the given requirements.

```
Input: preorder = [8, 5, 1, 7, 10, 12]

Reconstructed BST:
          8
        /   \
       5     10
      / \      \
     1   7      12
```

---

## 1. Algorithmic Approaches

### Approach A: Sort to Find Inorder ($O(N \log N)$ time)
Since the in-order traversal of a BST is strictly ascending, sorting the preorder array produces the inorder array in $O(N \log N)$ time. Then invoke the standard `buildTree(preorder, inorder)` in $O(N)$ time.

---

### Approach B: Optimal Single-Pass Upper Bound ($O(N)$ time, $O(H)$ space)

#### Core Intuition
Preorder visits **Root $\to$ Left $\to$ Right**.
Instead of searching for boundaries or maintaining lower and upper bounds, maintaining **just an upper bound `bound`** is sufficient:
1. For the root node, the upper bound is $+\infty$.
2. When creating the **left child**, the upper bound becomes the current `node->val` (everything in the left subtree must be $< \text{node}\to\text{val}$).
3. When creating the **right child**, the upper bound remains the parent's `bound` (everything in the right subtree must be $< \text{bound}$, and is already guaranteed $> \text{node}\to\text{val}$ because we failed to place it into the left child).

```cpp
TreeNode* bstFromPreorder(vector<int>& A) {
    int i = 0;
    return build(A, i, INT_MAX);
}

TreeNode* build(vector<int>& A, int& i, int bound) {
    if (i == A.size() || A[i] > bound) return nullptr;
    TreeNode* root = new TreeNode(A[i++]);
    root->left = build(A, i, root->val);
    root->right = build(A, i, bound);
    return root;
}
```

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — The index pointer `i` advances from $0$ to $N - 1$. Each element is visited and placed in $O(1)$ amortized steps.
- **Space Complexity:** $O(H)$ — Recursion call stack bounded by tree height $H$.

