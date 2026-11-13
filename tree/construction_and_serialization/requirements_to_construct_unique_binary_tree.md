# Requirements Needed to Construct a Unique Binary Tree

## 1. The Core Question
Given a combination of tree traversals (Inorder, Preorder, Postorder), when can we **uniquely reconstruct** the original binary tree?

---

## 2. Theoretical Breakdown by Traversal Pair

### A. Can a Single Traversal Construct a Unique Tree?
**NO.**
- **Inorder alone:** For $N$ distinct keys, there are Catalan number $C_N = \frac{1}{N+1}\binom{2N}{N}$ structurally distinct valid binary trees sharing the exact same inorder traversal!
- **Preorder alone or Postorder alone:** A linear sequence cannot distinguish between left-child branching and right-child branching without explicit `nullptr` markers (e.g., serialized `#`).

---

### B. Preorder + Inorder $\longrightarrow$ UNIQUE TREE (YES)
- **Preorder gives the ROOT:** The very first element `preorder[0]` is guaranteed to be the root of the current subtree.
- **Inorder partitions LEFT and RIGHT:** Finding the root in `inorder` splits the array:
  - Everything to the left of the root index belongs to the **Left Subtree**.
  - Everything to the right belongs to the **Right Subtree**.
- The size of the left partition dictates the exact segment boundary in the `preorder` array.
- This creates an unambiguous recursive bijection.

---

### C. Postorder + Inorder $\longrightarrow$ UNIQUE TREE (YES)
- **Postorder gives the ROOT:** The very last element `postorder.back()` is strictly the root of the current subtree.
- **Inorder partitions LEFT and RIGHT:** Finding the root in `inorder` cleanly divides the remaining elements into left and right subtrees.
- Again, this uniquely reconstructs the tree.

---

### D. Preorder + Postorder $\longrightarrow$ UNIQUE TREE? (NO, in general!)

#### Counterexample:
Consider two different binary trees:
```
  Tree A:        Tree B:
     1              1
    /                \
   2                  2
```
- **Tree A:** Preorder = `[1, 2]`, Postorder = `[2, 1]`.
- **Tree B:** Preorder = `[1, 2]`, Postorder = `[2, 1]`.

Both trees produce identical Preorder and Postorder traversals! Without an Inorder traversal, we cannot tell whether node `2` is a **left child** or a **right child** of `1`.

#### The Special Exception (Full Binary Trees):
If the problem guarantees that the binary tree is a **Full Binary Tree** (every internal node has strictly **2 children**, no node has 1 child):
- `preorder[1]` must be the root of the left subtree.
- Finding `preorder[1]` inside `postorder` delineates the left and right subtree boundaries!
- Therefore, **Preorder + Postorder can uniquely construct a tree IF AND ONLY IF the tree is a Full Binary Tree.**

---

## 3. Summary Rule for Coding Assessments

| Traversal Combination | Unique Arbitrary Binary Tree? | Unique Full Binary Tree? |
|---|:---:|:---:|
| **Inorder + Preorder** | **YES** | **YES** |
| **Inorder + Postorder** | **YES** | **YES** |
| **Inorder + Level-order**| **YES** | **YES** |
| **Preorder + Postorder**| **NO** (Ambiguous for 1-child nodes) | **YES** |
| **Preorder alone** | **NO** | **NO** |
| **Inorder alone** | **NO** | **NO** |
| **Postorder alone** | **NO** | **NO** |

> [!IMPORTANT]
> To uniquely construct an arbitrary binary tree, **Inorder traversal is strictly mandatory** alongside either Preorder or Postorder traversal because Inorder is the only traversal that provides directional left vs. right boundary separation.

