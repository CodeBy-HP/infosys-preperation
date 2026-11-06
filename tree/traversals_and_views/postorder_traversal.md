# Binary Tree Postorder Traversal

## Problem Statement
Given the `root` of a binary tree, return the **postorder traversal** of its nodes' values.

**Postorder Rule:** Traverse the **Left subtree**, then traverse the **Right subtree**, then visit the **Root (Current node)**.
$$\text{Order: } \text{Left} \longrightarrow \text{Right} \longrightarrow \text{Root}$$

---

## 1. Recursive Approach

```cpp
void postorder(TreeNode* root, vector<int>& res) {
    if (!root) return;
    postorder(root->left, res);
    postorder(root->right, res);
    res.push_back(root->val);
}
```
- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(H)$ stack frames.

---

## 2. Iterative Approach (Using 2 Stacks)

### Intuition
Postorder is $\text{Left} \to \text{Right} \to \text{Root}$.
Notice that reversing this gives $\text{Root} \to \text{Right} \to \text{Left}$.
This is just modified preorder (visiting Right before Left)!
1. Push `root` to `st1`.
2. While `st1` is not empty:
   - Pop `curr = st1.top()`.
   - Push `curr` to `st2`.
   - Push `curr->left` to `st1`.
   - Push `curr->right` to `st1`.
3. Pop all elements from `st2` into result.

- **Time Complexity:** $O(N)$
- **Space Complexity:** $O(N)$ — `st2` stores all $N$ nodes.

---

## 3. Iterative Approach (Using 1 Stack & Last Visited Pointer)

### Intuition
To use only one stack of size $O(H)$:
1. Traverse leftwards as far as possible, pushing nodes onto the stack.
2. When hitting `nullptr`, inspect `st.top()->right`.
3. If right child exists and was not just visited (`top->right != lastVisited`):
   - Move `curr = top->right` to process the right subtree.
4. Otherwise (no right child, or right child is already processed):
   - Pop the node from stack, record its value.
   - Update `lastVisited = popped_node`.
   - Keep `curr = nullptr` so next iteration pops the parent.

- **Time Complexity:** $O(N)$ — Every edge traversed at most twice.
- **Space Complexity:** $O(H)$ — Stack holds at most $H$ nodes along the branch.

