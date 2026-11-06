# Children Sum Property in Binary Tree

## Problem Statement
The **Children Sum Property** states that for every internal (non-leaf) node in a binary tree:
$$\text{node}\to\text{val} = (\text{node}\to\text{left} \text{ ? } \text{node}\to\text{left}\to\text{val} : 0) + (\text{node}\to\text{right} \text{ ? } \text{node}\to\text{right}\to\text{val} : 0)$$
Leaf nodes trivially satisfy the property.

Two common interview questions are asked on this topic:
1. **Validation:** Check if a given binary tree satisfies the children sum property.
2. **Transformation:** Modify an arbitrary binary tree such that it satisfies the children sum property, allowing only node value **increments** (never decrements).

---

## 1. Checking Children Sum Property

### Algorithm
- Base case: If node is `nullptr` or a leaf (`!node->left && !node->right`), return `true`.
- Calculate expected sum of existing children: $\text{sum} = (\text{left} ? \text{left}\to\text{val} : 0) + (\text{right} ? \text{right}\to\text{val} : 0)$.
- If $\text{node}\to\text{val} \ne \text{sum}$, return `false`.
- Recursively verify both left and right subtrees.

**Complexity:** $O(N)$ time, $O(H)$ space.

---

## 2. Converting an Arbitrary Tree to Satisfy Children Sum Property

### The Two-Phase Greedy Top-Down / Bottom-Up Trick
Because we can only **increment** values, we must avoid a situation where a parent exceeds its children's sum with no way to raise the children:
1. **Top-Down Pre-adjustment (Descending):**
   - Compare `node->val` with the sum of its children's current values.
   - If `node->val > left + right`, propagate the larger value down to both children (`child->val = node->val`).
   - If `node->val < left + right`, leave the parent as is (it will be updated on the way back up).
2. **Recurse:** Call `changeTree(node->left)` and `changeTree(node->right)`.
3. **Bottom-Up Post-adjustment (Ascending):**
   - When returning from both subtrees, set `node->val = (left ? left->val : 0) + (right ? right->val : 0)`.

**Complexity:** $O(N)$ time, $O(H)$ space.

