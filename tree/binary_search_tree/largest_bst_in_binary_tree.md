# Largest BST in a Binary Tree

## Problem Statement
Given the `root` of a binary tree, find the **size of the largest subtree** that is a Binary Search Tree (BST).

The size of a subtree is the **number of nodes** it contains.

```
          10
        /    \
       5      15
      / \       \
     1   8       7

Subtrees:
- Subtree rooted at 10: Not a BST (Right child has 7 < 10)
- Subtree rooted at 15: Not a BST (Right child is 7 < 15)
- Subtree rooted at 5:  Valid BST [1, 5, 8] -> Size = 3
- Subtree rooted at 1:  Valid BST -> Size = 1
- Subtree rooted at 8:  Valid BST -> Size = 1
- Subtree rooted at 7:  Valid BST -> Size = 1

Largest BST Size = 3 (rooted at node 5)
```

---

## 1. Algorithmic Approach (Bottom-Up Post-Order DFS in $O(N)$)

### The Naive $O(N^2)$ Trap
Checking `isValidBST(curr)` for every node takes $O(N)$ time per node, leading to $O(N^2)$ total complexity.

### The Bottom-Up Tuple Synthesis ($O(N)$ Time)
Instead of top-down validation, we gather information from the bottom up. Every node receives a tuple from its left and right subtrees:
$$\text{NodeValue} = (\text{minNode}, \text{maxNode}, \text{maxSize})$$

1. **Base Case (Null Pointer):**
   - Returns: `minNode = INT_MAX`, `maxNode = INT_MIN`, `maxSize = 0`.
2. **Current Node Invariant:**
   A subtree rooted at `root` is a valid BST **if and only if**:
   $$\text{left}.\text{maxNode} < \text{root}\to\text{val} < \text{right}.\text{minNode}$$
3. **If Valid BST:**
   - Size: $1 + \text{left}.\text{maxSize} + \text{right}.\text{maxSize}$.
   - New Minimum: $\min(\text{root}\to\text{val}, \text{left}.\text{minNode})$.
   - New Maximum: $\max(\text{root}\to\text{val}, \text{right}.\text{maxNode})$.
4. **If Invalid BST:**
   - Any ancestor of `root` can never form a valid BST!
   - To force all parents to fail, we corrupt the range:
     $$\text{minNode} = -\infty, \quad \text{maxNode} = +\infty$$
   - Size: $\max(\text{left}.\text{maxSize}, \text{right}.\text{maxSize})$.

---

## 2. Complexity Analysis
- **Time Complexity:** $O(N)$ — Every node is visited exactly once in post-order traversal.
- **Space Complexity:** $O(H)$ — Auxiliary call stack space bounded by the tree height.

