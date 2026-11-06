# Root to Leaf Paths in Binary Tree

## Problem Statement
Given the `root` of a binary tree, return all **root-to-leaf paths** in the tree.

A leaf is a node with no children (`!node->left && !node->right`).

```
          1
        /   \
       2     3
      / \
     4   5

Paths:
"1->2->4"
"1->2->5"
"1->3"
```

---

## 1. Algorithmic Approach (Top-Down Backtracking DFS)

### Path Propagation & Backtracking
1. Maintain a running path vector `currentPath`.
2. Push `node->val` to `currentPath`.
3. Check leaf condition:
   - If `!node->left && !node->right`: we reached a leaf! Record a snapshot of `currentPath` into `allPaths`.
4. Otherwise:
   - If `node->left`: recurse `dfs(node->left)`.
   - If `node->right`: recurse `dfs(node->right)`.
5. **Backtracking:** Upon returning, remove `node->val` from `currentPath` (`currentPath.pop_back()`) to keep the path state clean for sibling branches.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N \cdot H)$ — There are at most $L$ leaves (where $L \le \lceil N/2 \rceil$), each path takes $O(H)$ time to copy into the result.
- **Space Complexity:** $O(H)$ auxiliary recursion stack and path buffer.

