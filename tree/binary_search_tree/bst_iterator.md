# Binary Search Tree Iterator

## Problem Statement
Implement the `BSTIterator` class that represents an iterator over the **in-order traversal** of a binary search tree (BST):
- `BSTIterator(TreeNode* root)`: Initializes an object of the `BSTIterator` class. The `root` of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
- `boolean hasNext()`: Returns `true` if there exists a number in the traversal to the right of the pointer, otherwise returns `false`.
- `int next()`: Moves the pointer to the right, then returns the number at the pointer.

**Constraints:**
- `next()` and `hasNext()` should run in average **$O(1)$ time**.
- The iterator must consume strictly **$O(H)$ memory**, where $H$ is the height of the tree (storing the entire flattened in-order array of size $O(N)$ is disallowed).

```
        7
       / \
      3   15
         /  \
        9   20

BSTIterator bSTIterator = new BSTIterator(root);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False
```

---

## 1. Algorithmic Approach (Controlled In-Order Stack)

### Core Invariant
Instead of running a full in-order traversal upfront, we pause and resume in-order traversal on demand:
1. In the constructor, drill down along the left spine starting from `root`, pushing every node onto an explicit `std::stack<TreeNode*> st`.
   - The top of the stack is always the next smallest unvisited node.
2. **`hasNext()`:**
   - Simply returns `!st.empty()`. Runs in $O(1)$ time.
3. **`next()`:**
   - Pop `curr = st.top()`.
   - If `curr` has a right child (`curr->right != nullptr`), drill down along the left spine of `curr->right`, pushing all nodes to the stack (`pushAllLeft(curr->right)`).
   - Return `curr->val`.

### Why is `next()` Amortized $O(1)$?
Across the entire lifespan of iterating through all $N$ nodes in the tree, each node is pushed onto the stack exactly once and popped exactly once.
$$\text{Total pushes and pops across } N \text{ calls} = 2N \implies \text{Amortized time per call} = \frac{2N}{N} = O(1)$$

---

## 2. Complexity Analysis
- **Time Complexity:**
  - `hasNext()`: $O(1)$ worst-case.
  - `next()`: $O(1)$ amortized ($O(H)$ worst-case when drilling down a new branch).
- **Space Complexity:** $O(H)$ — The stack stores at most $H$ nodes along the active search path.

