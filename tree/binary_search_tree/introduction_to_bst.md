# Introduction to Binary Search Trees (BST)

## 1. What is a Binary Search Tree?
A **Binary Search Tree (BST)** is a binary tree with a strict ordering invariant defined on its keys:
For every node $X$ in the tree:
1. Every key in the **left subtree** of $X$ is strictly less than $X$'s key:
   $$\forall Y \in \text{LeftSubtree}(X), \quad \text{key}(Y) < \text{key}(X)$$
2. Every key in the **right subtree** of $X$ is strictly greater than $X$'s key:
   $$\forall Z \in \text{RightSubtree}(X), \quad \text{key}(Z) > \text{key}(X)$$
3. Both the left and right subtrees must themselves be valid binary search trees.

```
          8
        /   \
       3     10
      / \      \
     1   6      14
        / \     /
       4   7   13
```

---

## 2. Fundamental Properties

### Property 1: Inorder Traversal is Monotonically Sorted
The in-order traversal ($\text{Left} \to \text{Root} \to \text{Right}$) of a valid BST produces elements in **strictly ascending sorted order**:
$$\text{Inorder}(T) = [1, 3, 4, 6, 7, 8, 10, 13, 14]$$
This property forms the foundation for validation, $K$-th smallest/largest selection, and two-sum searches.

### Property 2: Extremal Elements
- **Minimum Element:** Located by following `node->left` repeatedly until reaching a node with no left child (leftmost leaf or half-leaf).
- **Maximum Element:** Located by following `node->right` repeatedly until reaching a node with no right child (rightmost node).

---

## 3. Time Complexity Spectrum

| Operation | Average Case (Balanced BST) | Worst Case (Skewed BST) |
|---|:---:|:---:|
| **Search** | $O(\log N)$ | $O(N)$ |
| **Insertion** | $O(\log N)$ | $O(N)$ |
| **Deletion** | $O(\log N)$ | $O(N)$ |
| **Min / Max** | $O(\log N)$ | $O(N)$ |
| **Floor / Ceil** | $O(\log N)$ | $O(N)$ |
| **Successor / Predecessor** | $O(\log N)$ | $O(N)$ |

All operations are proportional to the **tree height $H$**:
$$T(N) = O(H)$$
- When balanced (e.g., AVL trees, Red-Black trees, `std::set`), $H = \lfloor \log_2 N \rfloor$, ensuring guaranteed $O(\log N)$.
- When keys are inserted in sorted order without balancing, the tree degenerates into a singly linked list ($H = N - 1$).

