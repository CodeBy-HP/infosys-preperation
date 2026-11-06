# Introduction to Binary Trees

## 1. What is a Binary Tree?
A **Binary Tree** is a non-linear, hierarchical data structure in which each node has at most two children, typically referred to as the **left child** and the **right child**.

Formally, a binary tree $T$ is either:
1. **Empty** (null / nil).
2. Consists of a **root node** $R$, and two disjoint subtrees: a **left subtree** $T_L$ and a **right subtree** $T_R$, both of which are themselves binary trees.

```
          1 (Root)
        /   \
       2     3
      / \     \
     4   5     6 (Leaves: 4, 5, 6)
```

---

## 2. Key Terminology & Definitions

| Term | Definition |
|---|---|
| **Root** | The topmost node of the tree with no parent (e.g., node `1`). |
| **Edge** | The directed link connecting a parent node to its child. A tree with $N$ nodes always has exactly $N - 1$ edges. |
| **Leaf Node** | A node with no children (`left == nullptr && right == nullptr`). |
| **Internal Node** | A node with at least one non-null child. |
| **Depth of a Node** | Number of edges from the root to that node. $\text{depth}(\text{root}) = 0$. |
| **Height of a Node** | Number of edges on the longest downward path from that node to a leaf. |
| **Height of a Tree** | Height of the root node. Empty tree has height $-1$ (or $0$ under 1-based convention). |
| **Degree of a Node** | Number of children the node has ($0, 1,$ or $2$). |

---

## 3. Major Types of Binary Trees

### A. Full (Strict / Proper) Binary Tree
Every node has either **0 or 2 children**. No node has exactly 1 child.
- **Theorem:** If a full binary tree has $L$ leaves, it has $I = L - 1$ internal nodes, and total nodes $N = 2L - 1$.

### B. Complete Binary Tree
All levels are completely filled except possibly the last level, which is filled **from left to right** without gaps.
- Ideal for array-based representation without pointers (e.g., Heaps).
- Parent of index $i$: $\lfloor (i - 1) / 2 \rfloor$.
- Left child: $2i + 1$, Right child: $2i + 2$.

### C. Perfect Binary Tree
All internal nodes have exactly 2 children, and all leaf nodes are at the **exact same depth**.
- Total nodes at height $h$: $N = 2^{h+1} - 1$.
- Total leaves: $2^h$.

### D. Balanced Binary Tree
For every node in the tree, the difference between the height of the left subtree and the right subtree is at most 1:
$$|\text{height}(\text{left}) - \text{height}(\text{right})| \le 1$$
- Guarantees $O(\log N)$ search, insert, and delete operations (e.g., AVL trees, Red-Black trees).

### E. Degenerate (Skewed) Binary Tree
Every internal node has only one child. The tree deteriorates into a singly linked list with $O(N)$ height.

---

## 4. Fundamental Properties & Mathematical Relations
1. **Maximum nodes at level $l$ (0-indexed):** $2^l$.
2. **Maximum nodes in a tree of height $h$:** $2^{h+1} - 1$.
3. **Minimum height of a tree with $N$ nodes:** $\lceil \log_2(N + 1) \rceil - 1 \approx O(\log N)$.
4. **Maximum height of a tree with $N$ nodes:** $N - 1$ (skewed tree).
5. **Relation between leaves ($n_0$) and degree-2 nodes ($n_2$):**
   In any binary tree:
   $$n_0 = n_2 + 1$$
   *Proof:* Total edges $E = N - 1 = n_0 + n_1 + n_2 - 1$. Also, each degree-$k$ node contributes $k$ edges: $E = 0 \cdot n_0 + 1 \cdot n_1 + 2 \cdot n_2$. Equating gives $n_0 + n_1 + n_2 - 1 = n_1 + 2n_2 \implies n_0 = n_2 + 1$.

---

## 5. C++ Node Representation

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
```

